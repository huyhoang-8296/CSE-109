fraction_calculator : fraction_calculator.o libfraction.a
	g++ -L. -o fraction_calculator fraction_calculator.o -lfraction
fraction_calculator.o: fraction_calculator.cpp fraction.h
	g++ -c fraction_calculator.cpp
libfraction.a: fraction.o
	ar crs libfraction.a fraction.o
fraction.o: fraction.cpp fraction.h
	g++ -c fraction.cpp
clean :
	rm fraction_calculator fraction_calculator.o fraction.o libfraction.a
