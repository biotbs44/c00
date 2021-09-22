/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangjeonghun <yangjeonghun@student.42      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:23:49 by yangjeong         #+#    #+#             */
/*   Updated: 2021/09/22 11:28:56 by yangjeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_comb2(int num1, int num2);

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 0;
	while (1)
	{
		if ((num1 == 98) && (num2 == 99))
		{
			break ;
		}
		else if (num2 == 99)
		{
			num2 = 0;
			num1++;
		}
		else
			num2++;
		if (num1 < num2)
			ft_sort_comb2(num1, num2);
	}
}

void	ft_sort_comb2(int num1, int num2)
{
	char	num1_1;
	char	num1_2;
	char	num2_1;
	char	num2_2;

	num1_2 = (num1 % 10) + 48;
	num1_1 = ((num1 / 10) % 10) + 48;
	num2_2 = (num2 % 10) + 48;
	num2_1 = ((num2 / 10) % 10) + 48;
	write(1, &num1_1, 1);
	write(1, &num1_2, 1);
	write(1, " ", 1);
	write(1, &num2_1, 1);
	write(1, &num2_2, 1);
	if ((num1 == 98) && (num2 == 99))
		write(1, "\n", 1);
	else
		write(1, ", ", 2);
}
