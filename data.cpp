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

#include "data.h"

Data::Data()
{

}
Data::~Data(){

}

/**
 * @brief Data::clearAll Clears all the vectors from the Data container.
 * Calls the clear() function of an STL vector to remove all the content from it.
 */
void Data::clearAll(){
    this->defData.clear();
    this->varData.clear();
    this->fileNames.clear();
    this->varMeans.clear();
    this->statistic.clear();
}

/**
 * @brief Data::reorderData Re-orders vectors within the data container.
 * Calls reorderVec function to change the order of all vector members within the class by using a set of indices stored in vector "order".
 * @param order Set of indices to re-arrange member vectors.
 */
void Data::reorderData(vector<size_t>& order){
    reorderVec(this->defData, order);
    reorderVec(this->varData, order);
    reorderVec(this->fileNames, order);
    this->varMeans.clear();
    this->statistic.clear();
}
