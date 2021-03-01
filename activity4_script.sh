#! /usr/bin/bash

for i in $(seq $1)
do
	echo -n $i " "
       	./thread 600000 600000
done

