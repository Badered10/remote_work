# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:58:29 by baouragh          #+#    #+#              #
#    Updated: 2024/02/11 02:08:20 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C libft

SRCS = mandatory/
		
BONUS_S =  	bonus/commands/add_slash_cmd.c  bonus/commands/check_cmds.c bonus/commands/get_command.c bonus/commands/get_env_paths.c bonus/commands/get_fullpath.c \
			bonus/tools/check_split.c bonus/tools/dup_2.c bonus/tools/free_double.c bonus/tools/print_err.c bonus/tools/strings_count.c \
			bonus/Multiple_pipes/creat_infile_fd.c bonus/Multiple_pipes/creat_outfile_fd.c bonus/Multiple_pipes/open_fds.c \
 			bonus/child/call_execve.c bonus/child/child.c bonus/child/fd_duper.c bonus/child/open_pipe.c \
			bonus/here_doc/here_doc.c bonus/here_doc/open_fds_doc.c \

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
	$(CC) $(CFLAGS) $(NAME) pipex_bonus.c -o $(PROGRAMME_NAME)
	
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