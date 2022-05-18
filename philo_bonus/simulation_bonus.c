/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:46:45 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/18 13:12:03 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	try_to_eat_even(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
}

void	try_to_eat_odd(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
}


void	try_to_eat(t_philo *philo, t_fork *fork1, t_fork *fork2)
{
	sem_wait(fork1->id);
	print_status(philo->info, "has taken a fork", philo->n);
	sem_wait(fork1->id);
	print_status(philo->info, "has taken a fork", philo->n);
	print_status(philo->info, "eating", philo->n);
	philo->start = get_time();
	ft_usleep(philo->info->time_to_eat);
	philo->eat = 0;
	philo->meal += 1;
	sem_post(fork2->id);
	sem_post(fork1->id);
	print_status(philo->info, "sleeping", philo->n);
}

void	set_turn(t_philo *philo, t_info *info, int turn)
{
	if (turn == philo->n)
		philo->eat = 1;
	info->n_to_eat -= 1;
	if (info->n_to_eat == 0)
		return ;
	if (turn + 2 <= info->number_of_philo)
		return (set_turn(philo, info, turn + 2));
	else
		return (set_turn(philo, info, 1));
}

void	ft_thinking(t_philo *philo, t_info *info)
{
	long long start_thinking;

	start_thinking = get_time();
	while (get_time() - start_thinking <= info->time_to_eat)
	{
		check_time(philo);
		usleep(100);
	}
}

void	wait_for_turn(t_philo *philo, t_info *info)
{
	set_turn(philo, info, info->turn);
	info->n_to_eat = info->number_of_philo / 2;
	if (info->turn + 1 > info->number_of_philo)
		info->turn = 1;
	else
		info->turn += 1;
	if (philo->eat == 0)
		ft_thinking(philo, info);
}

void	*ft_simulation_bonus(t_philo *philo)
{
	int		n;
	t_info	*info;
	t_fork	*fork1;
	t_fork	*fork2;

	info = philo->info;
	if (philo->n + 1 > info->number_of_philo)
		n = 1;
	else
		n = philo->n + 1;
	fork1 = get_fork(info->fork, philo->n);
	fork2 = get_fork(info->fork, n);
	while (1)
	{
		wait_for_turn(philo, info);
		try_to_eat(philo, fork1, fork2);
		if (info->meal >= info->meal_num)
			exit(EXIT_SUCCESS);
		check_time(philo);
	}
	return (NULL);
}