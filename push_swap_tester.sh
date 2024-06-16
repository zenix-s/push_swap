#!/bin/bash

# Define the range of a 32-bit signed integer
MIN_INT=-2147483648
MAX_INT=2147483647

# Check if the user provided the number of numbers to generate
if [ -z "$1" ]; then
    echo "Usage: $0 <number_of_numbers>"
    exit 1
fi

NUM_COUNT=$1

# Generate NUM_COUNT unique random numbers within the range
generate_numbers() {
    local num_count=$1
    local num_list=()
    local num_set=()

    while [ ${#num_list[@]} -lt $num_count ]; do
        num=$((RANDOM * RANDOM))
        if ((RANDOM % 2)); then
            num=$(( -num ))
        fi
        if (( num >= MIN_INT && num <= MAX_INT )) && [[ ! " ${num_set[@]} " =~ " ${num} " ]]; then
            num_list+=($num)
            num_set+=($num)
        fi
    done

    echo "${num_list[@]}"
}

numbers=$(generate_numbers $NUM_COUNT)

# Execute push_swap with the generated numbers
./push_swap $numbers

