CC = g++
PROG = ../Release/Filter

OPENCV = `pkg-config --cflags --libs opencv4`
LIBS = $(OPENCV)

$(PROG): main.cpp filter.cpp filter.h
	$(CC) main.cpp filter.cpp filter.h -o $(PROG) $(LIBS)
