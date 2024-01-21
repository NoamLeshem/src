CC = gcc
AR = ar
CFLAGS = -Wall -g

OBJS_LOOPS = basicClassification.o advancedClassificationLoop.o
OBJS_RECURSIVE = basicClassification.o advancedClassificationRecursion.o
OBJS_MAIN = main.o

all: libclassrec.a libclassloops.so libclassrec.so libclassloops.a mains maindloop maindrec

loops: libclassloops.a

loopd: libclassloops.so

recursives: libclassrec.a

recursived: libclassrec.so

mains: mains.o libclassrec.a
	$(CC) $(CFLAGS) -o $@ $^
mains.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c -o mains.o
maindloop: mains.o libclassloops.so
	$(CC) $(CFLAGS) -o $@ mains.o ./libclassloops.so
maindrec: mains.o libclassrec.so
	$(CC) $(CFLAGS) -o $@ mains.o ./libclassrec.so
libclassrec.a: $(OBJS_RECURSIVE)
	$(AR) -rcs $@ $^
libclassloops.so: $(OBJS_LOOPS)
	$(CC) -shared -o $@ $^
libclassloops.a: $(OBJS_LOOPS)
	$(AR) -rcs $@ $^
libclassrec.so: $(OBJS_RECURSIVE)
	$(CC) -shared -o $@ $^
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec