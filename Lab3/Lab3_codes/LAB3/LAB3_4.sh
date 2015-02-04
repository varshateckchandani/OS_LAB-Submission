echo enter 1st Num:
read n1
echo enter 2nd Num:
read n2
if [ $n1 -gt $n2 ]
then 
echo larger of two : $n1
elif [ $n1 -lt $n2 ]
then 
echo larger of two : $n2
else
echo Both are equal

fi
