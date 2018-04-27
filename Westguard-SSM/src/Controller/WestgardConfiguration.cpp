//
// Created by charles.socie on 15/03/2018.
//

#include "WestgardConfiguration.h"

/** @class WestgardConfiguration
* @details Class WestgardConfiguration is build with a liste of RuleSetting and a boolean evaluateParameterizableRuleIf1_2sSucceed, it's use to return the value of the setting file
*/

/**
 * @details WesgardConfiguration constructor
 * @param evaluateParameterizableRuleIf1_2sSucceed bool of evaluateParameterizableRuleIf1_2sSucceed
 */
WestgardConfiguration::WestgardConfiguration(list<RuleSetting> rulelist, bool evaluateParameterizableRuleIf1_2sSucceed) : m_rulelist(rulelist) ,m_evaluateParameterizableRuleIf1_2sSucceed(evaluateParameterizableRuleIf1_2sSucceed){
    beginlist = m_rulelist.begin();
    endlist = m_rulelist.end();
}



/**
 * @details listrules setter
 * @param ERulesName rule to update
 * @param boolean to update rule statement
 * @param int value to update if the rule has one
 */
void WestgardConfiguration::setrule(const ERulesName name,const bool statement,const int value){
    int i = 0;
	switch(name){
    case RULE_1_2S : i=1;
    break;
    case RULE_1_3S : i=2;
    break;
    case RULE_2_2S : i=3;
    break;
    case RULE_2OF3_2S : i=4;
    break;
    case RULE_R_4S : i=5;
    break;
    case RULE_X_1S : i=6;
    break;
    case RULE_XX : i=7;
    break;
    case RULE_XT : i=8;
    break;
    default :
    	break;
    }
	list<RuleSetting>::iterator iteratorList;
    iteratorList = this->beginlist;
    for (int j=1; j<i; j++){
    	iteratorList++;
    }
    RuleSetting r = *iteratorList;
    r.setIsActive(statement);
    if(value!=0){
        r.setValue(value);
    }
    *iteratorList = r;
}

/**
* @details operator << overloading to write a WestgardConfiguration on an output stream
* @param o output stream
* @param WestgardConfiguration WestgardConfiguration needs to be write on the ostream
* @return the current WestgardConfiguration write with the following structure WestgardConfiguration :
 *                                                                                                      - Rule
 *                                                                                                      - Rule
 *                                                                                                      - ...
 *                                                                                                      - ParameterizableRule
*/
ostream&  operator<<( ostream& o,const WestgardConfiguration& westgardConfiguration) {
    o << "WestgardConfiguration :" << endl;
    list<RuleSetting>::iterator iteratorList;
    iteratorList = westgardConfiguration.beginlist;
    do{
        o << "  - " << *iteratorList;
        iteratorList++;
    }while (iteratorList != westgardConfiguration.endlist);
    o<< "  - evaluateParameterizableRuleIf1_2sSucceed : " << westgardConfiguration.m_evaluateParameterizableRuleIf1_2sSucceed;
    return o;
}

/**
 * @details compare two WestgardConfiguration
 * @param westgardConfiguration the WestgardConfiguration to compare with the current WestgardConfiguration
 * @return boolean true is equals otherwise false
 */
bool WestgardConfiguration::operator==(const WestgardConfiguration& westgardConfiguration) const{
    list<RuleSetting>::const_iterator iteratorList;
    list<RuleSetting>::const_iterator iteratorListWestgardConfiguration;
    iteratorList = this->m_rulelist.begin();
    bool egal = true;
    if(this->m_rulelist.size() == westgardConfiguration.m_rulelist.size()) {
        iteratorListWestgardConfiguration = westgardConfiguration.m_rulelist.begin();
        for (int i = 0; i < 8; i++) {
            RuleSetting r1 = *iteratorList;
            RuleSetting r2 = *iteratorListWestgardConfiguration;
            if (r1 == r2) {
            } else {
                egal = false;
            }
            iteratorList++;
            iteratorListWestgardConfiguration++;
        }
        if (this->m_evaluateParameterizableRuleIf1_2sSucceed !=
            westgardConfiguration.m_evaluateParameterizableRuleIf1_2sSucceed) {
            egal = false;
        }
    } else{
        egal = false;
    }
    return egal;
}
