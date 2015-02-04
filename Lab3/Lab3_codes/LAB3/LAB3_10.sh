list=(121001 121002 121003 121004 121005 121006 121007 121008 121009 121010)
read -p "Search your ID:" ID
for i in {0..9}
do
if [ "$ID" == "${list[$i]}" ]  
then
echo "You are on the list "
echo  "Position" `expr $i + 1`
c=0
exit 1
else 
c=1
fi
done
if [ "$c" == 1 ]
then
echo value not found
echo 
fi


