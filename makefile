objects = main.o Lecture.o Infos.o Statistic.o InfosStorage.o

analog: $(objects)
	c++ -o analog $(objects)
	
main.o: main.cpp
	c++ -std=c++17 -c main.cpp
	
Lecture.o: Lecture.cpp Lecture.h
	c++ -std=c++17 -c Lecture.cpp

Statistic.o: Statistic.cpp Statistic.h
	c++ -std=c++17 -c Statistic.cpp

Infos.o: Infos.cpp Infos.h
	c++ -std=c++17 -c Infos.cpp

InfosStorage.o: InfosStorage.cpp InfosStorage.h
	c++ -std=c++17 -c InfosStorage.cpp

.PHONY: clean

clean:
	rm analog $(objects) *.dot *.png
