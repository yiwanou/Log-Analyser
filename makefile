objects = main.o Lecture.o Infos.o

analog: $(objects)
	c++ -o analog $(objects)
	
main.o: main.cpp
	c++ -c main.cpp
	
Lecture.o: Lecture.cpp Lecture.h
	c++ -c Lecture.cpp

Infos.o: Infos.cpp Infos.h
	c++ -c Infos.cpp

.PHONY: clean

clean:
	rm analog $(objects)
