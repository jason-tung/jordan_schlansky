all: main.c
	gcc -o test main.c
clean:
	rm -f test *.o *~ *gch
run:
	./test