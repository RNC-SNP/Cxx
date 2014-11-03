#include <iostream>
#include <memory>

using namespace std;

int main (int argc, char **argv) {
	allocator<int> alloc;//object that can allocate ints
	auto p = alloc.allocate(10);//allocate 10 unconstructed ints

	//construct:
	auto q = p;
	for (int i = 0; i < 10; i++) {
		alloc.construct(q, i);
		cout << *q << endl;
		q++;
	}

	//destroy:
	while (q != p) {
		alloc.destroy(--q);
	}

	//free memory:
	alloc.deallocate(p, 10);

	return 0;
}