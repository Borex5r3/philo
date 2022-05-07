/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:19:38 by adbaich           #+#    #+#             */
/*   Updated: 2022/04/26 23:14:50 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct s_vars
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		index;
	size_t	init_time;
	pthread_mutex_t *mutex;
	size_t	last_meal;
} t_vars;

typedef struct i_vars
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	size_t	init_time;
} c_vars;

int		ft_atoi(const char *str);
void	*eat_time(void *philo1);