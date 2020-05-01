FLAGS = -pedantic-errors -std=c++11

generateRoom.o: generateRoom.cpp generateRoom.h
  g++ $(FLAGS) -c $<

main.o: main.cpp generateRoom.h
  g++ $(FLAGS) -c $<
main: generateRoom.o main.o
  g++ $(FLAGS) $^ -o $@
  
clean:
  rm -f main generateRoom.o gcd_main.o room.tgz
  
tar:
  tar -czvf room.tgz *.cpp *.h
  
.PHONY: clean tar
