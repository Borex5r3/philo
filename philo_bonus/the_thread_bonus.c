/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_thread_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:54:58 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/21 16:26:11 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	philos_ate(t_vars *philo)
{
	int	num_of_philos_ate;

	num_of_philos_ate = 0;
	if (philo->time_must_eat == 0)
		num_of_philos_ate++;
	return (num_of_philos_ate);
}

static int	philo_died(t_vars *philo)
{
	size_t	last_meal;

	last_meal = get_current_time_philo(philo) - philo->last_meal;
	if (last_meal > philo->time_to_die)
	{
		send_msg(0, philo);
		return (1);
	}
	return (0);
}

void	*my_join(void *philo1)
{
	t_vars	*philo;

	philo = (t_vars *)philo1;
	while (1)
	{	
		if (philos_ate(philo))
			exit(0);
		if (philo_died(philo))
			exit(-1);
		usleep(100);
	}
	return (philo1);
}
