#ifndef FILTER_H
#define FILTER_H
#include "process.h"

class Filter : public Process
{
public:
    Filter();
    ~Filter();

    void doProcessOne(DataLink&);
};

#endif // FILTER_H
