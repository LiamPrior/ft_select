# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprior <lprior@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 13:00:31 by lprior            #+#    #+#              #
#    Updated: 2018/05/13 19:03:10 by lprior           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_select.c ft_nodes.c ft_terminal.c ft_tools.c

FLAGS = -lncurses

NAME = ft_select

LIBFT = libft

all: $(NAME)

$(NAME):
	@echo "\033[32mCompiling source files\033[0m"
	@make -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) -L$(LIBFT) -lft -o $(NAME)

clean:
	@echo "\033[32mCleaning up\033[0m"
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "\033[32mFull clean\033[0m"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all re