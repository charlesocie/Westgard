//
// Created by charles.socie on 16/03/2018.
//

#include "WestgardResult.h"

/** @class WestgardResult
* @details Class WestgardResult is build with one EWGResult,one mean and one SD, it's use to return a result of the evaluation*/

/**
 * @details WestgardResult Constructor
 */
WestgardResult::WestgardResult(){}

/**
* @details operator << overloading to write a WestgardResult on an output stream
* @param o output stream
* @param WestgardResult WestgardResult needs to be write on the ostream
* @return the current WestgardResult write with the following structure WestgardResult :
 *                                                                          - EWGResult : ...
 *                                                                          - Mean : ...
 *                                                                          - OneSD : ...
*/
ostream& operator<<( ostream& o, const WestgardResult& westgardResult){
    o<< "WestgardResult :" << endl;
    o<< "  - EWGResult : " << westgardResult.m_eWGResult << endl;
    o<< "  - Mean : " << westgardResult.m_mean << endl;
    o<< "  - OneSD : " << westgardResult.m_oneSD << endl;
    return o;
}

/**
* @details compare two WestgardConfiguration
* @param westgardConfiguration the WestgardConfiguration to compare with the current WestgardConfiguration
* @return boolean true is equals otherwise false
*/
bool WestgardResult::operator==(const WestgardResult& westgardResult) const{
    return (this->m_eWGResult == westgardResult.m_eWGResult && this->m_mean == westgardResult.m_mean && this->m_oneSD == westgardResult.m_oneSD);
}

/**
 * @details convert a WestgardResult into a string
 * @return a string description of the WestagardResult
 */
string WestgardResult::Tostring() {
    string result;
    string result1;
    string result2;
    string result3;
    result = "WestgardResult :\n" ;
    result1 = "  - EWGResult : " + convertEWGResultToString(this->m_eWGResult) ;
    result2 = "\n  - Mean : " + to_string(this->m_mean);
    result3 = "\n  - OneSD : " + to_string(this->m_oneSD) ;
    result = result + result1 + result2 + result3;
    return result;
}

string WestgardResult::convertEWGResultToString(EWGResult enu){
    string result ;
    if(enu == WESTGARD_OK){
        result = "WESTGARD OK all rules evaluation passe successfully";
    }
    else if(enu == FAILED_1_2S){
        result = "Rule 1 2s evaluation failed";
    }
    else if(enu == FAILED_1_3S){
        result = "Rule 1 3s evaluation failed";
    }
    else if(enu == FAILED_2_2S){
        result = "Rule 2 2s evaluation failed";
    }
    else if(enu == FAILED_2OF3_2S){
        result = "Rule 2 of 3 2s evaluation failed";
    }
    else if(enu == FAILED_R_4S){
        result = "Rule R 4s evaluation failed";
    }
    else if(enu == FAILED_X_1S){
        result = "Rule X 1s evaluation failed";
    }
    else if(enu == FAILED_XX){
        result = "Rule Xx evaluation failed";
    }
    else if(enu == FAILED_XT){
        result = "Rule XT evaluation failed";
    }
    else {
        result = "evaluation failed no value to evaluate";
    }
    return result;
}