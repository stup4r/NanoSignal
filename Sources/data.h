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

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "types.h"

using namespace std;

/**
 * @brief The Data class Data container.
 * Contains the imported files, filenames, processed data, calculated values and parameters.
 */
class Data
{
public:
    Data();
    ~Data();

    /**
     * Reorders vector v, using indices of vector order.
     * @param v Vector whos order needs to be changed.
     * @param order Vector of new indices as new order.
     */
    template< class T >
    void reorderVec(vector<T> &v, vector<size_t> const &order )  {
        for (unsigned int s = 1, d; s < order.size(); ++ s ) {
            for ( d = order[s]; d < s; d = order[d] ) ;
            if ( d == s ) while ( d = order[d], d != s ) swap( v[s], v[d] );
        }
    }

    void clearAll();
    void reorderData(vector<size_t>&);

    vector<string> fileNames; /**< Imported file names */
    vector< vector<dataType> > defData; /**< Imported files - they get overwritten with Flattening or Filtering */
    vector< vector<dataType> > varData; /**< Variance data */
    vector< vector<dataType> > varMeans; /**< Variance means */
    vector< vector<dataType> > statistic; /**< Vector containing data for a box plot */

    map<string, int> parameters = { /** Map of parameters and their values */
        {"samplingFreq",20000},
        {"isDownsampled", 0},
        {"downSamplingFreq", 200},
        {"isFlattening", 0},
        {"flatWin", 4000000},
        {"flatWindowed", 1},
        {"flatOrder", 1},
        {"isFiltering", 0},
        {"filter", 2},
        {"filtWin", 400000},
        {"varWin", 200000},
        {"winValueChanged", 0},
        {"varBarSize", 100}
    };

};

#endif // DATA_H

