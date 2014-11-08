#include "People.hxx"
#include "Student.hxx"

int main (int argc, char **argv) {
	People *p = new People("Rinc", 25);
	p->introduce();//call People::introduce()
	p = new Student("Rinc", 25, "2008112208");//rebound to a derived object
	p->introduce();//call Student::introduce()
	p->People::introduce();//use the scope(::) to specify the function's version
	delete p;
	return 0;
}