/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:22:00 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:25:02 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int	ft_check_winsize(t_select *select)
{
	int		i;

	i = ft_get_longest_item(select);
	if (select->win.ws_row <= select->n_items || select->win.ws_col <= i)
	{
		if (select->win.ws_row <= select->n_items)
			ft_put_endl("\033[31mWindow height is too small.\033[0m");
		if (select->win.ws_col <= i)
			ft_put_endl("\033[31mWindow width is too small.\033[0m");
		return (-1);
	}
	return (1);
}

void		ft_print_list(t_select *select)
{
	int		i;

	i = 0;
	ft_clear_terminal();
	ft_put_endl("::::::::::::::::::::::::::::::::::::::::::::");
	ft_put_endl("::                 \033[34mSelect\033[0m                 ::");
	ft_put_endl("::::::::::::::::::::::::::::::::::::::::::::");
	if (ft_check_winsize(select) == -1)
		return ;
	while ((select->items)[i] != NULL)
	{
		if (select->pos == i)
		{
			if (select->selected[i] == 1)
				ft_put_underline_highlight((select->items)[i], ft_put_red);
			else
				ft_put_underline((select->items)[i], ft_put_green);
		}
		else
		{
			if (select->selected[i] == 1)
				ft_put_highlight((select->items)[i], ft_put_green);
			else
				ft_put_endl((select->items)[i]);
		}
		i++;
	}
}
