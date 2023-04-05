#include "push_swap.h"

t_node	*init_list(int *array, int size)
{ // Fonction pour initialiser une liste simplement chaînée à partir d'un tableau d'entiers

	t_node	*head; // Pointeur vers le premier nœud de la liste
	t_node	*current; // Pointeur vers le nœud courant
	t_node	*previous; // Pointeur vers le nœud précédent
	int		i; // Variable d'itération

	head = NULL;
	current = NULL;
	previous = NULL;
	i = 0;
	while (i < size) // Boucle pour parcourir le tableau d'entiers
	{
		current = (t_node *)malloc(sizeof(t_node)); // Allouer de la mémoire pour un nouveau nœud
		current->content = array[i]; // Assigner la valeur du tableau à l'attribut "content" du nœud
		current->next = NULL; // Initialiser l'attribut "next" du nœud à NULL
		if (previous) // Si le nœud précédent existe, le lier au nœud courant
			previous->next = current;
		else // Sinon, définir le nœud courant comme tête de liste
			head = current;
		previous = current; // Mettre à jour le nœud précédent
		i++; // Incrémenter l'indice
	}
	current->next = NULL; // S'assurer que le dernier nœud pointe vers NULL
	return (head); // Retourner la tête de liste
}

int	run_programme(int argc, char **argv)
{ // Fonction principale pour exécuter le programme

	t_node	run; // Variable de type t_node pour stocker les informations
	t_node	*head; // Pointeur vers la tête de la liste
	t_node	*current; // Pointeur vers le nœud courant
	t_node	*tmp; // Pointeur temporaire pour libérer la mémoire

	run.size = argc - 1; // Calcul de la taille du tableau d'entiers
	run.array = (int *)malloc(run.size * sizeof(int)); // Allouer de la mémoire pour le tableau
	run.i = 0;
	while (run.i < run.size) // Boucle pour remplir le tableau avec les arguments convertis en entiers
	{
		run.array[run.i] = ft_atoi(argv[run.i + 1]);
		run.i++;
	}
	head = init_list(run.array, run.size); // Initialiser la liste simplement chaînée
	free(run.array); // Libérer la mémoire allouée pour le tableau

	// Libérer la mémoire allouée pour la liste simplement chaînée
	current = head;
	tmp = NULL;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	return (0);
}
