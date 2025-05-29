#!/usr/bin/env python3
import random

# Generate 3000 unique random numbers between 1 and 100000
numbers = random.sample(range(1, 100001), 3000)
with open('random_3000.txt', 'w') as f:
    f.write(' '.join(map(str, numbers)))
