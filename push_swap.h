#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
    int		        *array;
	int				size;
	// int				i;
	int				content;
	int				index;
	int				value;
	struct s_node	*next;
	int				len;
	int				current_bit;
	int				max_index;
	int				max_bits;
	int				i;
	int				k;
	int				a;
	int				b;
	int				c;
	long long int	result;
	int				sign;
	int				digit;
	int				i_at;
	int				p;
	int				o;
	int				z;
    int             *arr;
    
    
}					t_node;

/*array*/
t_node				*init_list(int *array, int size);
int					run_programme(int argc, char **argv);

/*pars*/
int					ft_is_int(char *str);
void				ft_range_value_int(char **argv, int argc);
void				array_to_index_dlist(t_node **pile, int *array, int size);

/*print*/
void				print_err(char *message);
void				print_list(t_node *list);
void				print_pile(t_node *pile_a);

/*sort*/
void				radix(t_node **pila_a, t_node **pile_b);
int					max_bit_position(int max_num);
int					max_index_position(t_node **pile_a);
void				ft_my_push(t_node **pile, int value);

/*move*/
void				ft_push(t_node **pile_a, t_node **pile_b, int is_a);
void				ft_swap(t_node **pile, int is_a);
void				ft_rotate(t_node **pile, int is_a);
void				ft_r_rotate(t_node **pile, int is_a);

/*libft*/
int					ft_atoi(char *str);
long long int		ft_atoll(const char *str);
int					ft_lstsize(t_node *head);

/*sort_3,4,5_sort*/
void				sort_three_num(t_node **pile);
void				sort_four_num(t_node **pile_a, t_node **pile_b);
void				sort_five_elm(t_node **pile_a, t_node **pile_b);

/*ft_printf*/
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putnbr(long long nb);
static int			ft_walk(va_list ptr, char str) __attribute__((used));
int					ft_printf(const char *str, ...);

#endif
