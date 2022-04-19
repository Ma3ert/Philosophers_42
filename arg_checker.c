/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:45:50 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/12 16:48:32 by yait-iaz         ###   ########.fr       */
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

int	arg_validation(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_num(av[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}
