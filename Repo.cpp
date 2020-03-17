#include "Repo.h"

Repository::Repository() {
}

void Repository::addElem(Project p) {
	elem.push_back(p);
}

bool Repository::findElem(Project p) {
	vector<Project>::iterator it;
	it = find(elem.begin(), elem.end(), p);
	if (it != elem.end()) return true;
	return false;
}

void Repository::deleteElem(Project p) {
	vector<Project>::iterator it;
	it = find(elem.begin(), elem.end(), p);
	if (it != elem.end()) elem.erase(it);
}

int Repository::getSize() {
	return elem.size();
}

Project Repository::getItemFromPos(int i) {
	return elem[i];
}

Repository::~Repository() {
}

vector<Project> Repository::getAll() {
	return elem;
}

void Repository::updateElem(Project p,const char* gitPath, int noOfBranches, int totalNoOfCommits) {
	if (findElem(p)) {
		for (int i = 0; i < elem.size(); i++)
			if (elem[i] == p) {
				elem[i].setGitPath(gitPath);
				elem[i].setNoOfBranches(noOfBranches);
				elem[i].setTotalNoOfCommits(totalNoOfCommits);
			}
	}
}