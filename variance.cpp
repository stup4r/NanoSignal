#include "variance.h"

Variance::Variance()
{

}
Variance::~Variance(){

}

/**
 * Function that calculates variance of passed vector of data. Returns one value (of type double).
 * @param v - vector of doubles as data to be calculated variance of.
 */

dataType Variance::oneVariance(vector<dataType>& v) {
    dataType v_sum = 0.0;
    int n = v.size();
    for (int i = 0; i < n; ++i)
        v_sum += v[i];
    dataType v_average = v_sum/n;
    dataType var_sum = 0.0;
    dataType tmp = 0.0;
    dataType v_variance = 0.0;
    for (int i = 0; i < n; ++i) {
        tmp = pow((v[i]-v_average), 2);
        var_sum += tmp;
    }
    return v_variance = var_sum/(n-1);
}

void Variance::doProcessOne(DataLink& datalink){
    vector<dataType> tmp;
    // In the following iteration, i is less and equal to the rounded-down int, to avoid loosing one window
    for (unsigned int i = 1; i <= ((*datalink.file).size())/(this->windowSize); ++i) {
        vector<dataType> cutData(&(*datalink.file)[(this->windowSize)*(i-1)], &(*datalink.file)[i*(this->windowSize)]);
        tmp.push_back(oneVariance(cutData));
    }
    (*datalink.varfile) = tmp;
    tmp.clear();
}

void Variance::cutoffVariancce(vector<vector<dataType> >& varData, double cutoff){
    for (unsigned int i = 0; i < varData.size(); ++i){
        varData[i].erase(remove_if(varData[i].begin(), varData[i].end(), [cutoff](double n) {return n > cutoff;}), varData[i].end());
    }
}

dataType Variance::getMean(vector<dataType>& v){
    return accumulate(v.begin(), v.end(),0.0)/v.size();
}

dataType Variance::getError(vector<dataType>& v){
    dataType stDev = sqrt(oneVariance(v));
    return stDev/sqrt(v.size());
}

void Variance::averageBars(Data& data){
    data.varMeans.clear();
    vector<dataType> means;
    vector<dataType> errors;
    int meanWin = data.parameters["varBarSize"];

    for (unsigned int i = 0; i < data.varData.size(); ++i){
        for (unsigned int j = 1; j<= (data.varData[i].size())/meanWin; ++j){
            vector<dataType> cutData(&(data.varData[i])[meanWin*(j-1)], &(data.varData[i])[j*meanWin]);
            means.push_back(getMean(cutData));
            errors.push_back(getError(cutData));
        }
        data.varMeans.push_back(means);
        data.varMeans.push_back(errors);
        means.clear();
        errors.clear();
    }
}

dataType Variance::getMedian(vector<dataType> v){
    dataType median;
    size_t size = v.size();
    sort(v.begin(), v.end());
    if (size % 2 == 0) {
        median = (v[size / 2 -1] + v[size/2])/2;
    }
    else{
        median = v[size/2];
    }

    return median;
}

void Variance::getBoxplotStat(vector<vector<dataType> >& varData, vector<vector<dataType> >& stat){
    stat.clear();
    for (unsigned int i = 0; i < varData.size(); ++i){

        dataType Q1, Q2, Q3, IQR, min, max;
        vector<dataType> firsthalf, secondhalf, v;
        v = varData[i];
        size_t size = v.size();

        sort(v.begin(), v.end());
        if (size % 2 == 0) {
            for (unsigned int i = 0; i < size; ++i){
                if (i < size/2){firsthalf.push_back(v[i]);}
                else{secondhalf.push_back(v[i]);}
            }
        }
        else{
            for (unsigned int i = 0; i < size; ++i){
                if (i < size/2){
                    firsthalf.push_back(v[i]);
                }
                else{
                    secondhalf.push_back(v[i]);
                }
            }
            firsthalf.push_back(v[size/2]);
        }
        Q2 = getMedian(v);
        Q1 = getMedian(firsthalf);
        Q3 = getMedian(secondhalf);
        IQR = Q3 - Q1;
        min = Q1 - 1.5*IQR;
        max = Q3 + 1.5*IQR;

        stat.push_back({min, Q1, Q2, Q3, max});

        vector<dataType> outliers;
        for (unsigned int i=0; i < v.size(); ++i){
            if(v[i] < min or v[i] > max) {outliers.push_back(v[i]);}
        }
        stat.push_back(outliers);

    }
}
