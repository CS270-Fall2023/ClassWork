#!/bin/bash
source multiply.sh

num1=3
num2=4
multiply $num1 $num2
result=$?        # get the exit code
echo "Product of $num1 and $num2 is $result"

