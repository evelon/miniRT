/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:45:20 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 15:27:53 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int		init_scene(void)
{
	if (!(g_scene = (t_scene *)malloc(sizeof(t_scene))))
		return (0);
	g_scene->camera_head = NULL;
	g_scene->light_head = NULL;
	g_scene->object_head = NULL;
	g_scene->cur_camera = NULL;
	return (1);
}

static int		ft_parse_route(char **word)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(*word, "R", 1))
		ret = ft_parse_resolution(word);
	else if (!ft_strncmp(*word, "A", 1))
		ret = ft_parse_ambient(word);
	else if (!ft_strncmp(*word, "c", 2))
		ret = ft_parse_camera(word);
	else if (!ft_strncmp(*word, "l", 1))
		ret = ft_parse_light(word);
	else if (!ft_strncmp(*word, "pl", 2))
		ret = ft_parse_pl(word);
	else if (!ft_strncmp(*word, "sp", 2))
		ret = ft_parse_sp(word);
	else if (!ft_strncmp(*word, "sq", 2))
		ret = ft_parse_sq(word);
	else if (!ft_strncmp(*word, "cy", 2))
		ret = ft_parse_cy(word);
	else if (!ft_strncmp(*word, "tr", 2))
		ret = ft_parse_tr(word);
	else
		perror_exit("The file has an invalid line");
	return (ret);
}

int				ft_parse_rt(char *line)
{
	char	**word;
	int		i;
	int		ret;

	word = ft_split(line, ' ');
	if (word == NULL || *word == NULL || **word == '\0')
		return ('\0');
	i = 0;
	ret = ft_parse_route(word);
	free_split(word);
	return (ret);
}

int				ft_parse_scene(int fd)
{
	char	*line;
	int		ret;

	ret = 1;
	if (!(init_scene()))
		perror_exit("Malloc failed");
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			perror_exit("Failed to read file");
		if (*line == '\0' || *line == '#')
			continue;
		ret = ft_parse_rt(line);
		printf("%s\n", line);
		free(line);
	}
	if (g_width == -1)
		perror_exit("No Resolution found");
	if (g_ambient == NULL)
		perror_exit("No Ambient found");
	if (g_scene->camera_head == NULL)
		perror_exit("No Camera found");
	g_scene->cur_camera = g_scene->camera_head;
	return (1);
}
