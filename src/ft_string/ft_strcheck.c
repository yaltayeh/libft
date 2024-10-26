int	ft_strcheck(const char *str, int (*f)(int))
{
	if (!str || !f)
		return (-1);
	while (*str)
	{
		if (!f(*str))
			return (0);
		str++;
	}
	return (1);
	
}