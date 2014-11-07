#include "People.hxx"
#include "Student.hxx"

int main (int argc, char **argv) {
	People *p = new People("Rinc", 25);
	p->introduce();
	p = new Student("Rinc", 25, "2008112208");
	p->introduce();
	delete p;
	return 0;
}