# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:58:29 by baouragh          #+#    #+#              #
#    Updated: 2024/02/12 17:11:37 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C libft

COMMON_SRCS = bonus/commands/add_slash_cmd.c  bonus/commands/check_cmds.c bonus/commands/get_command.c bonus/commands/get_env_paths.c bonus/commands/get_fullpath.c \
			bonus/tools/check_split.c bonus/tools/dup_2.c bonus/tools/free_double.c bonus/tools/print_err.c bonus/tools/strings_count.c \
			bonus/fds_manage/create_infile_fd.c bonus/fds_manage/create_outfile_fd.c bonus/fds_manage/open_fds.c \
 			bonus/child/call_execve.c bonus/child/child.c bonus/child/fd_duper.c bonus/child/open_pipe.c \
			bonus/here_doc/here_doc.c bonus/here_doc/open_fds_doc.c
		
SRCS_MANDATORY = $(COMMON_SRCS) mandatory_srcs/pipex.c	
SRCS_BONUS = $(COMMON_SRCS) bonus/pipex_bonus.c

OBJS_M = $(SRCS_MANDATORY:.c=.o)
OBJS_B = $(SRCS_BONUS:.c=.o)

CP = cp libft/libft.a ./$(LIB)

LIB = lib/pipex.a

NAME = pipex

all: $(OBJS_M)
	@$(MAKE)
	@$(CP)
	@ar -rcs $(LIB) $(OBJS_M)
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME)

bonus: $(OBJS_B)
	@$(MAKE)
	@$(CP)
	@ar -rcs $(LIB) $(OBJS_B)
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	@$(MAKE) clean
	@rm -f $(OBJS_M) $(OBJS_B)

fclean: clean
	@$(MAKE) fclean
	@rm -rf $(LIB) $(NAME) 

re: fclean all

clear:
	clear
	
m: all clean clear

b: bonus clean clear
 
.PHONY: all clean fclean re
.SECONDARY : $(OBJS_M) $(OBJS_S)