/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:05:34 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/20 13:55:39 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define FILE_DS 2

# include <term.h>
# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct		s_select
{
	struct termios	term;
	struct winsize	win;
	char			**items;
	int				*selected;
	int				n_items;
	int				pos;
}					t_select;

t_select			*ft_save_and_load(t_select *select, int mode);
char				*ft_strdup(char *str);
void				ft_add_list(t_select *select, int n, char **list);
void				ft_print_list(t_select *select);
int					ft_get_longest_item(t_select *select);
void				ft_free_mem(t_select *select);
void				ft_exit(void);
int					ft_put_char(int c);
int					ft_put_char_fd(int c, int fd);
void				ft_put_str(char *str);
void				ft_put_str_fd(char *str, int fd);
void				ft_put_endl(char *str);
void				ft_put_green(char *str);
void				ft_put_red(char *str);
void				ft_put_underline(char *str, void (*ft_pt)(char*));
void				ft_put_highlight(char *str, void (*ft_pt)(char*));
void				ft_put_underline_highlight(char *str, void (*ft_pt)(char*));
void				ft_clear_terminal(void);
int					ft_change_term_behavior(struct termios *term);
int					ft_reset_term_behavior(struct termios *term);
void				ft_handle_signals(void);
void				ft_win_change(void);
void				ft_keyhook(void);
void				ft_go_up(t_select *select);
void				ft_go_down(t_select *select);
void				ft_select_item(t_select *select);
void				ft_enter(t_select *select);
void				ft_remove_item(t_select *select);

#endif
