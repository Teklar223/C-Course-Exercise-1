CFLAGS=-I. -lm
FLAGS= -Wall -g
OBJLOOP = advancedClassificationLoop.o basicClassification.o
OBJREC = advancedClassificationRecursion.o basicClassification.o
OBJMAIN = main.o

all: loops loopd recursives recursived mains maindloop maindrec

loops: libclassloops.a
loopd: libclassloops.so
recursives: libclassrec.a
recursived: libclassrec.so

mains: $(OBJMAIN) libclassrec.a
	gcc $(FLAGS) -o mains $(OBJMAIN) libclassrec.a $(CFLAGS)

maindloop: $(OBJMAIN) libclassloops.so
	gcc $(FLAGS) -o maindloop $(OBJMAIN) ./libclassloops.so $(CFLAGS)

maindrec: $(OBJMAIN) libclassrec.so
	gcc $(FLAGS) -o maindrec $(OBJMAIN) ./libclassrec.so $(CFLAGS)

###############################################################

libclassloops.a: $(OBJLOOP)
	ar -rcs libclassloops.a $(OBJLOOP) 

libclassrec.a: $(OBJREC)
	ar -rcs libclassrec.a $(OBJREC)

libclassloops.so: $(OBJLOOP)
	gcc $(FLAGS) -shared -o libclassloops.so $(OBJLOOP)

libclassrec.so: $(OBJREC)
	gcc $(FLAGS) -shared -o libclassrec.so $(OBJREC)

################################################################

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc $(FLAGS) -c advancedClassificationLoop.c $(CFLAGS)

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc $(FLAGS) -c advancedClassificationRecursion.c $(CFLAGS)

basicClassification.o: basicClassification.c NumClass.h
	gcc $(FLAGS) -c basicClassification.c $(CFLAGS)

main.o: main.c NumClass.h
	gcc $(FLAGS) -c main.c $(CFLAGS)


.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec