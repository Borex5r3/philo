/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_and_usleep_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:58:37 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/18 00:32:17 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	get_time(void)
{
	size_t				time;
	struct timeval		current_time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

size_t	get_current_time_philo(t_vars *philo)
{
	size_t	current_time;

	current_time = get_time() - philo->init_time;
	return (current_time);
}

void	usleep_action(size_t time_action, t_vars *philo)
{
	time_action = time_action + get_current_time_philo(philo);
	while (get_current_time_philo(philo) != time_action)
		usleep(400);
}

void	send_msg(int action_index, t_vars *philo)
{
	sem_wait(philo->msg);
	if (action_index == 1)
		printf("%zu ms %d has taken a fork\n",
			get_current_time_philo(philo), philo->index);
	else if (action_index == 2)
	{
		printf("%zu ms %d has taken a fork\n",
			get_current_time_philo(philo), philo->index);
		printf("%zu ms %d is eating\n",
			get_current_time_philo(philo), philo->index);
	}
	else if (action_index == 3)
		printf("%zu ms %d is sleeping\n",
			get_current_time_philo(philo), philo->index);
	else if (action_index == 4)
		printf("%zu ms %d is thinking\n",
			get_current_time_philo(philo), philo->index);
	else
		printf("%zu ms %d died\n",
			get_current_time_philo(philo), philo->index);
	if (action_index != 0)
		sem_post(philo->msg);
}
