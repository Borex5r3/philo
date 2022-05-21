/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:19:30 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/12 17:39:51 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	init_mutexes(pthread_mutex_t *mutex, int number_of_philosophers)
{
	pthread_mutex_t	msg;
	int				i;

	pthread_mutex_init(&msg, NULL);
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (msg);
}

void	fill_philos(t_vars *philo, t_info *common_info,
		pthread_mutex_t *mutex, pthread_mutex_t msg)
{
	pthread_t	*t;
	int			i;

	t = malloc(sizeof(pthread_t) * common_info->number_of_philosophers);
	if (!t)
		return ;
	i = 0;
	while (i < common_info->number_of_philosophers)
	{
		philo[i].init_time = common_info->init_time;
		philo[i].msg = &msg;
		philo[i].last_meal = 0;
		philo[i].mutex = mutex;
		philo[i].number_of_philosophers = common_info->number_of_philosophers;
		philo[i].init_time = common_info->init_time;
		philo[i].time_to_die = common_info->time_to_die;
		philo[i].time_to_eat = common_info->time_to_eat;
		philo[i].time_to_sleep = common_info->time_to_sleep;
		philo[i].time_must_eat = common_info->time_must_eat;
		philo[i].index = i + 1;
		pthread_create(&t[i], NULL, eat_time, (void *)&philo[i]);
		usleep(100);
		i++;
	}
}

void	create_philosophers(t_info *common_info)
{
	pthread_mutex_t	msg;
	pthread_mutex_t	*mutex;
	t_vars			*philo;

	philo = malloc(sizeof(t_vars) * common_info->number_of_philosophers);
	if (!philo)
		return ;
	mutex = malloc(sizeof(pthread_mutex_t)
			* common_info->number_of_philosophers);
	if (!mutex)
		return ;
	msg = init_mutexes(mutex, common_info->number_of_philosophers);
	fill_philos(philo, common_info, mutex, msg);
	my_join(common_info, philo, mutex, msg);
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
