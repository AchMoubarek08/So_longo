NAME = so_long
NAME_BONUS = 

SRC =	so_long.c get_next_line.c get_next_line_utils.c parse.c utils.c map.c\

		
SRC_BONUS = 


OBJ =	so_long.o get_next_line.o get_next_line_utils.o parse.o utils.o map.o\


OBJ_BONUS = 

all : $(NAME)

$(NAME):
	
	@gcc $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS) : 
	@gcc -fsanitize=address -Imlx $(SRC_BONUS) -o $(NAME_BONUS)
	@echo "🎁🎁🎁"

bonus: $(NAME_BONUS)

clean :
 
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "🚮🚮🚮"

fclean : clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🗑️ 🗑️ 🗑️"

re : fclean all