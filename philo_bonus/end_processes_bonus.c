/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:16:39 by adbaich           #+#    #+#             */
/*   Updated: 2022/05/22 00:29:40 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	wait_processes(t_info *common_info, pid_t *ids)
{
	int	res;
	int	ret;
	int	i;

	res = 1;
	ret = 1;
	while (ret > 0)
	{
		ret = waitpid(-1, &res, 0);
		if (res != 0)
		{
			i = 0;
			while (i < common_info->number_of_philosophers)
			{
				kill(ids[i], SIGKILL);
				i++;
			}
			return ;
		}
	}
}

void	philo_is_dead(t_info *common_info, pid_t *ids)
{
	int	res;
	int	i;

	res = 1;
	while (res > 0)
	{
		waitpid(-1, &res, 0);
		if (res != 0)
		{
			i = 0;
			while (i < common_info->number_of_philosophers)
			{
				kill(ids[i], SIGKILL);
				i++;
			}
			return ;
		}
	}
}
