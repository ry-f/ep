int		ft_atoi(const char	*str)
{
	int i;
	int neg;
	int count;

	count = 0;
	neg = 0;
	i = 0;

	while (str[i] != '\0' && str[i] == ' ')
	{
		i++;
	}
	if (str[i] != '\0'){
		if (str[i] == '-')
			neg = 1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			count *= 10;
			count += (int)str[i] - '0';
			i++;
		}
		if (neg == 1)
			count *= -1;
	}
	return (count);
}
