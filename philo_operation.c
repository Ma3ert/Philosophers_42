/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:18:59 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/05 16:00:55 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	first_philo(t_philo *philo, t_info *info)
{
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	pthread_create(philo->tread_id, NULL, ft_simulation, NULL);
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->eat = info->time_to_eat;
	philo->time_to_die = info->time_to_die; 
	philo->sleep = info->time_to_sleep;
	philo->next = NULL;
}

void	philo_init(t_philo *philo, t_info *info)
{
	t_philo	*next_philo;
	t_philo	*tmp;

	next_philo = NULL;
	if (!philo)
		first_philo(philo, info);
	tmp = philo;
	first_philo(next_philo, info);
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

int	info_init(t_info *info, char **av)
{
	int i;
	int	l;

	i = 1;
	l = ft_d_strlen(av);
	if (l != 5 || l != 6)
		return (0);
	if (arg_validation(av) == 0)
		return (0);
	info->number_of_philo = ft_atoi(av[i++]);
	info->time_to_die = ft_atoi(av[i++]);
	info->time_to_eat = ft_atoi(av[i++]);
	info->time_to_sleep = ft_atoi(av[i++]);
	if (l == 5)
		info->meal_num = -1;
	else
		info->meal_num = ft_atoi(av[i]);
}