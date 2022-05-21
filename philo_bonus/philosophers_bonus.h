/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:48:57 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/22 00:30:29 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SEM_FORKS "/forks"
# define SEM_MSG "/msg"

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
	sem_t			*forks;
	sem_t			*msg;
}	t_vars;

typedef struct i_vars
{
	int			number_of_philosophers;
	int			time_to_eat;
	int			time_must_eat;
	size_t		time_to_die;
	int			time_to_sleep;
	size_t		init_time;
	sem_t		*forks;
	sem_t		*msg;
}	t_info;

void	eat_time(t_vars	*philo);
void	*my_join(void *philo1);
void	think_time(t_vars *philo);
void	sleep_time(t_vars *philo);
void	eat_time(t_vars *philo);
int		check_args2(int d, int e);
int		check_args1(int a, int b, int c);
int		check_args_help(char *p);
void	four_args(char **av);
void	five_args(char **av);
void	usleep_action(size_t time_action, t_vars *philo);
void	send_msg(int action_index, t_vars *philo);
size_t	get_time(void);
size_t	get_current_time_philo(t_vars *philo);
int		ft_atoi(const char *str);
void	create_philosopher(t_info *common_info, int index);
void	philo_is_dead(t_info *common_info, pid_t *ids);
void	wait_processes(t_info *common_info, pid_t *ids);

#endif