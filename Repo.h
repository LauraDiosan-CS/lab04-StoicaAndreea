#pragma once
#include "ProjectG.h"
#include<vector>

using namespace std;

class Repository
{
private:
	vector<Project> elem;
public:
	Repository();
	void addElem(Project);
	bool findElem(Project);
	void deleteElem(Project);
	void updateElem(Project, const char*,int,int);
	Project getItemFromPos(int);
	vector<Project>getAll();
	int getSize();
	~Repository();
};
