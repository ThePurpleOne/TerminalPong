
main: main.o moving_object.o ball.o paddle.o playground.o
	g++  main.o moving_object.o ball.o paddle.o playground.o -lncurses -o main 

main.o: main.cpp
	g++ -c main.cpp -o main.o

moving_object.o : moving_object.cpp
	g++ -c moving_object.cpp -o moving_object.o

ball.o: ball.cpp
	g++ -c ball.cpp -o ball.o

paddle.o: paddle.cpp
	g++ -c paddle.cpp -o paddle.o

playground.o: playground.cpp
	g++ -c playground.cpp -o playground.o

