#!/bin/bash

#!/bin/bash
# Convierte caracteres alfabéticos en valores hexadecimales
while IFS= read -r line; do
    echo "$line" | awk '{
        result = ""
        for (i = 1; i <= length($0); i++) {
            char = substr($0, i, 1)
            if (char ~ /[a-z]/) {
                hex = sprintf("%x", index("abcdefghijklmnopqrstuvwxyz", char) - 1)
                result = result hex
            } else {
                result = result char
            }
        }
        print result
    }'
done

