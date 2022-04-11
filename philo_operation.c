/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:18:59 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/11 15:02:09 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	first_philo(t_philo *philo, t_info *info, int n)
{
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	gettimeofday(&(philo->start), NULL);
	philo->n = n + 1;
	philo->eat = 0;
	philo->die = 0;
	philo->think = 0;
	philo->sleep = 0;
	philo->next = NULL;
	info->philo = philo;
	pthread_create(philo->tread_id, NULL, ft_simulation, info);
}

void	philo_init(t_philo *philo, t_info *info, int n)
{
	t_philo	*next_philo;
	t_philo	*tmp;

	next_philo = NULL;
	if (!philo)
		first_philo(philo, info, n);
	tmp = philo;
	first_philo(next_philo, info, n);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = next_philo;
}

int	philo_counting(t_philo *philo)
{
	int	i;
	t_philo *tmp;

	tmp = philo;
	i = 1;
	while (tmp)
	{
		tmp->n = i;
		i++;
		tmp = tmp->next;
	}
	return (i - 1);
}

t_philo	*get_philo(t_philo *philo, int n)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		if (tmp->n == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	print_status(char *status, int n)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	printf("%ld %d %s\n", current_time.tv_usec, n, status);
}

int	check_time(t_info *info)
{
	t_philo	*philo;
	struct timeval current_time;

	philo = info->philo;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec - philo->start.tv_usec > info->time_to_die)
	{
		philo->die = 1;
		print_status("died", info->philo->n);
		info->number_of_philo -= 1;
		return (0);
	}
	return (1);
}

int	info_init(t_info *info, char **av)
{
	int i;
	int	l;

	i = 1;
	l = ft_d_strlen(av);
	if (l != 5 || l != 6)
		return (0);
	if (arg_validation(av) == 0)
		return (0);
	info->turn = 1;
	info->meal = 0;
	info->next_to_eat = 1;
	info->number_of_philo = ft_atoi(av[i++]);
	info->n_to_eat = info->number_of_philo / 2;
	info->time_to_die = ft_atoi(av[i++]);
	info->time_to_eat = ft_atoi(av[i++]);
	info->time_to_sleep = ft_atoi(av[i++]);
	if (l == 5)
		info->meal_num = -1;
	else
		info->meal_num = ft_atoi(av[i]);
}
