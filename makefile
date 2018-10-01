main: main.cpp Asteroide.o gfx.o
	g++ gfx.o main.o -o main -lX11
	#g++ main.cpp Asteroide.o gfx.o -o main -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
#Asteroide.o: Asteroide.hpp
#	g++ Asteroide.hpp -c

gfx.o: gfx.c gfx.h
	gcc gfx.c -c -o gfx.o
	#gcc gfx.c -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm

#g++ main.cpp -c -o main.o && g++ gfx.o main.o -o prin -lX11
