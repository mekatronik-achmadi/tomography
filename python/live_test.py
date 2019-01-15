#!/usr/bin/python3

import serial
import time
import matplotlib
matplotlib.use('TKAgg')
import matplotlib.pyplot as plt
import numpy as np

n_step = 6
n_seq  = 0
addr   = '/dev/ttyACM0'

fig = plt.figure()
win = fig.canvas.manager.window

ser = serial.Serial(addr,9600,timeout=1)

ser.write(b'led %i\r' % n_seq)
time.sleep(0.25)

def sensor_barplot():

    int_array = np.array([4095,4095,4095,4095,4095,4095])
    rects = plt.bar(range(n_step), int_array,  align = 'center')

    while True:
        time.sleep(0.25)
        ser.write(b'adc\r')
        serline = ser.readline()
        str_array = str(serline,'ascii').rstrip("\n\r").split(",")
        int_array = np.asarray(list(map(int, str_array)))

        for rect, h in zip(rects, int_array):
            rect.set_height(h)
            fig.canvas.draw()

win.after(10, sensor_barplot)
plt.show()
