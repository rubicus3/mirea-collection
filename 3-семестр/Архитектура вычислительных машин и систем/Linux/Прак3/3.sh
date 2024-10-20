#!/bin/bash

ls -lR $1 | awk 'BEGIN { sum = 0 } $1 ~ /^-/ && $9 ~ /\.txt$/ {sum += $5} END { print "Сумма =", sum }'
