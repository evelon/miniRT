/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:43:53 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 15:01:32 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "../../libft/libft.h"
# include "../../get_next_line/get_next_line.h"
# include "img_to_bmp.h"

/*
** Types as code.
*/

# define FT_NOT 0
# define FT_INT 1
# define FT_DBL 2
# define FT_COL 3
# define FT_VEC 4

/*
** Global variables.
*/

extern void				*g_mlx;
extern void				*g_win;
extern int				g_width;
extern int				g_height;
extern double			g_ratio;

/*
** Structures and functions for t_vec.
*/

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

t_vec					v_new(double x, double y, double z);
t_vec					v_sub(t_vec u, t_vec w);
t_vec					v_add(t_vec u, t_vec w);
t_vec					v_mul(t_vec v, double t);
t_vec					v_div(t_vec v, double t);

double					v_len(t_vec v);
double					v_dot(t_vec u, t_vec w);
t_vec					v_crs(t_vec u, t_vec w);
t_vec					v_unit(t_vec v);

double					v_cos(t_vec u, t_vec w);
double					v_sin(t_vec u, t_vec w);
t_vec					v_blend(t_vec u, t_vec w);
t_vec					v_max(t_vec u, t_vec w);
t_vec					v_cap(t_vec v);

/*
** Structures and functions for t_color.
*/

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

t_color					vec_to_color(t_vec vec);
t_vec					color_to_vec(t_color color);
unsigned int			color_to_int(t_color color);

/*
** Structures and functions for mlx functions.
*/

typedef struct			s_image
{
	void				*img;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					*data_addr;
}						t_image;

/*
** error/flag/filename check. + etc.
*/

int						perror_exit(char *err);
int						save_check(char *flag);
int						ex_check(char *filename);
double					dbl_max(double u, double w);

/*
** save_bmp functions
*/

t_bitmapfileheader		set_bmp_file_header();
t_bitmapinfoheader		set_bmp_info_header();
void					save_bmp(t_image *image);

/*
** figures and macros to check shapes.
*/

# define SPHERE 'S'
# define PLANE 'P'
# define SQUARE 'Q'
# define CYLINDER 'C'
# define TRIANGLE 'T'

typedef struct			s_ray
{
	t_vec				origin;
	t_vec				direction;
}						t_ray;

typedef struct			s_sphere
{
	t_vec				center;
	double				radius;
	t_color				color;
}						t_sphere;

typedef struct			s_plane
{
	t_vec				point;
	t_vec				ori_v;
	t_color				color;
}						t_plane;

typedef struct			s_square
{
	t_vec				center;
	t_vec				ori_v;
	double				side_half;
	t_color				color;
}						t_square;

typedef struct			s_cylinder
{
	t_vec				center;
	t_vec				ori_v;
	double				radius;
	double				height;
	t_color				color;
}						t_cylinder;

typedef struct			s_triangle
{
	t_vec				first;
	t_vec				second;
	t_vec				third;
	t_color				color;
}						t_triangle;

typedef struct			s_rectangle
{
	t_vec				center;
	t_vec				ori_v;
	t_vec				axis;
	double				width;
	double				height;
}						t_rectangle;

/*
** Structures and global variables for a scene.
*/

typedef struct			s_camera_lst
{
	t_vec				pov;
	t_vec				lower_left;
	t_vec				width;
	t_vec				height;
	struct s_camera_lst	*next;
}						t_camera_lst;

typedef struct			s_light_lst
{
	t_vec				source;
	double				brightness;
	t_color				color;
	struct s_light_lst	*next;
}						t_light_lst;

typedef struct			s_object_lst
{
	char				type;
	void				*object;
	struct s_object_lst	*next;
}						t_object_lst;

typedef struct			s_ambient
{
	double				ratio;
	t_color				color;
}						t_ambient;

typedef struct			s_scene
{
	t_camera_lst		*camera_head;
	t_light_lst			*light_head;
	t_object_lst		*object_head;
	t_camera_lst		*cur_camera;
}						t_scene;

extern t_ambient		*g_ambient;
extern t_scene			*g_scene;

/*
** Fuctions for parsing a .rt file.
*/

int						ft_parse_scene(int fd);
int						ft_parse_rt(char *line);

int						ft_parse_resolution(char **word);
int						ft_parse_ambient(char **word);
int						ft_parse_camera(char **word);
int						ft_parse_light(char **word);

int						ft_parse_pl(char **word);
int						ft_parse_sp(char **word);
int						ft_parse_sq(char **word);
int						ft_parse_cy(char **word);
int						ft_parse_tr(char **word);

t_camera_lst			*ft_new_camera();
t_light_lst				*ft_new_light();
t_object_lst			*ft_new_object(char type, void *object);
void					init_camera(t_camera_lst *camera, \
		char *c_pov, char *c_unit, char *c_fov);

int						is_valid_color(t_color c);
int						is_valid_unit(t_vec u);
t_color					ft_read_color(char *str);
t_vec					ft_read_vec(char *str);
int						ft_num_type(char *str);

int						ft_count_word(char **word);
double					ft_atof(char *str);

/*
** Ray structure and Fuctions for raytracing.
*/

typedef struct			s_hit_point
{
	void				*object;
	double				t_value;
	t_vec				point;
	t_vec				v_color;
	t_vec				vec_normal;
	t_vec				vec_light;
	t_vec				vec_viewer;
	t_vec				vec_reflection;
	t_vec				vec_half;
}						t_hit_point;

void					put_color_to_pixel(t_image *image, \
		int x, int y, t_color color);
void					scene_paint(t_image *image);

double					ray_sphere_t(t_ray *ray, t_sphere *sphere);
double					ray_plane_t(t_ray *ray, t_plane *plane);
double					ray_cylinder_t(t_ray *ray, t_cylinder *cylinder);
double					ray_square_t(t_ray *ray, t_square *square);
double					ray_triangle_t(t_ray *ray, t_triangle *triangle);

double					ray_cylinder_quad(t_ray *ray, t_cylinder *cylinder, \
		double *a, double *b, double *c);
double					ray_sq_plane_t(t_ray *ray, t_square *square);
double					ray_cylinder_cap_t(t_ray *ray, t_cylinder *cylinder);
double					ray_cylinder_shadow(t_ray *ray, t_cylinder *cylinder);

double					distance_ray_point(t_vec point_a, t_vec origin, \
		t_vec direction);
double					distance_ray_ray(t_ray *line1, t_ray *line2);
t_vec					foot_point_ray(t_vec point_a, t_vec origin, \
		t_vec direction);
double					distance_points(t_vec p1, t_vec p2);

t_hit_point				*ray_sphere(t_ray *ray, t_sphere *sphere);
t_hit_point				*ray_plane(t_ray *ray, t_plane *plane);
t_hit_point				*ray_cylinder(t_ray *ray, t_cylinder *cylinder);
t_hit_point				*ray_square(t_ray *ray, t_square *square);
t_hit_point				*ray_triangle(t_ray *ray, t_triangle *triangle);

int						ray_shadow(t_hit_point *hit, t_light_lst *light);
t_hit_point				*hit_object(t_ray *ray);
double					ray_rectangle_t(t_ray *ray, t_rectangle *rec);

double					hit_specular(t_hit_point *hit, t_light_lst *light);
t_vec					hit_diffuse(t_hit_point *hit, t_light_lst *light);

void					set_hit(t_hit_point *hit, t_light_lst *light);
t_vec					ray_point(t_ray *ray, double t);
double					min_positive(double a, double b);

#endif
