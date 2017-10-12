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

#include "reader.h"
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

Reader::Reader()
{

}
Reader::~Reader(){

}

void Reader::setIsDownsampled(bool ds){
    this->isDownsampled = ds;
}
void Reader::setDownSamplingStep(int dss){
    this->downSamplingStep = dss;
}

/**
 * \brief Function called to open a (one only) file and import its data into a vector.
 * Dependin on whether the file contains commenting character "#", import is different. This is based on the fact that currently only prototype (single column files) or JPK (multiple column files with "#" comments) are used.
 * Function looks for the keywords: "Vertical Deflection" and calculates the number of a column it shows up after the acquisition (can be different column).
 * @param name - string that coresponds to the filename of the file being imported (and its path).
 * @param mydata - reference to the vector where data will be stored.
 */
void Reader::doProcessOne(DataLink& datalink){

    vector<dataType> tmp;

    fstream isLine((*datalink.name).c_str());
    string isFirstLine;
    getline(isLine, isFirstLine);

    if (isFirstLine[0] == '#'){
        int clmn=0;
        fstream is((*datalink.name).c_str());
        string line;


        while(!is.eof()){
                getline(is, line);

                if (line.length() == 0 || line[0] == '#'){
                    if (line.find("Vertical Deflection") != std::string::npos){
                        size_t defPosition = line.find("Vertical Deflection");
                        size_t n = std::count(line.begin(), line.begin()+defPosition, '"');
                        clmn = n/2;
                    }
                }
                else{

                    for (int i = 0; i<clmn;++i){

                        size_t found = line.find(' ');
                        if (found!=std::string::npos){
                            line.erase(0,found+1);
                        }
                    }

                istringstream ss(line);
                double c;
                ss >> c;
                tmp.push_back(c);
                }
            }

    }
    else{

        ifstream is((*datalink.name).c_str());
        istream_iterator<dataType> start(is), end;
        vector<dataType> extr(start, end);
        tmp = extr;
        extr.clear();
    }

    if (this->isDownsampled == true) {
        vector<dataType> tmp2;
        for(unsigned int i = 0; i<tmp.size(); i += (this->downSamplingStep)){
            tmp2.push_back(tmp[i]);
        }
        (*datalink.file) = tmp2;
        tmp2.clear();
    }

    else {
    (*datalink.file) = tmp;
    tmp.clear();
    }
}
