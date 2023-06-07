#!/usr/bin/bash
eval "make all"
input_dir=./in/
output_dir=./out/
for entry in "$input_dir"*
do
    echo $(basename "$entry")
    eval ./data < $input_dir$(basename "$entry") > data.out
    diff data.out $output_dir$(basename "$entry")
    if [[ $? -ne 0 ]]; then
        echo $entry
        break
    fi
done
