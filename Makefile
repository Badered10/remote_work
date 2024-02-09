# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:58:29 by baouragh          #+#    #+#              #
#    Updated: 2024/02/09 22:36:17 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C libft

SRCS = mandatory/
		
BONUS_S = bonus_srcs/call_execve.c bonus_srcs/check_paths.c bonus_srcs/child.c \
		bonus_srcs/cmd_path.c bonus_srcs/creat_infile_fd.c bonus_srcs/creat_outfile_fd.c\
		bonus_srcs/dup_2.c bonus_srcs/fd_duper.c bonus_srcs/free_double.c \
		bonus_srcs/get_command.c bonus_srcs/get_env_paths.c bonus_srcs/here_doc.c\
		bonus_srcs/open_fds.c bonus_srcs/open_fds_doc.c bonus_srcs/open_pipe.c \
		bonus_srcs/print_err.c bonus_srcs/check_cmds_outfile.c bonus_srcs/strings_count.c \
		bonus_srcs/check_split.c

OBJS = $(SRCS:.c=.o)
BONUS_O = $(BONUS_S:.c=.o)

CP = cp libft/libft.a ./$(NAME)

NAME = pipex.a

PROGRAMME_NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE)
	$(CP)
	ar -rcs $(NAME) $(OBJS)
	
bonus: $(PROGRAMME_NAME)

$(PROGRAMME_NAME): $(BONUS_O)
	$(MAKE)
	$(CP)
	ar -rcs $(NAME) $(BONUS_O)
	$(CC) $(CFLAGS) $(NAME) pipex_bonus.c -o $(PROGRAMME_NAME)

clean:
	$(MAKE) clean
	rm -f $(OBJS) $(BONUS_O)

fclean: clean
	$(MAKE) fclean
	rm -rf $(NAME) $(PROGRAMME_NAME)

re: fclean all
 
.PHONY: all clean fclean re