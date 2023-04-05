#include "push_swap.h"

int	ft_is_int(char *str)
{ // Fonction pour vérifier si une chaîne de caractères représente un entier valide

	int	i; // Variable d'itération

	i = 0;
	if (str[i] == '\0') // Si la chaîne est vide, retourner 0 (faux)
		return (0);
	if (str[i] == '-' || str[i] == '+') // Si la chaîne commence par un signe, passer au caractère suivant
		i++;
	while (str[i] != '\0') // Boucle pour parcourir la chaîne
	{
		// Si le caractère courant n'est pas un chiffre, retourner 0 (faux)
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++; // Incrémenter l'indice
	}
	return (1); // Si tous les caractères sont des chiffres, retourner 1 (vrai)
}

void	ft_range_value_int(char **argv, int argc)
{ // Fonction pour vérifier si les arguments sont des entiers valides et uniques

	int			i; // Variable d'itération pour les arguments
	int			j; // Variable d'itération pour comparer les arguments
	long long	value; // Variable pour stocker la valeur de l'argument converti en entier long long

	i = 1;
	while (i < argc) // Boucle pour parcourir les arguments
	{
		// Si l'argument n'est pas un entier valide, quitter le programme
		if (!ft_is_int(argv[i]))
			exit(1);
		value = ft_atoll(argv[i]); // Convertir l'argument en entier long long

		// Si la valeur est hors de la plage des entiers, quitter le programme
		if (value > INT_MAX || value < INT_MIN)
			exit(1);

		j = i + 1;
		while (j < argc) // Boucle pour comparer les arguments entre eux
		{
			// Si deux arguments ont la même valeur, quitter le programme
			if (atoi(argv[i]) == atoi(argv[j]))
				exit(1);
			j++; // Incrémenter l'indice de comparaison
		}
		i++; // Incrémenter l'indice de l'argument
	}
}
