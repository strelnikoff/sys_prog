#!/bin/bash

grep "Failed password for" /var/log/auth.log | grep -Po "[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+" | sort | uniq -c > clear_log
python3 ssh_auth.py
touch /var/log/auth.log
