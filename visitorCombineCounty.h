#ifndef VCOMBOC_H
#define VCOMBOC_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"
#include "demogCombo.h"
#include "visitorCombine.h"
#include "parse.h"
#include <memory>
#include <fstream>
#include <cassert>

class visitorCombineCounty : public visitorCombine {
public:
    visitorCombineCounty() {
    }

    //store demographic data by county name
	void visit(shared_ptr<demogData> obj) {
        //fill in
        string regionName = obj->getRegionName();
        string key = "";
        if(regionName.find("County")!=string::npos)
        {
            key = regionName.substr(0,regionName.size()-7)+obj->getStateName();
        }
        else
        {
            key = regionName +obj->getStateName();
        }
        //cout << key << endl;
        // if(allComboDemogData.count(key)==0)
        // {
        pair<string, shared_ptr<demogCombo>> NUMONE (key,make_shared<demogCombo>(obj));
        allComboDemogData.insert(NUMONE);
        // }
        // else
        // {
        //     cout << "??" << endl;
        //     allComboDemogData[key]->popUpdate(*obj);
        // }
    }
    
    //aggregate police shooting data by county
    void visit(shared_ptr<psData> obj) {
        //fill in
        string regionName = obj->getcounty();
        //cout << regionName << endl;
        string key = "";
        if(regionName.find("County")!=string::npos)
        {
            key = regionName.substr(0,regionName.size()-7)+obj->getStateName();
        }
        else
        {
            key = regionName+obj->getStateName();
        }
        //cout << key << endl;
        if(allComboPoliceData.count(key)==0)
        {
            pair<string, shared_ptr<psCombo>> NUMONE (key,make_shared<psCombo>(*obj));
            allComboPoliceData.insert(NUMONE);
        }
        else
        {
            allComboPoliceData[key]->Update(*obj);
        }
        //cout << key << endl;
    }
    
    void visit(shared_ptr<psCombo> obj) {std::cout<<"";}
    private:
        //only inherited data at this point
};

#endif
