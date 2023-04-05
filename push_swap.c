#include "push_swap.h"

void	print_err(char *message)
{
	write(2, "Error\n", 7);
	write(2, message, strlen(message));
	exit(1);
}

void	bubble_sort(int *arr, int size)
{ // Fonction pour trier un tableau d'entiers en utilisant l'algorithme de tri à bulles
	int	temp; // Variable temporaire pour stocker la valeur à échanger
	int	swapped; // Variable pour vérifier si des échanges ont eu lieu
	int	i; // Variable d'itération pour les passes
	int	j; // Variable d'itération pour les comparaisons

	i = 0;
	while (i < size - 1) // Boucle pour effectuer les passes
	{
		swapped = 0; // Initialiser la variable swapped à 0 (aucun échange)
		j = 0;
		while (j < size - i - 1) // Boucle pour effectuer les comparaisons
		{
			if (arr[j] > arr[j + 1]) // Si la valeur actuelle est supérieure à la suivante
			{
				temp = arr[j]; // Stocker la valeur actuelle dans temp
				arr[j] = arr[j + 1]; // Échanger les valeurs
				arr[j + 1] = temp; // Remettre la valeur stockée dans temp à sa nouvelle position
				swapped = 1; // Indiquer qu'un échange a eu lieu
			}
			j++; // Incrémenter l'indice de comparaison
		}
		i++; // Incrémenter l'indice de passe
		if (swapped == 0) // Si aucun échange n'a eu lieu lors de la dernière passe
			break ; // Sortir de la boucle, car le tableau est déjà trié
	}
}

void	ft_func_to_sort(t_node *pile_a)
{
	t_node		*pile_b;
	
	pile_b = NULL;
	if (ft_lstsize(pile_a) == 3)
	{
		sort_three_num(&pile_a);
		exit(1);
	}
	else if (ft_lstsize(pile_a) == 4)
	{
		sort_four_num(&pile_a, &pile_b);
		exit(1);
	}
	else if (ft_lstsize(pile_a) == 5)
	{
		sort_five_elm(&pile_a, &pile_b);
		exit(0);
	}
}

int	main(int argc, char **argv)
{ // Déclaration de la fonction principale "main" avec les arguments "argc" et "argv"

	t_node		*pile_a; // Déclaration d'un pointeur vers un nœud nommé "pile_a"
	t_node		*pile_b; // Déclaration d'un pointeur vers un nœud nommé "pile_b"
	t_node		main; // Déclaration d'une variable de type "t_node" nommée "main"

	main.o = 0; // Initialisation de l'attribut "o" de la structure "main" à 0
	main.z = 1; // Initialisation de l'attribut "z" de la structure "main" à 1
	if (argc < 2) // Si le nombre d'arguments est inférieur à 2, quitter le programme
		exit(1);
	ft_range_value_int(argv, argc); // Vérification de l'intervalle des valeurs des arguments
	run_programme(argc, argv); // Exécution du programme avec les arguments donnés
	pile_a = NULL; // Initialisation de "pile_a" à NULL
	pile_b = NULL; // Initialisation de "pile_b" à NULL
	main.p = argc - 1; // Assignation de la valeur "argc - 1" à l'attribut "p" de la structure "main"

	// Remplissage de la pile "pile_a" avec les arguments convertis en entiers
	while (main.p > 0)
		ft_my_push(&pile_a, ft_atoi(argv[main.p--]));

	// Allocation de mémoire pour un tableau d'entiers
	main.arr = (int *)malloc(sizeof(int) * (argc - 1));

	// Remplissage du tableau "main.arr" avec les arguments convertis en entiers
	while (main.z < argc)
	{
		main.arr[main.o] = ft_atoi(argv[main.z]);
		main.o++;
		main.z++;
	}

	bubble_sort(main.arr, argc - 1); // Tri du tableau "main.arr" avec l'algorithme de tri à bulles

	// Conversion du tableau trié en une liste doublement chaînée
	array_to_index_dlist(&pile_a, main.arr, argc - 1);

	// Si le nombre d'arguments est inférieur ou égal à 6, utiliser la fonction "ft_func_to_sort"
	if(argc <= 6)
		ft_func_to_sort(pile_a);
	else // Sinon, utiliser l'algorithme de tri "radix"
		radix(&pile_a, &pile_b);

	return (0); // Retourner 0 pour indiquer la fin du programme sans erreurs
}
