/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:17:12 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/20 15:40:36 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	fork_init(t_fork **fork)
{
	static int	n;

	*fork = malloc(sizeof(t_fork));
	if (!(*fork))
		return ;
	n += 1;
	sem_unlink(ft_itoa(n));
	(*fork)->id = sem_open(ft_itoa(n), O_CREAT, 0644, 1);
	(*fork)->used = 0;
	(*fork)->next = NULL;
}

void	add_fork(t_fork **head_fork)
{
	t_fork	*tmp;
	t_fork	*next_fork;

	next_fork = NULL;
	if (!(*head_fork))
		fork_init(head_fork);
	tmp = *head_fork;
	fork_init(&next_fork);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = next_fork;
}

int	fork_counting(t_fork *fork)
{
	int		i;
	t_fork	*tmp;

	i = 1;
	tmp = fork;
	while (tmp)
	{
		tmp->n = i;
		i++;
		tmp = tmp->next;
	}
	return (i - 1);
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