#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}


static const char	*ft_isspace(const char *str)
{
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else
			break ;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	str = ft_isspace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}


int	ft_exit(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i == 1)
		exit(0);
	else if (i == 2)
	{
		if (ft_isdigit(argv[1][0]))
			exit(ft_atoi(argv[1]));
		else
		{
			printf("exit\nminishell: exit: %s: numeric argument required\n", argv[1]);
			exit(255);
		}
	}
	else
	{
		printf("exit\nminishell: exit: too many arguments\n");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_exit(argv);
	return (0);
}