# sum of natural numbers through command line

if [ -z "$1" ]
then
	echo "(50 * (50+1)) / 2" |bc
	
else
	echo "($1 * ($1+1)) / 2" |bc
fi
