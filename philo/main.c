/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/17 12:37:56 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_time()
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((long long)(now.tv_usec / 1000) + (now.tv_sec * 1000));
}

void	ft_usleep(long long time)
{
	long long start;

	start = get_time();
	while (get_time() - start <= time)
	{
		usleep(50);
	}
}

t_philo	*create_simulation(t_philo *philo, t_fork *fork, t_info *info)
{
	int		fk;
	int		ph;

	fk = 0;
	ph = 0;
	while (fk < info->number_of_philo)
	{
		add_fork(&fork);
		fk++;
	}
	fork_counting(fork);
	info->fork = fork;
	while (ph < info->number_of_philo)
	{
		add_philo(&philo, info, ph);
		ph++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_philo	*join;
	t_fork	*fork;
	t_info	*info;

	philo = NULL;
	fork = NULL;
	info = NULL;
	if (arg_validation(av, ac) == 0)
	{
		printf("argument error!\n");
		return (0);
	}
	info = info_init(av, ac);
	join = create_simulation(philo, fork, info);
	while (join)
	{
		pthread_join(join->tread_id, NULL);
		join = join->next;
	}
	return (0);
}
