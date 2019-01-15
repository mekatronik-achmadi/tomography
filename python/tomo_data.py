#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 15 16:41:13 2019

@author: achmadi
"""

import numpy as np
import math as mt
import seaborn as sbn

#import matplotlib
#matplotlib.use('TKAgg')

import matplotlib.pyplot as plt
import matplotlib.lines as mline

class DataTomo:
    def __init__(self,nstep):
        self.n_step = nstep
        
    def closeWin(self):
        plt.close("all")
    
    def dataLoad(filename):
        datamat = np.load(filename)
        return datamat
    
    def dataSave(filename,datamat):
        np.save(filename,datamat)
        
    def plotMap(self,radius):
        
        angle = 360 / self.n_step
        theta = angle / 2
        
        p_IR = np.zeros((self.n_step,2))
        p_PT = np.zeros((self.n_step,2))
        
        for i in range(self.n_step):
            p_IR[i,0]=radius*mt.cos(mt.radians(i*angle))
            p_IR[i,1]=radius*mt.sin(mt.radians(i*angle))
    
            p_PT[i,0]=radius*mt.cos(mt.radians(theta+i*angle))
            p_PT[i,1]=radius*mt.sin(mt.radians(theta+i*angle))
            
        fig, ax = plt.subplots()
        for i in range(self.n_step):
            txtnum = "%s" % i
            ax.add_patch(plt.Circle((p_IR[i,0],p_IR[i,1]), 0.1, color='r'))
            plt.text(p_IR[i,0],p_IR[i,1],txtnum)
            ax.add_patch(plt.Circle((p_PT[i,0],p_PT[i,1]), 0.1, color='b'))
            plt.text(p_PT[i,0],p_PT[i,1],txtnum)
            
        ax.set_aspect('equal', adjustable='datalim')
        ax.plot()
        plt.show()
        
    def plotBar(self,datamat):
        plt.figure()
        for i in range(self.n_step):
            plt.subplot(self.n_step,1,i+1)
            plt.bar(range(self.n_step), datamat[:,i],  align = 'center')
        plt.show()
        
    def plotHMap(self,datamat):
        plt.figure()
        ax = sbn.heatmap(datamat)
        ax.set_aspect('equal', adjustable='datalim')
        ax.plot()
        plt.show()
        
    def plotBeam(self,datamat,radius):
        angle = 360 / self.n_step
        theta = angle / 2
        
        p_IR = np.zeros((self.n_step,2))
        p_PT = np.zeros((self.n_step,2))
        
        for i in range(self.n_step):
            p_IR[i,0]=radius*mt.cos(mt.radians(i*angle))
            p_IR[i,1]=radius*mt.sin(mt.radians(i*angle))
    
            p_PT[i,0]=radius*mt.cos(mt.radians(theta+i*angle))
            p_PT[i,1]=radius*mt.sin(mt.radians(theta+i*angle))
            
        fig, ax = plt.subplots()
        for i in range(self.n_step):
            txtnum = "%s" % i
            ax.add_patch(plt.Circle((p_IR[i,0],p_IR[i,1]), 0.1, color='r'))
            plt.text(p_IR[i,0],p_IR[i,1],txtnum)
            ax.add_patch(plt.Circle((p_PT[i,0],p_PT[i,1]), 0.1, color='b'))
            plt.text(p_PT[i,0],p_PT[i,1],txtnum)
            
        for i in range(self.n_step): 
            for j in range(self.n_step):    
                line = [(p_PT[j,0],p_PT[j,1]) , (p_IR[i,0],p_IR[i,1])]
                (line_xs, line_ys) = zip(*line)
                A = datamat[j,i]/4095
                ax.add_line(mline.Line2D(line_xs, line_ys, linewidth=2*radius, alpha=A, color='black'))
                
        ax.set_aspect('equal', adjustable='datalim')
        ax.plot()
        plt.show()