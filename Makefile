# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:58:29 by baouragh          #+#    #+#              #
#    Updated: 2024/02/07 15:59:03 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C libft

SRCS = 
		
BONUS_S = 

OBJS = $(SRCS:.c=.o)

BONUS_O = $(BONUS_S:.c=.o)

CP = cp libft/libft.a ./$(NAME)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(MAKE)
	$(CP)
	$(CC) $(CFLAGS) -c $(SRCS)
	
bonus: $(BONUS_O)

$(BONUS_O): $(BONUS_S)
	$(MAKE)
	$(CP)
	$(CC) $(CFLAGS) -c $(BONUS_S)
	ar -rcs $(NAME) $(BONUS_O)

clean:
	$(MAKE) clean
	rm -f $(OBJS) $(BONUS_O)

fclean: clean
	$(MAKE) fclean
	rm -rf $(NAME)

re: fclean all
 
.PHONY: all clean fclean re