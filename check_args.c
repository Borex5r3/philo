/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:30:25 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/10 19:30:56 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args2(int d, int e)
{
	if (d <= 0 || e <= 0)
		return (0);
	return (1);
}

int	check_args1(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return (0);
	return (1);
}

int	check_args_help(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] < 48 || p[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
