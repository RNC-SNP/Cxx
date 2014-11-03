#include <iostream>
#include <sstream>

using namespace std;

int main (int argc, char **argv) {
	istringstream iss("12 34.56 78.9 'Rinc'");//Init InputStringStream with string(should be devided with blank)

	string istr =  iss.str();//return a string
	cout << istr << endl;

	//Read int/double/float/string data from InputStringStream:
	int i;
	iss >> i;
	cout << i << endl;
	double d;
	iss >> d;
	cout << d << endl;
	float f;
	iss >> f;
	cout << f << endl;
	string s;
	iss >> s;
	cout << s << endl;

	ostringstream oss("");//Init OutputStringStream with string

	//Write data to OutputStringStream:
	oss.put('*');
	oss << "Rinc";
	oss << 12345.6789;

	string ostr = oss.str();//return a string
	cout << ostr << endl;

	//Use StringStream:
	stringstream ss;

	//Write data to StringStream:
	int ii = 12;
	char cc = '@';
	float ff = 34.56;
	ss << ii << cc << ff;

	//Read data from StringStream:
	int iix;
	ss >> iix;
	cout << iix << endl;
	char ccx;
	ss >> ccx;
	cout << ccx << endl;
	float ffx;
	ss >> ffx;
	cout << ffx << endl;

	cout << ss.str() << endl;
	ss.clear();

	return 0;
}
