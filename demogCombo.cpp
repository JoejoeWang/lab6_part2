#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {
    out << "Combo Info: ";
    out << ComboD.printState();
    out << "\nNumber of Counties: " << ComboD.getCountNum();
    out << " County Demographics Info: comboData, " << ComboD.getState()<<endl;
    out << "\nEducation info: " << "\n";
    //out << std::setprecision(2) << std::fixed;
    out << "(Bachelor or more): " << ComboD.getBAup() << "\%";
    out << " and total: " << ComboD.getBAupCount();
    out << "\n(high school or more): " <<ComboD.getHSup() << "\%";
    out << " and total: " << ComboD.getHSupCount();
    out << "\npersons below poverty: " << ComboD.getBelowPoverty() << "\%";
    out << " and total: " << ComboD.getBelowPovertyCount();
    out << "\nTotal population: " << ComboD.getPop();
    out  << "\ncommunity racial demographics: " << ComboD.getrace() << endl;
    return out;
}
