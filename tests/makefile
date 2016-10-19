CC      = CC
PROG    = test

INCPATH = /pkgs2/cppunit-1.10.2/include -I../src
OBJS = testing.o ../src/card.o ../src/deck.o ../src/display.o ../src/factory.o ../src/gamemanager.o ../src/hand.o ../src/handiterator.o ../src/score.o ../src/trick.o cardTestCase.o deckTestCase.o gameManagerTestCase.o handTestCase.o scoreTestCase.o trickTestCase.o handIteratorTestCase.o

runtest: $(PROG)
	./$(PROG)


$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) -L/pkgs2/cppunit-1.10.2/lib -lcppunit


%.o: %.cpp %.h
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@
clean:
	rm -r *.o test SunWS_cache
