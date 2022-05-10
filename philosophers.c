/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:19:30 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/10 19:32:37 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philosophers(c_vars *common_info)
{
	pthread_mutex_t	msg;
	pthread_t		*t;
	pthread_mutex_t	*mutex;
	t_vars			*philo;
	size_t			last_meal;
	int				i;
	int				j;
	int				num_of_philos_ate;
	int				index;

	t = malloc(sizeof(pthread_t) * common_info->number_of_philosophers);
	if (!t)
		return ;
	philo = malloc(sizeof(t_vars) * common_info->number_of_philosophers);
	if (!philo)
		return ;
	mutex = malloc(sizeof(pthread_mutex_t)
			* common_info->number_of_philosophers);
	if (!mutex)
		return ;
	pthread_mutex_init(&msg, NULL);
	i = 0;
	while (i < common_info->number_of_philosophers)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
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
	while (1)
	{
		if (common_info->time_must_eat > 0)
		{
			j = 0;
			num_of_philos_ate = 0;
			while (j < common_info->number_of_philosophers)
			{
				if (philo[j].time_must_eat == 0)
					num_of_philos_ate++;
				j++;
			}
			if (num_of_philos_ate == common_info->number_of_philosophers)
				return ;
		}
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
				return ;
			}
			i++;
		}
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	c_vars	common_info;
	int		count;

	count = 1;
	if (ac == 5)
	{
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
	else if (ac == 6)
	{
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
	return (0);
}
