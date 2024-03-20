#include <stddef.h>
#include "slide_line.h"

#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1

/**
 * slide_line - Slide and merge an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t current, next;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0; // Failure if direction is invalid

    if (direction == SLIDE_LEFT) {
        // Slide and merge to the left
        for (current = 0; current < size; current++) {
            if (line[current] == 0)
                continue;
            for (next = current + 1; next < size; next++) {
                if (line[next] == 0)
                    continue;
                if (line[current] == line[next]) {
                    line[current] *= 2;
                    line[next] = 0;
                    break;
                } else {
                    break;
                }
            }
        }
        // Slide all elements to the left
        for (current = 0, next = 0; current < size; current++) {
            if (line[current] != 0) {
                line[next++] = line[current];
            }
        }
        // Fill the rest with zeros
        for (; next < size; next++) {
            line[next] = 0;
        }
    } else { // direction == SLIDE_RIGHT
        // Slide and merge to the right
        for (current = size - 1; current < size; current--) {
            if (line[current] == 0)
                continue;
            for (next = current - 1; next < size; next--) {
                if (line[next] == 0)
                    continue;
                if (line[current] == line[next]) {
                    line[current] *= 2;
                    line[next] = 0;
                    break;
                } else {
                    break;
                }
            }
        }
        // Slide all elements to the right
        for (current = size - 1, next = size - 1; current < size; current--) {
            if (line[current] != 0) {
                line[next--] = line[current];
            }
        }
        // Fill the rest with zeros
        for (; next < size; next--) {
            line[next] = 0;
        }
    }
    return 1; // Success
}
