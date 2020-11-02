#!/bin/bash
################
# This will test if we pass the 0 argument test for Part 2A

# Check if program exists
if [ ! -f args_main ]; then
    echo "args_main doesn't exist!"
    exit 1;
fi

attempt_file=output2a-0_attempt.txt

# Run the program and save the output
rm -f "$attempt_file"
./args_main > "$attempt_file"

# Compare the results
diff output2a-0.txt "$attempt_file"
diff_status=$?

# Cleanup
rm -f "$attempt_file"

# Print the test results"
if [ "$diff_status" -ne 0 ]; then
    echo "ERROR: diff failed"
    exit 1
fi

echo "OK: All tests passed"
