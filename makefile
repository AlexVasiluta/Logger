GXX=gcc
FLAGS=-Wall -std=c11
OUTPUT_FILE=test

logger: test.c logger.h
	$(GXX) $(FLAGS) -o $(OUTPUT_FILE) test.c
