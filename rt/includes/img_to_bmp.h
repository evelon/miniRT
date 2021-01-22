/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_bmp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:03:04 by jolim             #+#    #+#             */
/*   Updated: 2021/01/08 22:31:40 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_TO_BMP_H
# define IMG_TO_BMP_H

# pragma pack(push, 1)

typedef struct		s_bitmapfileheader
{
	char			bf_type1;
	char			bf_type2;
	unsigned int	bf_size;
	unsigned short	bf_reserved1;
	unsigned short	bf_reserved2;
	unsigned int	bf_off_bits;
}					t_bitmapfileheader;

typedef struct		s_bitmapinfoheader
{
	unsigned int	bi_size;
	int				bi_width;
	int				bi_height;
	unsigned short	bi_planes;
	unsigned short	bi_bit_count;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_x_pels_per_meter;
	int				bi_y_pels_per_meter;
	unsigned int	bi_clr_used;
	unsigned int	bi_clr_important;
}					t_bitmapinfoheader;

# pragma pack(pop)
#endif
