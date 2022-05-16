##
## EPITECH PROJECT, 2019
## RPG
## File description:
## make the project
##

NAME	= my_rpg

CC  =   gcc -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio -lm -g

RM	= rm -f

SRCS	= 	src/main.c  				\
		src/display.c   			\
		src/event.c	    			\
		src/loop.c  				\
		src/player/create_player.c  		\
		src/player/hit_boat.c   		\
		src/player/pick_up.c   			\
		src/player/collisions.c   		\
		src/player/quest_objectives.c   \
		src/player/dock_handle.c    		\
		src/player/level_up.c   \
		src/player/ai/basics_move.c 		\
		src/player/ai/init_path.c 		\
		src/player/ai/tower_ai.c 		\
		src/player/ai/ai_spawn.c 		\
		src/player/parse/parse_quest.c		\
		src/player/ai/ai_towards.c  		\
		src/player/ai/astar.c			\
		src/player/ai/astar_algo.c		\
		src/player/ai/handle_node.c		\
		src/map/color.c 			\
		src/map/convert_map.c   		\
		src/map/draw_map.c  			\
		src/map/get_map_points.c    		\
		src/map/map.c   			\
		src/map/inventory.c			\
		src/map/open_map.c  			\
		src/model/parse/open_model.c		\
		src/model/parse/om_check_error.c	\
		src/model/convert_model.c   		\
		src/model/move_model.c  		\
		src/model/cube.c    			\
		src/model/get_center.c  		\
		src/model/life_bar.c            \
		src/model/manage_models.c   		\
		src/model/render_model.c    		\
		src/model/rotate_model.c		\
		src/model/sort_models.c 		\
		src/model/sort_cubes.c  		\
		src/model/shoot.c   			\
		src/model/destroy.c			\
		src/model/get_model_corners.c		\
		src/particles/create_particle.c 	\
		src/particles/render_particles.c    	\
		src/particles/behaviour.c   		\
		src/menu/menu.c				\
		src/menu/draw_scene.c			\
		src/menu/pause.c			\
		src/hit_box/button_hitbox.c		\
		src/hit_box/hit_box_classic.c       	\
		src/create_rpg/creates_scene.c		\
		src/create_rpg/create_textures.c	\
		src/create_rpg/create_texture_game.c	\
		src/create_rpg/create_game_sprite.c	\
		src/create_rpg/set_game_pos.c		\
		src/create_rpg/set_images_pos.c		\
		src/create_rpg/set_game_scale.c		\
		src/create_rpg/set_scale_images.c	\
		src/create_rpg/init_price.c	\
		src/create_rpg/create_quests.c  \
		src/sound/sound.c			\
		src/window/open_window.c		\
		src/free/free_rpg.c			\
		src/font/font.c             \
		src/create_rpg/image_parse.c           \
		src/window/window.c         \
		src/dock/dock.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -W -Wall -Wextra -I ./include/ -lmy

all: $(NAME)

$(NAME):	$(OBJS)
	make -C lib/my
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L./lib/my

clean:
	$(RM) $(OBJS)
	make clean -C lib/my

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all
	clean
	fclean
