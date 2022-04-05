/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:55:18 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/05 14:55:12 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	first_fork(t_fork *fork)
{
	fork = malloc(sizeof(t_fork));
	if (!fork)
		return ;
	pthread_mutex_init(fork->mutex, NULL);
	fork->used = 0;
	fork->next = NULL;
}

void	fork_init(t_fork *fork)
{
	t_fork	*next_fork;
	t_fork	*tmp;

	next_fork = NULL;
	if (!fork)
		first_fork(fork);
	tmp = fork;
	first_fork(next_fork);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = next_fork;
}

int	fork_counting(t_fork *fork)
{
	int		i;
	t_fork *tmp;

	i = 1;
	tmp = fork;
	while (tmp)
	{
		tmp->n = i;
		i++;
		tmp = tmp->next;
	}
}

t_fork	*get_fork(t_fork *fork, int n)
{
	t_fork	*tmp;

	tmp = fork;
	while (tmp)
	{
		if (tmp->n == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}