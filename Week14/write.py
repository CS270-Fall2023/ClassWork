#! /usr/bin/env python3

import os
import time

print("Client process ID: ", os.getpid())

# Prepare message
message = "Hello from PID {}".format(os.getpid())

# strings in C/C++ are null terminated, add null at the end
message = message + '\x00'

# string needs to be converted byte object
message = str.encode(message) 

while True:
    try:
        fd = os.open("aPipe", os.O_WRONLY)
        break
    except FileNotFoundError:
        time.sleep(1)

for i in range(3):
    print("Sending message to server")
    os.write(fd, message)
    time.sleep(3)

os.close(fd)
