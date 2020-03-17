
#include "Tests.h"
#include <iostream>
using namespace std;

int main() {
	cout << "start..." << endl;
	testDomain();
	testRepo();
	testFilterProjects();
	testProjectsWithRepo();
	cout << "succes";
	return 0;
}

