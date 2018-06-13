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

#ifndef READER_H
#define READER_H

#include "process.h"
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

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
