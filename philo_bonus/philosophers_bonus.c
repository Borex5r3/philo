/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:38:32 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/22 17:39:17 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	fill_philo(t_vars *philo, t_info *common_info, int index)
{
	philo->init_time = common_info->init_time;
	philo->last_meal = 0;
	philo->number_of_philosophers = common_info->number_of_philosophers;
	philo->init_time = common_info->init_time;
	philo->time_to_die = common_info->time_to_die;
	philo->time_to_eat = common_info->time_to_eat;
	philo->time_to_sleep = common_info->time_to_sleep;
	philo->time_must_eat = common_info->time_must_eat;
	philo->index = index;
	philo->forks = common_info->forks;
	philo->msg = common_info->msg;
	usleep(100);
}

void	create_philosopher(t_info *common_info, int index)
{
	t_vars		philo;
	pthread_t	t;

	philo.msg = common_info->msg;
	fill_philo(&philo, common_info, index);
	pthread_create(&t, NULL, my_join, &philo);
	eat_time(&philo);
}

int	main(int ac, char **av)
{
	if (ac == 5)
	{
		four_args(av);
	}
	else if (ac == 6)
	{
		five_args(av);
	}
	return (0);
}
