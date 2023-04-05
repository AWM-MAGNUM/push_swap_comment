#include "push_swap.h"

// Fonction pour échanger les deux premiers éléments d'une pile
void	ft_swap(t_node **pile, int op)
{
	// Déclaration des variables locales
	t_node	*first;
	t_node	*second;
	int		tmp;

	// Vérifier si la pile est vide ou s'il n'y a qu'un seul élément
	if (*pile == NULL || (*pile)->next == *pile)
		return ; // Si c'est le cas, quitter la fonction

	// Récupérer les deux premiers éléments de la pile
	first = *pile;
	second = (*pile)->next;

	// Échanger les valeurs des deux premiers éléments
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;

	// Afficher l'opération effectuée
	if (op == 0)
		write(1, "sb\n", 3); // Si op == 0, afficher "sb"
	else if (op == 1)
		write(1, "sa\n", 3); // Si op == 1, afficher "sa"
	else
		return ; // Sinon, quitter la fonction
}

// Fonction pour effectuer une rotation des éléments d'une pile
void	ft_rotate(t_node **pile, int op)
{
	// Déclaration des variables locales
	t_node	*last;
	t_node	*first;

	// Vérifier si la pile est vide ou s'il n'y a qu'un seul élément
	if (*pile == NULL || (*pile)->next == NULL)
		return ; // Si c'est le cas, quitter la fonction

	// Trouver le dernier élément de la pile
	last = *pile;
	while (last->next != NULL)
		last = last->next;

	// Récupérer le premier élément de la pile
	first = *pile;

	// Effectuer la rotation
	*pile = first->next;
	first->next = NULL;
	last->next = first;

	// Afficher l'opération effectuée
	if (op == 0)
		write(1, "rb\n", 3); // Si op == 0, afficher "rb"
	else if (op == 1)
		write(1, "ra\n", 3); // Si op == 1, afficher "ra"
	else
		return ; // Sinon, quitter la fonction
}

// Fonction pour effectuer une rotation inverse des éléments d'une pile
void	ft_r_rotate(t_node **pile, int is_a)
{
	// Déclaration des variables locales
	t_node	*last;
	t_node	*prev;

	// Vérifier si la pile contient au moins deux éléments
	if (*pile && (*pile)->next)
	{
		// Trouver le dernier élément et son prédécesseur
		last = *pile;
		prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}

		// Effectuer la rotation inverse
		prev->next = NULL;
		last->next = *pile;
		*pile = last;
	}

	// Afficher l'opération effectuée
	if (!is_a)
		write(1, "rrb\n", 4); // Si is_a == 0, afficher "rrb"
	else if (is_a == 1)
		write(1, "rra\n", 4); // Si is_a == 1, afficher "rra"
	
	// La fonction se termine ici, il n'y a pas besoin de return pour les fonctions void
}


// La condition while (last->next != NULL) signifie que la boucle continue de s'exécuter tant que l'élément suivant (last->next) n'est pas NULL. En d'autres termes, la boucle s'exécutera tant qu'il reste des éléments à parcourir dans la pile.
// Une fois que last->next est égal à NULL, cela signifie que nous avons atteint le dernier élément de la pile, et la boucle while s'arrête.
// Voici une explication étape par étape :
// last est initialisé au début de la pile (last = *pile).
// La boucle while vérifie si l'élément suivant (last->next) est NULL. Si ce n'est pas le cas, cela signifie qu'il y a encore des éléments à parcourir.
// À chaque itération, la boucle met à jour last pour pointer vers l'élément suivant (last = last->next), et stocke l'élément actuel dans prev.
// Lorsque la boucle atteint l'avant-dernier élément, last->next pointe vers le dernier élément. La boucle s'exécute une dernière fois, et last est maintenant le dernier élément de la pile, car last->next est égal à NULL.
// En résumé, la condition while (last->next != NULL) permet de parcourir la pile jusqu'à ce que last pointe vers le dernier élément. Lorsque last->next est égal à NULL, la boucle s'arrête, car nous avons atteint le dernier élément.

// pourquoi in a besoin de cette boucle de merde 
// Je comprends que la boucle puisse sembler compliquée, mais elle est nécessaire pour atteindre un objectif précis dans cette fonction. L'objectif de la fonction ft_r_rotate est d'effectuer une rotation inverse de la pile, en déplaçant le dernier élément au début de la pile.
// Pour y parvenir, nous devons d'abord identifier le dernier élément de la pile ainsi que son prédécesseur. Cette "boucle de merde" nous aide à accomplir cette tâche.
// Voici pourquoi nous avons besoin de cette boucle while :
// La pile est une structure de données de type liste chaînée. Chaque élément de la pile contient un pointeur vers l'élément suivant. Il n'y a pas d'accès direct au dernier élément, contrairement à un tableau où l'on peut accéder à n'importe quel élément par son index.
// Pour trouver le dernier élément, nous devons parcourir la pile en suivant les pointeurs next jusqu'à ce que nous atteignions un élément dont le pointeur next est NULL. C'est ce que fait la boucle while.
// Dans le processus, nous avons également besoin de garder une trace de l'élément précédant le dernier élément. C'est parce qu'une fois que nous avons identifié le dernier élément, nous devons "détacher" ce dernier élément de la pile en mettant le pointeur next du prédécesseur à NULL. La variable prev sert à stocker l'élément précédant le dernier élément.
// En résumé, cette boucle while est nécessaire pour parcourir la pile et identifier le dernier élément ainsi que son prédécesseur, afin de pouvoir effectuer la rotation inverse comme prévu.