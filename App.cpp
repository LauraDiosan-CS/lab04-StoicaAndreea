#include <iostream>
#include "RepoArray.h"
#include"ServiceArray.h"
#include "UI.h"
#include "Tests.h"
using namespace std;


int main() {
	cout << "start" << endl;
	Tests tes;
	tes.testDomain();
	tes.testRepoArray();
	tes.testProjectsWithRepoArray();
	tes.testServiceArray();
	cout << "succes" << endl;
	RepositoryArray repo;
	ServiceArray serv(repo);
	Project p1("aaa", 1, 1);
	Project p2("bbb", 2, 2);
	Project p3("ccc", 3, 0);
	Project p4("ddd", 2, 2);
	serv.addProject(p1);
	serv.addProject(p2);
	serv.addProject(p3);
	serv.addProject(p4);
	showUI(serv);
	return 0;
}