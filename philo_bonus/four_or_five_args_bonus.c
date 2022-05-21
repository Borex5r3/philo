/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_or_five_args_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:38:53 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/22 00:31:12 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

pid_t	*create_processes(t_info *common_info, pid_t *ids)
{
	int	i;

	i = -1;
	while (++i < common_info->number_of_philosophers)
		ids[i] = 1;
	i = 0;
	while (i < common_info->number_of_philosophers && ids[i] != 0)
	{
		ids[i] = fork();
		if (ids[i] == 0)
		{
			create_philosopher(common_info, i + 1);
		}
		i++;
	}
	return (ids);
}

void	four_args_help(t_info *common_info)
{
	pid_t	*ids;

	ids = malloc(sizeof(pid_t) * common_info->number_of_philosophers);
	if (!ids)
		return ;
	ids = create_processes(common_info, ids);
	philo_is_dead(common_info, ids);
}

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
		sem_unlink(SEM_FORKS);
		sem_unlink(SEM_MSG);
		common_info.forks = sem_open(SEM_FORKS, O_CREAT, 0,
				common_info.number_of_philosophers);
		common_info.msg = sem_open(SEM_MSG, O_CREAT, 0, 1);
		four_args_help(&common_info);
	}
}

void	five_args_help(t_info *common_info)
{
	pid_t	*ids;

	ids = malloc(sizeof(pid_t) * common_info->number_of_philosophers);
	if (!ids)
		return ;
	ids = create_processes(common_info, ids);
	wait_processes(common_info, ids);
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
		sem_unlink(SEM_FORKS);
		sem_unlink(SEM_MSG);
		common_info.forks = sem_open(SEM_FORKS, O_CREAT, 0,
				common_info.number_of_philosophers);
		common_info.msg = sem_open(SEM_MSG, O_CREAT, 0, 1);
		five_args_help(&common_info);
		return ;
	}
}
