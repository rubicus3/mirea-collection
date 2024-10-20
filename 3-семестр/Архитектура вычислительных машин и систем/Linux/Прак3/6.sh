#!/bin/bash

find $1 -name "data*.txt" -type f | awk -F/ '{print $(NF - 1)}' | uniq
