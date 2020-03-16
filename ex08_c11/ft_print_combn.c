#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_remlpir_str(char *str, int size, int nombre)
{
	str[size - 1] = nombre + 48;
	return (str);
}

void	ft_print_combn(int n)
{
	int		i;
	int		size;
	char	nb_max[n];
	char 	str[n];

	i = 9;
	size = n;
	/** get nb max **/
	while (n)
		nb_max[--n] = i-- + 48;
	nb_max[size] = '\0';
	printf("max char : %s\n", nb_max);
	printf("n: %d\n", n);
	/** init str **/
	i = 0;
	while (n < size)
		str[n++] = i++ + 48;
	str[size] = '\0';
	printf("str init : %s\n", str);

	/**
	while (str[0] <= (10 - n))
	{
		ft_putstr(ft_remlpir_str(str, size, i++));
		if (i < 9)
			ft_putstr(", ");
	}
	**/
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_print_combn(av[1][0] - 48);
	ft_putchar('\n');
	return (0);
}
