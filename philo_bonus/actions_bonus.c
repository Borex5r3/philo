/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:07:35 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/21 16:09:01 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	think_time(t_vars *philo)
{
	send_msg(4, philo);
	usleep(100);
	eat_time(philo);
}

void	sleep_time(t_vars *philo)
{
	send_msg(3, philo);
	usleep_action(philo->time_to_sleep, philo);
	think_time(philo);
}

void	eat_time(t_vars	*philo)
{
	sem_wait(philo->forks);
	send_msg(1, philo);
	sem_wait(philo->forks);
	send_msg(2, philo);
	philo->last_meal = get_current_time_philo(philo);
	usleep_action(philo->time_to_eat, philo);
	if (philo->time_must_eat > 0)
		philo->time_must_eat--;
	sem_post(philo->forks);
	sem_post(philo->forks);
	sleep_time(philo);
	return ;
}
