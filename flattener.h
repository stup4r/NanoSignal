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

#ifndef FLATTENER_H
#define FLATTENER_H

#include "polynomialFit.h"
#include "process.h"

/**
 * @brief The Flattener class Class that allows flattening of the signal.
 * Class inherits from the Process class.
 * doProcesOne is a mamber of the class Flattener and overrides the function from the mother class Process.
 */
class Flattener : public Process
{
public:
    Flattener();
    ~Flattener();

    void doProcessOne(DataLink&);
};

#endif // FLATTENER_H
