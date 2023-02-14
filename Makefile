##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Xavier VINCENT - Gautier BONHUR
##

NAME			=			navy

SRC_MAIN		=			src/main.c

SRC				=			src/errors/check_boats.c						\
							src/errors/check_map.c							\
							src/errors/errors.c								\
							src/errors/help.c								\
							src/game/navy.c									\
							src/game/connection/connection.c				\
							src/game/map/create_empty_map.c					\
							src/game/map/define_map_p1.c					\
							src/game/map/define_map_p2.c					\
							src/game/map/load_map.c 						\
							src/game/map/print_map.c						\
							src/game/asks_players/askplayer_one.c 			\
							src/game/asks_players/askplayer_two.c 			\
							src/game/asks_players/put_attack_in_file.c		\
							src/init/init_struct.c

SRC_TESTS		=			tests/errors/test_check_boats.c					\
							tests/errors/test_errors.c						\
							tests/errors/test_check_map.c

OBJ_MAIN		=			$(SRC_MAIN:.c=.o)

OBJ				=			$(SRC:.c=.o)

CFLAGS 			= 			-I./include

LDFLAGS 		= 			-L./lib -lmy

CRITERION		=			--coverage -lcriterion

all: 			$(NAME)

$(NAME):		$(OBJ) $(OBJ_MAIN)
	make -C lib re
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)

clean:
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno
	make -C lib clean

fclean:			clean
	rm -f $(NAME)
	make -C lib fclean

re:			clean all

tests_run:
	make -C lib re
	gcc -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS) $(LDFLAGS) $(CRITERION)
	./unit_tests
	rm unit_tests

cover:
	gcovr --exclude test/
	gcovr --branches --exclude test/

my_tests: 		tests_run cover
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno
	make -C lib clean

.PHONY:			clean
