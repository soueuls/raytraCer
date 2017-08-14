##
## Makefile for  in /home/tanguc_s/rendu/BONUS_RT
## 
## Made by Sergen Tanguc
## Login   <tanguc_s@epitech.net>
## 
## Started on  Mon Jun  2 13:34:32 2014 Sergen Tanguc
## Last update Sun Jun  8 20:58:31 2014 Sergen Tanguc
##

CC		=	gcc

CFLAGS		=	-W -Werror -Wall

CFLAGS		+=	`pkg-config --cflags gtk+-2.0`

LDFLAGS		=	`pkg-config --libs gtk+-2.0`

RM		=	rm -f

NAME		= 	Raytool

SRCS		= 	destroy_win.c	\
			text_save.c	\
			edit_func.c	\
			generation.c	\
			aff_img.c	\
			path.c		\
			box.c		\
			text.c		\
			scrol.c		\
			button.c	\
			spin_button.c	\
			init.c		\
			main.c

OBJS		= 	$(SRCS:.c=.o)

all: 			rt

rt: 			$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean: 		clean
			$(RM) $(NAME)

re: 			fclean all
