/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:18:59 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/17 12:55:46 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_init(t_philo **philo, t_info *info, int n)
{
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
	pthread_create(&((*philo)->tread_id), NULL, ft_simulation, *philo);
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
	philo_counting(*philo);
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

t_philo	*get_philo(t_philo *philo, int n)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		if (tmp->n == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_info	*info_init(char **av, int ac)
{
	int		i;
	t_info	*info;

	i = 1;
	if (ac != 6 && ac != 5)
		return (NULL);
	info = malloc(sizeof(t_info));
	info->pro_start = get_time();
	info->meal = 0;
	info->dead = 0;
	info->turn = 1;
	info->next_to_eat = 1;
	info->number_of_philo = ft_atoi(av[i++]);
	info->n_to_eat = info->number_of_philo / 2;
	info->time_to_die = ft_atoi(av[i++]);
	info->time_to_eat = ft_atoi(av[i++]);
	info->time_to_sleep = ft_atoi(av[i++]);
	if (ac == 5)
		info->meal_num = -1;
	else
		info->meal_num = ft_atoi(av[i]);
	return (info);
}
