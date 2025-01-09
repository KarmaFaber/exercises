#◉────▣───▢◇▢───▣────◉•◉───▣───▢   Colors:   ▢───▣───◉•◉───▣────▢◇▢───▣───◉#

BLACK   := \033[0;30m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m

CURRENT_COLOR := \033[0;34m
RESET   := \033[0m

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Variables:   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

NAME        := 14_ejerc
CC          := cc
CFLAGS      := -Wall -Wextra -Werror 
RM          := rm -rf

VALGRIND	:= valgrind --leak-check=full --show-leak-kinds=all -s

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Libft Variables ▢───▣───◉•◉───▣───▢◇▢───▣──◉#

LIBFT_DIR	:= libft/
LIBFT		:= $(LIBFT_DIR)/libft.a
INCLUDES_LIBFT := -I$(LIBFT_DIR)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ push_swap srcs ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

14_EJERC_SRCS	:= main.c utils.c read_comm_stdout.c read_comm_file.c count_lines_file_outputfile.c count_lines_file_stdout.c encript_text.c cat_sim_stdout.c

14_EJERC_OBJS	:= $(14_EJERC_SRCS:.c=.o)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢     rules      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(14_EJERC_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(14_EJERC_OBJS) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT) 
	@echo "$(CURRENT_COLOR) $(NAME) created.\n$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_LIBFT) -c $< -o $@ 

clean:
	$(RM) $(14_EJERC_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(CURRENT_COLOR)All object files have been cleaned.\n$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(CURRENT_COLOR) $(NAME) and libft.a: have been cleaned.\n$(RESET)"

re: fclean all

#◉───▣───▢◇▢───▣───◉•◉───▣───▢    Valgrind    ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

valgrind: all

	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──Running Valgrind..──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──$(RESET)"a
	@-$(VALGRIND) ./$(NAME)
	@echo "$(CURRENT_COLOR)➵⤐╌╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣── Valgrind completed. Check valgrind_output.log for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"
	

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Phony targets  ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

.PHONY: all clean fclean re valgrind 