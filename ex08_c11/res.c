
/** https://github.com/CmplxN/Piscine/blob/master/C00/ex08/ft_print_combn.c **/

#include <unistd.h>

void	printer(int output[9], int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		output[idx] = output[idx] + 48;
		write(1, &output[idx], 1);
		output[idx] = output[idx] - 48;
		idx++;
	}
	if (output[size - 1] == 9 && output[0] == 10 - size)
		return ;
	write(1, ", ", 2);
	return ;
}

void	dfs(int start, int cur_size, int dest_size, int output[9])
{
	int idx;

	if (cur_size == dest_size)
	{
		printer(output, dest_size);
		return ;
	}
	idx = start;
	while (idx < 10)
	{
		output[cur_size] = idx;
		dfs(idx + 1, cur_size + 1, dest_size, output);
		idx++;
	}
}

void	ft_print_combn(int n)
{
	int array[10];

	dfs(0, 0, n, array);
}