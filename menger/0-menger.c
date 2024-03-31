#include <stdio.h>
#include <math.h>

/**
 * @brief Dessine un caractère "#" ou un espace en fonction des coordonnées et de la taille spécifiées.
 *
 * Cette fonction affiche un caractère "#" si les coordonnées (x, y) sont à l'intérieur
 * de la grille de taille size, sinon elle affiche un espace.
 *
 * @param size Taille de la grille.
 * @param x Coordonnée horizontale.
 * @param y Coordonnée verticale.
 */
void draw_char(int size, int x, int y)
{
    if ((x >= size) || (y >= size) || (x < 0) || (y < 0)) {
        printf(" ");
    } else {
        printf("#");
    }
}

/**
 * menger - 2D menger sponge
 * @level: level of the menger sponge
 */
void menger(int level)
{
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
