# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:33:35 by jgoncalv          #+#    #+#              #
#    Updated: 2016/12/16 16:14:02 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, norme

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -L.

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = libft/ft_putchar.c\
		libft/ft_putchar_fd.c\
		libft/ft_putstr.c\
		libft/ft_putnstr.c\
		libft/ft_putstr_fd.c\
		libft/ft_putnbr.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putendl.c\
		libft/ft_putendl_fd.c\
		libft/ft_memset.c\
		libft/ft_bzero.c\
		libft/ft_memcpy.c\
		libft/ft_memccpy.c\
		libft/ft_memmove.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_memalloc.c\
		libft/ft_memdel.c\
		libft/ft_memjoin.c\
		libft/ft_memjoinf.c\
		libft/ft_strlen.c\
		libft/ft_strdup.c\
		libft/ft_strcpy.c\
		libft/ft_strncpy.c\
		libft/ft_strcat.c\
		libft/ft_strncat.c\
		libft/ft_strlcat.c\
		libft/ft_strchr.c\
		libft/ft_strrchr.c\
		libft/ft_strstr.c\
		libft/ft_strnstr.c\
		libft/ft_strcmp.c\
		libft/ft_strncmp.c\
		libft/ft_strnew.c\
		libft/ft_strdel.c\
		libft/ft_strclr.c\
		libft/ft_striter.c\
		libft/ft_striteri.c\
		libft/ft_strmap.c\
		libft/ft_strmapi.c\
		libft/ft_strequ.c\
		libft/ft_strnequ.c\
		libft/ft_strsub.c\
		libft/ft_strjoin.c\
		libft/ft_strtrim.c\
		libft/ft_strsplit.c\
		libft/ft_strtoupper.c\
		libft/ft_atoi.c\
		libft/ft_itoa.c\
		libft/ft_isalpha.c\
		libft/ft_isdigit.c\
		libft/ft_isalnum.c\
		libft/ft_isascii.c\
		libft/ft_isprint.c\
		libft/ft_toupper.c\
		libft/ft_tolower.c\
		libft/ft_lstnew.c\
		libft/ft_lstdelone.c\
		libft/ft_lstdel.c\
		libft/ft_lstadd.c\
		libft/ft_lstiter.c\
		libft/ft_lstmap.c\
		libft/ft_lstadd_end.c\
		libft/ft_realloc.c\
		libft/ft_tabnew.c\
		libft/ft_tablen.c\
		libft/ft_realloc_tab.c\
		libft/ft_uitoa.c\
		libft/ft_uitoa_base.c\
		libft/ft_putwchar.c\
		libft/ft_putwstr.c\
		libft/ft_wstrlen.c\
		libft/ft_wcharlen.c\
		printf/ft_printf.c\
		printf/ft_printf_check.c\
		printf/ft_printf_modifier.c\
		printf/ft_printf_uitoa_base.c\
		printf/ft_printf_itoa.c\
		printf/ft_printf_s.c\
		printf/ft_printf_percent.c\
		printf/ft_printf_c.c\
		printf/ft_printf_ws.c\
		printf/ft_printf_wc.c\
		printf/ft_printf_p.c\
		printf/ft_printf_dioux.c\
		libft/ft_putnwstr.c\
		gnl/get_next_line.c\

AR = ar rc

CPPFLAGS = -I include

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "made " $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(dir $(OBJ)) 2> /dev/null
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "clean " $(NAME)

fclean: clean
	@rm -f $(NAME)
	@echo "fclean " $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)
