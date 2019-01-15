#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 15 15:34:48 2019

@author: achmadi
"""

import serial
import time
import numpy as np
import math as mt
import seaborn as sbn

#import matplotlib
#matplotlib.use('TKAgg')

import matplotlib.pyplot as plt
import matplotlib.lines as mline

class SerialTomo:
    def __init__(self,addr,nstep):
        self.ser = serial.Serial(addr,9600,timeout=1)
        self.n_step = nstep
        self.data_mat = np.zeros([self.n_step, self.n_step])
        self.data_one = np.zeros(self.n_step)
        
    def closeWin(self):
        plt.close("all")
        
    def dataAll(self,tsleep=0.25):
        self.data_mat = np.zeros([self.n_step, self.n_step])
        
        for i in range(self.n_step):
            print('test sequence: %i' % i)
            self.ser.write(b'led %i\r' % i)
            time.sleep(tsleep)
            
            self.ser.write(b'adc\r')
            serline = self.ser.readline()
            str_array = str(serline,'ascii').rstrip("\n\r").split(",")
            int_array = np.asarray(list(map(int, str_array)))

            for j in range(self.n_step):
                self.data_mat[j,i] = int_array[j]

            time.sleep(tsleep)
            
        print('test finished')
        return self.data_mat
        
    def dataOne(self,n_seq,tsleep=0.25):
        self.data_one = np.zeros(self.n_step)
        print('test sequence: %i' % n_seq)
        self.ser.write(b'led %i\r' % n_seq)
        time.sleep(tsleep)

        self.ser.write(b'adc\r')
        serline = self.ser.readline()
        str_array = str(serline,'ascii').rstrip("\n\r").split(",")
        int_array = np.asarray(list(map(int, str_array)))
        
        self.data_one = int_array

        print('test finished')
        return self.data_one        
        
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
        
    def plotAllBar(self):
        plt.figure()
        for i in range(self.n_step):
            plt.subplot(self.n_step,1,i+1)
            plt.bar(range(self.n_step), self.data_mat[:,i],  align = 'center')
        plt.show()
        
    def plotAllHMap(self):
        plt.figure()
        ax = sbn.heatmap(self.data_mat)
        ax.set_aspect('equal', adjustable='datalim')
        ax.plot()
        plt.show()
        
    def plotAllBeam(self,radius):
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
                A = self.data_mat[j,i]/4095
                ax.add_line(mline.Line2D(line_xs, line_ys, linewidth=2*radius, alpha=A, color='black'))
                
        ax.set_aspect('equal', adjustable='datalim')
        ax.plot()
        plt.show()
        
    def plotOneBar(self):
        plt.figure()
        plt.bar(range(self.n_step), self.data_one,  align = 'center')
        plt.show()
    