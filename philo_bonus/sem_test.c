/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:17:58 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/12 12:28:04 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	n = 0;

void	*ft_sem_test(void *param)
{
	sem_t *id;

	id = (sem_t *)param;
	printf("waiting\n");
	sem_wait(id);
	printf("i will increment n: %d\n", n);
	sleep(1);
	n += 1;
	printf("i increment n: %d\n", n);
	sem_post(id);
	printf("going out\n");
	return (0);
}

int main(void)
{
	int	i;
	int	j;
	sem_t *id = sem_open("1", O_CREAT, 0644, 1);
	pthread_t thread[4];

	i = 0;
	j = 0;
	while (i < 4)
	{
		printf("its %d\n", i);
		pthread_create(&thread[i], NULL, ft_sem_test, &id);
		i++;
	}
	while (j < 4)
	{
		pthread_join(thread[j], NULL);
		j++;
	}
}