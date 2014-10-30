GXX = g++ -std=c++11
OBJS = main.o Screen.o WindowManager.o

xx : $(OBJS)
	$(GXX) -o xx $(OBJS)

main.o : main.cxx Screen.hxx WindowManager.hxx
	$(GXX) -c main.cxx

Screen.o : Screen.cxx Screen.hxx
	$(GXX) -c Screen.cxx

WindowManager.o : WindowManager.cxx Screen.hxx WindowManager.hxx
	$(GXX) -c WindowManager.cxx

clean:
	rm xx $(OBJS)