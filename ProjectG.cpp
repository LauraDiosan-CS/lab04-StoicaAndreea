#include "ProjectG.h"
#include <string.h>

Project::Project() {
	this->gitPath = NULL;
	this->noOfBranches = 0;
	this->totalNoOfCommits = 0;
}

Project::Project(const char* gitPath, int noOfBranches, int totalNoOfCommits) {
	this->gitPath = new char[strlen(gitPath)+1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
	this->noOfBranches = noOfBranches;
	this->totalNoOfCommits = totalNoOfCommits;
}

Project::Project(const Project& p) {
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath)+1, p.gitPath);
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
}

char* Project::getGitPath() {
	return this->gitPath;
}

int Project::getNoOfBranches() {
	return this->noOfBranches;
}

int Project::getTotalNoOfCommits() {
	return this->totalNoOfCommits;
}

void Project::setGitPath(const char* gitPath) {
	if (this->gitPath) delete[]this->gitPath;
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
}

void Project::setNoOfBranches(int noOfBranches) {
	this->noOfBranches = noOfBranches;
}

void Project::setTotalNoOfCommits(int totalNoOfCommits) {
	this->totalNoOfCommits = totalNoOfCommits;
}

Project::~Project() {
	if (gitPath) delete[] gitPath;
	this->gitPath = NULL;
	this->noOfBranches = -1;
	this->totalNoOfCommits = -1;
}

Project& Project::operator=(const Project& p) {
	if (this == &p) return *this; //in case of self assignment
	if (gitPath)delete[] gitPath;
	gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	noOfBranches = p.noOfBranches;
	totalNoOfCommits = p.totalNoOfCommits;
	return*this;

}

bool Project::operator == (const Project& p) {
	return(strcmp(this->gitPath, p.gitPath) == 0) and (this->noOfBranches == p.noOfBranches) and (this->totalNoOfCommits == p.totalNoOfCommits);
}

/*
ostream& operator<<(ostream& os, Project p) {
	os << p.gitPath << " " << p.noOfBranches<<" "<<p.totalNoOfCommits << endl;
	return os;
}*/