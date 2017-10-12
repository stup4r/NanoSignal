#ifndef VARIANCE_H
#define VARIANCE_H

#include "types.h"
#include "process.h"
#include <cmath>

/**
 * @brief The Variance class Child class of Process that calculates and manipulates variance.
 */
class Variance : public Process
{
public:
    Variance();
    ~Variance();

    dataType oneVariance(vector<dataType>&);
    void doProcessOne(DataLink&);
    void cutoffVariancce(vector<vector<dataType> >&, double);
    void averageBars(Data&);
    dataType getMean(vector<dataType>&);
    dataType getError(vector<dataType>&);
    dataType getMedian(vector<dataType>);
    void getBoxplotStat(Data&);

};

#endif // VARIANCE_H
