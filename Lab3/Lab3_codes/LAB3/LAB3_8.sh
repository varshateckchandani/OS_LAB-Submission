i=0
j=1
echo $i
s=0
while [ $s -le 20 ]
do
	echo `expr $j`
	k=$i
	i=$j
	j=`expr $j + $k`
	s=`expr $s + 1`

done
