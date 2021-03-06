#
# Makefile generated by:
# CodeBench 0.12
#
# Project: OWB_gui
#
# Created on: 21-02-2010 20:47:57
#
#

CC = SDK:gcc/bin/gcc
OBJ = \
	 events.o gui.o handlelibraries.o \
	 lists.o main.o OWB_gui.o \
	 usercode.o

BIN = owb_gui

INCPATH =

CFLAGS = $(INCPATH) 

LDFLAGS = -lauto -lraauto

LIBS = 
#	add any extra linker libraries you want here

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

all-before:
#	You can add rules here to execute before the project is built

all-after:
#	You can add rules here to execute after the project is built

clean: clean-custom
	rm $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(BIN) $(CFLAGS) $(LDFLAGS)

events.o: events.c includes.h globals.h
	$(CC) -c events.c -o events.o $(CFLAGS)

gui.o: gui.c includes.h globals.h gui.h
	$(CC) -c gui.c -o gui.o $(CFLAGS)

handlelibraries.o: handlelibraries.c includes.h globals.h
	$(CC) -c handlelibraries.c -o handlelibraries.o $(CFLAGS)

lists.o: lists.c includes.h globals.h
	$(CC) -c lists.c -o lists.o $(CFLAGS)

main.o: main.c includes.h globals.h
	$(CC) -c main.c -o main.o $(CFLAGS)

OWB_gui.o: OWB_gui.c includes.h globals.h
	$(CC) -c OWB_gui.c -o OWB_gui.o $(CFLAGS)

usercode.o: usercode.c includes.h globals.h
	$(CC) -c usercode.c -o usercode.o $(CFLAGS)

