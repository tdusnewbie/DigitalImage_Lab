CC = g++
SRCS = 1653147_1653113_BT01.cpp
PROG = ../Release/1653147_1653113_BT01

OPENCV = `pkg-config --cflags --libs opencv4`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(SRCS) -o $(PROG) $(LIBS)