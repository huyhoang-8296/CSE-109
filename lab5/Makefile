main: main.o libdata_structures.so
	g++ -L./lib -o main ./lib/main.o -ldata_structures
	mv main bin/.
main.o: src/main.cpp include/linkedlist.h
	g++ -c -I./include src/main.cpp -o main.o
	mv main.o lib/.
libdata_structures.so: linkedlist.o BST.o hashtable.o student.o
	g++ -shared lib/linkedlist.o lib/student.o lib/BST.o lib/hashtable.o -o libdata_structures.so
	mv libdata_structures.so lib/.
	cp lib/libdata_structures.so bin/libdata_structures.so
linkedlist.o: src/linkedlist.cpp include/linkedlist.h include/linkedlist.h
	g++ -c -fpic -I./include src/linkedlist.cpp -o linkedlist.o
	mv linkedlist.o lib/.
hashtable.o: src/hashtable.cpp include/hashtable.h include/hashtable.h
	g++ -c -fpic -I./include src/hashtable.cpp -o hashtable.o
	mv hashtable.o lib/.
student.o: src/student.cpp include/student.h include/student.h
	g++ -c -fpic -I./include src/student.cpp -o student.o
	mv student.o lib/.
BST.o: src/BST.cpp include/tree.h include/tree.h
	g++ -c -fpic -I./include src/BST.cpp -o BST.o
	mv BST.o lib/.
clean:
	rm lib/*.o
	rm bin/main