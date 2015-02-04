#!/bin/sh

echo  "Enter two numbers for Addition : "
echo -n "Number1: "
read num1

echo -n "Number2: "
read num2
echo 
echo
echo "$num1 + $num2 = `expr $num1 + $num2`"
echo "$num1 - $num2 = `expr $num1 - $num2`"
echo "$num1 * $num2 = `expr $num1 \* $num2`"
echo "$num1 / $num2 = `expr $num1 / $num2`"
