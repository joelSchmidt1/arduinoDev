# -*- coding: utf-8 -*-
"""
Created on Sun Sep 24 18:56:12 2017

@author: Joel
"""

decimalNum = raw_input("What is the decimal number?")

decimalInt = int(decimalNum)

def converter(i):
    if i == 0: return "0"
    s = ''
    while i:
        if i & 1 == 1:
            s = "1" + s
        else:
            s = "0" + s
        i /= 2
    return s
        
        
print converter(decimalInt)