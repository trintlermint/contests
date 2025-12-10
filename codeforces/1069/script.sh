echo 10 > input7.txt
for i in {1..10}; do
  n=$(shuf -i 2-1000 -n 1)
  l=$(shuf -i 1-$((n-1)) -n 1)
  r=$(shuf -i $((l+1))-$n -n 1)
  echo "$n $l $r" >> input7.txt
done
