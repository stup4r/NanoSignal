#ifndef FOURIER_H
#define FOURIER_H

#include "process.h"
#include "fft.h"

/**
 * @brief The Fourier class Class that allows FFT calculation of the signal.
 * Class inherits from the Process class.
 * doProcesOne is a mamber of the class Fourier and overrides the function from the mother class Process.
 */
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
