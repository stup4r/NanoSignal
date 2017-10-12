#ifndef READER_H
#define READER_H

#include "process.h"

using namespace std;

/**
 * @brief The Reader class Child class of Process that imports files.
 */
class Reader : public Process
{
public:
    Reader();
    ~Reader();
    void doProcessOne(DataLink&);

    void setIsDownsampled(bool);
    void setDownSamplingStep(int);

private:
    bool isDownsampled = false; /**< Downsampling trigger */
    int downSamplingStep = 200; /**< Downsampled frequency */
};

#endif // READER_H
