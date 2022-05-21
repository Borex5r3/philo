/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_or_five_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:38:53 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/12 17:39:23 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	four_args(char **av)
{
	t_info	common_info;
	int		count;

	count = 1;
	while (check_args_help(av[count]) && count < 4)
		count++;
	if (!check_args_help(av[count]))
		count--;
	if (check_args1(ft_atoi(av[2]), ft_atoi(av[1]),
			ft_atoi(av[3])) && check_args2(ft_atoi(av[4]), 1) && count == 4)
	{
		common_info.number_of_philosophers = ft_atoi(av[1]);
		common_info.time_to_die = ft_atoi(av[2]);
		common_info.time_to_eat = ft_atoi(av[3]);
		common_info.time_to_sleep = ft_atoi(av[4]);
		common_info.time_must_eat = -2;
		common_info.init_time = get_time();
		create_philosophers(&common_info);
	}
}

void	five_args(char **av)
{
	t_info	common_info;
	int		count;

	count = 1;
	while (check_args_help(av[count]) && count < 5)
		count++;
	if (!check_args_help(av[count]))
		count--;
	if (check_args1(ft_atoi(av[2]), ft_atoi(av[1]), ft_atoi(av[3]))
		&& check_args2(ft_atoi(av[4]), ft_atoi(av[5])) && count == 5)
	{
		common_info.number_of_philosophers = ft_atoi(av[1]);
		common_info.time_to_die = ft_atoi(av[2]);
		common_info.time_to_eat = ft_atoi(av[3]);
		common_info.time_to_sleep = ft_atoi(av[4]);
		common_info.time_must_eat = ft_atoi(av[5]);
		common_info.init_time = get_time();
		create_philosophers(&common_info);
	}
}
