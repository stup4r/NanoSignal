#ifndef FLATTENER_H
#define FLATTENER_H

#include "polynomialFit.h"
#include "process.h"

/**
 * @brief The Flattener class Class that allows flattening of the signal.
 * Class inherits from the Process class.
 * doProcesOne is a mamber of the class Flattener and overrides the function from the mother class Process.
 */
class Flattener : public Process
{
public:
    Flattener();
    ~Flattener();

    void doProcessOne(DataLink&);
};

#endif // FLATTENER_H
