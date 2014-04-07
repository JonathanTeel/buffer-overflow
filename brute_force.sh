#!/bin/bash

if [ -f vulnerable.c ] && ! [ -f vulnerable.out ]; then
    echo '[-] run `make` first!'
    exit 1
elif [ -f test/vulnerable.c ]; then
    echo '[-] run this script from inside test/'
    exit 1
fi

echo '[+] running brute-force attack'
sleep 1

for i in {1..100}; do
    ./vulnerable.out $(./myexploit.out 600 $[(i-50)*8])
    if [ -f break ]; then
        break
    fi
done
