/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:20 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/04 17:56:37 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PHILLOSOPHER_H
#ifdef PHILLOSOPHER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct d_philo
{
	pthread_t		tread_id;
	int				n;
	int				eat;
	int				think;
	int				sleep;
	int				left_fork;
	int				right_fork;
	struct d_philo	*next;
}				t_philo;

typedef struct d_fork
{
	int				n;
	int				used;
	pthread_mutex_t *mutex;
	struct d_fork	*next;
}				t_fork;

int		ft_atoi(const char *str);
int		is_num(char *str);

void	first_philo(t_philo *philo);
void	philo_init(t_philo *philo);
int		philo_counting(t_philo *philo);

void	first_fork(t_fork *fork);
void	fork_init(t_fork *fork);
int		fork_counting(t_fork *fork);

#endif