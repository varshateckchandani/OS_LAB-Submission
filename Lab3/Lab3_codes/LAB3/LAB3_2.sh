#!/bin/sh



case $2 in
	+) echo "$1 + $3 = `expr $1 + $3`" ;;

	-) echo "$1 - $3 = `expr $1 - $3`" ;;

	/) echo "$1 / $3 = `expr $1 / $3`" ;;

	%) echo "$1 % $3 = `expr $1 % $3`" ;;	

	\*) echo "$1 * $3 = `expr $1 \* $3`";;

	*) echo Invalid Choice
esac






