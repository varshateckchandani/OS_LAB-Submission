hour=$(date +"%H")
minute=$(date +"%M")
second=$(date +"%S")

if [ $hour -lt 12 -a $hour -ge 8 ]
then 
	echo "Good morning !!!"
elif [ $hour -lt 16 -a $hour -ge 12 ]
then
	echo "Good afternoon!!!"
else 
	echo "Good evening!!!"
fi
