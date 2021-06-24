main: main.o hashtable.a
	g++ -L./lib -o main ./lib/main.o -lhashtable
	mv main bin/.
main.o: src/main.cpp include/hashtable.h
	g++ -c -I./include src/main.cpp -o main.o
	mv main.o lib/.
hashtable.a: hashtable.o user.o
	ar crs hashtable.a lib/hashtable.o lib/user.o 
	mv hashtable.a lib/.
	cp lib/hashtable.a bin/hashtable.a
hashtable.o: src/hashtable.cpp include/hashtable.h include/user.h
	g++ -c -I./include src/hashtable.cpp -o hashtable.o
	mv hashtable.o lib/.
user.o: src/user.cpp include/user.h
	g++ -c -I./include src/user.cpp -o user.o
	mv user.o lib/.
clean:
	rm lib/*.o
	rm bin/main