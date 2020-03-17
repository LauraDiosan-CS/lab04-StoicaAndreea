#include "Tests.h"
#include "ProjectG.h"
#include "Operations.h"
#include "assert.h"
#include "Repo.h"
#include <iostream>
using namespace std;
void testDomain() {
	Project p1("pppp", 4, 2);
	Project p2(p1);
	assert(p1 == p2);
	p2.setNoOfBranches(1);
	assert(p2.getNoOfBranches() == 1);
}


void testRepo() {
	Project s1("Ana", 19, 12);
	Project s2("Maria", 19, 14);
	Project s3("Ana", 20, 15);
	Project s4("Ana", 18, 10);
	Repository rep;
	rep.addElem(s1);
	rep.addElem(s2);
	rep.addElem(s3);
	rep.addElem(s4);
	assert(rep.getSize() == 4);
	assert(rep.getItemFromPos(0) == s1);
	assert(rep.findElem(s1) == 1);

	rep.updateElem(rep.getItemFromPos(0), "aaa", 1, 1);
	assert(strcmp(rep.getItemFromPos(0).getGitPath(),"aaa") == 0);

	rep.deleteElem(rep.getItemFromPos(3));
	assert(rep.getSize() == 3);
}

void testFilterProjects() {
	Project s1("Ana", 19,12);
	Project s2("Maria", 19,14);
	Project s3("Ana", 20,15);
	Project s4("Ana", 18,10);
	Project proj[4] = { s1, s2, s3, s4 };
	Project results[4];
	int m = 0;
	filterProjects(proj, 4, 19,13, results, m);

	assert((m == 2) && (results[0] == s2) && (results[1] == s3));
}
void testProjectsWithRepo() {
	Project s1("Ana", 19, 12);
	Project s2("Maria", 19, 12);
	Project s3("Dana", 20, 0);
	Project s4("Oana", 18, 10);
	Repository rep;
	rep.addElem(s1);
	rep.addElem(s2);
	rep.addElem(s3);
	rep.addElem(s4);
	assert(rep.getSize() == 4);
	vector<Project> results;
	filterProjectsWithRepo(rep, 20, 0, results);
	assert((results.size() == 1) && (results[0] == s3));
	deleteProjectsWithCommitsAndBranches(rep);
	assert(rep.getSize() == 3);
}