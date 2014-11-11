GXX = g++ -std=c++11
OBJS = main.o People.o Student.o

xx : $(OBJS)
	$(GXX) -o xx $(OBJS)

main.o : main.cxx People.hxx Student.hxx
	$(GXX) -c main.cxx

People.o : People.cxx People.hxx Object.hxx
	$(GXX) -c People.cxx

Student.o : Student.cxx Student.hxx
	$(GXX) -c Student.cxx

clean:
	rm xx $(OBJS)