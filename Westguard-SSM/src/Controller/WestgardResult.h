//
// Created by charles.socie on 16/03/2018.
//

#ifndef WESTGARDBRICK_WESTGARDRESULT_H
#define WESTGARDBRICK_WESTGARDRESULT_H


#include "EWGResult.h"
#include<iostream>

using namespace std;

class WestgardResult {
private:
    /**
     * Westgard algorithm result
     */
    EWGResult m_eWGResult;
    /**
     * Mean used to evaluate the rules
     */
    float m_mean;
    /**
     * standard deviation used to evaluate the rules
     */
    float m_oneSD;

public:
    /*Constructor*/
    WestgardResult();

    /*Setter*/
    /**
     * @details EWGResult Setter
     * @param ewgResult EWGResult to set
     */

    inline void setEWGResult(const EWGResult ewgResult){this->m_eWGResult = ewgResult;}

    /**
     * @details Mean Setter
     * @param mean value of the mean
     */
    inline void setMean(const float mean){this->m_mean = mean;}

    /**
     * @details OneSD Setter
     * @param oneSD value of the SD
     */
    inline void setOneSD(const float oneSD){this->m_oneSD = oneSD;}

    /*Getter*/
    /**
     * @details EWGResult Getter
     * @return eWGResult as EWGResult
     */
    inline EWGResult getEWGResult()const {return  this->m_eWGResult;}

    /**
     * @details Mean Getter
     * @return Mean as a float
     */
    inline float getMean()const {return  this->m_mean;}

    /**
     * @details OneSD Getter
     * @return OneSD as a float
     */
    inline float getOneSD()const {return  this->m_oneSD;}

    /*Operator*/
    string Tostring();
    string convertEWGResultToString(EWGResult enu);
    friend ostream& operator<<( ostream& , const WestgardResult&);
    bool operator==(const WestgardResult& westgardResult) const;
};


#endif //WESTGARDBRICK_WESTGARDRESULT_H
