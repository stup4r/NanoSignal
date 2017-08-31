#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "types.h"

using namespace std;

class Data
{
public:
    Data();
    ~Data();

    template< class T >
    void reorderVec(vector<T> &v, vector<size_t> const &order )  {
        for (unsigned int s = 1, d; s < order.size(); ++ s ) {
            for ( d = order[s]; d < s; d = order[d] ) ;
            if ( d == s ) while ( d = order[d], d != s ) swap( v[s], v[d] );
        }
    }

    void clearAll();
    void reorderData(vector<size_t>&);

    vector<string> fileNames;
    vector< vector<dataType> > defData;
    vector< vector<dataType> > varData;
    vector< vector<dataType> > varMeans;

    map<string, int> parameters = {
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
        {"varBarSize", 100}
    };

};

#endif // DATA_H
