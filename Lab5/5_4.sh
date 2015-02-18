# Largest file

x= find . -type f -print0 | xargs -0 du | sort -n | tail -1 | cut -f2 | xargs -I{} du -sh {}
echo $x
