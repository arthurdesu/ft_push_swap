CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = main.c bubble_sort.c chunk_sort.c moves.c radix_sort.c \
		helper_func/adapt_algo.c  helper_func/call_bench.c  helper_func/compute_disorder.c  helper_func/ft_atoi.c  helper_func/ft_lstadd_back.c  \
		helper_func/ft_lstclear.c  helper_func/ft_split.c helper_func/ft_strncmp.c  \
		helper_func/init_stack_a.c  helper_func/select_flag.c  helper_func/update_index.c  helper_func/which_sort.c \
		helper_func/ft_strlen.c helper_func/ft_lstsize.c helper_func/ft_lstnew.c helper_func/ft_putstr_fd.c\
		ft_printf/ft_printf.c ft_printf/ft_printchar.c ft_printf/ft_printnbr_base.c ft_printf/ft_printstr.c ft_printf/ft_printaddress.c

OBJ = $(SRC:.c=.o)
LIBHELP = libhelp.a
HEADERS = push_swap.h ft_printf/ft_printf.h
NAME = push_swap
SRC_BONUC = bonus/checker.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c
B_HEADERS = $(HEADERS) bonus/checker.h
b_program = checker

All: $(LIBHELP) $(NAME)

$(LIBHELP): $(OBJ)
	@ar cr $(LIBHELP) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(LIBHELP) -o $@

bonus: $(b_program) $(LIBHELP)

$(b_program): $(SRC_BONUC) $(B_HEADERS)
	$(CC) $(CFLAGS) $(SRC_BONUC) $(LIBHELP) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(LIBHELP)

re: fclean all

.PHONY: clean