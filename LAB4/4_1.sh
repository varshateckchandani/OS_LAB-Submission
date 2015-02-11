
x=1;
while [ "$x" -eq 1  ] 
do
	echo n: ;
	read n;
	if [ "$n" -lt 50 ]
	then
	{
	a=`expr $n \* $n`
	echo square $n: $a;
	}

	else
	echo "Number is not valid"
	fi

done
