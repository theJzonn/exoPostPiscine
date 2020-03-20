/** clang -Wall -Werror -Wextra ft_print_combn.c && ./a.out */

#include <stdio.h>

void	ft_print_combn(int n);

int		main(int ac, char **av)
{
	(void)ac;
	ft_print_combn(av[1][0] - 48);
	printf("\n");
	return (0);
}
