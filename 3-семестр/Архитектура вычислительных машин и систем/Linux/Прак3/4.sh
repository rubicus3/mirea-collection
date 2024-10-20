#!/bin/bash

ls -la --block-size=4K $1 | awk 'BEGIN { sum = 0 } $1 ~ /^-/ {sum += $5} END { print "Кол-во = ", sum }'
