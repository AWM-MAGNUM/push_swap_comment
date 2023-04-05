#include "push_swap.h"

void	radix(t_node **pile_a, t_node **pile_b)
{ // Fonction pour trier une pile en utilisant l'algorithme de tri radix
	t_node	sort; // Structure pour stocker les variables utilisées dans l'algorithme

	sort.i = 0; // Initialiser l'itérateur i à 0
	sort.len = ft_lstsize(*pile_a); // Obtenir la taille de la pile_a
	sort.max_index = max_index_position(pile_a); // Trouver la position de l'index maximal dans la pile_a
	sort.max_bits = max_bit_position(sort.len); // Trouver la position du bit le plus significatif
	*pile_b = NULL; // Initialiser pile_b à NULL

	while (sort.i <= sort.max_bits) // Boucle pour parcourir les bits
	{
		sort.k = 0; // Initialiser l'itérateur k à 0
		while (sort.k < sort.len) // Boucle pour chaque élément de la pile
		{
			sort.current_bit = ((*pile_a)->index >> sort.i); // Calculer le bit courant
			if (!(sort.current_bit & 1)) // Si le bit courant est 0
				ft_push(pile_a, pile_b, 0); // Déplacer l'élément de pile_a vers pile_b
			else
				ft_rotate(pile_a, 1); // Sinon, effectuer une rotation sur pile_a
			sort.k++; // Incrémenter l'itérateur k
		}
		sort.i++; // Incrémenter l'itérateur i
		while (*pile_b) // Tant que pile_b n'est pas vide
			ft_push(pile_b, pile_a, 1); // Déplacer les éléments de pile_b vers pile_a
	}
}

void	ft_push(t_node **pile_a, t_node **pile_b, int op)
{ // Fonction pour déplacer un élément d'une pile vers une autre
	t_node	*tmp; // Pointeur temporaire vers un nœud
	t_node	*new_elem; // Pointeur vers le nouvel élément

	if (*pile_a == NULL) // Si la pile_a est vide, retourner
		return ;
	tmp = *pile_a; // Stocker le nœud en tête de pile_a dans tmp
	new_elem = (t_node *)malloc(sizeof(t_node)); // Allouer de la mémoire pour le nouvel élément
	if (!new_elem) // Si l'allocation échoue, retourner
		return ;
	new_elem->value = (*pile_a)->value; // Copier la valeur du nœud en tête de pile_a
	new_elem->index = (*pile_a)->index; // Copier l'index du nœud en tête de pile_a
	new_elem->next = NULL; // Faire pointer le nouvel élément vers NULL

	if (*pile_b == NULL) // Si pile_b est vide
		*pile_b = new_elem; // Faire pointer pile_b vers le nouvel élément
	else // Sinon
	{
		new_elem->next = *pile_b; // Faire pointer le nouvel élément vers l'ancienne tête de pile_b
		*pile_b = new_elem; // Mettre à jour la tête de pile_b
	}
	*pile_a = (*pile_a)->next; // Mettre à jour la tête de pile_a
	free(tmp);
	if (op == 1)
		write(1, "pa\n", 3);
	else if (op == 0)
		write(1, "pb\n", 3);
}

