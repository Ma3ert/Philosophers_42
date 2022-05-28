/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:17:12 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/28 11:12:45 by yait-iaz         ###   ########.fr       */
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

// int	fork_counting(t_fork *fork)
// {
// 	int		i;
// 	t_fork	*tmp;

// 	i = 1;
// 	tmp = fork;
// 	while (tmp)
// 	{
// 		tmp->n = i;
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (i - 1);
// }

// t_fork	*get_fork(t_fork *fork, int n)
// {
// 	t_fork	*tmp;

// 	tmp = fork;
// 	while (tmp)
// 	{
// 		if (tmp->n == n)
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }
