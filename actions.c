/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:14:09 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/10 19:16:32 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think_time(t_vars *philo)
{
	send_msg(4, philo);
	usleep(100);
	eat_time((void *)philo);
}

void	sleep_time(t_vars *philo)
{
	send_msg(3, philo);
	usleep_action(philo->time_to_sleep, philo);
	think_time(philo);
}

void	*eat_time(void *philo1)
{
	t_vars	*philo;

	philo = (t_vars *)philo1;
	pthread_mutex_lock(&philo->mutex[philo->index - 1]);
	send_msg(1, philo);
	if (philo->number_of_philosophers == philo->index)
		pthread_mutex_lock(&philo->mutex[0]);
	else
		pthread_mutex_lock(&philo->mutex[philo->index]);
	send_msg(2, philo);
	philo->last_meal = get_current_time_philo(philo);
	usleep_action(philo->time_to_eat, philo);
	if (philo->time_must_eat > 0)
		philo->time_must_eat--;
	if (pthread_mutex_unlock(&philo->mutex[philo->index - 1]))
		return (NULL);
	if (philo->number_of_philosophers == philo->index)
		pthread_mutex_unlock(&philo->mutex[0]);
	else
		pthread_mutex_unlock(&philo->mutex[philo->index]);
	sleep_time(philo);
	return (philo1);
}
