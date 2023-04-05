#include "push_swap.h"

void	ft_my_push(t_node **pile, int value)
{ // Fonction pour ajouter un élément en tête de pile
	t_node	*new_node; // Pointeur vers le nouveau nœud

	new_node = malloc(sizeof(t_node)); // Allouer de la mémoire pour le nouveau nœud
	if (new_node == NULL) // Si l'allocation échoue, quitter le programme
		exit(1);
	new_node->value = value; // Assigner la valeur au nouveau nœud
	new_node->next = *pile; // Faire pointer le nouveau nœud vers l'ancienne tête de pile
	*pile = new_node; // Mettre à jour la tête de pile
}

void	array_to_index_dlist(t_node **pile, int *array, int size)
{ // Fonction pour attribuer les index des éléments d'un tableau aux nœuds d'une liste
	t_node	*tmp; // Pointeur temporaire vers un nœud
	int		j; // Variable d'itération

	tmp = *pile;
	while (tmp) // Boucle pour parcourir la liste
	{
		j = 0;
		while (j < size) // Boucle pour parcourir le tableau
		{
			if (array[j] == tmp->value) // Si la valeur du tableau correspond à celle du nœud
			{
				tmp->index = j; // Assigner l'index au nœud
				break ; // Passer au nœud suivant
			}
			j++; // Incrémenter l'indice
		}
		tmp = tmp->next; // Passer au nœud suivant
	}
	return ;
}

int	max_index_position(t_node **pile_a)
{ // Fonction pour trouver la position de l'index maximal dans la pile
	t_node	*current; // Pointeur vers le nœud courant
	int		max_index; // Variable pour stocker l'index maximal

	current = *pile_a;
	max_index = current->index;
	while (current) // Boucle pour parcourir la pile
	{
		if (current->index > max_index) // Si l'index courant est supérieur à l'index maximal
			max_index = current->index; // Mettre à jour l'index maximal
		current = current->next; // Passer au nœud suivant
	}
	return (max_index);
}

int	max_bit_position(int max_bits)
{ // Fonction pour trouver la position du bit le plus significatif
	int	max; // Variable pour stocker la position du bit le plus significatif

	max = 0;
	while (max_bits > 0) // Boucle pour diviser max_bits par 2 jusqu'à ce qu'il soit égal à 0
	{
		max_bits /= 2;
		max++; // Incrémenter la position du bit le plus significatif
	}
	return (max - 1); // Retourner la position du bit le plus significatif moins 1
}
