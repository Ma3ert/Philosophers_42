/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:20 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/20 00:10:29 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PHILLOSOPHER_H
#ifdef PHILLOSOPHER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

# define MIN_INT "-2147483648"
# define MAX_INT "2147483647"


typedef struct d_fork
{
	int				n;
	int				used;
	pthread_mutex_t mutex;
	struct d_fork	*next;
}				t_fork;

typedef struct d_info
{
	t_fork	*fork;
	int		turn;
	int		dead;
	int		meal;
	int		n_to_eat;
	int		next_to_eat;
	int		number_of_philo;
	long 	time_to_eat;
	long 	time_to_sleep;
	long	time_to_die;
	int		meal_num;
	struct	timeval	pro_start;
}				t_info;

typedef struct d_philo
{
	struct	timeval	start;
	struct	d_info	*info;
	pthread_t		tread_id;
	int				n;
	int				think;
	int				eat;
	int				die;
	int				sleep;
	int				left_fork;
	int				right_fork;
	struct d_philo	*next;
}				t_philo;

int		ft_atoi(const char *str);
int		is_num(char *str);
int		check_value(char *str, char *str2);
int		check_range(char *str);
int		arg_validation(char **av);
int		ft_d_strlen(char **av);

void	add_philo(t_philo **philo, t_info *info, int n);
void	philo_init(t_philo **philo, t_info *info, int n);
int		philo_counting(t_philo *philo);
t_philo	*get_philo(t_philo *philo, int n);

void	add_fork(t_fork **head_fork);
void	fork_init(t_fork **fork);
int		fork_counting(t_fork *fork);

t_info	*info_init(char **av, int ac);

void	print_status(t_info *info, char *status, int n);
int		check_time(t_philo *philo);

void	*ft_simulation(void *param);
t_fork	*get_fork(t_fork *fork, int n);

#endif