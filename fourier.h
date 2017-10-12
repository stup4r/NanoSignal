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
