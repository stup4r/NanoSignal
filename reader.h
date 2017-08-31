#ifndef READER_H
#define READER_H

#include "process.h"

using namespace std;

class Reader : public Process
{
public:
    Reader();
    ~Reader();
    void doProcessOne(DataLink&);

    void setIsDownsampled(bool);
    void setDownSamplingStep(int);

private:
    bool isDownsampled = false;
    int downSamplingStep = 200;
};

#endif // READER_H
