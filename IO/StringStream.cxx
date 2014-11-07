#include <iostream>
#include <sstream>

int main (int argc, char **argv) {
	std::istringstream iss("12 34.56 78.9 'Rinc'");//Init InputStringStream with string(should be devided with blank)

	std::string istr =  iss.str();//return a string
	std::cout << istr << std::endl;

	//Read int/double/float/string data from InputStringStream:
	int i;
	iss >> i;
	std::cout << i << std::endl;
	double d;
	iss >> d;
	std::cout << d << std::endl;
	float f;
	iss >> f;
	std::cout << f << std::endl;
	std::string s;
	iss >> s;
	std::cout << s << std::endl;

	std::ostringstream oss("");//Init OutputStringStream with string

	//Write data to OutputStringStream:
	oss.put('*');
	oss << "Rinc";
	oss << 12345.6789;

	std::string ostr = oss.str();//return a string
	std::cout << ostr << std::endl;

	//Use StringStream:
	std::stringstream ss;

	//Write data to StringStream:
	int ii = 12;
	char cc = '@';
	float ff = 34.56;
	ss << ii << cc << ff;

	//Read data from StringStream:
	int iix;
	ss >> iix;
	std::cout << iix << std::endl;
	char ccx;
	ss >> ccx;
	std::cout << ccx << std::endl;
	float ffx;
	ss >> ffx;
	std::cout << ffx << std::endl;

	std::cout << ss.str() << std::endl;
	ss.clear();

	return 0;
}
