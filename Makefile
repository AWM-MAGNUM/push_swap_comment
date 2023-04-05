NAMES = push_swap 
 
CFILES = array.c pars.c push_swap.c func_utils.c swap_utils.c radix.c move_insruct.c tiny_pile_generator.c ft_printf.c 

CC = CC

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

all :  $(NAMES)

$(NAMES) : $(CFILES)
			$(CC) $(CFLAGS) $(CFILES) -o push_swap

clean : 
		$(RM) $(NAMES)

fclean : clean 

re : fclean all 
