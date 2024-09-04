#include "substring.h"

/**
 * check_substring - Vérifie si les mots dans "words" sont présents
 * dans une sous-chaîne
 * @s: chaîne à analyser
 * @words: tableau de mots à rechercher
 * @word_len: longueur de chaque mot
 * @nb_words: nombre de mots dans le tableau
 * @start_idx: index de début de la sous-chaîne dans s
 *
 * Return: 1 si la sous-chaîne est une concaténation valide des mots, 0 sinon
 */
int	check_substring(const char *s, const char **words, int word_len,
	int nb_words, int start_idx)
{
	int	word_found[nb_words];
	int	i, j, found;

	memset(word_found, 0, nb_words * sizeof(int));

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!word_found[j] &&
				strncmp(s + start_idx + i * word_len, words[j], word_len) == 0)
			{
				word_found[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
			return (0);
	}
	return (1);
}

/**
 * find_substring - Trouve tous les indices des sous-chaînes dans "s" qui sont
 * des concaténations des mots dans "words"
 * @s: chaîne à analyser
 * @words: tableau de mots
 * @nb_words: nombre de mots dans le tableau
 * @n: adresse où stocker le nombre d'indices trouvés
 *
 * Return: Tableau alloué dynamiquement avec les indices,
 * ou NULL si aucun trouvé
 */
int	*find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int	word_len, total_len, s_len, *indices, count, i;

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);

	indices = (int *)malloc(s_len * sizeof(int));
	if (indices == NULL)
		return (NULL);
	count = 0;

	if (s_len < total_len)
	{
		*n = 0;
		free(indices);
		return (NULL);
	}

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (check_substring(s, words, word_len, nb_words, i))
			indices[count++] = i;
	}

	*n = count;
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}

	return (indices);
}
