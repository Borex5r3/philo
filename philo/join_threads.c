/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:08:40 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/15 00:51:56 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philos_ate(t_vars *philo, t_info *common_info)
{
	int	num_of_philos_ate;
	int	i;

	i = 0;
	num_of_philos_ate = 0;
	while (i < common_info->number_of_philosophers)
	{
		if (philo[i].time_must_eat == 0)
			num_of_philos_ate++;
		i++;
	}
	return (num_of_philos_ate);
}

static int	philo_died(t_vars *philo, t_info *common_info,
			pthread_mutex_t *mutex, pthread_mutex_t msg)
{
	int		i;
	size_t	last_meal;
	int		index;

	i = 0;
	while (i < common_info->number_of_philosophers)
	{
		last_meal = get_current_time_philo(&philo[i]) - philo[i].last_meal;
		if (last_meal > common_info->time_to_die)
		{
			index = i;
			i = 0;
			while (i < common_info->number_of_philosophers)
			{
				pthread_mutex_destroy(&mutex[i]);
				i++;
			}
			send_msg(0, &philo[index]);
			pthread_mutex_destroy(&msg);
			return (1);
		}
		i++;
	}
	return (0);
}

void	my_join(t_info *common_info, t_vars *philo,
		pthread_mutex_t *mutex, pthread_mutex_t msg)
{
	while (1)
	{
		if (common_info->time_must_eat > 0)
		{			
			if (philos_ate(philo, common_info)
				== common_info->number_of_philosophers)
				return ;
		}
		if (philo_died(philo, common_info, mutex, msg))
			return ;
		usleep(100);
	}
}
