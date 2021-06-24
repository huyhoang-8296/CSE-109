spell_checker : spell_checker.o libhashtable.a
	g++ -L. -o spell_checker spell_checker.o -lhashtable
spell_checker.o: spell_checker.cpp hashtable.h
	g++ -c spell_checker.cpp
libhashtable.a: hashtable.o
	ar crs libhashtable.a hashtable.o
hashtable.o: hashtable.cpp hashtable.h
	g++ -c hashtable.cpp
clean :
	rm spell_checker spell_checker.o hashtable.o libhashtable.a
