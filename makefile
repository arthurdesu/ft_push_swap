CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c bubble_sort.c chunk_sort.c moves.c radix_sort.c
HELPER = helper_func/adapt_algo.c  helper_func/call_bench.c  helper_func/compute_disorder.c  helper_func/ft_atoi.c  helper_func/ft_lstadd_back.c  \
		helper_func/ft_lstclear.c  helper_func/ft_split.c helper_func/ft_strncmp.c  \
		helper_func/init_stack_a.c  helper_func/select_flag.c  helper_func/update_index.c  helper_func/which_sort.c \
		helper_func/ft_strlen.c helper_func/ft_lstsize.c helper_func/ft_lstnew.c
OBJ = $(HELPER:.c=.o)
LIBHELP = libhelp.a
HEADERS = push_swap.h
NAME = push_swap

All: $(LIBHELP) $(NAME)

$(LIBHELP): $(OBJ)
	@ar cr $(LIBHELP) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) $(LIBHELP) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(LIBHELP)

re: fclean all

.PHONY: clean