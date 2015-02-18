# Palindrome strings

x=`expr $1 | rev`
if [ $x == $1 ]
then
	echo The entered string $1 is a palindrome
else
	echo The entered string $1 is not a palindrome
fi	
