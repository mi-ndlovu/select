/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:43:48 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:31:39 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		ft_put_char_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

int		ft_put_char(int c)
{
	return (write(FILE_DS, &c, 1));
}

void	ft_put_endl(char *str)
{
	ft_put_str(str);
	ft_put_char((int)'\n');
}

void	ft_put_str_fd(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_put_char_fd((int)str[i++], fd);
}

void	ft_put_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_put_char((int)str[i++]);
}
