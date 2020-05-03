FLAGS = -pedantic-errors -std=c++11

generateRoom.o: generateRoom.cpp generateRoom.h
	g++ $(FLAGS) -c $<

goCommand.o: go_command.cpp go_command.h
	g++ $(FLAGS) -c $<
	
main.o: main.cpp generateRoom.h
	g++ $(FLAGS) -c $<

main2.o: main.cpp go_command.h
	g++ $(FLAGS) -c $<
	
main: generateRoom.o go_command.o main.o main2.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main generateRoom.o go_command.o main.o main2.o room.tgz

tar:
	tar -czvf room.tgz *.cpp *.h

.PHONY: clean tar
