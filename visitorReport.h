#ifndef VISITREP_H
#define VISITREP_H

#include "psData.h"
#include "demogData.h"
#include "visitor.h"

class visitorReport : public Visitor {
public:
	void visit(psData *e){};
	void visit(psCombo *e){
		cout << "print aggregate police shooting data";
		cout << "\nState info: "<< e->getState();
		cout << ", total states: 1";
		cout << "\nNumber of incidents: " << e->getNumberOfCases();
		cout << "\nRacial demographics of state incidents: "<< "Racial Demographics Info: \n";
		cout << e->getRacialData();
	}
	void visit(demogData *p){
		cout << "print summary demog Data:";
		cout << "\nRegion info: " << "comboData, " << p->getState();
		cout << "\nEducation info:";
		cout << "\n(Bachelor or more): " << p->getBAup() << "% and total: " << p->getBAupCount();
		cout << "\n(high school or more): " << p->getHSup()<< "% and total: " << p->getHSupCount();
		cout << "\nTotal population: " << p->getPop();
		cout << "\nRacial Demographics Info: \n";
		cout << p->getrace();
	}

    private:
    	int numVisited;
};

#endif