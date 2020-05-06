FLAGS = -pedantic-errors -std=c++11

generateRoom.o: generateRoom.cpp generateRoom.h
	g++ $(FLAGS) -c $<

commands.o: commands.cpp commands.h generateRoom.h struct.h
	g++ $(FLAGS) -c $<

commandCheck.o: commandCheck.cpp commandCheck.h
	g++ $(FLAGS) -c $<
	
main.o: main.cpp commands.h commandCheck.h struct.h
	g++ $(FLAGS) -c $<
	
main: generateRoom.o commands.o main.o commandCheck.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main generateRoom.o commands.o main.o commandCheck.o room.tgz

tar:
	tar -czvf room.tgz *.cpp *.h

.PHONY: clean tar
