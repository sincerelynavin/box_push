CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror -g
OBJ = color.o random.o terminal.o maparray.o base.o box.o controls.o tutorial.o main.o  
EXEC = box

ifdef PULL
CFLAGS += -D PULL
PULL : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

color.o : color.h color.c 	
	$(CC) $(CFLAGS) color.c -c 

random.o : random.h random.c 
	$(CC) $(CFLAGS) random.c -c 

terminal.o : terminal.h terminal.c 
	$(CC) $(CFLAGS) terminal.c -c 

maparray.o : maparray.h color.h box.h boolean.h base.h maparray.c 
	$(CC) $(CFLAGS) maparray.c -c

base.o : base.h terminal.h maparray.h tutorial.h boolean.h base.c 
	$(CC) $(CFLAGS) base.c -c 

box.o : box.h random.h box.c
	$(CC) $(CFLAGS) box.c -c 

controls.o : controls.h base.h terminal.h maparray.h boolean.h controls.c 
	$(CC) $(CFLAGS) controls.c -c 

tutorial.o : tutorial.h tutorial.c 
	$(CC) $(CFLAGS) tutorial.c -c

main.o : base.h box.h boolean.h controls.h tutorial.h maparray.h main.c
	$(CC) $(CFLAGS) main.c -c 

clean :
	rm -f $(EXEC) $(OBJ)

	