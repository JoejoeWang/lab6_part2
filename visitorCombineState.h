#ifndef VCOMBOS_H
#define VCOMBOS_H


#include "visitorCombine.h"
#include <memory>

class visitorCombineState : public visitorCombine {
public:
    visitorCombineState() {}

	void visit(shared_ptr<demogData> obj) {
        //fill in
        //cout << "h?" << endl;
        if(allComboDemogData.size()==0)
        {
            //cout << "he!" << endl;
            demogCombo first;
            first = demogCombo(obj);
            pair<string, shared_ptr<demogCombo>> NUMONE (obj->getStateName(),make_shared<demogCombo>(first));
            allComboDemogData.insert(NUMONE);
        }
        else
        {
            bool in = false;
            for(auto entry : allComboDemogData)
            {
                if(entry.first == obj->getStateName())
                {
                    entry.second->popUpdate(*obj);
                    in = true;
                }
            }
            if(in == false)
            {
                demogCombo newone;
                newone = demogCombo(obj);
                pair<string, shared_ptr<demogCombo>> Firstterm (obj->getStateName(),make_shared<demogCombo>(newone));
                allComboDemogData.insert(Firstterm);
            }
        }
    }
    
    void visit(shared_ptr<psData> obj) {
        //fill in
        if(allComboPoliceData.size()==0)
        {
            psCombo first;
            first = psCombo(*obj);
            pair<string, shared_ptr<psCombo>> NUMONE (obj->getStateName(),make_shared<psCombo>(first));
            allComboPoliceData.insert(NUMONE);
        }
        else
        {
            bool in = false;
            for(auto entry : allComboPoliceData)
            {
                if(entry.first == obj->getStateName())
                {
                    entry.second->Update(*obj);
                    in = true;
                }
            }
            if(in == false)
            {
                psCombo newone;
                newone = psCombo(*obj);
                pair<string, shared_ptr<psCombo>> Firstterm (obj->getStateName(),make_shared<psCombo>(newone));
                allComboPoliceData.insert(Firstterm);
            }
        }
    }

    void visit(shared_ptr<psCombo> obj) {}
    private:
       //inherited
};

#endif
