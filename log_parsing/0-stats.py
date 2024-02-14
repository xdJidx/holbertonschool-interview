#!/usr/bin/python3
""" Log parsing """
import sys
import signal


# Variables to store metrics
total_file_size = 0
status_code_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0,
                      404: 0, 405: 0, 500: 0}

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
