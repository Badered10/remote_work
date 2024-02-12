# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:58:29 by baouragh          #+#    #+#              #
#    Updated: 2024/02/11 12:21:24 by baouragh         ###   ########.fr        #
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

CP = cp libft/libft.a ./$(NAME)

NAME = lib/pipex.a

MADANTORY = pipex

BONUS_PIPEX = pipex_bonus

all: $(MADANTORY)

$(MADANTORY): $(OBJS_M)
	@$(MAKE)
	@$(CP)
	@ar -rcs $(NAME) $(OBJS_M)
	@$(CC) $(CFLAGS) $(NAME) -o $(MADANTORY)
	
bonus: $(BONUS_PIPEX)

$(BONUS_PIPEX): $(OBJS_B)
	@$(MAKE)
	@$(CP)
	@ar -rcs $(NAME) $(OBJS_B)
	@$(CC) $(CFLAGS) $(NAME) -o $(BONUS_PIPEX)

clean:
	@$(MAKE) clean
	@rm -f $(OBJS_M) $(OBJS_B)

fclean: clean
	@$(MAKE) fclean
	@rm -rf $(NAME) $(MADANTORY) $(BONUS_PIPEX)

re: fclean all
 
.PHONY: all clean fclean re
.SECONDARY : $(OBJS_M) $(OBJS_S)