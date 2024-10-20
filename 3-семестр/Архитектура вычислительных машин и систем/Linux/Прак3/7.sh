#!/bin/bash

last | awk -v user="$1" 'BEGIN {c = 0} $1 == user {c += 1} END {print c}'
