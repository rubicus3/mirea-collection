#!/bin/bash

last | awk '{
    if($1 != "reboot") {
        for(i = 1; i <= NF; i++) {
            if($i ~ /[0-9]:/)
            {
                print $1, $i;
                break;
            }
        }
    }
}' | sort -k2
