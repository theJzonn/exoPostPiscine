#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	affiche(char *res, int size)
{
	while (res[size - 1] <= '9')
	{
		ft_putstr(res);
		res[size - 1]++;
		if (res[0] < (10 - size) + 48
			|| (size == 1 && res[size - 1] == '9'))
			ft_putstr(", ");
	}
}

void	ft_up_str(char *start, char *end, int size)
{
	int		i;
	int		index;
	char 	res[size];

	i = 0;
	index = size - 2;
	while (start[i])
	{
		res[i] = start[i];
		i++;
	}
	res[i] = '\0';
	affiche(res, size);
	while (res[0] != (10 - size) + 48)
	{
		if (res[index] == end[index])
			index--;
		while (res[index] < end[index])
		{
			affiche(res, size);
			res[index]++;
			i = index + 1;
			while (res[i])
			{
				res[i] = res[i - 1] + 1;
				i++;
			}
			ft_putstr("\n");
		}
	}
	ft_putstr(end);
}

void	ft_print_combn(int n)
{
	int		i;
	int		size;
	char	nb_max[n];
	char 	nb_debut[n];

	i = 9;
	size = n;
	/** get nb max **/
	while (n)
		nb_max[--n] = i-- + 48;
	nb_max[size] = '\0';
	/** init nb **/
	i = 0;
	while (n < size)
		nb_debut[n++] = i++ + 48;
	nb_debut[size] = '\0';
	if (size > 0 && size < 10)
		affiche(nb_debut, size);
	if (size > 1 && size < 10)
		ft_up_str(nb_debut, nb_max, size);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_print_combn(av[1][0] - 48);
	ft_putstr("\n");
	return (0);
}
