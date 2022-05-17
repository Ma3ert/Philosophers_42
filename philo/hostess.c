/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hostess.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:41:21 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/17 14:59:13 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_hostess_even(t_info *info, t_philo *philo)
{
	philo->think = 0;
	print_status(info, "is eating", philo->n);
	philo->meal += 1;
	philo->start = get_time();
	ft_usleep(info->time_to_eat);
	if (philo->n == 1 || philo->n == 2)
	{
		if (info->turn == 1)
			info->turn = 2;
		else
			info->turn = 1;
	}
}

void	ft_hostess_odd(t_info *info, t_philo *philo)
{
	if (philo->n == info->number_of_philo)
		info->meal += 1;
	if (info->n_to_eat - 1 >= 0)
		info->n_to_eat -= 1;
	if (info->next_to_eat + 2 > info->number_of_philo && info->n_to_eat > 0)
		info->next_to_eat = info->next_to_eat + 2 - info->number_of_philo;
	else if (info->n_to_eat > 0)
		info->next_to_eat += 2;
	print_status(info, "is eating", philo->n);
	philo->think = 0;
	philo->start = get_time();
	ft_usleep(info->time_to_eat);
	if (philo->n == info->turn)
	{
		info->n_to_eat = info->number_of_philo / 2;
		if (info->turn + 1 > info->number_of_philo)
			info->turn = 1;
		else
			info->turn += 1;
		info->next_to_eat = info->turn;
	}
}
