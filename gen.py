#!/usr/bin/python3
import random

n = 20
H = 10
W = 10
print(n, 3*W)
for i in range(n):
    print(random.randint(1, H), random.randint(1, W))