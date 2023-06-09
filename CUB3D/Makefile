#------  1.PROJECT FILES VARIABLES

NAME = cub3D

CFILES = main.c	\
		 PARSING/clean_parsing.c \
		 PARSING/clean_parsing2.c \
		 PARSING/parse_colors.c \
		 PARSING/parse_elements.c \
		 PARSING/parse_infile.c \
		 PARSING/parse_map.c \
		 PARSING/parsing.c \
		 PARSING/utils_colors.c \
		 PARSING/utils_colors2.c \
		 PARSING/utils_colors3.c \
		 PARSING/utils_cub.c \
		 PARSING/utils_elements.c \
		 PARSING/utils_map_fill.c \
		 PARSING/utils_map.c \
		 RAYCASTING/init_ray.c \
		 RAYCASTING/rutil.c \
		 RENDER/cleaner.c \
		 RENDER/init_mlx.c \
		 RENDER/keys.c \
		 RENDER/player_init.c \
		 RENDER/texture.c \
		 RENDER/play_move.c \
		 RENDER/cam_move.c 


OBJS :=  	${addprefix ./OBJ/,${CFILES:%.c=%.o}}
DEP   = 	${addprefix ./OBJ/,${OBJS:%.o=%.d}}

#------  2.COMPILING VARIABLES

CFLAGS = -Wall -Werror -Wextra -MMD -MP -I./includes -g3
RL = -lreadline
LIB	   = -L./LIB/libft/ -lft -lm -lbsd -L./LIB/minilibx-linux -lmlx -lX11 -lXext 

#------  3.COLORS VARIABLES

