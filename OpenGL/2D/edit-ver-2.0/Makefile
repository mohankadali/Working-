.PHONY : clean

Project : DexBall
	./exec/DexBall

DexBall : main.o menu.o
	g++ -o DexBall main.o menu.o  -lGL -lGLU -lglut 
	mv *.o ./object/
	mv DexBall ./exec
main.o : 
	g++ -c  ./source/main.cpp
menu.o : 
	g++ -c ./source/menu.cpp

clean:
	rm -rf ./object/*.o
	rm -rf ./exec/*

