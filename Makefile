NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS =
RM = rm -rf

MLX_DIR = minilibx
MLX = mlx

FT_DIR = libft
FT = ft

LIBS =	-L$(FT_DIR) -l$(FT) \
		-L$(MLX_DIR) -l$(MLX) -framework OpenGL -framework AppKit

INCS = fractol.h
SRCS =	main.c \
		init.c \
		render.c \
		hooks.c \
		fractals.c \
		ft_atof.c \
		ft_isvalid_float.c \
		ft_isvalid_int.c \
		utils_colors.c \
		utils_color_interpol.c \
		utils_complex_math.c \
		utils_check_input.c \
		utils_math.c \
		utils_errors.c \
		utils_settings.c
#		leaks_checker.c
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJS_DIR):
	mkdir $@

$(OBJS_DIR)/%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./fractol 2 -0.6 0.6

.PHONY: all clean fclean re
