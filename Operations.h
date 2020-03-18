#pragma once
#include "ProjectG.h"
#include "Repo.h"
#include "REpoArrayy.h"

void filterProjects(Project Projects[], int n, int a, int b, Project projFilter[], int& m);
void filterProjectsWithRepoArray(RepositoryArray& repa, int a, int b, Project projFilter[], int& m);
void filterProjectsWithRepo(Repository& rep, int a,int b, vector<Project>& projFilter);
void deleteProjectsWithCommitsAndBranches(Repository&rep);
void deleteProjectsWithCommitsAndBranchesArray(RepositoryArray& repa);
