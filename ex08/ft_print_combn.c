/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangjeonghun <yangjeonghun@student.42      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:28:39 by yangjeong         #+#    #+#             */
/*   Updated: 2021/09/22 12:59:46 by yangjeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_make_array_and_check_ascending(int num, int end, int n);
void	ft_write_array(char *str, int num, int end, int n);

void	ft_print_combn(int n)
{
	int	num;
	int	break_num;
	int	mul_ten;
	int	num_pos;

	break_num = 0;
	num = 0;
	mul_ten = 1;
	num_pos = n - 1;
	while (num_pos >= 1)
	{
		num += (mul_ten * num_pos--);
		mul_ten *= 10;
	}
	mul_ten = 1;
	num_pos = 9;
	while (num_pos >= (10 - n))
	{
		break_num += ((num_pos--) * (mul_ten));
		mul_ten *= 10;
	}
	while (num <= break_num)
		ft_make_array_and_check_ascending(num++, break_num, n);
}

void	ft_make_array_and_check_ascending(int num, int end, int n)
{
	char	str[10];
	int		idx;
	int		end_idx;
	int		temp;
	int		flag;

	flag = 0;
	temp = num;
	end_idx = n - 1;
	idx = n - 1;
	while (end_idx >= 0)
	{
		str[end_idx--] = (temp % 10) + 48;
		temp /= 10;
	}
	end_idx = n - 1;
	while (idx < end_idx)
	{
		if (str[idx] >= str[idx + 1])
			flag = 1;
		idx++;
	}
	if (flag == 0)
		ft_write_array(str, num, end, n);
}

void	ft_write_array(char *str, int num, int end, int n)
{
	int	idx;
	int	idx_p;
	int	temp;

	temp = num;
	idx = n - 1;
	idx_p = 0;
	if (num == end)
	{
		while (idx_p < n)
			write(1, &str[idx_p++], 1);
		write(1, "\n", 1);
	}
	else
	{
		while (idx_p < n)
			write(1, &str[idx_p++], 1);
		write(1, ", ", 2);
	}
}

int	main(void)
{
	ft_print_combn(5);
	return (0);
}
