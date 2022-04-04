/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/04 17:59:47 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int ac, char **av)
{
	t_philo	*philo;
	t_fork	*fork;
	int		ph;

	philo = NULL;
	fork = NULL;
	if (is_num(av[1]) == 1)
		ph = ft_atoi(av[1]);
	else
	{
		printf("argument error!\n");
		return (0);
	}
	while (ph != 0)
	{
		philo_init(philo);
		fork_init(fork);
		ph--;
	}
	philo_counting(philo);
	fork_counting(fork);
	
	return (0);
}