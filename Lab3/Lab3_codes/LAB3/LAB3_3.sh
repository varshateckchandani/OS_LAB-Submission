#!/bin/sh

echo  "Number Expression Number "
read num1 exp num2

case $exp in
	+) echo "$num1 + $num2 = `expr $num1 + $num2`" ;;

	-) echo "$num1 - $num2 = `expr $num1 - $num2`" ;;

	/) echo "$num1 / $num2 = `expr $num1 / $num2`" ;;

	%) echo "$num1 % $num2 = `expr $num1 % $num2`" ;;	

	\*) echo "$num1 * $num2 = `expr $num1 \* $num2`";;

	*) echo Invalid Choice
esac






