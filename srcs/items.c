/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:18:43 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:27:35 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_add_list(t_select *select, int n, char **list)
{
	int		i;

	i = 0;
	select->items = (char**)malloc(sizeof(char*) * (n + 1));
	select->selected = (int*)malloc(sizeof(int) * (n + 1));
	if (select->items == NULL || select->selected == NULL)
		return ;
	(select->items)[n] = NULL;
	(select->selected)[n] = (int)'\0';
	select->n_items = n;
	select->pos = 0;
	while (i < n)
	{
		(select->items)[i] = ft_strdup(list[i]);
		i++;
	}
	ioctl(FILE_DS, TIOCGWINSZ, &(select->win));
}

void			ft_select_item(t_select *select)
{
	int		pos;

	pos = select->pos;
	if (select->selected[pos] == 1)
		select->selected[pos] = -1;
	else
		select->selected[pos] = 1;
	if (select->pos == select->n_items - 1)
		select->pos = 0;
	else
		select->pos += 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}

static int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				ft_get_longest_item(t_select *select)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	if (select->n_items <= 0)
		return (0);
	len = ft_strlen((select->items)[0]);
	while ((select->items)[i] != NULL)
	{
		j = ft_strlen((select->items)[i]);
		if (len <= j)
			len = j;
		i++;
	}
	return (len);
}
