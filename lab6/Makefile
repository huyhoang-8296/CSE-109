main : main.o libstudent.a
	g++ -L. -o main main.o -lstudent
main.o: main.cpp student.h
	g++ -c main.cpp
libstudent.a: student.o
	ar crs libstudent.a student.o
student.o: student.cpp student.h
	g++ -c student.cpp
clean :
	rm main main.o fraction.o libstudent.a
