echo "Enter Actual rent of the house: "
read Actual_rent

echo "Enter your basic salary: "
read Basic_salary

a=0.12 


#HRA= "$a*$Basic_salary" | bc 
#HRA= "scale=5; $(($Actual_rent - $a*$Basic_salary))" | bc   

#bc <<< 'scale=4; HRA= $(($Actual_rent - $a \* $Basic_salary | bc -l))'
#echo $HRA | bc
echo "$Actual_rent - $a * $Basic_salary" | bc
