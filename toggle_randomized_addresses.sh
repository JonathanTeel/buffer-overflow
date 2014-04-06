#!/bin/bash

if ! [ $(id -u) -eq 0 ]; then
    echo '[-] Run this script as root!'
    echo '[-] exit 1'
    exit 1
fi

if [ $(cat /proc/sys/kernel/randomize_va_space) -eq 0 ]; then
    echo 2 > /proc/sys/kernel/randomize_va_space
    echo '[+] Randomized Addresses Re-enabled.'
else
    echo 0 > /proc/sys/kernel/randomize_va_space
    echo '[+] Randomized Addresses Disabled.'
fi
