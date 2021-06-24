ccalc : ccalc.o libcomplex.a
	g++ -L. -o ccalc ccalc.o -lcomplex
ccalc.o: ccalc.cpp complex.h
	g++ -c ccalc.cpp
libcomplex.a: complex.o
	ar crs libcomplex.a complex.o
complex.o: complex.cpp complex.h
	g++ -c complex.cpp
clean :
	rm ccalc ccalc.o complex.o libcomplex.a
