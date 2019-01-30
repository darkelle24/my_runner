##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## infin_add
##

NAME	=		my_runner

SRC		=		src/jeu/destroy.c					\
				src/jeu/init_jeu_2.c				\
				src/jeu/init_jeu_1.c				\
				src/jeu/jeu_1.c						\
				src/jeu/jeu_2.c						\
				src/jeu/jeu_3.c						\
				src/jeu/jeu_4.c						\
				src/jeu/jeu_5.c						\
				src/jeu/jeu_6.c						\
				src/jeu/jeu_7.c						\
				src/jeu/jeu_8.c						\
				src/jeu/jeu_9.c						\
				src/jeu/jeu_10.c					\
				src/fc_other/calcultemp.c			\
				src/fc_other/color_1.c				\
				src/fc_other/color_2.c				\
				src/fc_other/createarray.c			\
				src/fc_other/createarrayspe.c		\
				src/fc_other/create_object.c		\
				src/fc_other/create_rect.c			\
				src/fc_other/create_speed.c			\
				src/fc_other/create_text.c			\
				src/fc_other/create_vect.c			\
				src/fc_other/create_window.c		\
				src/fc_other/destroy_object.c		\
				src/fc_other/destroy_texturearray.c	\
				src/fc_other/lecturescore.c			\
				src/fc_other/longtochar.c			\
				src/fc_other/longtocharspe.c		\
				src/fc_other/move_objectx.c			\
				src/fc_other/my_put_nbr.c			\
				src/fc_other/my_rev_list.c			\
				src/fc_other/my_rev_listspe.c		\
				src/fc_other/my_strlen.c			\
				src/fc_other/save.c					\
				src/loosescreen/loosescreen_1.c		\
				src/loosescreen/loosescreen_2.c		\
				src/loosescreen/loosescreen_3.c		\
				src/menu/menu_1.c					\
				src/menu/menu_2.c					\
				src/mapgame.c

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-ggdb

all:	$(NAME)

$(NAME):		$(OBJ)
		gcc -o $(NAME) $(OBJ) -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

spe:		$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

tests_run:
		gcc -o test ../tests/testct.c cat.c -lcriterion
		./test

##gcc -ggdb src/createstruct.c src/destjeufc.c src/initjeufc.c src/mapgame.c -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio