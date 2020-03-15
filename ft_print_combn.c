#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	int i;
	int size;

	if (n > 0 && n < 10)
	{
		i = 0;
		size = n;
		while(n <= 0)
		{
			while ()
			ft_affiche_comb(i, size);
			i++;
			n--;
		}
	}
}
