# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspiess <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 20:10:51 by lspiess           #+#    #+#              #
#    Updated: 2020/07/04 10:55:01 by lspiess          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = .:.:srcs

SRCNAMES = main.c ft_ls.c ft_lsutils.c ft_lsdata_utils.c ft_lsformat_utils.c \
ft_lsnode_utils.c ft_lstree_addnode.c ft_lstree_print.c ft_lsrec_utils.c \
ft_lstree_freetree.c ft_lsprintutils.c ft_lsprintblocks.c ft_lserr.c \
ft_lsdatamajor.c ft_lstree_avl.c ft_lsopencurrentdir_seekfile.c \
ft_lsprintutilstwo.c

OBJSNAMES = $(SRCNAMES:.c=.o)
OBJSPATH = objs
OBJS = $(addprefix $(OBJSPATH)/,$(OBJSNAMES))

#ADD -WERROR to CFLAGS ELSE BEFORE PUSHING
CC = gcc
ifdef f
	ifeq ($(f), n)
		CFLAGS =
	endif
	ifeq ($(f), d)
		CFLAGS = -Wall -Wextra -ggdb3 -fsanitize=address
	endif
else
	CFLAGS =
endif

HEADERNAMES = libft.h ft_ls.h
HEADERSPATH = includes_ls
HEADERS = $(addprefix $(HEADERSPATH)/, $(HEADERNAMES))

#RENAME ft_ls
NAME = ft_ls

LDFLAG = -Llibft
LDLIB = -lft

GREEN = \033[32m
CLEAR = \033[0m
CLRLINE = \033[K
BTOLINE = \033[A

all : $(NAME)

$(NAME) ::
	@cd libft && $(MAKE)

$(NAME) :: $(OBJS)
	@$(CC) $(CFLAGS) -I $(HEADERSPATH) -o $@ $^ $(LDFLAG) $(LDLIB)
	@echo "$(CLRLINE)$(GREEN)ft_ls$(CLEAR)"

$(OBJSPATH)/%.o : %.c $(HEADERS)
	@mkdir $(OBJSPATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I $(HEADERSPATH) -o $@ -c $<
	@echo "$<$(CLRLINE)$(BTOLINE)"

clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJSPATH) 2> /dev/null || true
	@cd libft && make clean

fclean : clean
	@rm -f $(NAME)
	@cd libft && make fclean

re : fclean all

.PHONY : all, clean, fclean, re
