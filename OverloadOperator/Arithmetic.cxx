#include <iostream>

using namespace std;

class Point {
public:
	Point(int i1, int i2, int i3): x(i1), y(i2), z(i3){}
	Point operator-();
	Point operator++();
	bool operator==(const Point &p);
	Point operator+(const Point &p);
	int x, y, z;
};

Point Point::operator-() {
	return Point(-x, -y, -z);
}

Point Point::operator++() {
	return Point(++x, ++y, ++z);
}

bool Point::operator==(const Point &p) {
	return x == p.x && y == p.y && z == p.z;
}

Point Point::operator+(const Point &p) {
	return Point(x + p.x, y + p.y, z + p.z);
}

int main (int argc, char **argv) {
	Point p1(1, 3, 5);
	Point p2(2, 4, 6);
	cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
	Point p3 = -(p1 + p2);
	//p3.operator++();
	++p3;
	cout << "p3: " << p3.x << ", " << p3.y << ", " << p3.z <<endl;
	return 0;
}