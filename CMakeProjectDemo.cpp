// CMakeProjectDemo.cpp : Defines the entry point for the application.
//

#include "CMakeProjectDemo.h"
#include "SecondFile.h"
#include "math2/thirdfile.h"
#include "config.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		// report version
		std::cout << argv[0] << " Version " << CMakeProjectDemo_VERSION_MAJOR << "."
			<< CMakeProjectDemo_VERSION_MINOR << std::endl;
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
	
	}

	cout << "Hello CMake." << endl;

	CDemo1 d1;
	d1.Do();

	CDemo3 d3;
	d3.func();

	return 0;
}
