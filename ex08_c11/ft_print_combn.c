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

void	affiche(char *res, char *end, int index, int size)
{
	int i;

	while (res[index] < end[index])
	{
		while (res[size - 1] <= '9')
		{
			ft_putstr(res);
			res[size - 1]++;
			if (res[0] < (10 - size) + 48
				|| (size == 1 && res[size - 1] == '9'))
				ft_putstr(", ");
		}
		res[index]++;
		i = index + 1;
		while (res[i])
		{
			res[i] = res[i - 1] + 1;
			i++;
		}
		ft_putstr("\n");
	}
	if (res[0] != end[0])
	{
		ft_putstr(res);
		ft_putstr(", ");
	}
	ft_putstr("\n");
}

void	ft_up_str(char *res, char *end, int size)
{
	int		i;
	int		index;

	i = 0;
	index = size - 1;
	while (index > 0)
	{
		if (index == size - 1 || res[index] == end[index])
			index--;
		affiche(res, end, index, size);
		index--;
		res[index]++;
		i = index + 1;
		while (res[i])
		{
			res[i] = res[i - 1] + 1;
			i++;
		}
		if (res[index + 1] != end[index + 1])
			index++;
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
	/**if (size > 0 && size < 10) affiche(nb_debut, size);**/
	if (size > 1 && size < 10)
		ft_up_str(nb_debut, nb_max, size);
}
