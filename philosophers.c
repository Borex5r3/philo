/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:19:30 by adbaich           #+#    #+#             */
/*   Updated: 2022/04/21 19:47:17 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_time(void)
{
	size_t				time;
	struct timeval	current_time;
	
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

size_t	get_usleep_time(size_t time_action)
{
	size_t	usleep_time;

	usleep_time = 10 * time_action;
	return (usleep_time);
}

size_t	get_current_time_philo(t_vars *philo)
{
	size_t current_time;

	current_time = get_time() - philo->init_time;
	return (current_time);
}

void	usleep_action(size_t time_action, t_vars *philo)
{
	size_t	i;

	i = 0;
	while (get_current_time_philo(philo) != time_action)
		i++;
}

void	think_time(t_vars *philo)
{
	printf("%zu ms %d is thinking\n", get_current_time_philo(philo), philo->index);
}

void	sleep_time(t_vars *philo)
{
	printf("%zu ms %d is sleeping\n", get_current_time_philo(philo), philo->index);
	usleep_action(philo->time_to_sleep, philo);
	think_time(philo);
}

void	*eat_time(void *philo1)
{
	size_t	limit_time;
	size_t	usleep_time;
	t_vars 	*philo;
	size_t	i;

	philo = (t_vars *)philo1;
	philo->init_time = get_time();
	// philo->last_meal[*philo->index] = get_time();
	printf("%zu ms %d has taken a fork\n", get_current_time_philo(philo), philo->index);
	printf("%zu ms %d is eating\n", get_current_time_philo(philo), philo->index);
	philo->last_meal = get_current_time_philo(philo);
	usleep_action(philo->time_to_eat, philo);
	// philo->last_meal[*philo->index] = get_time();
	sleep_time(philo);
	return (philo1);
}

void	create_philosophers(c_vars *common_info)
{
	pthread_t	*t;
	t_vars		*philo;
	int			i;

	t = malloc(sizeof(pthread_t) * common_info->number_of_philosophers);
	if (!t)
		return ;
	philo = malloc(sizeof(t_vars) * common_info->number_of_philosophers);
	if (!philo)
		return ;
	i = 0;
	while (i < common_info->number_of_philosophers)
	{
		philo[i].last_meal = 0;
		philo[i].number_of_philosophers = common_info->number_of_philosophers;
		philo[i].init_time = common_info->init_time;
		philo[i].time_to_die = common_info->time_to_die;
		philo[i].time_to_eat = common_info->time_to_eat;
		philo[i].time_to_sleep = common_info->time_to_sleep;
		philo[i].index = i + 1;
		pthread_create(&t[i], NULL, eat_time, (void *)&philo[i]);
		usleep(500);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < common_info->number_of_philosophers)
		{
			if (get_current_time_philo(&philo[i]) - philo[i].last_meal > common_info->time_to_die)
			{
				printf("%zu ms %d died\n", get_current_time_philo(&philo[i]), philo[i].index);
				return ;
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	c_vars	common_info;

	common_info.number_of_philosophers = ft_atoi(av[1]);
	common_info.time_to_die = ft_atoi(av[2]);
	common_info.time_to_eat = ft_atoi(av[3]);
	common_info.time_to_sleep = ft_atoi(av[4]);
	create_philosophers(&common_info);
	printf("%d -- %d -- %d -- %d\n", common_info.number_of_philosophers, common_info.time_to_die, common_info.time_to_eat, common_info.time_to_sleep);
	return (0);
}
