#!/bin/bash

ls -ls $1 | awk 'BEGIN { sum = 0 } {sum += $1} END { print "Сумма каталога в блоках = ", sum }'
