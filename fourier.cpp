#include "fourier.h"

Fourier::Fourier()
{

}
Fourier::~Fourier(){

}
void Fourier::setSamplingFreq(int n){
    this->samplingFreq = n;
}

unsigned long Fourier::getSizeN(){
    return this->sizeN;
}

void Fourier::doProcessOne(DataLink& datalink){

    // Pay attention! If multithreaded, its gonna override files with FFTs!

    unsigned long m = 1;
    size_t size = (*datalink.file).size();
    while (power(m) <= size) {m++;}
    m = m-1;
    unsigned long N = power(m);
    this->sizeN = N;
    vector<dataType> y(N);
    vector<dataType> x;
    copy_n((*datalink.file).begin(), N, back_inserter(x));
    (*datalink.file).clear();

    FFT(1,m,x,y);

    copy_n(x.begin(), N/2, back_inserter((*datalink.file)));
    for(unsigned int i = 0; i < (*datalink.file).size(); ++i){
        (*datalink.file)[i] = abs((*datalink.file)[i]);
    }
}
