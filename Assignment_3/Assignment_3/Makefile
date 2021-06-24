scheduler: scheduler.o libLL.so
	gcc -L./lib -o scheduler ./lib/scheduler.o -lLL
	mv scheduler bin/.
scheduler.o: src/scheduler.c include/linked_list.h
	gcc -c -I./include src/scheduler.c -o scheduler.o
	mv scheduler.o lib/.
libLL.so: linked_list.o process.o
	gcc -shared lib/linked_list.o lib/process.o -o libLL.so
	mv libLL.so lib/.
	cp lib/libLL.so bin/libLL.so
linked_list.o: src/linked_list.c include/linked_list.h include/process.h
	gcc -c -fpic -I./include src/linked_list.c -o linked_list.o
	mv linked_list.o lib/.
process.o: src/process.c include/process.h
	gcc -c -fpic -I./include src/process.c -o process.o
	mv process.o lib/.
clean:
	rm lib/*.o
	rm bin/scheduler