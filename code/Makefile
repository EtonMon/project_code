#Ethan
#ext8jv
#Lab 107

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2
DEBUG= -g
OFILES= wordPuzzle.o hashTable.o timer.o

.SUFFIXES: .o .cpp

wordPuzzle: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -lrt
	@echo "wordPuzzle.cpp hashTable.cpp timer.cpp compiled"

clean:
	-rm -f *.o *~ a.out

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h

