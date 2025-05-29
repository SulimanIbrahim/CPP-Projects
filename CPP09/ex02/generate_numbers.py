#!/usr/bin/env python3
import random

# Generate 3000 unique random numbers between 1 and 10000
numbers = random.sample(range(1, 10001), 3000)
print(' '.join(map(str, numbers)))
