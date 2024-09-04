#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>

/*
 * Prototype de la fonction find_substring.
 * s : chaîne de caractères à analyser
 * words : tableau de mots, dont chaque sous-chaîne valide doit être une concaténation
 * nb_words : nombre d'éléments dans le tableau words
 * n : adresse où stocker le nombre d'éléments dans le tableau retourné
 *
 * La fonction retourne un tableau alloué dynamiquement, stockant chaque index dans s
 * où une sous-chaîne valide a été trouvée. Si aucune solution n'est trouvée, elle retourne NULL.
 */
int	*find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
