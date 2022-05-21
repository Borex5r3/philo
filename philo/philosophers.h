/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:19:38 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/12 17:40:18 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	int				number_of_philosophers;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				index;
	size_t			init_time;
	size_t			last_meal;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*msg;
}	t_vars;

typedef struct i_vars
{
	int			number_of_philosophers;
	int			time_to_eat;
	int			time_must_eat;
	size_t		time_to_die;
	int			time_to_sleep;
	size_t		init_time;
}	t_info;

int		ft_atoi(const char *str);
void	*eat_time(void *philo1);
void	send_msg(int action_index, t_vars *philo);
size_t	get_time(void);
size_t	get_current_time_philo(t_vars *philo);
void	usleep_action(size_t time_action, t_vars *philo);
void	*eat_time(void *philo1);
void	sleep_time(t_vars *philo);
void	think_time(t_vars *philo);
int		check_args_help(char *p);
int		check_args1(int a, int b, int c);
int		check_args2(int d, int e);
void	my_join(t_info *common_info, t_vars *philo,
			pthread_mutex_t *mutex, pthread_mutex_t msg);
void	four_args(char **av);
void	five_args(char **av);
void	create_philosophers(t_info *common_info);

#endif