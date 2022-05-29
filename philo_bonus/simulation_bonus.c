/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:46:45 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/28 12:15:19 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	try_to_eat(t_philo *philo, t_fork *fork)
{
	sem_wait(fork->id);
	print_status(philo->info, "has taken a fork", philo->n);
	sem_wait(fork->id);
	print_status(philo->info, "has taken a fork", philo->n);
	philo->think = 1;
	print_status(philo->info, "is eating", philo->n);
	philo->start = get_time();
	ft_usleep(philo->info->time_to_eat);
	philo->eat = 0;
	philo->meal += 1;
	sem_post(fork->id);
	sem_post(fork->id);
	philo->think = 0;
	print_status(philo->info, "is sleeping", philo->n);
	ft_usleep(philo->info->time_to_sleep);
}

void	set_turn(t_philo *philo, t_info *info, int turn)
{
	if (turn == philo->n && info->number_of_philo != 1)
	{
		philo->eat = 1;
		philo->think = 1;
		return ;
	}
	info->n_to_eat -= 1;
	if (info->n_to_eat <= 0)
		return ;
	if (turn + 2 <= info->number_of_philo)
		return (set_turn(philo, info, turn + 2));
	else
		return (set_turn(philo, info, 1));
}

void	*ft_thinking(void *param)
{
	long long	start;
	t_philo		*philo;
	t_info		*info;

	philo = (t_philo *)param;
	info = philo->info;
	start = get_time();
	while (philo->think == 0)
	{
		check_time(philo);
	}
	return (NULL);
}

void	wait_for_turn(t_philo *philo, t_info *info)
{
	pthread_t	thread;

	set_turn(philo, info, info->turn);
	info->n_to_eat = info->number_of_philo / 2;
	if (info->turn + 1 > info->number_of_philo)
		info->turn = 1;
	else
		info->turn += 1;
	if (philo->eat == 0)
	{
		if (info->number_of_philo > 1)
			print_status(info, "thinking", philo->n);
		pthread_create(&thread, NULL, ft_thinking, (void *)philo);
		pthread_detach(thread);
		usleep(100);
	}
}

void	*ft_simulation_bonus(t_philo *philo)
{
	int			n;
	t_info		*info;
	t_fork		*fork;

	info = philo->info;
	if (philo->n + 1 > info->number_of_philo)
		n = 1;
	else
		n = philo->n + 1;
	fork = philo->info->fork;
	while (1)
	{
		wait_for_turn(philo, info);
		try_to_eat(philo, fork);
		if (philo->meal >= info->meal_num && info->meal_num > 0)
			exit(EXIT_SUCCESS);
		check_time(philo);
	}
	return (NULL);
}
