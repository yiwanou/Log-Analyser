objects = main.o Lecture.o

analog: $(objects)
	c++ -o analog $(objects)
	
main.o: main.cpp
	c++ -c main.cpp
	
Lecture.o: Lecture.cpp Lecture.h
	c++ -c Lecture.cpp

.PHONY: clean

clean:
	rm analog $(objects)
