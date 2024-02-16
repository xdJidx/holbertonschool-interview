#!/usr/bin/python3
"""
Log parsing script.

This script reads input lines from stdin, expecting each line to be in the format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

After every 10 lines and/or a keyboard interruption (CTRL + C), it prints the following metrics:
- Total file size: <total size>
- Number of lines by status code:
  possible status codes: 200, 301, 400, 401, 403, 404, 405, and 500
"""

import sys


# Variables to store metrics
total_file_size = 0
status_code_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0,
                      404: 0, 405: 0, 500: 0}


def print_metrics(signum, frame):
    """
    Print metrics and exit the program.
    """
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts):
        count = status_code_counts[code]
        if count > 0:
            print(f"{code}: {count}")
    sys.exit(0)

try:
    for i, line in enumerate(sys.stdin, start=1):
        parts = line.strip().split()

        # Check if the line follows the specified format
        if len(parts) == 10 and parts[5] == '"GET' and parts[7].isdigit():
            file_size = int(parts[7])
            status_code = int(parts[8])

            # Update metrics
            total_file_size += file_size
            status_code_counts[status_code] += 1

            # Print metrics after every 10 lines
            if i % 10 == 0:
                print(f"File size: {total_file_size}")
                for code in sorted(status_code_counts):
                    count = status_code_counts[code]
                    if count > 0:
                        print(f"{code}: {count}")
                print()

except KeyboardInterrupt:
    pass

finally:
    # Print final metrics on keyboard interruption
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts):
        count = status_code_counts[code]
        if count > 0:
            print(f"{code}: {count}")
