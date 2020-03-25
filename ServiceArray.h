#pragma once
#include "RepoArray.h"
#include "ProjectG.h"
using namespace std;

class ServiceArray
{
private:
	RepositoryArray repo;
public:
	ServiceArray();
	ServiceArray(const RepositoryArray&);
	void setRepo(const RepositoryArray&);
	void filterProjects(int a, int b, Project projFilter[], int& m);
	void addProject(Project&);
	int delProject(Project&);
	Project* getAll();
	Project updateProject(Project, const char*, int, int);
	int findOne(Project);
	Project getItemFromPos(int);
	int getSize();
	void deleteProjectsWithCommitsAndBranchesArray();
	//Project* sortByGitPath();
	//Project* sortByTotalNoOfCommits();
	//Project* filterByPathAndCommits(const char* n, int a);
	~ServiceArray();
};


