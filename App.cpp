
#include "Tests.h"
#include <iostream>
using namespace std;

int main() {
	cout << "start..." << endl;
	testDomain();
	testRepo();
	testRepoArray();
	testFilterProjects();
	testProjectsWithRepo();
	testProjectsWithRepoArray();
	cout << "succes";
	return 0;
}

