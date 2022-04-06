/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/06 16:11:21 by yait-iaz         ###   ########.fr       */
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
	fk = 0;
	ph = 0;
	if (info_init(&info, av) == 0)
	{
		printf("argument error!\n");
		return (0);
	}
	while (fk < info.number_of_philo)
	{
		fork_init(fork);
		fk++;
	}
	fork_counting(fork);
	info.fork = fork;
	while (ph < info.number_of_philo)
	{
		philo_init(philo, &info, ph);
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
