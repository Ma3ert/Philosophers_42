/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:06:52 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/28 12:16:09 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_info	*info_init(char **av, int ac)
{
	int		i;
	t_info	*info;

	i = 1;
	if (ac != 6 && ac != 5)
		return (NULL);
	info = malloc(sizeof(t_info));
	info->pro_start = get_time();
	sem_unlink("print");
	info->print = sem_open("print", O_CREAT, 0644, 1);
	info->meal = 0;
	info->dead = 0;
	info->turn = 1;
	info->next_to_eat = 1;
	info->number_of_philo = ft_atoi(av[i++]);
	info->pids = malloc(sizeof(int) * info->number_of_philo);
	info->n_to_eat = info->number_of_philo / 2;
	info->time_to_die = ft_atoi(av[i++]);
	info->time_to_eat = ft_atoi(av[i++]);
	info->time_to_sleep = ft_atoi(av[i++]);
	if (ac == 5)
		info->meal_num = -1;
	else
		info->meal_num = ft_atoi(av[i]);
	return (info);
}

void	create_simulation(t_philo *philo, t_fork *fork, t_info *info)
{
	int		ph;
	int		fk;

	ph = 1;
	fk = 0;
	fork_init(&fork, info->number_of_philo);
	info->fork = fork;
	while (ph <= info->number_of_philo)
	{
		add_philo(&philo, info, ph);
		ph++;
	}
}

void	kill_proccess(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		kill(info->pids[i], SIGKILL);
		i++;
	}
}

void	ft_exit(t_philo *philo, t_info *info, int status, int n)
{
	if (n == 0)
		return ;
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_SUCCESS)
		{
			if (info->meal_num == 0)
				return ;
			waitpid(-1, &status, 0);
			return (ft_exit(philo, info, status, n - 1));
		}
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			sem_unlink("print");
			kill_proccess(info);
		}
	}
}

int	main(int ac, char **av)
{
	int		n;
	int		status;
	t_fork	*fork;
	t_philo	*philo;
	t_info	*info;

	philo = NULL;
	fork = NULL;
	if (arg_validation(av, ac) == 0)
	{
		printf("argument error!\n");
		return (0);
	}
	info = info_init(av, ac);
	if (!info)
		return (0);
	create_simulation(philo, fork, info);
	waitpid(-1, &status, 0);
	ft_exit(philo, info, status, info->number_of_philo);
	n = 1;
	sem_unlink("forks");
}
