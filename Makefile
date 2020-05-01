FLAGS = -pedantic-errors -std=c++11

generateRoom.o: generateRoom.cpp generateRoom.h
  g++ $(FLAGS) -c $<
