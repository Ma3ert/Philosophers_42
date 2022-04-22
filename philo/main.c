/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/22 17:20:46 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
