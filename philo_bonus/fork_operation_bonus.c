/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:17:12 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/28 12:15:09 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	fork_init(t_fork **fork, int n)
{
	*fork = malloc(sizeof(t_fork));
	if (!(*fork))
		return ;
	sem_unlink("forks");
	(*fork)->id = sem_open("forks", O_CREAT, 0644, n);
	(*fork)->used = 0;
}
