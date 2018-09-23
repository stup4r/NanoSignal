/*************************************************************************
 *
 *  NanoSignal: Signal analysis toolbox.
 *  Copyright (C) 2017  Petar Stupar
 *  Collective Copyright Holder.
 *  Licensed under the GPLv3.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ************************************************************************/

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

/**
 * @brief Fourier::doProcessOne FFT calculation of the signal.
 * FFt calculation is done using the FFT function from fft.h and placing the spectra in another vector within the datalink.
 * @param datalink Helper struct that connects (references) to a single file, its file name and the Fourier transform.
 */
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
