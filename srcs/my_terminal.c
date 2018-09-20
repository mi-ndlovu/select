/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:19:05 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:29:30 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_clear_terminal(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_put_char);
}

void			ft_enter(t_select *select)
{
	int		i;

	i = 0;
	ft_reset_term_behavior(&(select->term));
	while (select->n_items > i)
	{
		if ((select->selected)[i] == 1)
		{
			ft_put_str_fd((select->items)[i], 1);
			ft_put_char_fd(' ', 1);
		}
		i++;
	}
	ft_put_char_fd('\n', 1);
	exit(0);
}

void			ft_exit(void)
{
	t_select	*select;

	select = ft_save_and_load(NULL, 1);
	ft_free_mem(select);
	ft_reset_term_behavior(&(select->term));
	exit(0);
}

static void		ft_clr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		str[i++] = '\0';
}

void			ft_keyhook(void)
{
	char	key[5];

	key[4] = '\0';
	while (1)
	{
		ft_clr(key);
		read(0, key, 4);
		if (key[0] == 27 && key[1] == '\0' && key[2] == '\0')
			return ;
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'A')
			ft_go_up(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'B')
			ft_go_down(ft_save_and_load(NULL, 1));
		else if (key[0] == 32 && key[1] == '\0' && key[2] == '\0')
			ft_select_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 10 && key[1] == '\0' && key[2] == '\0')
			ft_enter(ft_save_and_load(NULL, 1));
		else if (key[0] == 127 && key[1] == '\0' && key[2] == '\0')
			ft_remove_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 51)
			ft_remove_item(ft_save_and_load(NULL, 1));
	}
}
