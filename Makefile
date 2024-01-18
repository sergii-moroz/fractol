NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make

MLX_DIR = minilibx
MLX = mlx
MLX_LIB = ./$(MLX_DIR)/lib$(MLX).a

FT_DIR = libft
FT = ft
FT_LIB = ./$(FT_DIR)/lib$(FT).a

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
		utils_hooks_1.c \
		utils_hooks_2.c \
		utils_hilbert_curve.c

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone https://github.com/pasqualerossi/minilibx.git $(MLX_DIR) && \
		$(MAKE) -C $(MLX_DIR); \
	fi

$(FT_LIB):
	cd ./$(FT_DIR) && $(MAKE) bonus && $(MAKE) clean

$(NAME): $(FT_LIB) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJS_DIR):
	mkdir $@

$(OBJS_DIR)/%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	cd ./$(FT_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
