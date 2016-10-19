CC      = CC
file0 = driver
file1 = factory
file2 = gamemanager
file3 = card
file4 = deck
file5 = score
file6 = trick
file7 = display
file8 = hand
file9 = handiterator
file10 = trickiterator

runeuchre: euchre
	./euchre

euchre: $(file9).o $(file8).o $(file7).o $(file6).o $(file5).o $(file4).o $(file3).o $(file2).o $(file1).o $(file0).o
	$(CC) -o euchre $(file9).o $(file8).o $(file7).o $(file6).o $(file5).o $(file4).o $(file3).o $(file2).o $(file1).o $(file0).o

$(file0).o: $(file0).cpp
	$(CC) -c $(file0).cpp 

$(file1).o: $(file1).cpp $(file1).h
	$(CC) -c $(file1).cpp 

$(file2).o: $(file2).cpp $(file2).h
	$(CC) -c $(file2).cpp
#add the -DBIG directive for a 32-card deck

$(file3).o: $(file3).cpp $(file3).h
	$(CC) -c $(file3).cpp 

$(file4).o: $(file4).cpp $(file4).h
	$(CC) -c $(file4).cpp 

$(file5).o: $(file5).cpp $(file5).h
	$(CC) -c $(file5).cpp
	
$(file6).o: $(file6).cpp $(file6).h
	$(CC) -c $(file6).cpp 

$(file7).o: $(file7).cpp $(file7).h
	$(CC) -c $(file7).cpp
	
$(file8).o: $(file8).cpp $(file8).h
	$(CC) -c $(file8).cpp

$(file9).o: $(file9).cpp $(file9).h
	$(CC) -c $(file9).cpp

clean:
	rm -r *.o euchre SunWS_cache
