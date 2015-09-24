##
## Makefile for Makefile in /home/aubess_t/work/PSU_2014_philo/gui
## 
## Made by aubess_t aubess_t
## Login   <aubess_t@epitech.net>
## 
## Started on  Sun Mar  1 21:47:22 2015 aubess_t aubess_t
## Last update Sun Mar  1 21:47:29 2015 aubess_t aubess_t
##

NAME		= philo

CC		= cc

DIR		= src/

CFLAGS		= -lpthread -lSDL -lSDLmain -lSDL_ttf -lm -W -Wall -Werror -Wextra

SRC		= $(DIR)main.c \
		  $(DIR)interface_debug.c \
		  $(DIR)interface_framerate.c \
		  $(DIR)interface_render.c \
		  $(DIR)interface_render_fct.c \
		  $(DIR)interface_SDL_fct.c \
		  $(DIR)interface_line_fct.c \
		  $(DIR)interface_circle_fct.c \
		  $(DIR)interface_rect_fct.c \
		  $(DIR)interface_text_fct.c \
		  $(DIR)interface_SDL_init.c \
		  $(DIR)interface_init.c \
		  $(DIR)interface_poll_event.c \
		  $(DIR)interface_process.c \
		  $(DIR)interface_flip.c \
		  $(DIR)interface_clear_all.c \
		  $(DIR)philosophes_meeting.c \
		  $(DIR)philosophes_init.c

OBJ		= $(SRC:.c=.o)

RM		= rm -f

all		: $(NAME)

$(NAME)		: $(OBJ)
		  @$(CC) -o $(NAME) $(SRC) $(CFLAGS)
clean		:
		  @$(RM) $(OBJ)
		  @echo "[31;01mDeleting file...[00m"

fclean		: clean
		  @$(RM) $(NAME)
		  @echo "[31;01mDeleting binary...[00m"

re		: fclean all

.PHONY		: all clean fclean re
