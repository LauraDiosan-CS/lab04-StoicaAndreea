#include "ServiceArray.h"
#include <algorithm> 

ServiceArray::ServiceArray()
{
}

ServiceArray::ServiceArray(const RepositoryArray& r)
{
	repo = r;
}

void ServiceArray::setRepo(const RepositoryArray& r)
{
	repo = r;
}

void ServiceArray::filterProjects(int a, int b, Project projFilter[], int& m)
{
	for (int i = 0; i < repo.getSize(); i++) {
		Project crtProject = repo.getItemFromPos(i);

		if ((crtProject.getNoOfBranches() >= a) && (crtProject.getTotalNoOfCommits() >= b)) {
			projFilter[m++] = crtProject;
		}
	}
}

void ServiceArray::addProject(Project& p)
{
	repo.addElem(p);
}

int ServiceArray::delProject(Project& p)
{
	if (findOne(p) != -1) {
		repo.delElem(p);
		return 0;
	}
	return -1;
}

Project* ServiceArray::getAll()
{
	return repo.getAll();
}

Project ServiceArray::updateProject(Project p, const char* gp, int b, int c)
{
	repo.updateElem(p, gp, b, c);
	return p;
}

int ServiceArray::findOne(Project p)
{
	return repo.findElem(p);
}
Project ServiceArray::getItemFromPos(int i) {
	if (i >= 0 and i < repo.getSize())
		return repo.getItemFromPos(i);
	Project p;
	return p ;
}

int ServiceArray::getSize() {
	return repo.getSize();
}
void ServiceArray::deleteProjectsWithCommitsAndBranchesArray() {
	for (int i = 0; i < repo.getSize(); i++) {
		if (repo.getItemFromPos(i).getNoOfBranches() * repo.getItemFromPos(i).getTotalNoOfCommits() == 0)
		{
			repo.delElem(repo.getItemFromPos(i));
		}
	}
}
/*
//sorts Projects alphabetically
Project* ServiceArray::sortByGitPath()
{
	Project all[] = repo.getAll();
	std::sort(all.begin(), all.end());
	return all;
}

bool myProjCompare(Project x, Project y) { return (x.getTotalNoOfCommits() > y.getTotalNoOfCommits()); }


//sorts descending after commits
Project* ServiceArray::sortByTotalNoOfCommits()
{
	Project all = repo.getAll();
	std::sort(all.begin(), all.end(), myProjCompare);
	return all;
}

Project* ServiceArray::filterByPathAndCommits(const char* gp, int c)
{
	Project* rez;
	for (int i = 0; i < repo.size(); i++)
	{
		Project* crt = repo.elemAtPos(i);
		if (strstr(crt.getGitPath(), gp) && crt.getTotalNoOfCommits() >= c)
			rez.push_back(crt);
	}
	return rez;
}
*/


ServiceArray::~ServiceArray()
{
}
