/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_status_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:56:20 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/21 13:05:12 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

void	print_status(t_info *info, char *status, int n)
{
	long		time;
	long long	current_time;
	long long	philo_time;

	current_time = get_time();
	philo_time = info->pro_start;
	time = current_time - philo_time;
	sem_wait(info->print);
	printf("%ld %d %s\n", time, n, status);
	sem_post(info->print);
}

int	check_time(t_philo *philo)
{
	t_info			*info;
	long			time;
	long long		current_time;

	info = philo->info;
	current_time = get_time();
	time = current_time - philo->start;
	if (time > info->time_to_die)
	{
		philo->die = 1;
		print_status(philo->info, "died", philo->n);
		sem_wait(info->print);
		exit(EXIT_FAILURE);
	}
	return (1);
}
