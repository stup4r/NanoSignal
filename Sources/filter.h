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

#ifndef FILTER_H
#define FILTER_H
#include "process.h"

class Filter : public Process
{
public:
    Filter();
    ~Filter();

    void doProcessOne(DataLink&);
};

#endif // FILTER_H
