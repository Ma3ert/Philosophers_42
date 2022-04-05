/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:20 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/05 16:08:11 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PHILLOSOPHER_H
#ifdef PHILLOSOPHER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

# define MIN_INT "-2147483648"
# define MAX_INT "2147483647"

typedef struct d_philo
{
	pthread_t		tread_id;
	int				n;
	int				eat;
	int				time_to_die;
	int				sleep;
	int				left_fork;
	int				right_fork;
	struct d_philo	*next;
}				t_philo;

typedef struct d_info
{
	t_fork	*fork;
	int		number_of_philo;
	int 	time_to_eat;
	int 	time_to_sleep;
	int		time_to_die;
	int		meal_num;
}				t_info;

typedef struct d_fork
{
	int				n;
	int				used;
	pthread_mutex_t *mutex;
	struct d_fork	*next;
}				t_fork;

int		ft_atoi(const char *str);
int		is_num(char *str);
int		check_value(char *str, char *str2);
int		check_range(char *str);
int		arg_validation(char **av);

void	first_philo(t_philo *philo, t_info *info);
void	philo_init(t_philo *philo, t_info *info);
int		philo_counting(t_philo *philo);

void	first_fork(t_fork *fork);
void	fork_init(t_fork *fork);
int		fork_counting(t_fork *fork);

int		ft_simulation(t_philo *philo);

#endif