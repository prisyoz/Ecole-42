/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:00:41 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 18:24:07 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		count;
	int		sign;
	long	nbr;

	count = 0;
	sign = 1;
	nbr = 0;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 13))
	{
		count++;
	}
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		nbr = (nbr * 10) + (str[count] - '0');
		count++;
	}
	return (nbr * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	count;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	count = 0;
	while (t1[count] || t2[count])
	{
		if (t1[count] != t2[count])
			return (t1[count] - t2[count]);
		count++;
	}
	return (0);
}
