unsigned int  ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	
	i = 0;
	if (size == 0)
		return 0;
	else
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	return (i - 1);
}