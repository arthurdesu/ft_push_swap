SRCS		=	push_swap.c \
	helper/ft_split.c \
	helper/ft_putstr_fd.c \
	helper/ft_strlen.c \
	helper/ft_atoi.c \
	helper/ft_strncmp.c \
	helper/ft_lstnew.c \
	helper/ft_lstclear.c \
	helper/ft_lstadd_back.c \
	helper/ft_is_flag.c \
	helper/ft_moves.c \
	helper/ft_lstsize.c \
	helper/ft_set_index.c \
	helper/ft_stack_fill.c \
	helper/ft_flag.c \
	helper/ft_sort.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_utils.c \
	ft_printf/ft_write.c \
	sort_algorithms/chunk_sort.c \
	sort_algorithms/bubble_sort.c \
	sort_algorithms/radix_sort.c 

OBJ			=	$(SRCS:.c=.o)
NAME		=	push_swap

all: $(NAME)

$(NAME): $(OBJ)
	@cc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

%.o: %.c 
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
