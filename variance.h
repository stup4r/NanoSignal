#ifndef VARIANCE_H
#define VARIANCE_H

#include "types.h"
#include "process.h"
#include <cmath>

class Variance : public Process
{
public:
    Variance();
    ~Variance();

    dataType oneVariance(vector<dataType>&);
    void doProcessOne(DataLink&);
    void cutoffVariancce(vector<vector<dataType> >&, double);
    void averageBars(Data& data);
    dataType getMean(vector<dataType>&);
    dataType getError(vector<dataType>&);
    dataType getMedian(vector<dataType>);
    void getBoxplotStat(vector<vector<dataType> >&, vector<vector<dataType> >&);

};

#endif // VARIANCE_H
