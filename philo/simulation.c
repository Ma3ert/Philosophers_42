/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:26 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/22 17:43:50 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_hostess_even(t_info *info, t_philo *philo)
{
	philo->think = 0;
	print_status(info, "is eating", philo->n);
	philo->meal += 1;
	gettimeofday(&(philo->start), NULL);
	usleep(info->time_to_eat * 1000);
	if (philo->n == 1 || philo->n == 2)
	{
		if (info->turn == 1)
			info->turn = 2;
		else
			info->turn = 1;
	}
}

void	try_to_eat_even(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	t_info *info;

	info = philo->info;
	if ((info->turn % 2 == 0 && philo->n % 2 == 0) || \
		(info->turn % 2 != 0 && philo->n % 2 != 0))
	{
		pthread_mutex_lock(&(fork1->mutex));
		print_status(info, "has taken a fork", philo->n);
		fork1->used = 1;
		pthread_mutex_lock(&(fork2->mutex));
		print_status(info, "has taken a fork", philo->n);
		fork2->used = 1;
		ft_hostess_even(info, philo);
		pthread_mutex_unlock(&(fork1->mutex));
		fork1->used = 0;
		pthread_mutex_unlock(&(fork2->mutex));
		fork2->used = 0;
		print_status(info, "is sleeping", philo->n);
		usleep(info->time_to_sleep * 1000);
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
	gettimeofday(&(philo->start), NULL);
	usleep(info->time_to_eat * 1000);
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

void	try_to_eat_odd(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	t_info	*info;

	info = philo->info;
	if (info->next_to_eat == philo->n && info->n_to_eat > 0)
	{
		pthread_mutex_lock(&(fork1->mutex));
		fork1->used = 1;
		print_status(info, "has taken a fork", philo->n);
		pthread_mutex_lock(&(fork2->mutex));
		fork2->used = 1;
		print_status(info, "has taken a fork", philo->n);
		ft_hostess_odd(info, philo);
		pthread_mutex_unlock(&(fork1->mutex));
		fork1->used = 0;
		pthread_mutex_unlock(&(fork2->mutex));
		fork2->used = 0;
		print_status(info, "is sleeping", philo->n);
		usleep(info->time_to_sleep * 1000);
	}
}

void	wait_for_turn(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	t_info *info;

	info = philo->info;
	while (fork1->used == 1 || fork2->used == 1 || info->number_of_philo == 1)
	{
		if (philo->think == 0)
			print_status(info, "is thinking", philo->n);
		philo->think = 1;
		if (check_time(philo) == 0)
		{
			philo->think = 0;
			break ;
		}
	}
}

void	*ft_simulation(void *param)
{
	int		n;
	t_info	*info;
	t_fork	*fork1;
	t_fork	*fork2;
	t_philo	*philo;

	philo = (t_philo *)param;
	info = philo->info;
	if (philo->n + 1 > info->number_of_philo)
		n = 1;
	else
		n = philo->n + 1;
	fork1 = get_fork(info->fork, philo->n);
	fork2 = get_fork(info->fork, n);
	n = info->number_of_philo;
	while (n == info->number_of_philo)
	{
		wait_for_turn(philo, fork1, fork2);
		if (info->number_of_philo % 2 == 0 && philo->die == 0)
			try_to_eat_even(philo, fork1, fork2);
		else if (philo->die == 0)
			try_to_eat_odd(philo, fork1, fork2);
		if (info->meal_num == philo->meal)
			break ;
		if (info->meal_num == info->meal)
			break ;
	}
	return (NULL);
}