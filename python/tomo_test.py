#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 15 16:30:07 2019

@author: achmadi
"""

import time
from tomo_serial import SerialTomo
from tomo_data import DataTomo

n_matrix = 6

tomo_obj = SerialTomo('/dev/ttyACM0',n_matrix)
data_obj = DataTomo(n_matrix)

base = tomo_obj.dataAll()

print('now put your object')
print('re-measure in:')
for i in range(10):
    print("%i" % (9-i))
    time.sleep(1)

tomo_obj.dataAll()

data_obj.plotBeam(base,3)
tomo_obj.plotAllBeam(3)
