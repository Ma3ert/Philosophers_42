/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:39:46 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/05/22 13:04:55 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	l_n(long n)
{
	int	l;

	l = 1;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static char	*n_allo(int l, int sign)
{
	char	*str;

	if (sign < 0)
		str = malloc(sizeof(char) * (l + 1) + 1);
	else
		str = malloc(sizeof(char) * l + 1);
	return (str);
}

static char	*niggative(int l, char *str, long n)
{
	l += 1;
	str[l] = '\0';
	l--;
	while (l > 0)
	{
		str[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	str[l] = '-';
	return (str);
}

static char	*positive(int l, char *str, long n)
{
	str[l] = '\0';
	l--;
	while (l > 0)
	{
		str[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	str[l] = n + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		l;
	long	nb;
	int		sign;
	char	*str;

	nb = n;
	sign = 1;
	if (nb < 0)
	{
		sign *= -1;
		nb *= -1;
	}
	l = l_n(nb);
	str = n_allo(l, sign);
	if (!str)
		return (0);
	if (sign < 0)
		str = niggative(l, str, nb);
	else
		str = positive(l, str, nb);
	return (str);
}

