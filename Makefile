SRCS_FILES			= 	pipex.c command.c path.c child_process.c init_data.c \
						finish_data.c main.c validate_command.c validate_args.c \
						parser.c validate_fd_files.c exec_children_process.c \
						load_data.c

SRCS_FILES_BONUS	= 	pipex_bonus.c command_bonus.c path_bonus.c child_process_bonus.c init_data_bonus.c \
						finish_data_bonus.c main_bonus.c validate_command_bonus.c validate_args_bonus.c \
						parser_bonus.c validate_bonus.c exec_children_process_bonus.c \
						load_data_bonus.c here_doc_bonus.c

SRCS_DIR			= sources

SRCS_DIR_BONUS		= sources_bonus

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

SRCS_BONUS			= $(addprefix $(SRCS_DIR_BONUS)/, $(SRCS_FILES_BONUS))

OBJS				= $(SRCS:.c=.o)

OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

LIBFT_DIR			= ./libs/libft

LIBFT				= ./libs/libft/libft.a

RM 					= rm -f

CC					= cc

CFLAGS 				= -Wall -Wextra -Werror -g

NAME				= pipex
NAME_BONUS			= pipex_bonus

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(OBJS)
					$(CC)  $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(OBJS_BONUS)
					$(CC)  $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):			
					$(MAKE) -C $(LIBFT_DIR)
					
clean:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft bonus