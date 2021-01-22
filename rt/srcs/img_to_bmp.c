/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:21:40 by jolim             #+#    #+#             */
/*   Updated: 2021/01/22 15:02:02 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/img_to_bmp.h"

t_bitmapfileheader	set_bmp_file_header(void)
{
	t_bitmapfileheader	fileheader;

	fileheader.bf_type1 = 'B';
	fileheader.bf_type2 = 'M';
	fileheader.bf_size = 54 + g_width * g_height * 4;
	fileheader.bf_reserved1 = 0;
	fileheader.bf_reserved2 = 0;
	fileheader.bf_off_bits = 54;
	return (fileheader);
}

t_bitmapinfoheader	set_bmp_info_header(void)
{
	t_bitmapinfoheader	infoheader;

	infoheader.bi_size = 40;
	infoheader.bi_width = g_width;
	infoheader.bi_height = -g_height;
	infoheader.bi_planes = 1;
	infoheader.bi_bit_count = 32;
	infoheader.bi_compression = 0;
	infoheader.bi_size_image = g_width * g_height * 4;
	infoheader.bi_x_pels_per_meter = 0;
	infoheader.bi_y_pels_per_meter = 0;
	infoheader.bi_clr_used = 0;
	infoheader.bi_clr_important = 0;
	return (infoheader);
}

void				save_bmp(t_image *image)
{
	int					fd;
	t_bitmapfileheader	bmfh;
	t_bitmapinfoheader	bmih;
	char				*filename;
	int					i;

	printf("Name the file including the extension '.bmp'\n");
	get_next_line(0, &filename);
	fd = open(filename, O_CREAT | O_EXCL | O_RDWR, 0444);
	if (fd < 0)
		perror_exit("Failed to make a file");
	bmfh = set_bmp_file_header();
	bmih = set_bmp_info_header();
	if (write(fd, &bmfh, 14) != 14)
		perror_exit("Failed to save file header");
	if (write(fd, &bmih, 40) != 40)
		perror_exit("Failed to save info header");
	i = 0;
	while (i < (image->size_line / 4) * g_height)
	{
		if (i % (image->size_line / 4) < g_width)
			write(fd, &image->data_addr[i], 4);
		i++;
	}
	write(fd, image->data_addr, g_width * g_height * 4);
}
