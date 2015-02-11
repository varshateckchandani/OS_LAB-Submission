echo "Enter pattern to be searched";
 read pattern;
echo "Enter file name ";
read filename;
grep $pattern $filename;

if [ $? -eq 0 ]
then              
echo Pattern found ;
else
echo Pattern not found;
fi


