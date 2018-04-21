GXX=g++
FLAGS=-Wall

logger: test.cpp logger.hpp
	$(GXX) $(FLAGS) -o test test.cpp