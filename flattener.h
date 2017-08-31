#ifndef FLATTENER_H
#define FLATTENER_H

#include "polyfit.h"
#include "process.h"

class Flattener : public Process
{
public:
    Flattener();
    ~Flattener();

    void doProcessOne(DataLink&);
};

#endif // FLATTENER_H
