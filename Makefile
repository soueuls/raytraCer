##
## Makefile for rtv1 in /home/colin/Desktop/igraph/rtv1##
## Made by colin## Login   <colin@epitech.net>
##
## Started on  Tue Jan 21 00:41:49 2014 colin
## Last update Sun Jun  8 21:38:57 2014 Colin Coudray
##
##		aux/save_img.c			\
##		aux/convert_jpeg.c		\
##

CC      = 	gcc

NAME    = 	rt

RTQT	=	RTqt

SRC	= 	main.c				\
		aux/aux_mlx.c			\
		aux/aux.c			\
		aux/aux2.c			\
		aux/calc_aux.c			\
		aux/my_str_to_word_tab.c	\
		aux/get_next_line.c		\
		aux/save_img.c			\
		parsing/parsing.c		\
		parsing/init_cam.c		\
		parsing/init_light.c		\
		parsing/init_leaf.c		\
		parsing/init_obj.c		\
		calculs/set_sphere.c		\
		calculs/set_cone.c		\
		calculs/set_cylindre.c		\
		calculs/set_plan.c		\
		calculs/rota.c			\
		calculs/calc_solution.c		\
		calculs/solve_eq_3rd.c		\
		calculs/solve_eq_4th.c		\
		calculs/set_blob.c		\
		calculs/set_cubeh.c		\
		calculs/set_triangle.c		\
		image/color_obj.c		\
		image/draw_img.c		\
		image/calc_color.c		\
		image/effects.c			\
		image/noisecp.c			\
		image/color_noise.c		\
		image/vect_calc.c		\
		image/filters.c			\
		image/calc_color_aux.c		\
		image/calc_color_utils.c	\
		image/background_img.c		\
		image/load_celshader.c		\
		image/sobel_filter.c		\
		image/bump_mapping.c		\
		JPEG/compress_jpeg.c		\
		JPEG/decompress_jpeg.c		\
		JPEG/image_conversion_format.c

OBJ     = 	$(SRC:.c=.o)

LIB     = 	-L/usr/X11/lib -lmlx -lXext -lX11 -lm -ljpeg -framework OpenGL -framework AppKit

CFLAGS  +=	-W -Wall -ofast -I./includes/ -I/usr/X11/include

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)
		rm -fr $(RTQT)

re: 		fclean all
