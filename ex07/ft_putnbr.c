/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangjeonghun <yangjeonghun@student.42      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:25:07 by yangjeong         #+#    #+#             */
/*   Updated: 2021/09/22 11:27:37 by yangjeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	str[13];	
	int		idx;
	int		i;

	i = 0;
	idx = 0;
	while (i < 13)
	{
		str[i++] = '\0';
	}
	while (nb != 0)
	{
		str[idx++] = (nb % 10) + 48;
		nb /= 10;
	}
	while (idx >= 1)
	{
		idx--;
		write(1, &str[idx], 1);
	}
}
