//
// Created by charles.socie on 15/03/2018.
//

#ifndef WESTGARDBRICK_RULESETTING_H
#define WESTGARDBRICK_RULESETTING_H
#include<iostream>
#include "ERulesName.h"

using namespace std;

class RuleSetting {

private:
    /**
     * rule's name
     */
    ERulesName m_name;
    /**
     * boolean define if the rule is active or not
     */
    bool m_isActive;
    /**
     * value of the X for the Parameterisable rule, is -1 for the other rules
     */
    int m_value = -1 ;


public:
    /*Constructor*/
    RuleSetting(ERulesName name);

    /*Getter*/
    /**
     * @details getter of name
     * @return name's statement
     */
    inline ERulesName getName()const{return m_name;}
    /**
     * @details getter of isActive
     * @return isActive's statement
     */
    inline bool getIsActive()const {return m_isActive;}
    /**
     * @details getter of value
     * @return nomber of value to evaluate
     */
    inline int getValue()const {return m_value;}

    /*Setter*/
    /**
     * @details setter of isActive
     * @param isActive rule's statement
     */
    inline void setIsActive(const bool isActive){this->m_isActive = isActive;}
    /**
     * @details setter of value
     * @param value rule's value
     */
    inline void setValue(const int value){this->m_value = value;}

    /*Operator*/
    friend ostream& operator<<( ostream& , const RuleSetting&);
    bool operator==(RuleSetting const ruleSetting)const ;
};


#endif //WESTGARDBRICK_RULESETTING_H
