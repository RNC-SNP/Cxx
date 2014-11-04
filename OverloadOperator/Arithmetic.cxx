#include <iostream>

using namespace std;

class Point {
public:
	Point(double d1, double d2, double d3): x(d1), y(d2), z(d3){}
	Point operator-();
	bool operator==(const Point &p);
	Point operator+(const Point &p);
	double x, y, z;
};

Point Point::operator-() {
	return Point(-x, -y, -z);
}

bool Point::operator==(const Point &p) {
	return x == p.x && y == p.y && z == p.z;
}

Point Point::operator+(const Point &p) {
	return Point(x + p.x, y + p.y, z + p.z);
}

int main (int argc, char **argv) {
	Point p1(1.2, 2.3, 3.4);
	Point p2(5.6, 6.7, 7.8);
	cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
	Point p3 = -(p1 + p2);
	cout << "p3: " << p3.x << ", " << p3.y << ", " << p3.z <<endl;
	return 0;
}