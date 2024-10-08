NAME				=	template
LIB					=	ft
INC_DIR				=	inc
SRC_DIR				=	src
OBJ_DIR				=	obj
LIB_DIR				=	lib

FILES				=	 \
						main \

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -g
IFLAGS				=	-I$(INC_DIR) -Imlx -I/usr/include -I$(LIB_DIR)/$(INC_DIR)
LFLAGS				=	-L$(LIB_DIR) -l$(LIB)
VFLAGS				=	 \
						--track-origins=yes \
						--leak-check=full \
						# --show-leak-kinds=all \
						-s \

LOGFILE				=	valgrind_result.log

OBJ_EXIST			=	.obj

SRCS				=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS				=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c | $(OBJ_EXIST)
						@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_EXIST):
						@mkdir -p $(OBJ_DIR)

all:					$(NAME)

val:					re
						@valgrind $(VFLAGS) ./$(NAME) > $(LOGFILE) 2>&1
						@code $(LOGFILE)

$(NAME):				$(OBJS)
						@make all --no-print-directory -C $(LIB_DIR)
						@$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

lib_clean:
						@make clean --no-print-directory -C $(LIB_DIR)

clean:					lib_clean
						@$(RM) -rf $(OBJ_DIR)

fclean:					clean
						@$(RM) $(NAME)
						@$(RM) $(LOGFILE)

re:						fclean all

norm:
						@$(call check_norminette, $(SRC_DIR))
						@$(call check_norminette, $(INC_DIR))
						@$(call check_norminette, $(LIB_DIR))

define check_norminette
						@if norminette $1 | grep -q Error; then \
							norminette $1 | grep Error; \
						else \
							echo "$1: OK!"; \
						fi
endef

.PHONY:					all clean fclean re norm