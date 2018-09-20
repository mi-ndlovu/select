/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:19:19 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:30:58 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void	ft_put_green(char *str)
{
	ft_put_str("\033[32m");
	ft_put_str(str);
	ft_put_endl("\033[0m");
}

void	ft_put_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("so", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("se", NULL), 1, ft_put_char);
}

void	ft_put_red(char *str)
{
	ft_put_str("\033[31m");
	ft_put_str(str);
	ft_put_endl("\033[0m");
}

void	ft_put_underline_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("so", NULL), 1, ft_put_char);
	tputs(tgetstr("us", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_put_char);
	tputs(tgetstr("se", NULL), 1, ft_put_char);
}

void	ft_put_underline(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("us", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_put_char);
}
