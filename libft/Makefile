# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspiess <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 20:10:51 by lspiess           #+#    #+#              #
#    Updated: 2019/09/12 14:22:18 by lspiess          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = .:.:string

SRCNAMES = \
ft_lstdelone.c ft_strcmp.c ft_appnchar.c ft_lstinsert.c \
ft_strcpy.c ft_appnchar_inplace.c ft_lstiter.c ft_strdup.c ft_appnstr.c \
ft_lstmap.c ft_strequ.c ft_appnstr_inplace.c ft_lstnew.c ft_striter.c \
ft_appstr.c ft_lstpop.c ft_striteri.c ft_appstr_inplace.c ft_malloc_bzero.c \
ft_strjoin.c ft_atoa_base.c ft_malloc_memset.c ft_strjoin_free.c ft_atoi.c \
ft_memccpy.c ft_strlcat.c ft_bigadd.c ft_memchr.c ft_strlcat_free.c \
ft_bigcompare.c ft_memcmp.c ft_strlen.c ft_bigmul.c ft_memcpy.c ft_strmap.c \
ft_bigpow.c ft_memdel.c ft_strmapi.c ft_bigsub.c ft_memmove.c ft_strncat.c \
ft_bigutils.c ft_memset.c ft_strncmp.c ft_bigutils_mul.c ft_mmalloc.c \
ft_strncpy.c ft_bzero.c ft_prependnstr.c ft_strndup.c ft_elem_len.c \
ft_prependstr.c ft_strnequ.c ft_free.c ft_prepnchar.c ft_strnjoin.c \
ft_frees.c ft_prepnchar_inplace.c ft_strnstr.c ft_is_escapable.c \
ft_prepnstr_inplace.c  ft_strrchr.c ft_isalnum.c ft_printmem.c ft_strrev.c \
ft_isalpha.c ft_putchar.c ft_strsplit.c ft_isascii.c ft_putchar_fd.c \
ft_strstr.c ft_isdigit.c ft_putendl.c ft_strsub.c ft_isprint.c \
ft_putendl_fd.c ft_strtrim.c ft_isqrt.c ft_putnbr.c ft_tolower.c ft_istrlen.c \
ft_putnbr_fd.c ft_toupper.c ft_itoa.c ft_putstr.c ft_ulltoa.c ft_lltoa.c \
ft_putstr_fd.c ft_ulltoa_base.c ft_lltoa_base.c ft_strcapitalize.c \
ft_ulltoa_base_caps.c ft_lstadd.c ft_strcat.c get_next_line.c ft_lstdel.c \
ft_strchr.c ft_lstdelnode.c ft_strclr.c ft_nblen.c

OBJSNAMES = $(SRCNAMES:.c=.o)
OBJSPATH = objects_libft
OBJS = $(addprefix $(OBJSPATH)/,$(OBJSNAMES))

CC = gcc
ifdef f
	ifeq ($(f), no)
		CFLAGS=
	endif
	ifeq ($(f), debug)
		CFLAGS = -Wall -Wextra -ggdb3
	endif
else
	CFLAGS = -Wall -Wextra -Werror
endif

#\033[nK => K pour effacer les n premiers caractères
#Ne rien mettre ou mettre 0 efface toute la ligne
#​
#\033[nA => A pour placer le curseur n lignes plus haut.
#Ne rien mettre ou mettre 0 laisse le curseur sur sa position actuelle

# -lft pour indique au'il y a une lib statique, et -L<libname(without .a)>
#  pour ajouter

HEADERSNAMES = libft.h
HEADERSPATH = ../includes_ls
HEADERS = $(addprefix $(HEADERSPATH)/, $(HEADERSNAMES))

NAME = libft.a

GREEN = \033[32m
CLEAR = \033[0m
CLRLINE = \033[K
BTOLINE = \033[A

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(CLRLINE)$(GREEN)libft.a$(CLEAR)"

$(OBJSPATH)/%.o : %.c $(HEADERS)
	@mkdir $(OBJSPATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I $(HEADERSPATH) -o $@ -c $<
	@echo "$<$(CLRLINE)$(BTOLINE)"

clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJSPATH) 2> /dev/null || true

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
