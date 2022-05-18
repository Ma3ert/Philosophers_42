/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:47:01 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/17 15:13:57 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_init(t_philo **philo, t_info *info, int n)
{
	static int	i;
	(*philo) = malloc(sizeof(t_philo));
	if (!(*philo))
		return ;
	(*philo)->start = get_time();
	(*philo)->meal = 0;
	(*philo)->n = n;
	(*philo)->eat = 0;
	(*philo)->die = 0;
	(*philo)->think = 0;
	(*philo)->sleep = 0;
	(*philo)->next = NULL;
	(*philo)->info = info;
	(*philo)->id = fork();
	if ((*philo)->id == 0)
		ft_simulation_bonus(*philo);
	else
		info->pids[i++] = (*philo)->id;
}

void	add_philo(t_philo **philo, t_info *info, int n)
{
	t_philo	*tmp;
	t_philo	*next_philo;

	next_philo = NULL;
	if (!(*philo))
		philo_init(philo, info, n);
	else
	{
		tmp = *philo;
		philo_init(&next_philo, info, n);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = next_philo;
	}
}

int	philo_counting(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	tmp = philo;
	i = 1;
	while (tmp)
	{
		tmp->n = i;
		i++;
		tmp = tmp->next;
	}
	return (i - 1);
}
