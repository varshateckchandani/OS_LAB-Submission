echo "Enter Filename: "
read file1
x=0
if test -e $file1
then
	echo $file1 exists
	x=1
else
	echo $file1 "doesn't exist"
	
	
fi	

if [ $x -eq 1 ]
then
	y=0
	echo "Enter another Filename: "
	read file2
	if test -e $file2
	then
		y=1
		echo $file2 exist
	else
		echo $file2 "doesn't exist"
		
	fi


	if [ $y -eq 1 ]
	then
		cat $file1 >> $file2
	else
		cat $file1 > $file2
	fi

else 
	echo Invalid filename $file1 
fi
