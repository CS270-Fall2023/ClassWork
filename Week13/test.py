#!/usr/bin/env python3
import myFunctions
#from myFunctions import repeat
import os, platform



def main():
    #print('Your System: ' + platform.system())
    c = os.getcwd()
    myFunctions.listDir(c)

    # print(myFunctions.repeat('Yay ', False))      ## YayYayYay
    # print(myFunctions.repeat('Woo Hoo ', True))   ## Woo HooWoo HooWoo Hoo!!!


# Standard boilerplate to call the main() function to begin
# the program.
if __name__ == '__main__':
    main()

