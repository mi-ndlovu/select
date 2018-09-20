/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:27:09 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:26:47 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	len = 0;
	while (str[len] != '\0')
	{
		tmp[len] = str[len];
		len++;
	}
	return (tmp);
}

static void		ft_swap_arrs(t_select *select, char **new_s, int *new_i)
{
	int		i;

	i = 0;
	while ((select->items)[i] != NULL)
		free((select->items)[i++]);
	free((select->items));
	free(select->selected);
	if (select->pos == select->n_items - 1)
		select->pos--;
	(select->n_items)--;
	if (select->n_items == 0)
	{
		ft_reset_term_behavior(&(select->term));
		exit(0);
	}
	select->items = new_s;
	select->selected = new_i;
}

static void		ft_delete_item(t_select *select)
{
	char	**new_list;
	int		*new_selection;
	int		pos;
	int		items;
	int		i;

	pos = 0;
	items = select->n_items;
	new_list = (char**)malloc(sizeof(char*) * items);
	new_selection = (int*)malloc(sizeof(int) * items);
	new_list[items - 1] = NULL;
	new_selection[items - 1] = (int)'\0';
	i = 0;
	while (pos < items)
	{
		if (pos != select->pos)
		{
			new_list[i] = ft_strdup(select->items[pos]);
			new_selection[i] = (select->selected)[pos];
			i++;
		}
		pos++;
	}
	ft_swap_arrs(select, new_list, new_selection);
}

void			ft_remove_item(t_select *select)
{
	ft_delete_item(select);
	ft_save_and_load(select, 0);
	ft_print_list(select);
}
