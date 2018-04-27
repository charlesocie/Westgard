//
// Created by charles.socie on 15/03/2018.
//

#include "RuleSetting.h"

/** @class RuleSetting
* @details Class RuleSetting is use to return the setting of the current rules in the xml file
*/

/**
 * @details RuleSetting constructor
 * @param isActive define if the rule is active or not
 * @param value define the number of value to evaluate
 */
RuleSetting::RuleSetting(ERulesName name) : m_name(name), m_isActive(true), m_value(-1){

}

/**
 * @details operator << overloading to write a RuleSetting on an output stream
 * @param o output stream
 * @param RuleSetting RuleSetting needs to be write on the ostream
 * @return the current RuleSetting write with the following structure Rule's name : statement , value(if exist)
 */
ostream&  operator<<( ostream& o,const RuleSetting& ruleSetting) {
    o << ruleSetting.m_name << " : " << ruleSetting.m_isActive;
    if(ruleSetting.m_value != -1){
        o << " , " << ruleSetting.m_value << endl;
    } else{
        o<<endl;
    }
    return o;
}

/**
 * @details compare two RuleSetting
 * @param RuleSetting the WestgardConfiguration to compare with the current RuleSetting
 * @return boolean true is equals otherwise false
 */
bool RuleSetting::operator==(RuleSetting const ruleSetting)const {
    bool egal;
    if(this->m_name == ruleSetting.m_name && this->m_value == ruleSetting.m_value && this->m_isActive == ruleSetting.m_isActive){
        egal = true;
    } else{
        egal = false;
    }
    return egal;
}
