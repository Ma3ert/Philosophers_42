/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:10:08 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/23 01:12:17 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57))
			i++;
		else
			return (0);
	}
	return (1);
}

int	arg_validation(char **av, int ac)
{
	int	i;

	i = 1;
	if (ac > 6)
		return (0);
	if (ac < 5)
		return (0);
	while (av[i])
	{
		if (is_num(av[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}