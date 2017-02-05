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

SRC_NAME = put/ft_putchar.c\
		put/ft_putchar_fd.c\
		put/ft_putstr.c\
		put/ft_putnstr.c\
		put/ft_putstr_fd.c\
		put/ft_putnbr.c\
		put/ft_putnbr_fd.c\
		put/ft_putendl.c\
		put/ft_putendl_fd.c\
		mem/ft_bzero.c\
		mem/ft_memset.c\
		mem/ft_memcpy.c\
		mem/ft_memccpy.c\
		mem/ft_memmove.c\
		mem/ft_memchr.c\
		mem/ft_memcmp.c\
		mem/ft_memalloc.c\
		mem/ft_memdel.c\
		mem/ft_memjoin.c\
		mem/ft_memjoinf.c\
		str/ft_strlen.c\
		str/ft_strdup.c\
		str/ft_strcpy.c\
		str/ft_strncpy.c\
		str/ft_strcat.c\
		str/ft_strncat.c\
		str/ft_strlcat.c\
		str/ft_strchr.c\
		str/ft_strrchr.c\
		str/ft_strstr.c\
		str/ft_strnstr.c\
		str/ft_strcmp.c\
		str/ft_strncmp.c\
		str/ft_strnew.c\
		str/ft_strdel.c\
		str/ft_strclr.c\
		str/ft_striter.c\
		str/ft_striteri.c\
		str/ft_strmap.c\
		str/ft_strmapi.c\
		str/ft_strequ.c\
		str/ft_strnequ.c\
		str/ft_strsub.c\
		str/ft_strjoin.c\
		str/ft_strtrim.c\
		str/ft_strsplit.c\
		str/ft_strtoupper.c\
		convert/ft_atoi.c\
		convert/ft_itoa.c\
		is/ft_isalpha.c\
		is/ft_isdigit.c\
		is/ft_isalnum.c\
		is/ft_isascii.c\
		is/ft_isprint.c\
		is/ft_toupper.c\
		is/ft_tolower.c\
		lst/ft_lstnew.c\
		lst/ft_lstdelone.c\
		lst/ft_lstdel.c\
		lst/ft_lstadd.c\
		lst/ft_lstiter.c\
		lst/ft_lstmap.c\
		lst/ft_lstadd_end.c\
		str/ft_realloc.c\
		tab/ft_tabnew.c\
		tab/ft_tablen.c\
		tab/ft_realloc_tab.c\
		convert/ft_uitoa.c\
		convert/ft_uitoa_base.c\
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
		wchar/ft_wstrlen.c\
		wchar/ft_wcharlen.c\
		wchar/ft_putwchar.c\
		wchar/ft_putwstr.c\
		wchar/ft_putnwstr.c\
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
