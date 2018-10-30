main: main.cpp
	g++ main.cpp -c -o main.o && g++ gfx.o main.o -o main -lX11

gfx.o: gfx.c gfx.h
	gcc gfx.c -c -o gfx.o
