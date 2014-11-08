#include "People.hxx"
#include "Student.hxx"

int main (int argc, char **argv) {
	People *p = new People("Rinc", 25);
	//call base class's function:
	p->introduce();
	p->print();
	delete p;
	p = new Student("Rinc", 25, "2008112208");//rebound to a derived object
	//call derived class's function:
	p->introduce();
	p->print();
	//use the scope(::) to call base class's function:
	p->People::introduce();
	p->People::print();
	delete p;
	return 0;
}