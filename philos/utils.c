/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/04/23 17:39:19 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utils.c

#include "philo.h"

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

long	ft_atol(char *argv)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (argv[i] == ' ' || (argv[i] >= 9 && argv[i] <= 13))
		i++;
	if (argv[i] == '+')
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		res = res * 10 + (argv[i] - '0');
		i++;
	}
	return (res);
}
