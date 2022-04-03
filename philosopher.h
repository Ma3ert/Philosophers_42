/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:58:20 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/04/03 17:10:10 by yait-iaz         ###   ########.fr       */
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

#endif