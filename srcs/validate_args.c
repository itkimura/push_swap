/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/17 17:51:33 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/

int	is_valid_str(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] == '-' || arg[i] == '+') && !(arg[i + 1] >= '0' && arg[i + 1] <= '9'))
			return (0);
		if (!(*arg >= '0' && *arg <= '9') && *arg != ' ' && *arg != '-' && *arg != '+')
			return (0);
		i++;
	}
	return (1);
}

int nb_of_arg(char *arg)
{
	int	nb;

	nb = 0;
	while (*arg)
	{
		if (*arg != ' ')
		{
			nb++;
			while ((*arg >= '0' && *arg <= '9') || *arg == '-' || *arg == '+')
				arg++;
			if (!*arg)
				break ;
		}
		arg++;
	}
	return (nb);
}

int	validate_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!is_valid_str(av[i]))
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		i++;
	}
	return (1);
}
