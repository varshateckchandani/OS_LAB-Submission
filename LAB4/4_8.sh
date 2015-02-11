echo "Enter filename of which number of new lines are to be found: "
read filename

sed -n '$=' "$filename"
