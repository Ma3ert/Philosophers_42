/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:03:18 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/23 16:40:14 by yait-iaz         ###   ########.fr       */
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

	pthread_mutex_lock(&(info->print));
	current_time = get_time();
	if (info->dead == 1)
	{
		pthread_mutex_unlock(&(info->print));
		return ;
	}
	philo_time = info->pro_start;
	time = current_time - philo_time;
	printf("%ld %d %s\n", time, n, status);
	if (ft_strcmp(status, "died") != 0)
		pthread_mutex_unlock(&(info->print));
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
		info->number_of_philo -= 1;
		print_status(philo->info, "died", philo->n);
		philo->info->dead = 1;
		pthread_mutex_unlock(&info->print);
		return (0);
	}
	return (1);
}
