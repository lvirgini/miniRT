#include <stdio.h>
 #include <stdlib.h>



static int		ft_is_ok(long int result, int sign)
{
	result *= sign;
	if (result > 2147483647)
		return (-1);
	if (result < -2147483648)
		return (0);
	return ((int)result);
}

int				ft_atoi(const char *s)
{
	int			i;
	int			max;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '\0')
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		++i;
	}
	max = 0;
	while (s[i] >= '0' && s[i] <= '9' && max++ < 13)
	{
		result = result * 10 + (s[i] - '0');
		++i;
	}
	return (ft_is_ok(result, sign));
}

double		ft_atof(const char *nptr)
{
	int		integer_part;
	double	result;

	integer_part = ft_atoi(nptr);
	while (nptr && *nptr != '.')
		nptr++;
	if (nptr && *nptr == '.')
	{
		nptr++;
		result = (double)ft_atoi(nptr);
	}
	else
		result = 0;
	while (result >= 1)
		result /= 10;
	result += integer_part;
	return (result);
}

int main()
{
	float f = ((unsigned)~0);
	double d = (unsigned)~0;

	printf("float = %lu\n double = %lu\n", sizeof(float), sizeof(double));
	printf("float max = %lf\n double max = %lf\n", f, d);

	char *s = "1234567.1234549";
	printf("%f\n", ft_atof(s));
	printf("%f\n", atof(s));
	return (0);
}