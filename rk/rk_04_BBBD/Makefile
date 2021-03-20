CC := gcc
CFILES := $(wildcard *.c)
INCS := $(wildcard *.h)
FLAGS := -std=c99 -Wall -Werror

build: $(patsubst %.c, %.o, $(CFILES))
	$(CC) $(FLAGS) $^ -o app.exe

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -c $<


run: build
	./app.exe in.txt out.txt

clean:
	rm *.exe *.o