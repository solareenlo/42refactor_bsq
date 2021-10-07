/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 15:18:53 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <fcntl.h>
# include <libgen.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FT_BUFSIZ 32768
# define IN 1
# define OUT 0
# define SUCCESS 1
# define FAIL 0
# define FT_ERR_MAP "map error\n"
# define TRUE 1
# define FALSE 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef int		t_bool;

typedef struct	s_map_info
{
	int			rows;
	int			cols;
	char		empty;
	char		obstacle;
	char		full;
}				t_map_info;

typedef struct	s_square
{
	int			col;
	int			row;
	int			max_size;
}				t_square;

int				g_max_size;
int				g_col;
int				g_row;
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_puterror(char *str);
int				ft_strlen(char *str);
t_bool			ft_is_printable(char c);
t_bool			ft_isspace(char c);
t_bool			ft_isdigit(char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *str, char *charset);
int				ft_atoi(char *str);
int				ft_validate_map_info(char **map);
t_map_info		*ft_parse_map_info(char **map);
int				ft_validate_map(char **map, t_map_info *info);
t_bool			ft_is_last_char_a_line_break(char *content);
void			ft_init_square(t_square *p_square);
t_bool			ft_is_empty_char(char **map, int col, int row, t_map_info *p_info);
void			ft_find_biggest_square(char **map, t_map_info *p_info);
void			ft_write_biggest_square(char **map, t_map_info *p_info);
void			ft_put_map(char **map, t_map_info *p_info);
int				ft_get_map_cols(char **map);

#endif
