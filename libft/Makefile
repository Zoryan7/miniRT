include ../animation/assets.mk
include ../animation/dragon.mk
include ../animation/rocket.mk
include ../animation/train.mk

CC= cc

CFLAGS= -Ofast -Wall -Werror -Wextra -I ./ -g

NAME= libft.a

OBJ_DIR:= objs

SOURCES= libc/ft_atoi.c libc/ft_bzero.c libc/ft_calloc.c libc/ft_isalnum.c libc/ft_isalpha.c \
		libc/ft_isascii.c libc/ft_isdigit.c libc/ft_isprint.c mem/ft_memchr.c mem/ft_memcmp.c \
		mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c str/ft_strchr.c str/ft_strlcpy.c str/ft_strjoin_free.c\
		str/ft_strlcat.c str/ft_strlen.c str/ft_strncmp.c str/ft_strcmp.c str/ft_strnstr.c str/ft_strrchr.c  str/ft_strschr.c\
		libc/ft_tolower.c libc/ft_toupper.c libc/ft_strisdigit.c libc/ft_strisalpha.c libc/ft_strisalnum.c\
		str/ft_itoa.c str/ft_itoa_int.c str/ft_itoa_float.c str/ft_atol.c other/ft_putchar_fd.c other/ft_putendl_fd.c other/ft_putnbr_fd.c other/ft_putstr_fd.c other/ft_is_whitespace.c other/ft_reverse_bool.c \
		str/ft_split.c str/ft_strdup.c str/ft_strndup.c str/ft_striteri.c str/ft_strjoin.c str/ft_strmapi.c str/ft_clamp.c \
		str/ft_strtrim.c str/ft_substr.c str/ft_free_tab.c str/ft_len_split.c str/ft_split_whitespace.c str/ft_atof.c \
		chained_list/ft_lstadd_front.c chained_list/ft_lstlast.c chained_list/ft_lstnew.c chained_list/ft_lstsize.c chained_list/ft_lstdelone.c \
		chained_list/ft_lstclear.c chained_list/ft_lstiter.c chained_list/ft_lstmap.c chained_list/ft_lstadd_back.c \
		printf/ft_printf.c printf/ft_putchar.c printf/ft_putstr.c printf/ft_putnbr.c printf/ft_putunnbr.c \
		printf/ft_putupper_hexa.c printf/ft_putlower_hexa.c printf/ft_putvoid.c \
		math/ft_max.c math/ft_abs.c math/ft_min.c math/ft_vec_add.c math/ft_vec_sub.c  math/ft_max_vec.c math/ft_min_vec.c math/ft_vec_cross.c math/ft_vec_dot.c math/ft_vec_lenght.c \
		math/ft_normalize.c math/ft_vec_scale.c math/ft_vec_mult.c math/ft_vec_abs.c math/ft_absf.c math/ft_vec_sqrt.c math/ft_sign.c math/ft_signf.c \
		math/ft_vec_sign.c math/ft_vec_max.c math/ft_vec_divide.c math/ft_vec_min.c math/ft_vec_divide_vec.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		file/ft_len_file.c \

OBJECTS= $(SOURCES:%.c=$(OBJ_DIR)/%.o)

TOTAL_FILES := $(words $(SOURCES))
CURRENT_FILE = 0

define progress_bar
	@if [ $(CURRENT_FILE) -eq 0 ]; then printf "$(BLUE)$(GEAR) Compiling $(NAME) :$(RESET)\n"; fi
	@$(eval CURRENT_FILE=$(shell echo $$(( $(CURRENT_FILE) + 1 ))))
	@FILLED=$$(( $(CURRENT_FILE) * 20 / $(TOTAL_FILES) )); \
	EMPTY=$$(( 20 - FILLED )); \
	if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then \
		COLOR="$(GREEN)"; \
	else \
		COLOR="$(YELLOW)"; \
	fi; \
	printf "\r$${COLOR}["; \
	i=0; while [ $$i -lt $$FILLED ]; do printf "♥"; i=$$((i+1)); done; \
	i=0; while [ $$i -lt $$EMPTY ]; do printf " "; i=$$((i+1)); done; \
	printf "] %3d%%$(RESET)" $$(( $(CURRENT_FILE) * 100 / $(TOTAL_FILES) )); \
	if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then printf "\n"; fi
endef

all: $(NAME)

$(OBJ_DIR)/%.o: ./%.c	
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call progress_bar)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@$(eval CURRENT_FILE=0)
	@printf "$(RED)$(TRASH)  Removing objects ($(NAME))$(RESET)\n"
	@rm -rf $(OBJECTS)

fclean: clean
	@printf "$(RED)$(TRASH)  Removing binary  ($(NAME))$(RESET)\n"
	@rm -rf $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY : all clean fclean re