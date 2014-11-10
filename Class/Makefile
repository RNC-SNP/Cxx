CXX = clang++ -std=c++11
OBJS = main.o Screen.o WindowManager.o

xx : $(OBJS)
	$(CXX) -o xx $(OBJS)

main.o : main.cxx Screen.hxx WindowManager.hxx
	$(CXX) -c main.cxx

Screen.o : Screen.cxx Screen.hxx
	$(CXX) -c Screen.cxx

WindowManager.o : WindowManager.cxx Screen.hxx WindowManager.hxx
	$(CXX) -c WindowManager.cxx

clean:
	rm xx $(OBJS)