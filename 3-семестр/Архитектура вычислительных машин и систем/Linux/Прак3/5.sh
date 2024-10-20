#!/bin/bash

ls -l $1 | awk ' $1 ~ /^-/ { print $1, $NF | "sort" }'
