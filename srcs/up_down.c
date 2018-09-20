/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:19:31 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:32:32 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		ft_go_up(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == min)
		select->pos = max - 1;
	else
		select->pos = select->pos - 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}

void		ft_go_down(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == (max - 1))
		select->pos = min;
	else
		select->pos = select->pos + 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}

t_select	*ft_save_and_load(t_select *select, int mode)
{
	static t_select	*tmp = NULL;

	if (mode == 0)
		tmp = select;
	return (tmp);
}

void		ft_free_mem(t_select *select)
{
	int		i;

	i = 0;
	while ((select->items)[i] != NULL)
	{
		free((select->items)[i]);
		i++;
	}
	free(select->items);
	free(select->selected);
}
