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
		if (res[0] != (10 - size) + 48)
			ft_putstr(", ");
	}
}

void	ft_up_str(char *start, char *end, int size)
{
	int		i;
	int		index;
	char 	res[size];

	i = 0;
	index = size - 1;
	//(void)end;
	while (start[i])
	{
		res[i] = start[i];
		i++;
	}
	res[i] = '\0';
	affiche(res, size);
	ft_putstr("\n");

	while (res[0] != (10 - size) + 48)
	{
		index--;
		while (res[index] != end[index])
		{
			res[index]++;
			i = index + 1;
			while (res[i])
			{
				res[i] = res[i - 1] + 1;
				i++;
			}
			affiche(res, size);
			ft_putstr("\n");
		}
	}
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
	printf("max char : %s\n", nb_max);
	printf("n: %d\n", n);
	/** init nb **/
	i = 0;
	while (n < size)
		nb_debut[n++] = i++ + 48;
	nb_debut[size] = '\0';
	//printf("str init : %s\n", nb_debut);
	ft_up_str(nb_debut, nb_max, size);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_print_combn(av[1][0] - 48);
	ft_putstr("\n");
	return (0);
}
