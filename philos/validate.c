/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:23 by jemorais          #+#    #+#             */
/*   Updated: 2025/04/23 17:39:27 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// validate.c

#include "philo.h"

bool	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
			return (false);
		if (argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		if (ft_atol(argv[i]) == 0 || ft_atol(argv[i]) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}
