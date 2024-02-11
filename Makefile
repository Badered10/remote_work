# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:58:29 by baouragh          #+#    #+#              #
#    Updated: 2024/02/11 02:45:37 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C libft
		
SRCS =  	bonus/commands/add_slash_cmd.c  bonus/commands/check_cmds.c bonus/commands/get_command.c bonus/commands/get_env_paths.c bonus/commands/get_fullpath.c \
			bonus/tools/check_split.c bonus/tools/dup_2.c bonus/tools/free_double.c bonus/tools/print_err.c bonus/tools/strings_count.c \
			bonus/fds_manage/creat_infile_fd.c bonus/fds_manage/creat_outfile_fd.c bonus/fds_manage/open_fds.c \
 			bonus/child/call_execve.c bonus/child/child.c bonus/child/fd_duper.c bonus/child/open_pipe.c \
			bonus/here_doc/here_doc.c bonus/here_doc/open_fds_doc.c \

OBJS = $(SRCS:.c=.o)

CP = cp libft/libft.a ./$(NAME)

NAME = pipex.a

MADANTORY = pipex

BONUS_PIPEX = pipex_bonus

all: $(MADANTORY)

$(MADANTORY): $(OBJS)
	$(MAKE)
	$(CP)
	ar -rcs $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) pipex.c -o $(MADANTORY)
	
bonus: $(BONUS_PIPEX)

$(BONUS_PIPEX): $(OBJS)
	$(MAKE)
	$(CP)
	ar -rcs $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) pipex_bonus.c -o $(BONUS_PIPEX)

clean:
	$(MAKE) clean
	rm -f $(OBJS) $(OBJS)

fclean: clean
	$(MAKE) fclean
	rm -rf $(NAME) $(MADANTORY) $(BONUS_PIPEX)

re: fclean all
 
.PHONY: all clean fclean re