#include "UI.h"
#include <iostream>
using namespace std;

void addProj(ServiceArray& s) {
	Project proj;
	cout << "Give the Project:";
	cin >> proj;
	s.addProject(proj);
	cout << "the Project has been successfully added" << endl;
}


void findProj(ServiceArray& serv) {
	Project proj;
	cout << "Give the Project:";
	cin >> proj;
	int rez = serv.findOne(proj);
	if (rez>=0) cout << "The Project has been found!" << endl;
	else cout << "The Project has not been found!" << endl;
}

void delProj(ServiceArray& serv) {
	Project proj;
	cout << "Give the Project:" << endl;;
	cin >> proj;
	int rez = serv.delProject(proj);
	if (rez == 0) cout << "Projectul a fost  sters cu succes!" << endl;
	else cout << "Projectul NU a fost sters!" << endl;
}

void showAll(ServiceArray& serv) {
	//Project* proj = serv.getAll();
	for (int i = 0; i < serv.getSize(); i++)
		cout << serv.getItemFromPos(i).getGitPath()<<" "<< serv.getItemFromPos(i).getNoOfBranches()<<" "<< serv.getItemFromPos(i).getTotalNoOfCommits()<< endl;
}

/*
void showAlphabeticallySorted(Service& serv) {
	vector<Project> proj = serv.sortByName();
	for (Project s : proj)
		cout << s;
}
void showAgeSorted(Service& serv) {
	vector<Project> proj = serv.sortByAge();
	for (Project s : proj)
		cout << s;
}

void showFilteredProjects(Service& serv) {
	char* n = new char[10];
	int v;
	cout << "Dati subsirul cautat in nume: ";
	cin >> n;
	cout << "Dati limita de varsta:";
	cin >> v;

	vector<Project> proj = serv.filterByNameAndAge(n, v);
	for (Project s : proj)
		cout << s;
	delete[] n;
}*/

void showUI(ServiceArray& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIONS: " << endl;
		cout << "	1. Add Project " << endl;
		cout << "	2. Search Project " << endl;
		cout << "	3. Delete Project " << endl;
		cout << "	4. Show Projects " << endl;
		//cout << "	5. Afiseaza Projectii ordonati alfabetic " << endl;
		//cout << "	6. Afiseaza Projectii ordonati descrescator dupa varsta " << endl;
		//cout << "	7. Filtreaza Projectii dupa nume si varsta " << endl;
		cout << "	0. EXIT!" << endl;
		cout << "option: (number):  ";
		int opt;
		cin >> opt;
		cout <<endl;
		switch (opt) {
		case 1: {addProj(serv); break; }
		case 2: {findProj(serv); break; }
		case 3: {delProj(serv); break; }
		case 4: {showAll(serv); break; }
			  //case 5: {showAlphabeticallySorted(serv); break; }
			  //case 6: {showAgeSorted(serv); break; }
			  //case 7: {showFilteredProjects(serv); break; }
		case 0: {gata = true; cout << "BYE BYE..." << endl; }
		}
	}
}
