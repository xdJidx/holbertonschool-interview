#include "lists.h"

/**
 * check_cycle - vérifie si une liste chaînée simple contient une boucle
 * @list: pointeur vers la tête de la liste
 * Retourne : 0 s'il n'y a pas de boucle, 1 s'il y a une boucle
 */
int check_cycle(listint_t *list)
{
    listint_t *lent = list, *rapide = list;

    while (lent && rapide && rapide->next)
    {
        lent = lent->next;
        rapide = rapide->next->next;

        if (lent == rapide)
            return 1;
    }

    return 0;
}