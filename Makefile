SRCS		=	push_swap.c \
	sort_algorithms/bubble_sort.c \
	sort_algorithms/chunk_sort.c \
	sort_algorithms/radix_sort.c \
	helper/ft_atoi.c \
	helper/ft_flag.c \
	helper/ft_lstadd_back.c \
	helper/ft_lstclear.c \
	helper/ft_lstnew.c \
	helper/ft_lstsize.c \
	helper/ft_moves.c \
	helper/ft_putstr_fd.c \
	helper/ft_set_index.c \
	helper/ft_sort.c \
	helper/ft_split.c \
	helper/ft_stack_fill.c \
	helper/ft_strlen.c \
	helper/ft_strncmp.c \
	ft_printf/ft_printaddress.c \
	ft_printf/ft_printchar.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printnbr_base.c \
	ft_printf/ft_printstr.c

# SRCS_BNS = bonus/checker.c \
# 	bonus/gnl/get_next_line.c \
# 	bonus/gnl/get_next_line_utils.c \

OBJ			=	$(SRCS:.c=.o)
# OBJ_BNS		=	$(SRCS_BNS:.c=.o)
NAME		=	push_swap
# NAME_BNS	=	checker

all: $(NAME)

# bonus: $(NAME_BNS)

$(NAME): $(OBJ)
	@cc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

# $(NAME_BNS): $(OBJ_BNS)
# 	@cc -Wall -Wextra -Werror $(OBJ_BNS) -o $(NAME_BNS)

%.o: %.c push_swap.h ft_printf/ft_printf.h
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
