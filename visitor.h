#ifndef VISITOR_H
#define VISITOR_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"
#include <memory>

/* a visitor can visit any of my specific data types */
class Visitor {
  public:
    virtual void visit(shared_ptr<psData> ps) = 0;
    virtual void visit(shared_ptr<demogData> d) = 0;
    virtual void visit(shared_ptr<psCombo> co) = 0;
};
#endif

