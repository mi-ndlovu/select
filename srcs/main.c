/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:28:24 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:28:30 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void	ft_win_change(void)
{
	t_select	*tmp;

	tmp = ft_save_and_load(NULL, 1);
	ioctl(FILE_DS, TIOCGWINSZ, &(tmp->win));
	ft_save_and_load(tmp, 0);
	ft_print_list(tmp);
}

int		ft_change_term_behavior(struct termios *term)
{
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	if (tcgetattr(FILE_DS, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(FILE_DS, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_put_char);
	tputs(tgetstr("vi", NULL), 1, ft_put_char);
	return (0);
}

int		ft_reset_term_behavior(struct termios *term)
{
	tputs(tgetstr("ve", NULL), 1, ft_put_char);
	tputs(tgetstr("te", NULL), 1, ft_put_char);
	term->c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(FILE_DS, TCSANOW, term)) == -1)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_select	select;

	if (argc > 1)
	{
		if (ft_change_term_behavior(&(select.term)) == -1)
			return (-1);
		ft_handle_signals();
		ft_clear_terminal();
		ft_add_list(&select, argc - 1, &argv[1]);
		ft_save_and_load(&select, 0);
		ft_print_list(&select);
		ft_keyhook();
		ft_free_mem(&select);
		ft_reset_term_behavior(&(select.term));
	}
	return (0);
}
