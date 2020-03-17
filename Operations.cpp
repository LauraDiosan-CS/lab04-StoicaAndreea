#include "operations.h"
#include "Repo.h"

// filter all the projects who have the no of branches and no of commits than a given limit
// In: an array of projects and their number of branches(integer), a path (String), a number of commits (integer)
// Out: an array of filtered projects and their number of branches(integer), a path (String), a number of commits (integer)
void filterProjects(Project projects[], int n, int a,int b, Project projFilter[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if ((projects[i].getTotalNoOfCommits()>=b) && (projects[i].getNoOfBranches() >= a)) {
			projFilter[m++] = projects[i];
		}
	}
} 

// filter all the projects who have the no of branches and no of commits than a given limit
// In: an array of projects and their number of branches(integer), a path (String), a number of commits (integer)
// Out: an array of filtered projects and their number of branches(integer), a path (String), a number of commits (integer)
void filterProjectsWithRepo(Repository& rep, int a,int b, vector<Project>& studFilter) {
	for (int i = 0; i < rep.getSize(); i++) {
		Project crtProject = rep.getItemFromPos(i);

		if ((crtProject.getNoOfBranches()>=a) && (crtProject.getTotalNoOfCommits() >= b)) {
			studFilter.push_back(rep.getItemFromPos(i));
		}
	}
}


// deletes all the projects who have the no of branches * no of commits =0
// In: an array of projects and their number of branches(integer), a path (String), a number of commits (integer)
// Out: an array of filtered projects and their number of branches(integer), a path (String), a number of commits (integer)
void deleteProjectsWithCommitsAndBranches(Repository& rep) {
	for (int i = 0; i < rep.getSize(); i++) {
		if (rep.getItemFromPos(i).getNoOfBranches() * rep.getItemFromPos(i).getTotalNoOfCommits() == 0)
		{
			rep.deleteElem(rep.getItemFromPos(i));
		}
	}
}