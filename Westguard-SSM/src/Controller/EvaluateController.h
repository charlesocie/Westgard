//
// Created by charles.socie on 05/03/2018.
//

#ifndef WESTGARDBRICK_EVALUATECONTROLLER_H
#define WESTGARDBRICK_EVALUATECONTROLLER_H


#include "../Model/IRule.h"
#include "EWGResult.h"
#include "Measure.h"
#include "ERulesName.h"
#include "EUpdateResult.h"
#include "WestgardResult.h"
#include "WestgardConfiguration.h"
#include "../DataMapper/RulesDataMapper.h"
#include "../Model/Rule_1_2s.h"
#include "../Model/Rule_1_3s.h"
#include "../Model/Rule_2_2s.h"
#include "../Model/Rule_R_4s.h"
#include "../Model/Rule_Xx.h"
#include "../Model/Rule_XT.h"
#include "../Model/Rule_X_1s.h"
#include "../Model/Rule_2of3_2s.h"
#include <math.h>

class EvaluateController {
    friend class EvaluateControllerTest;

private:
    /*ATTRIBUTS*/
    /** EvaluateController instance*/
    static EvaluateController *ms_instance;
    /** containt the list of the 8 Rule Westgard algorithm recommend to evaluate*/
    IRule* m_rulesList[8];
    /** decided the algorithm action if Rules_1_2s is not failed*/
    bool m_evaluateParameterizableRulesIf1_2sSucced;


    /*METHODES*/
    void createRules();
    WestgardResult evaluateRules(const list<float> listValueMeasure, const float mean, const float oneSD);
    WestgardResult evaluation1_3sto_XT(const list<float> listValueMeasure, WestgardResult* m_westgardResult);
    WestgardResult evaluationParameterizableRules(const list<float> listValueMeasure, WestgardResult* m_westgardResult);
    float calculate1SDWithTargetAndTolerance(const float target, const float tolerance);
    list<float> sortMeasureByDate(list<Measure> listMeasure);
    float calculateMean(list<float> measure);
    float calculate1SDWithMean(list<float> measure, const float mean);


protected:

    /*CONSTRUCTOR*/
    EvaluateController();

public:

    /*DESTRUCTOR*/
    ~EvaluateController();

    /*METHODES*/
    WestgardResult evaluateWestgard(list<Measure> list);
    WestgardResult evaluateRulesWithTargetAndTolerance(const list<Measure> listMeasure, const float target, const float tolerance);
    WestgardResult evaluateRulesWithMeanAnd1SD(const list<Measure> listMeasure, const float mean, const float oneSD);
    EUpdateResult updateRuleWithNameAndStatement(const ERulesName ruleName, const bool statement);
    EUpdateResult updateRuleWithNameStatementAndValue(const ERulesName ruleName, const bool statement, const int value);
    EUpdateResult updateEvaluateParameterizableRulesIf1_2sSucceed(const bool statement);
    WestgardConfiguration getWestgardConfiguration()const ;


    /*SETTER*/
    /**
     * @details set evaluateParameterizableRulesIf1_2sSucced to know whitch Rules the Westgard algorithm need to evaluate in case Rule_1_2s don't raise an error
     * @param statement evaluateParameterizableRulesIf1_2sSucced's statement
     */
    inline void setEvaluateParameterizableRulesIf1_2sSucceed(const bool statement){m_evaluateParameterizableRulesIf1_2sSucced = statement;}

    /*GETTER*/


    /**
     * @details EvaluateParameterizableRulesIf1_2sSucceed getter
     * @return bool of the current statement of EvaluateParameterizableRulesIf1_2sSucceed
     */
    inline bool getEvaluateParameterizableRulesIf1_2sSucceed() const{return m_evaluateParameterizableRulesIf1_2sSucced;}

    /**
     * @details m_rulesList getter
     * @param  int rule to return
     * @return one rule of the rule list
     */
    inline IRule* getRuleList(int i) const{return m_rulesList[i];}

    static EvaluateController *getInstance();


};


#endif //WESTGARDBRICK_EVALUATECONTROLLER_H
