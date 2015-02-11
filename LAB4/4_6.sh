hour=$(date +"%H")
minute=$(date +"%M")
second=$(date +"%S")

if [ $hour -lt 12 ]
then 
	echo "Good morning !!!"
elif [ $hour -lt 16 ]
then
	echo "Good afternoon!!!"
else 
	echo "Good evening!!!"
fi
