CPP      = g++.exe
OBJ      = main.o Rooms.o
EXE      = Project.exe
CPPFLAGS = -std=c++17
RM       = rm.exe -f

DOCGEN   = doxygen
DOXYFILE   = doxyFile

TESTS    = UnitTests.cpp
TESTSOBJ = UnitTests.o
TESTSEXE = tests.exe

.PHONY: all all-before all-after clean clean-custom

run: build
	$(EXE)

build: $(EXE)

rebuild: clean build

clean:
	$(RM) $(OBJ) $(EXE) $(TESTSOBJ) $(TESTSEXE)

$(EXE): main.o  Rooms.o 
	$(CPP) $(OBJ) -o $(EXE)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CPPFLAGS)

Rooms.o: Rooms.cpp Rooms.h
	$(CPP) -c Rooms.cpp -o Rooms.o $(CPPFLAGS)

doc: $(EXE)
	$(DOCGEN) $(DOXYFILE)

tests: $(TESTSEXE)

$(TESTSEXE): UnitTests.o Rooms.o
	$(CPP) UnitTests.o Rooms.o -o $(TESTSEXE) $(CPPFLAGS)

UnitTests.o: UnitTests.cpp
	$(CPP) -c UnitTests.cpp -o UnitTests.o $(CPPFLAGS)
