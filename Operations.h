#pragma once
#include "ProjectG.h"
#include "Repo.h"

void filterProjects(Project Projects[], int n, int a, int b, Project projFilter[], int& m);

void filterProjectsWithRepo(Repository& rep, int a,int b, vector<Project>& studFilter);

void deleteProjectsWithCommitsAndBranches(Repository&rep);