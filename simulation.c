/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:26 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:11 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	try_to_eat_even(t_info *info, t_fork *fork1, t_fork *fork2)
{
	if ((info->turn % 2 == 0 && info->philo->n % 2 == 0) || \
		(info->turn % 2 != 0 && info->philo->n % 2 != 0))
	{
		pthread_mutex_lock(fork1->mutex);
		fork1->used = 1;
		print_status("has taken a fork", info->philo->n);
		pthread_mutex_lock(fork2->mutex);
		print_status("has taken a fork", info->philo->n);
		fork2->used = 1;
		if (info->philo->n == 1 || info->philo->n == 2)
		{
			if (info->philo->n == 2 && info->meal_num != -1)
				info->meal += 1;
			if (info->turn == 1)
				info->turn = 2;
			else
				info->turn = 1;
		}
		print_status("is eating", info->philo->n);
		usleep(info->time_to_eat);
		pthread_mutex_unlock(fork1->mutex);
		fork1->used = 0;
		pthread_mutex_unlock(fork2->mutex);
		fork2->used = 0;
		print_status("is sleeping", info->philo->n);
		usleep(info->time_to_sleep);
	}
}

void	ft_hostess(t_info *info, t_philo *philo)
{
	if (info->n_to_eat - 1 >= 0)
		info->n_to_eat -= 1;
	if (info->next_to_eat + 2 > info->number_of_philo && info->n_to_eat > 0)
		info->next_to_eat = info->number_of_philo - info->next_to_eat + 2;
	else if (info->n_to_eat > 0)
		info->next_to_eat += 2;
	print_status("is eating", info->philo->n);
	usleep(info->time_to_eat);
	if (philo->n == info->turn)
	{
		info->n_to_eat = info->number_of_philo / 2;
		info->turn += 1;
		info->next_to_eat = info->turn;
	}
}

void	try_to_eat_odd(t_info *info, t_fork *fork1, t_fork *fork2)
{
	if (info->next_to_eat == info->philo->n && info->n_to_eat > 0)
	{
		pthread_mutex_lock(fork1->mutex);
		fork1->used = 1;
		print_status("has taken a fork", info->philo->n);
		pthread_mutex_lock(fork2->mutex);
		fork2->used = 1;
		print_status("has taken a fork", info->philo->n);
		ft_hostess(info, info->philo);
		pthread_mutex_unlock(fork1->mutex);
		pthread_mutex_unlock(fork2->mutex);
		fork1->used = 0;
		fork2->used = 0;
		print_status("is sleeping", info->philo->n);
		usleep(info->time_to_sleep);
	}
}

int	ft_simulation(t_info *info)
{
	int		n;
	t_fork	*fork1;
	t_fork	*fork2;

	if (info->philo + 1 > info->number_of_philo)
		n = 1;
	else
		n = info->philo->n + 1;
	fork1 = get_fork(info->fork, info->philo->n);
	fork2 = get_fork(info->fork, n);
	n = info->number_of_philo;
	while (n == info->number_of_philo)
	{
		while (fork1->used == 1 || fork2->used == 1)
		{
			if (info->philo->think == 0)
				print_status("is thinking", info->philo->n);
			info->philo->think = 1;
			if (check_time(info) == 0)
			{
				info->philo->think = 0;
				break ;
			}
		}
		if (info->philo->n % 2 == 0 && info->philo->die == 0)
			try_to_eat_even(info, fork1, fork2);
		else if (info->philo->die == 0)
			try_to_eat_odd(info, fork1, fork2);
		if (info->meal_num == info->meal)
			break ;
	}
}
