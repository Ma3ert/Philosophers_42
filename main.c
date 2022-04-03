/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/03 22:57:01 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	first_philo(t_philo *philo)
{
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	philo->n = 1;
	philo->next = NULL;
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->
}

void	philo_init(t_philo *philo)
{
	if (philo == NULL)
		first_philo(philo);
	philo = malloc(sizeof(t_philo));
	philo->
}

int main(int ac, char **av)
{
	t_philo	*philo;
	int		n;

	n = 4;
	philo = NULL;
	while (n != 0)
	{
		philo_init(philo);
		n--;
	}
}