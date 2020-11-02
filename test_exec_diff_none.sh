#!/bin/bash
################
# This will test if we check for if arguments have been provided properly for Part 2b

# Check if program exists
if [ ! -f exec_diff_main ]; then
    echo "exec_diff_main doesn't exist!"
    exit 1;
fi

attempt_file=output2b-none_attempt.txt

# Run the program and save the output
rm -f "$attempt_file"
./exec_diff_main > "$attempt_file"

# Compare the results
diff output2b-none.txt "$attempt_file"
diff_status=$?

# Cleanup
rm -f "$attempt_file"

# Print the test results"
if [ "$diff_status" -ne 0 ]; then
    echo "ERROR: diff failed"
    exit 1
fi

echo "OK: All tests passed"
