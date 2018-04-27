//
// Created by charles.socie on 15/03/2018.
//

#ifndef WESTGARDBRICK_WESGARDCONFIGURATION_H
#define WESTGARDBRICK_WESGARDCONFIGURATION_H

#include<iostream>
#include "RuleSetting.h"
#include <list>

using namespace std;

class WestgardConfiguration {

private:
    /**
     * list of the rule's setting
     */
    list<RuleSetting> m_rulelist;
    /**
     * boolean of the setting evaluateParameterizableRuleIf1_2sSucceed
     */
    bool m_evaluateParameterizableRuleIf1_2sSucceed;

    list<RuleSetting>::iterator beginlist;
    list<RuleSetting>::iterator endlist;

public:
    /*Constructor*/
    WestgardConfiguration(list<RuleSetting> rulelist, bool evaluateParameterizableRuleIf1_2sSucceed);

    /*Setter*/
    /**
     * @details EvaluateParameterizableRuleIf1_2sSucceed setter
     * @param boolean to update EvaluateParameterizableRuleIf1_2sSucceed
     */
    inline void setEvaluateParameterizableRuleIf1_2sSucceed(const bool b){this->m_evaluateParameterizableRuleIf1_2sSucceed = b;}
    void setrule(const ERulesName name,const bool statement,const int value = 0);

    /*Getter*/
    /**
     * @details rulelist's getter
     * @return  rulelist
     */
    inline list<RuleSetting> getListRules()const {return m_rulelist;}
    /**
     * @details evaluateParameterizableRuleIf1_2sSucceed's getter
     * @return bool of evaluateParameterizableRuleIf1_2sSucceed
     */
    inline bool getEvaluateParameterizableRuleIf1_2sSucceed()const {return m_evaluateParameterizableRuleIf1_2sSucceed;}

    /*Operator*/
    friend ostream& operator<<( ostream& , const WestgardConfiguration&);
    bool operator==(const WestgardConfiguration& westgardConfiguration) const;
};


#endif //WESTGARDBRICK_WESGARDCONFIGURATION_H
