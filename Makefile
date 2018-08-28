# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabouche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 17:01:34 by mabouche          #+#    #+#              #
#    Updated: 2018/06/19 17:01:35 by mabouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS = 	#-fsanitize=address

# Default rule
DEFRULE =	all

# Binary
NAME =		push_swap
NAME_2 = 	checker
DST =

# Directories
SRCDIR =	srcs
SRCDIR_2 =	srcs_2
OBJDIR =	objs
OBJDIR_2 =	objs_2
INCDIR =	inc/

# Sources
SRC = \
			push_swap.c\
			rotate.c\
			r_rotate.c\
			swap.c\
			push.c\
			find_med.c\
			tri_three.c\
			tri_five.c\
			tri_five_2.c\
			insertion_sort.c\
			insertion_sort_2.c\
			quicksort.c\
			util.c\
			ope_list.c\
			sorts.c\
			check_pars.c\

SRC_2 = \
			checker.c\
			checker_2.c\
			push.c\
			r_rotate.c\
			rotate.c\
			swap.c\
			util.c\
			ope_list.c\
			check_pars.c\

OBJ =		$(SRC:.c=.o)
OBJ_2 = 	$(SRC_2:.c=.o)

# Prefixes
LIBFT =		-Llibft/ -lft


# Paths foreach
LIBP =		$(addprefix -L, $(LIBNAME)/)
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJP_2 =		$(addprefix $(OBJDIR_2)/, $(SRC_2:.c=.o))
INCP =		$(foreach dir, $(INCDIR), -I$(dir))

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #
# RULES

# Main rules
default:
	@echo -e "$(LOG_BOLD)Default execution: rule $(DEFRULE)$(LOG_NOCOLOR)"
	@make $(DEFRULE)
	@echo -e "$(LOG_BOLD)Execution finished     $(LOG_NOCOLOR)ヽ(ヅ)ノ"

all: libftcomp $(OBJDIR) $(NAME) $(OBJDIR_2) $(NAME_2)

re: fclean all

# Compilation rules
libftcomp:
	@make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -o $@ $^ $(INCP) $(LIBFT)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR) compiled........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJDIR_2)/%.o: $(SRCDIR_2)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME_2)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR_2):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME_2)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJDIR_2)

$(NAME_2): $(OBJP_2)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME_2)$(LOG_NOCOLOR)....................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -o $@ $^ $(INCP) $(LIBFT)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME_2)$(LOG_NOCOLOR) compiled........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"


.PHONY: fclean clean glu

clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME_2)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR_2)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean libft$(LOG_NOCOLOR)"
	@make clean -C libft/

fclean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean libft$(LOG_NOCOLOR)"
	@make fclean -C libft/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME_2)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJDIR_2)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)
	@rm -f $(NAME_2)

glu: re clean
