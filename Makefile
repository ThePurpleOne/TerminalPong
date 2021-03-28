SRCF = src/
BLDF = build/
CC = g++

main: main.o moving_object.o ball.o paddle.o playground.o
	$(CC)  $(BLDF)main.o $(BLDF)moving_object.o $(BLDF)ball.o $(BLDF)paddle.o $(BLDF)playground.o -lncurses -o main 

main.o: $(SRCF)main.cpp
	$(CC) -c $(SRCF)main.cpp -o $(BLDF)main.o

moving_object.o : $(SRCF)moving_object.cpp
	$(CC) -c $(SRCF)moving_object.cpp -o $(BLDF)moving_object.o

ball.o: $(SRCF)ball.cpp
	$(CC) -c $(SRCF)ball.cpp -o $(BLDF)ball.o

paddle.o: $(SRCF)paddle.cpp
	$(CC) -c $(SRCF)paddle.cpp -o $(BLDF)paddle.o

playground.o: $(SRCF)playground.cpp
	$(CC) -c $(SRCF)playground.cpp -o $(BLDF)playground.o

