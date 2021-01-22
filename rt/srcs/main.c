/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:49:20 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 16:04:35 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	*g_mlx;
void	*g_win;
int		g_width = -1;
int		g_height = -1;
double	g_ratio = 0;

t_ambient		*g_ambient = NULL;
t_scene			*g_scene = NULL;

int		handle_key(int keycode, void *param)
{
	t_image	*image;

	image = (t_image *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 8)
	{
		printf("Changing camera\n");
		if (g_scene->cur_camera->next == NULL)
			g_scene->cur_camera = g_scene->camera_head;
		else
			g_scene->cur_camera = g_scene->cur_camera->next;
		scene_paint(image);
		mlx_put_image_to_window(g_mlx, g_win, image->img, 0, 0);
	}
	return (0);
}

int		close_hook(void)
{
	exit(0);
	return (0);
}

int		run_n_loop(t_image *image, char *title)
{
	g_win = mlx_new_window(g_mlx, g_width, g_height, title);
	mlx_put_image_to_window(g_mlx, g_win, image->img, 0, 0);
	mlx_key_hook(g_win, handle_key, image);
	mlx_hook(g_win, 17, 1L << 17, close_hook, (void *)0);
	mlx_loop(g_mlx);
	return (0);
}

void	resize_resolution(void)
{
	int		x;
	int		y;

	mlx_get_screen_size(g_mlx, &x, &y);
	if (g_ratio > 1 && x < g_width)
	{
		g_width = x;
		g_height = x / g_ratio;
	}
	if (g_ratio < 1 && y < g_height)
	{
		g_height = y;
		g_width = y * g_ratio;
	}
	return ;
}

int		main(int ac, char **av)
{
	int		fd;
	t_image	image;

	if (ac < 2 || ac > 3)
		return (perror_exit("Wrong number of arguments"));
	ex_check(av[1]);
	if ((fd = open(av[1], O_RDONLY)) < 3)
		return (perror_exit("Failed to read file"));
	ft_parse_scene(fd);
	image.img = mlx_new_image((g_mlx = mlx_init()), g_width, g_height);
	image.data_addr = (int *)mlx_get_data_addr(image.img, \
			&image.bits_per_pixel, &image.size_line, &image.endian);
	if (ac == 3 && save_check(av[2]))
	{
		scene_paint(&image);
		save_bmp(&image);
		return (0);
	}
	resize_resolution();
	scene_paint(&image);
	run_n_loop(&image, av[1]);
}
