/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:18:59 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/04 17:45:16 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	first_philo(t_philo *philo)
{
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	pthread_create(philo->tread_id, NULL, ft_eat(), NULL);
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->eat = 0;
	philo->think = 0;
	philo->sleep = 0;
	philo->next = NULL;
}

void	philo_init(t_philo *philo)
{
	t_philo	*next_philo;
	t_philo	*tmp;

	next_philo = NULL;
	if (!philo)
		first_philo(philo);
	tmp = philo;
	first_philo(next_philo);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = next_philo;
}

int	philo_counting(t_philo *philo)
{
	int	i;
	t_philo *tmp;

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
