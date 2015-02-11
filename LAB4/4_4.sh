
count=0
echo "Enter a number: "
read num
i=2
sum=`expr $num / 2`
while [ "$i" -le "$sum" ] 
do
	temp=`expr $num % $i`
	if [ $temp -eq 0 ]
	then
        count=`expr $count + 1`
	break
	fi
     	i=`expr $i + 1`
done

if [[ "$count" -eq 0 && "$num" -ne 1 ]]
then
	echo Prime Number
else
	echo Not a prime number
fi
