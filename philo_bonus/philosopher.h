/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:07:28 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/22 11:16:12 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct d_fork
{
	sem_t			*id;
	int				used;
	int				n;
	struct d_fork	*next;
}				t_fork;

typedef struct d_info
{
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_of_philo;
	int				next_to_eat;
	int				n_to_eat;
	int				dead;
	int				turn;
	int				meal;
	int				meal_num;
	struct d_fork	*fork;
	sem_t			*print;
	int				*pids;
	long long		pro_start;
}				t_info;

typedef struct d_philo
{
	pid_t			id;
	int				meal;
	int				eat;
	int				die;
	int				think;
	int				sleep;
	int				n;
	long long		start;
	struct d_info	*info;
	struct d_philo	*next;
}				t_philo;

long long	get_time(void);
void		ft_usleep(long long time);

char		*ft_itoa(int n);
int			ft_atoi(const char *str);
int			is_num(char *str);
int			arg_validation(char **av, int ac);
int			ft_d_strlen(char **av);

void		philo_init(t_philo **philo, t_info *info, int n);
void		add_philo(t_philo **philo, t_info *info, int n);
int			philo_counting(t_philo *philo);

void		fork_init(t_fork **fork);
void		add_fork(t_fork **head_fork);
int			fork_counting(t_fork *fork);
t_fork		*get_fork(t_fork *fork, int n);

void		*ft_simulation_bonus(t_philo *philo);
void		ft_hostess_odd(t_info *info, t_philo *philo);
void		ft_hostess_even(t_info *info, t_philo *philo);

void		print_status(t_info *info, char *status, int n);
int			check_time(t_philo *philo);

#endif