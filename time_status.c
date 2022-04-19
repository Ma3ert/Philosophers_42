/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:03:18 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/18 23:40:32 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_status(t_info *info, char *status, int n)
{
	long			time;
	struct timeval	current_time;
	struct timeval	philo_time;

	gettimeofday(&current_time, NULL);
	philo_time = info->pro_start;
	time = ((current_time.tv_usec / 1000) + (current_time.tv_sec * 1000)) -\
		((philo_time.tv_usec / 1000) + (philo_time.tv_sec * 1000));
	printf("%ld %d %s\n", time, n, status);
}

int	check_time(t_philo *philo)
{
	t_info			*info;
	long			time;
	struct timeval	current_time;

	info = philo->info;
	gettimeofday(&current_time, NULL);
	time = ((current_time.tv_sec - philo->start.tv_sec) * 1000) \
	+ ((current_time.tv_usec - philo->start.tv_usec) / 1000);
	if (time > info->time_to_die)
	{
		philo->die = 1;
		print_status(philo->info, "died", philo->n);
		info->number_of_philo -= 1;
		return (0);
	}
	return (1);
}
