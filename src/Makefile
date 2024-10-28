PROGRAM = diceroll
SOURCES = controller.cc logic.cc view.cc
OBJECTS = controller.o logic.o view.o
CFLAGS  = -g -Wall -std=c++11
COMPILER= g++

.SUFFIXES:
.SUFFIXES: .cc .o

.cc.o: ; $(COMPILER) $(CFLAGS) -c $<

$(PROGRAM) : $(OBJECTS)
	$(COMPILER) -o ../$(PROGRAM) $(CFLAGS) $(OBJECTS)

clean: ; /bin/rm -f $(PROGRAM) $(OBJECTS) depend

# handle dependencies
depend : $(SOURCES)
	gcc -M $(SOURCES) > depend

include depend
