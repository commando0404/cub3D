/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:40:40 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/22 10:03:26 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "constant.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"


typedef struct s_check
{
	int		n;
	int		s;
	int		e;
	int		w;
	int		f;
	int		c;
}			t_check;


typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;


typedef struct s_mouse
{
	int		x;
	int		y;
}			t_mouse;


typedef struct s_text
{
	char	*n_tex;
	char	*s_tex;
	char	*e_tex;
	char	*w_tex;
	int		floor;
	t_rgb	frgb;
	t_rgb	crgb;
}			t_text;


typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;


typedef struct s_ray
{
	int		tx;
	int		ty;
	int		color;
	double	camera_x;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidex;
	double	sidey;
	double	deltax;
	double	deltay;
	double	pwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight_;
	int		start;
	int		ntext;
	double	wallx;
	double	step;
	double	postex;
	int		tex_y;
	int		end;
	int		tex_x;
}			t_ray;


typedef struct s_cub
{
	int		i;
	int		j;
	int		fd;
	char	**str;
	char	**map_t;
	char	*line;
	char	*helper;
	char	*all_line;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	int		buf[HEIGHT_][WIDTH_];
	int		**texture;
	t_img	img;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_esc;
	int		key_left;
	int		key_right;
	int		max_line;
	double	move_speed;
	double	rot_speed;
	t_ray	ray;
	t_text	text;
	t_mouse	mouse;
	int		pix;
	int		skip_lines;
	int		lines;
}			t_cub;


// initialization
void		ft_init(t_cub *var);
void		init_hooks(t_cub *var);
void		init_rot(t_cub *var, char c);

int			ft_search(char *str, int search_char);


// read map
char		*get_line(int fd);


//exit and free functions
void		ft_perror(char *str);
void		free_(char **ptr);
void		ft_error(char *str);


// check map and elements
void		ft_check_map(char *map, t_cub *var);
int			ft_check_color(char *color);
void		check_newline(t_cub *var, char *map);
int			check_newline2(t_cub *var, char *map);
void		map_checks_(t_cub *var, char *map);
int			extension(char *s1, char *s2);
int			check_textures(t_cub *var);
int			check_closed_spaces(t_cub *var);
int			check_east_walls(t_cub *var);
int			check_west_walls(t_cub *var);
int			check_first_line(t_cub *var);
int			check_south_wall(t_cub *var);
void		check_tab(char *str);
int			ft_check_validation_of_map(char **str);
int			check_orientation(char *str);
int			check_floor_ceilling(char *str);


// draw
void		draw(t_cub *var);
void		ft_draw_mini_map(t_cub *var);
void		ft_draw_player(t_cub *var, int px, int py);
void		back_ground(t_cub *var);
void		floor_and_ceilling(t_cub *var, int y);


//moves
int			key_press(int key, t_cub *var);
int			key_update(int key, t_cub *var);
int			key_release(int key, t_cub *var);
int			mouse_move(int x, int y, t_cub *var);
void		mouse_move_left(int x, int y, int diff, t_cub *var);
void		mouse_move_right(int x, int y, int diff, t_cub *var);
int			mouse_move(int x, int y, t_cub *var);
void		move_right(t_cub *var, double move_speed);
void		move_left(t_cub *var, double move_speed);
void		look_right(t_cub *var);
void		look_left(t_cub *var);
void		move_up(t_cub *var);
void		move_down(t_cub *var);  



//raycasting
void		calc(t_cub *var);


//load and get map elements
void		load_image(t_cub *var, int *texture, char *path, t_img *img);
void		load_texture(t_cub *var);
int			rgb_to_hex(int r, int g, int b);
void		load_texture(t_cub *var);
void		get_textures(t_cub *var);
void		get_floor_and_ceilling(t_cub *var);
void		put_ceilling_color(char **tmp, t_cub *var);
void		ft_skip_espace_and_fill(t_cub *var, int *i, char **str);
int			build_map(t_cub *var);
void		put_floor_color(char **tmp, t_cub *var);


//count
void		get_size(t_cub *var);
int			player_pos(t_cub **var);
int			count_rows(t_cub *var);
int			count_comma(char *color);
size_t		count_parts(char **str);
int			get_len(t_cub *variables);
void		count_elements(t_cub *var);
void		get_max_line(t_cub *var);

#endif