RS=        \033[0m
DARK=        \033[1;32m
RED=        \033[31m
GREEN=        \033[32m
YELLOW=        \033[33m
BLUE=        \033[34m
MAGENTA=    \033[35m
CYAN=        \033[36m
WHITE=        \033[37m
BOLDBLACK=    \033[1m\033[30m
BOLDRED=    \033[1m\033[31m
BOLDWHITE=    \033[1m\033[37m
BOLDGREEN=    \033[1m\033[32m

#------  4.RULES

all: ${NAME}
-include ${DEP}

./OBJ/%.o: ./%.c
	@mkdir -p ${@D}
	@cc ${CFLAGS} -o $@ -c $<
	
${NAME} : ${OBJS}
	@make -C ./LIB/minilibx-linux/
	@make -C ./LIB/libft/
	@echo "${MAGENTA}assembling in progress for cub3D...${RS}"
	@echo "${GREEN}done and moved into obj directory${RS}"
	@echo "${MAGENTA}compiling cub3D... ${RS}"
	@cc ${CFLAGS} ${OBJS} ${RL} ${LIB} -o ${NAME}
	@echo "${GREEN}⡶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⢶"
	@echo "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⢰"
	@echo "⡇⠀⠀⠀⠀⠀⠀⠀⠀         CUB3D READY!                   ⢸"
	@echo "⡇⠀⠀⠀⠀⠀⠀⠀⠀             BY                      ⠀⠀⠀⢸"
	@echo "⡇                FWONG & KHUYNH   	         ⢸"
	@echo "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨"
	@echo "⡷⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⢶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⡾"
	@echo "⠀⠀⠀⠉⠉⠉⠉⣽⡿⠁⣠⣾⡿⠾⣯⣿⠿⠯⢭⣉⠉⠉⠉⠉⣉⣭⣿⡯⠽⠯⢭⣟⡫⣽⣿⣁⣠⣦⣄⠉⠳⣿⣍⠉⠉⠉⠉⠉⠁⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⠃⢠⣿⣿⣴⣾⠿⠛⠋⠉⠛⠲⠯⣵⣶⡯⠟⠋⢁⣀⣠⣤⣤⣬⣽⣾⣿⣿⣻⣿⣿⣷⣄⠘⣿⡄⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸⣿⡿⠛⢁⣤⠶⠛⠋⠉⠉⠛⠻⢿⠤⡴⠞⠛⣉⣽⠿⠛⢉⣠⣤⣤⢤⣝⣿⣿⣿⣿⡄⢸⣿⡀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⡇⠀⢸⡏⠀⠰⠋⠁⠀⠀⢀⣤⣶⣾⣿⣿⡤⠤⠤⣾⣋⢀⡤⠞⢫⣿⣿⣿⣷⡄⠉⠻⣿⣿⡇⠀⣿⠁⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⡇⠀⢸⣇⠀⠀⠀⢀⣠⠾⢋⡵⢋⣿⢻⣿⠿⣶⡄⠀⢹⠋⠀⠀⣿⣿⢿⣧⣿⣿⣀⣠⣿⣿⠁⠀⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⡇⠀⢸⣿⠀⠀⠚⠛⣷⡞⠋⠀⢸⣿⣟⢿⣶⣿⣧⣠⡿⣤⣤⣤⣽⡿⠿⠛⠛⢉⣿⣿⣿⡿⠀⠀⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⡇⠀⠈⣿⠀⠀⠀⣀⣀⣉⣻⣶⣤⣿⣿⠿⠟⠛⠉⠁⠀⠀⠀⠀⣀⣀⣠⣤⠾⠋⢉⣿⣿⡇⠀⠀⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⣿⡆⢠⣾⠋⠉⣩⣉⣉⣙⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⢛⣉⣉⣡⣤⡶⠾⣿⣿⣿⠁⠀⢠⣿⡄⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣇⠀⠀⢻⡇⠈⠛⠶⣦⣬⣉⣉⣙⡛⠛⠛⠛⠛⠛⠛⠛⠛⢛⣛⣉⣉⣉⣠⣤⣶⣿⠟⠁⠀⢀⣾⡿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠘⣿⣤⡀⠀⠀⠈⠉⠉⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠉⠉⠉⢁⣠⣼⣏⠀⣀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠈⣿⣧⠀⠀⠘⢿⣿⢷⣦⣄⣀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣠⣤⣶⠿⠛⠉⢨⣿⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠘⣿⣧⡀⠀⠀⣿⠀⠈⠉⠛⠛⠿⠿⠿⠿⠛⠛⠛⠛⠛⠛⠛⠋⠉⠀⠀⠀⠀⠈⠛⢾⣢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⣾⡿⢿⣦⣴⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⠄⠀⠀⠀⠀⠀⠀⠀⠀"


clean:
	@rm -rf OBJ/
	@rm -f ${OBJS}
	@make $@ -C ./LIB/libft/
	@echo "${BOLDGREEN}ALL CLEAN: no more obj files ${RS}"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
	@echo "⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
	@echo "⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
	@echo "⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
	@echo "⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
	@echo "⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜"
	@echo "⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
	@echo "⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬛⬜⬜⬛⬜⬜⬛⬜⬜⬜⬜⬜⬛⬛⬜⬜"
	@echo "⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬛⬜⬜⬛⬜⬜⬛⬜⬜⬜⬜⬜⬛⬛⬜⬜"
	@echo "⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬛⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛EVERYTHING IS GONE⬛⬛⬛⬛⬛⬛⬛⬜⬜⬛⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬛⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"

fclean:
	@rm -rf OBJ/
	@rm -f ${NAME}
	@make $@ -C ./LIB/libft/
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
	@echo "⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
	@echo "⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
	@echo "⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
	@echo "⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
	@echo "⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜"
	@echo "⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
	@echo "⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬛⬜⬜⬛⬜⬜⬛⬜⬜⬜⬜⬜⬛⬛⬜⬜"
	@echo "⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬛⬜⬜⬛⬜⬜⬛⬜⬜⬜⬜⬜⬛⬛⬜⬜"
	@echo "⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬛⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛EVERYTHING IS GONE⬛⬛⬛⬛⬛⬛⬛⬜⬜⬛⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬛⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜"
	@echo "⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"

re:	fclean all

.PHONY: all clean fclean re

#------  4.FYI
#
#	$@ = rule name | $< = dependency, ex "./pushswap/%.c"
#	addprefix: do not need to write path for each files
#	-L while compiling: looking for certain files or directories
#	.PHONY: used to mute if a file named like a target rule exist, eg.if we had a file named "clean"
#	Make -C: flag to change directory  before executing the rule
#	% wildcard (files matching a pattern)