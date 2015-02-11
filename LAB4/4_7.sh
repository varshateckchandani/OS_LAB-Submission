
ls -l "$1"

echo "Do you want to revoke the permission of a file: "
read permission

if [ $permission == y -o $permission == Y ]
then
chmod 111 $1
ls -l "$1"
fi

