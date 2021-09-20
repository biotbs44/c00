#include <unistd.h>
void	ft_sort_num(int	num);
void	ft_print_num(char	a, char	b, char c);

void	ft_print_comb(void)
{
	int		num;
	char	a;
	char	b;
	char	c;

	a = 0;
	b = 0;
	c = 0;
	num = 12;
	while (num <= 789)
	{
		if (num == 789)
		{
			write(1, "7", 1);
			write(1, "8", 1);
			write(1, "9", 1);
			break ;
		}
		ft_sort_num(num);
		num++;
	}
}

void	ft_sort_num(int	num)
{
	char	a;
	char	b;
	char	c;

	c = (num % 10) + 48;
	b = ((num / 10) % 10) + 48;
	a = (((num / 10) / 10) % 10) + 48;
	if ((a != b) && (b != c) && (a != c))
	{
		if ((a < b) && (b < c))
		{
			ft_print_num(a, b, c);
		}
	}
}	

void	ft_print_num(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, ", ", 2);
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
