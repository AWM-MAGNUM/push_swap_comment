#include "push_swap.h"

void	sort_three_num(t_node **pile)
{ // Fonction pour trier une pile de 3 éléments
	t_node	sort_3; // Structure pour stocker les 3 valeurs

	sort_3.a = (*pile)->value; // Stocker la première valeur
	sort_3.b = (*pile)->next->value; // Stocker la deuxième valeur
	sort_3.c = (*pile)->next->next->value; // Stocker la troisième valeur

	if (sort_3.a > sort_3.b && sort_3.c < sort_3.a && sort_3.c < sort_3.b)
	{ // Si la première valeur est la plus grande et la troisième est la plus petite
		ft_swap(pile, 1); // Échanger les deux premières valeurs
		ft_r_rotate(pile, 1); // Effectuer une rotation inverse sur la pile
	}
	else if (sort_3.a < sort_3.b && sort_3.b > sort_3.c && sort_3.c > sort_3.a)
	{ // Si la deuxième valeur est la plus grande et la troisième est la deuxième plus grande
		ft_swap(pile, 1); // Échanger les deux premières valeurs
		ft_rotate(pile, 1); // Effectuer une rotation sur la pile
	}
	else if (sort_3.a > sort_3.b && sort_3.b < sort_3.c && sort_3.c > sort_3.a)
		ft_swap(pile, 1); // Si la première valeur est la plus grande et la deuxième est la plus petite, échanger les deux premières valeurs
	else if (sort_3.a < sort_3.b && sort_3.b > sort_3.c)
		ft_r_rotate(pile, 1); // Si la deuxième valeur est la plus grande et la première est la plus petite, effectuer une rotation inverse sur la pile
	else if (sort_3.c > sort_3.b && sort_3.b < sort_3.a && sort_3.a > sort_3.c)
		ft_rotate(pile, 1); // Si la troisième valeur est la plus grande et la deuxième est la plus petite, effectuer une rotation sur la pile
}

void	sort_four_num(t_node **pile_a, t_node **pile_b)
{ // Fonction pour trier une pile de 4 éléments
	int		min_val; // Variable pour stocker la valeur minimale
	t_node	*min_node; // Pointeur vers le nœud contenant la valeur minimale
	t_node	*tmp; // Pointeur temporaire vers un nœud

	min_val = (*pile_a)->value; // Stocker la première valeur de pile_a
	min_node = *pile_a; // Faire pointer min_node vers la tête de pile_a
	tmp = *pile_a; // Faire pointer tmp vers la tête de pile_a

	while (tmp) // Parcourir la pile
	{
		if (tmp->value < min_val) // Si la valeur de tmp est inférieure à la valeur minimale actuelle
		{
			min_val = tmp->value; // Mettre à jour la valeur minimale
			min_node = tmp; // Mettre à jour le pointeur vers le nœud contenant la valeur minimale
		}
		tmp = tmp->next; // Passer au nœud suivant
	}
		while (*pile_a != min_node) // Tant que la tête de pile_a n'est pas le nœud contenant la valeur minimale
	{
		ft_rotate(pile_a, 1); // Effectuer une rotation sur pile_a
	}
	ft_push(pile_a, pile_b, 0); // Déplacer le nœud contenant la valeur minimale de pile_a vers pile_b
	sort_three_num(pile_a); // Trier les trois éléments restants dans pile_a
	ft_push(pile_b, pile_a, 1); // Déplacer le nœud contenant la valeur minimale de pile_b vers pile_a

}

void	sort_five_elm(t_node **pile_a, t_node **pile_b)
{ // Fonction pour trier une pile de 5 éléments
	int		min_val; // Variable pour stocker la valeur minimale
	t_node	*min_node; // Pointeur vers le nœud contenant la valeur minimale
	t_node	*tmp; // Pointeur temporaire vers un nœud

	min_val = (*pile_a)->value; // Stocker la première valeur de pile_a
	min_node = *pile_a; // Faire pointer min_node vers la tête de pile_a
	tmp = *pile_a; // Faire pointer tmp vers la tête de pile_a

	while (tmp) // Parcourir la pile
	{
		if (tmp->value < min_val) // Si la valeur de tmp est inférieure à la valeur minimale actuelle
		{
			min_val = tmp->value; // Mettre à jour la valeur minimale
			min_node = tmp; // Mettre à jour le pointeur vers le nœud contenant la valeur minimale
		}
		tmp = tmp->next; // Passer au nœud suivant
	}
	while (*pile_a != min_node) // Tant que la tête de pile_a n'est pas le nœud contenant la valeur minimale
	{
		ft_rotate(pile_a, 1); // Effectuer une rotation sur pile_a
	}
	ft_push(pile_a, pile_b, 0); // Déplacer le nœud contenant la valeur minimale de pile_a vers pile_b
	sort_four_num(pile_a, pile_b); // Trier les quatre éléments restants dans pile_a et pile_b
	ft_push(pile_b, pile_a, 1); // Déplacer le nœud contenant la valeur minimale de pile_b vers pile_a
}


