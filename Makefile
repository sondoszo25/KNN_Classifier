CC = g++ -std=c++11 -pthread


OBJS	= server.o Data.o Myvector.o DefaultIOo.o CLI.o Command.o filesave.o
OUT	= server.out,client.out

OBJSSERVER = server.o Data.o Myvector.o DefaultIO.o CLI.o Command.o filesave.o
SOURCESERVER	= server.cpp Data.cpp Myvector.cpp DefaultIO.cpp CLI.cpp Command.cpp filesave.cpp
HEADERSERVER	= Data.h Myvector.h DefaultIOo.h CLI.h Command.h Filesave.h
OUTSERVER	= server.out

OBJCLIENT = client.o Data.o Myvector.o  DefaultIO.o Command.o filesave.o
SOURCECLIENT= client.cpp Data.cpp Myvector.cpp DefaultIO.cpp Command.cpp filesave.cpp
HEADERCLIENT	= Data.h Myvector.h DefaultIOo.h Command.h Filesave.h
OUTCLIENT	= client.out

ifeq ($(OS),Windows_NT)
	RM = del /F /Q 
	ERROR_IGNORE = 2>NUL || VER>NUL
	EXE = a.exe 
else 
	RM = rm -rf 
	ERROR_IGNORE = 2>/dev/null 
	EXE = a.out 
endif


FLAGS	 = -g -c -Wall
LFLAGS	 = 
all: server.out client.out


server.out: $(OBJSSERVER) 
	$(CC) $(OBJSSERVER) -o $(OUTSERVER)

client.out: $(OBJCLIENT) 
	$(CC) $(OBJCLIENT) -o $(OUTCLIENT) 


server.o: server.cpp 
	$(CC) -c server.cpp

client.o: client.cpp 
	$(CC) -c client.cpp
	

Data.o: Data.cpp Data.h 
	$(CC) -c Data.cpp	

Myvector.o: Myvector.cpp Myvector.h
	$(CC) -c Myvector.cpp

DefaultIO.o: DefaultIO.cpp DefaultIOo.h
	$(CC) -c DefaultIO.cpp

CLI.o: CLI.cpp CLI.h
	$(CC) -c CLI.cpp

Command.o: Command.cpp Command.h
	$(CC) -c Command.cpp

filesave.o: filesave.cpp Filesave.h
	$(CC) -c filesave.cpp

buf: 
	rm *.o server.out client.out
	$(RM) $(OBJSSERVER) $(ERROR_IGNORE) 
	$(RM) $(OBJCLIENT) $(ERROR_IGNORE) 
	$(RM) $(EXE) $(ERROR_IGNORE)