CXX = clang++ -std=c++11
OBJS = main.o People.o Student.o

xx : $(OBJS)
	$(CXX) -o xx $(OBJS)

main.o : main.cxx People.hxx Student.hxx
	$(CXX) -c main.cxx

People.o : People.cxx People.hxx Object.hxx
	$(CXX) -c People.cxx

Student.o : Student.cxx Student.hxx
	$(CXX) -c Student.cxx

clean:
	rm xx $(OBJS)