CC=gcc
CFALGS = -std=c99 -Wall -Wextra -Werror
LFLAGS = -lcsfml-window -lcsfml-graphics -lcsfml-audio -lpthread

NAME = tetris

SRC = main.c gfx/renderer.c gfx/map.c threads/game.c
DEPS = gfx/renderer.h gfx/map.h threads/game.h
OBJS = main.o gfx/renderer.o gfx/map.o threads/game.o

YOU: $(SRC) $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(NAME) 
