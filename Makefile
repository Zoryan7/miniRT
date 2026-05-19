include animation/assets.mk
include animation/dragon.mk
include animation/loading.mk
include animation/rocket.mk
include animation/train.mk

LIB= libft/libft.a

MLX= minilibx-linux/libmlx.a

OBJ_DIR:= objs

CC = cc

CFLAGS = -Wall -g -Wextra -Werror 

SRCS_DIR = srcs
SRC_FILES = mini_rt.c \
			parsing/parsing.c parsing/parsing_utils.c parsing/parsing_utils_2.c parsing/parsing_utils_3.c parsing/parsing_utils_4.c parsing/dict.c \
			parsing/parsing_rt/parse_ambient.c parsing/parsing_rt/parse_camera.c parsing/parsing_rt/parse_file.c  parsing/initialize.c parsing/initialize_2.c parsing/parsing_rt/parse_triangle.c \
			parsing/parsing_rt/parse_light.c parsing/parsing_rt/parse_object.c parsing/parsing_rt/parse_object_utils.c parsing/parsing_rt/parsing_brightness.c  parsing/parsing_rt/parsing_color.c \
			parsing/parsing_rt/parsing_float.c parsing/parsing_rt/parsing_rt_utils.c parsing/parsing_rt/parsing_rt_utils_2.c parsing/parsing_rt/parse_object_specificities.c parsing/parsing_rt/parse_object_specificities_2.c parsing/parsing_rt/parse_texture.c\
			parsing/parsing_json/check_value.c parsing/parsing_json/check_value_2.c parsing/parsing_json/initialize_object.c parsing/parsing_json/initialize_object_2.c parsing/parsing_json/parse_ambient_json.c parsing/parsing_json/parse_texture_json.c\
			parsing/parsing_json/parse_camera_json.c parsing/parsing_json/parse_file_json.c parsing/parsing_json/parse_light_json.c parsing/parsing_json/parse_object_sphere_json.c \
			parsing/parsing_json/parse_object_plane_json.c  parsing/parsing_json/parse_object_cylinder_json.c \
			parsing/parsing_json/parse_object_cone_json.c parsing/parsing_json/parse_object_rounded_box_json.c parsing/parsing_json/parse_object_box_json.c parsing/parsing_json/parse_object_triangle_json.c \
			parsing/parsing_json/parse_value.c 	parsing/parsing_json/parse_value_2.c parsing/parsing_json/parsing_json_utils.c parsing/parsing_json/parsing_json_utils_2.c \
			bvh/bvh_utils.c bvh/bvh_utils_2.c bvh/bvh.c bvh/calcul_min.c bvh/calcul_max.c bvh/child_bvh.c bvh/global_node.c \
			event/ft_press.c event/ft_release.c event/ft_close.c event/mouse_hook.c event/mouse_move.c event/select_control.c event/select_general.c \
			event/change_info.c event/change_settings.c event/press_classic_2.c event/press_classic.c event/press_control.c event/press_general.c \
			event/small_menu_2.c event/small_menu_3.c event/small_menu_4.c event/small_menu_5.c \
			draw/ft_gui.c draw/ft_put_pixel.c draw/ft_crosshair.c draw/ft_atoa.c draw/ft_control_page_txt.c draw/ft_general_page_txt.c draw/ft_subpage_map.c draw/ft_subpage_res.c \
			render/render.c utils/utils.c render/get_pixel.c render/moov.c render/menu.c render/light.c render/moov_2.c render/inter_point_2.c render/bump.c render/render_core.c \
			render/multi_threading.c render/render_utils.c render/inter_point.c render/ray.c render/color.c render/calcul.c render/moov_3.c render/opti.c render/color_utils.c \
			intersection/intersection.c intersection/intersection_box.c intersection/intersection_bvh.c intersection/intersection_cone.c render/checkcorner.c intersection/init_cylinder.c\
			intersection/intersection_cylinder.c intersection/intersection_r_box.c intersection/intersection_r_box_2.c intersection/intersection_r_box_3.c intersection/intersection_bvh_2.c\
			threading/threading.c \
			uv/uv.c uv/uv_utils.c uv/uv_box.c uv/uv_cone.c uv/uv_cylindre.c uv/uv_plane.c uv/uv_rbox.c uv/uv_sphere.c uv/uv_triangle.c \
			normal/normal.c normal/normal_box.c normal/normal_cone.c normal/normal_cylinder.c normal/normal_plane.c normal/normal_rbox.c normal/normal_sphere.c normal/normal_triangle.c \
			garbage_collector/garbage_collector.c garbage_collector/free.c
# 			

SOURCES = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))

OBJECTS = $(SOURCES:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME= miniRT

all:
	@$(MAKE) --no-print-directory $(NAME)

$(LIB):
	@$(MAKE) --no-print-directory -C libft

$(MLX):
	@$(MAKE) --no-print-directory -C minilibx-linux

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I includes -I libft -c $< -o $@
	$(call progress_bar)

$(NAME): $(LIB) $(MLX) $(OBJECTS)
	@printf "\n"
	@$(CC) $(CFLAGS) $(OBJECTS) -Llibft -Lminilibx-linux -lft -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

dragon:
	$(call dragon)
	$(call dragon_fire)

rocket:
	$(call rocket)
	$(call launch_rocket)

train:
	$(call train)
	@bash animation/script_train.sh

clean:
	@$(eval CURRENT_FILE=0)
	@printf "$(RED)$(TRASH)  Removing objects ($(NAME))$(RESET)\n"
	@rm -rf $(OBJECTS)
	@$(MAKE) --no-print-directory -C libft clean

fclean:
	@printf "$(RED)$(TRASH)  Removing objects ($(NAME))$(RESET)\n"
	@rm -rf $(OBJECTS)
	@printf "$(RED)$(TRASH)  Removing binary  ($(NAME))$(RESET)\n"
	@rm -rf $(NAME) $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C libft fclean

fcleanrt:
	@printf "$(RED)$(TRASH)  Removing objects ($(NAME))$(RESET)\n"
	@rm -rf $(OBJECTS)
	@printf "$(RED)$(TRASH)  Removing binary  ($(NAME))$(RESET)\n"
	@rm -rf $(NAME) $(OBJ_DIR)

rt: fcleanrt all

re: fclean all

.PHONY : all clean fclean re rocket train dragon