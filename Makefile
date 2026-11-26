NAME		= push_swap
NAME_BNS	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRC_MAIN	= push_swap.c

SRCS		= sort_algorithms/selection_sort.c \
			sort_algorithms/chunk_sort.c \
			sort_algorithms/radix_sort.c \
			helper/ft_atoi.c \
			helper/ft_flag.c \
			helper/ft_lstadd_back.c \
			helper/ft_lstclear.c \
			helper/ft_lstnew.c \
			helper/ft_lstsize.c \
			helper/ft_putstr_fd.c \
			helper/ft_set_index.c \
			helper/ft_sort.c \
			helper/is_sort.c \
			helper/ft_split.c \
			helper/ft_stack_fill.c \
			helper/ft_strlen.c \
			helper/ft_strncmp.c \
			helper/ft_sqrt.c \
			helper/in_range.c \
			helper/max_pos.c \
			moves/ft_push.c \
			moves/ft_swap.c \
			moves/ft_rotate.c \
			moves/ft_reverce_rotate.c \
			ft_dprintf/ft_printaddress.c \
			ft_dprintf/ft_printchar.c \
			ft_dprintf/ft_dprintf.c \
			ft_dprintf/ft_printnbr_base.c \
			ft_dprintf/ft_printstr.c

SRCS_BNS	= bonus/checker.c \
			bonus/gnl/get_next_line.c \
			bonus/gnl/get_next_line_utils.c \
			bonus/moves/bonus_push.c \
			bonus/moves/bonus_swap.c \
			bonus/moves/bonus_rotate.c \
			bonus/moves/bonus_reverce_rotate.c \
			bonus/helper/ft_ops.c \
			bonus/helper/bonus_lstadd_back.c \
			bonus/helper/bonus_lstclear.c \
			bonus/helper/bonus_lstnew.c

HEADERS		= push_swap.h \
			ft_dprintf/ft_dprintf.h

HEADERS_BNS	= bonus/checker.h

OBJ_MAIN	= $(SRC_MAIN:.c=.o)
OBJ			= $(SRCS:.c=.o)
OBJ_BNS		= $(SRCS_BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_MAIN) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADERS) $(HEADERS_BNS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_MAIN) $(OBJ) $(OBJ_BNS)

fclean: clean
	@$(RM) $(NAME) $(NAME_BNS)

re: fclean all

.PHONY: all bonus clean fclean re