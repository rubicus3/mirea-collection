#!/bin/bash

ls -la $1 | awk '$1 ~ /^d/ && $9 ~ /[а-яА-ЯЁё]+/ {print $9, $10}'
