CC = g++
SRCS = Lab01.cpp
PROG = ../Release/16147_BT00

OPENCV = `pkg-config --cflags --libs opencv4`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(SRCS) -o $(PROG) $(LIBS)