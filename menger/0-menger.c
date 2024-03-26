#include <stdio.h>
#include <math.h>

void draw_char(int size, int x, int y) {
    if ((x >= size) || (y >= size) || (x < 0) || (y < 0)) {
        printf(" ");
    } else {
        printf("#");
    }
}

void menger(int level) {
    int size, x, y, div_x, div_y;

    if (level < 0) return;

    size = (int)pow(3, level);

    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            div_x = x;
            div_y = y;

            while (div_x > 0 && div_y > 0) {
                if (div_x % 3 == 1 && div_y % 3 == 1) {
                    printf(" ");
                    break;
                }
                div_x /= 3;
                div_y /= 3;
            }
            if (div_x == 0 || div_y == 0) {
                draw_char(size, x, y);
            }
        }
        printf("\n");
    }
}

