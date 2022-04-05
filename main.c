/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/05 16:10:12 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int ac, char **av)
{
	t_philo	*philo;
	t_philo	*join;
	t_fork	*fork;
	t_info	info;
	int		ph;
	int		fk;

	philo = NULL;
	fork = NULL;
	if (info_init(&info, av) == 0)
	{
		printf("argument error!\n");
		return (0);
	}
	ph = info.number_of_philo;
	fk = ph;
	while (fk != 0)
	{
		fork_init(fork);
		fk--;
	}
	fork_counting(fork);
	info.fork = fork;
	while (ph != 0)
	{
		philo_init(philo, &info);
	}
	philo_counting(philo);
	join = philo;
	while (join)
	{
		pthread_join(join->tread_id, NULL);
		join = join->next;
	}
	return (0);
}