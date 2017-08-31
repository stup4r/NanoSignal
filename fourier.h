#ifndef FOURIER_H
#define FOURIER_H

#include "process.h"
#include "fft.h"

class Fourier : public Process
{
public:
    Fourier();
    ~Fourier();

    void setSamplingFreq(int);
    unsigned long getSizeN();
    void doProcessOne(DataLink&);

private:
    int samplingFreq = 20000;
    unsigned long sizeN = 1;
};

#endif // FOURIER_H
