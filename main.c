/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/18 01:48:27 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int ac, char **av)
{
	t_philo	*philo;
	t_philo	*join;
	t_fork	*fork;
	t_info	*info;
	int		ph;
	int		fk;

	philo = NULL;
	fork = NULL;
	info = NULL;
	fk = 0;
	ph = 0;
	if (arg_validation(av) == 0)
	{
		printf("argument error!\n");
		return (0);
	}
	info = info_init(av, ac);
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
	join = philo;
	while (join)
	{
		pthread_join(join->tread_id, NULL);
		join = join->next;
	}
	return (0);
}
