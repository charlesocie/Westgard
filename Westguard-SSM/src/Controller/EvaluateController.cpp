//
// Created by charles.socie on 05/03/2018.
//


#include "EvaluateController.h"


/** @class EvaluateController
* @details Controller allow \a WestgardInterface to communicate with the Model Package
*/

EvaluateController *EvaluateController::ms_instance = nullptr;

/** @details Constructor*/
EvaluateController::EvaluateController() : m_evaluateParameterizableRulesIf1_2sSucced(NULL){
    createRules();
    IRules_DataMapper *mapper = new RulesDataMapper();
    mapper->readToSetListRules(m_rulesList, &m_evaluateParameterizableRulesIf1_2sSucced);

}

/** @details Destructor*/
EvaluateController::~EvaluateController(){
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
EvaluateController *EvaluateController::getInstance(){
    if (NULL == ms_instance)
    {
        ms_instance =  new EvaluateController();
    }
    return ms_instance;
}

/**
 * @details file \a rulesList with the instance of all of the 8 Rules
 */
void EvaluateController::createRules(){
    m_rulesList[0] = Rule_1_2s::getInstance();
    m_rulesList[1] = Rule_1_3s::getInstance();
    m_rulesList[2] = Rule_2_2s::getInstance();
    m_rulesList[3] = Rule_2of3_2s::getInstance();
    m_rulesList[4] = Rule_R_4s::getInstance();
    m_rulesList[5] = Rule_X_1s::getInstance();
    m_rulesList[6] = Rule_Xx::getInstance();
    m_rulesList[7] = Rule_XT::getInstance();
}

/**
 * @details evaluate the Rule_1_2s then call different function depending of the evaluation result of Rule_1_2s
 * @param listValueMeasure list of \a float
 * @param mean mean of listValueMeasure
 * @param oneSD standard deviation of \a listValueMeasure
 * @return WestgardResult if Rule_1_2s evaluation is :
 *              - WESTGARD_RULE_FAILED : call \a evaluation1_3sto_XT() function
 *              - WESTGARD_RULE_OK : check evaluateParameterizableRulesIf1_2sSucced statement :
 *                                                              - true : call  evaluationParameterizableRules() function
 *                                                              - false : return a WestgardResult
 */
WestgardResult EvaluateController::evaluateRules(const list<float> listValueMeasure, const float mean, const float oneSD){
	WestgardResult* m_westgardResult = new WestgardResult();
	m_westgardResult->setMean(mean);
    m_westgardResult->setOneSD(oneSD);
    if( listValueMeasure.empty() == false) {
          ERuleStatement result1_2s;
          m_westgardResult->setEWGResult(WESTGARD_OK);
          result1_2s = m_rulesList[0]->evaluate(listValueMeasure, mean, oneSD);
          if (result1_2s == WESTGARD_RULE_FAILED) {
        	  m_westgardResult->setEWGResult(FAILED_1_2S);
              *m_westgardResult = evaluation1_3sto_XT(listValueMeasure, m_westgardResult);
          } else if (result1_2s == WESTGARD_RULE_OK) {
              if (m_evaluateParameterizableRulesIf1_2sSucced == true) {
            	  *m_westgardResult = evaluationParameterizableRules(listValueMeasure, m_westgardResult);
              } else {
                  m_westgardResult->setEWGResult(WESTGARD_OK);
              }
          } else if (result1_2s == WESTGARD_RULE_DISABLE) {
              *m_westgardResult = evaluation1_3sto_XT(listValueMeasure, m_westgardResult);
          } else {
        	  //throw Execption
          }
      }else {
        m_westgardResult->setEWGResult(FAILED_NO_VALUE);
      }
    return *m_westgardResult;
}
/**
 * @details evaluate the Rule_1_3s, Rule_2_2s (or Rule_2of3_2s) and Rule_R_4s then call different function depending of evaluation's result
 * @param listValueMeasure list of \a float
 * @param mean mean of listValueMeasure
 * @param oneSD standard deviation of \a listValueMeasure
 * @return if all the Rules are Ok call evaluationParameterizableRules() function
 *          else return WestgardResult with the failed rule inside, the mean and the SD
 */
WestgardResult EvaluateController::evaluation1_3sto_XT(const list<float> listValueMeasure, WestgardResult* m_westgardResult) {
    int i = 1;
    ERuleStatement result;
    EWGResult failedRules = WESTGARD_OK;
    while((m_westgardResult->getEWGResult() == WESTGARD_OK || m_westgardResult->getEWGResult() == FAILED_1_2S) && i<5 ){
            result = m_rulesList[i]->evaluate(listValueMeasure, m_westgardResult->getMean(), m_westgardResult->getOneSD());
            if(result == WESTGARD_RULE_FAILED){
                switch(i) {
                    case 1: failedRules = FAILED_1_3S;
                        break;
                    case 2: failedRules = FAILED_2_2S;
                        if(m_rulesList[2]->getIsActive() == true){
                            i++;
                        }
                        break;
                    case 3: failedRules = FAILED_2OF3_2S;
                        break;
                    case 4: failedRules = FAILED_R_4S;
                        break;
                }
                m_westgardResult->setEWGResult(failedRules);
            }
            i++;
    }
    if(i == 5){
    	*m_westgardResult = evaluationParameterizableRules(listValueMeasure, m_westgardResult);
    }
    return *m_westgardResult;
}

/**
 *
* @details evaluate the Rule_X_1s, Rule_Xx and Rule_XT
 * @param listValueMeasure list of \a float
 * @param mean mean of listValueMeasure
 * @param oneSD standard deviation of \a listValueMeasure
 * @return return WestgardResult depending of the result of rule's evaluation
 */
WestgardResult EvaluateController::evaluationParameterizableRules(const list<float> listValueMeasure, WestgardResult* m_westgardResult){
    int i = 5;
    ERuleStatement result;
    EWGResult failedRules;
    while((m_westgardResult->getEWGResult() == WESTGARD_OK || m_westgardResult->getEWGResult() == FAILED_1_2S) && i<8 ){
        result = m_rulesList[i]->evaluate(listValueMeasure, m_westgardResult->getMean(), m_westgardResult->getOneSD());
        if(result == WESTGARD_RULE_FAILED){
            switch(i) {
                case 5: failedRules = FAILED_X_1S;
                    break;
                case 6: failedRules = FAILED_XX;
                    break;
                case 7: failedRules = FAILED_XT;
                    break;
            }
            m_westgardResult->setEWGResult(failedRules);
        }
        i++;
    }
    return *m_westgardResult;
}

/**
 * @details calculate the standard deviation
 * @param target target of \a listMeasure
 * @param tolerance tolerance of \a listMeasure
 * @return the standard deviation of \a listMeasure
 */
float EvaluateController::calculate1SDWithTargetAndTolerance(float target, float tolerance){
    float tolMax = target+tolerance;
    float tolMin = target-tolerance;
    float SD = tolMax - tolMin;
    SD = SD/4;
    SD = round(SD * 100) / 100;
    return SD;
}

/**
 * @details sort the \a listMeasure by ascending order of their \a Date
 * @param listMeasure list of \a Measure
 * @return a list of \a float witch is link to the ordered \a listMeasure
 */
list<float> EvaluateController::sortMeasureByDate(list<Measure> listMeasure){
    list<float> listSortValues;
    if(listMeasure.empty() == false){
        list<Measure>::iterator iteratorList;
        listMeasure.sort();
        for (iteratorList = listMeasure.begin(); iteratorList != listMeasure.end(); iteratorList++) {
            Measure measure = *iteratorList;
            listSortValues.push_back(measure.getValue());
        }
    }
    return listSortValues;
}


/**
 * @details call the private fonction evaluateRules()
 * @param listMeasure list of \a Measure
 * @param mean mean of listValueMeasure
 * @param oneSD standard deviation of \a listValueMeasure
 * @return WestgardResult depending of rule's evaluation
 */
WestgardResult EvaluateController::evaluateRulesWithMeanAnd1SD(const list<Measure> listMeasure, const float mean, const float oneSD){
    return evaluateRules(sortMeasureByDate(listMeasure), mean, oneSD);
}

/**
 * @details convert target and tolerance to mean and standard deviation then call the private fonction evaluateRules()
 * @param listMeasure list of \a Measure
 * @param mean mean of listValueMeasure
 * @param oneSD standard deviation of \a listValueMeasure
 * @return WestgardResult depending of rule's evaluation
 */
WestgardResult EvaluateController::evaluateRulesWithTargetAndTolerance(const list<Measure> listMeasure, const float target,
                                                                       const float tolerance){
    return evaluateRules(sortMeasureByDate(listMeasure), target, calculate1SDWithTargetAndTolerance(target, tolerance));
}

/**
 * @details evaluate the westgard algorithm with a list a Measure
 * @param list list of Measure don't need to be sort
 * @return WestgardResult with the result of the westgard algorithm , the mean and the SD
 */
WestgardResult EvaluateController::evaluateWestgard(const list<Measure> listMeasure){
	list<float> listValue;
	float mean = 0;
	float SD = 0;
	if(listMeasure.size() != 0){
		listValue = sortMeasureByDate(listMeasure);
		mean = calculateMean(listValue);
		SD = calculate1SDWithMean(listValue, mean);
	}
    return evaluateRules(listValue, mean, SD);
}

/**
 * @details update a Rule's statement
 * @param ruleName rule's name
 * @param statement rule's statement
 * @return EUpdateResult depending if the update succeed or failed
 */
EUpdateResult EvaluateController::updateRuleWithNameAndStatement(const ERulesName ruleName, const bool statement){
    RulesDataMapper* rulesDataMapper = new RulesDataMapper();
    EUpdateResult resultUpdate = rulesDataMapper->updateWithNameAndStatement(ruleName,statement);
    if (resultUpdate == UPDATE_OK) {
    	int i = 0;
        while (ruleName != m_rulesList[i]->getName() || i == 8){
        	i++;
        }
        m_rulesList[i]->setIsActive(statement);
        if((m_rulesList[i]->getName() == RULE_2_2S || m_rulesList[i]->getName() == RULE_2OF3_2S ) && statement == true){
        	if(m_rulesList[i]->getName() == RULE_2_2S){
        		m_rulesList[i+1]->setIsActive(false);
        	}else{
        		m_rulesList[i-1]->setIsActive(false);
        	}
        	resultUpdate = UPDATE_OK_RELOAD;
        }
    }
    delete rulesDataMapper;
    return resultUpdate;
}

/**
 * @details update a Parameterizable_Rules's statement and value
 * @param ruleName rule's name
 * @param statement rule's statement
 * @param value number of values to evaluate
 * @return EUpdateResult depending if the update succeed or failed
 */
EUpdateResult EvaluateController::updateRuleWithNameStatementAndValue(const ERulesName ruleName, const  bool statement, const int value){
    RulesDataMapper* rulesDataMapper = new RulesDataMapper();
    IParameterizable_Rules* parameterizableRules = NULL;
    EUpdateResult resultUpdate = rulesDataMapper->updateWithNameStatementAndValue(ruleName,statement,value);
    if (resultUpdate == UPDATE_OK) {
        switch(ruleName){
        	case RULE_X_1S:
        		parameterizableRules = Rule_X_1s::getInstance();
                break;
			case RULE_XX:
				parameterizableRules = Rule_Xx::getInstance();
				break;
			case RULE_XT:
				parameterizableRules = Rule_XT::getInstance();
				break;
			default :
				break;
        }
        if(parameterizableRules != NULL) {
            parameterizableRules->setValue(value);
            parameterizableRules->setIsActive(statement);
        }
    }
    delete rulesDataMapper;
    return resultUpdate;
}

/**
 * @details Update EvaluateParameterizableRulesIf1_2sSucceed attribute and update it in the XML file
 * @param statement statement to update
 * @return EUpdateResult depending of the result of the update
 */
EUpdateResult EvaluateController::updateEvaluateParameterizableRulesIf1_2sSucceed(const bool statement){
    setEvaluateParameterizableRulesIf1_2sSucceed(statement);
    RulesDataMapper* rulesDataMapper = new RulesDataMapper();
    EUpdateResult result = rulesDataMapper->updateParameterizableStatement(statement);
    if(result == UPDATE_OK){
        setEvaluateParameterizableRulesIf1_2sSucceed(statement);
    }
    delete rulesDataMapper;
    return result;
}


/**
 * @details getter for the setting of the XML file
 * @return WestgardConfiguration of setting of the XML file
 */
WestgardConfiguration EvaluateController::getWestgardConfiguration()const {
    RulesDataMapper* r1 = new RulesDataMapper();
    WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
    delete r1;
    return westgardConfiguration;
}

/**
 * @details calculate the mean the the current list of float
 * @param measure list of float to calculate the mean
 * @return flaot as the mean
 */
float EvaluateController::calculateMean(list<float> measure){
    float mean = 0;
    list<float>::iterator iteratorList = measure.begin();
    while(iteratorList != measure.end()){
        mean = mean + *iteratorList;
        iteratorList++;
    }
    if(measure.size() !=0){
    	int size = measure.size();
    	mean = mean / size;
        mean = round(mean * 100) /100;
    }
    return mean;
}

/**
 * @details calculate the standard deviation of the current list of float and it mean
 * @param measure list of float
 * @param mean mean of the list of float
 * @return a float for the standard deviation
 */
float EvaluateController::calculate1SDWithMean(list<float> measure, const float mean){
    float oneSD = 0 ;
    float absoluteValue = 0;
    list<float>::iterator iteratorList = measure.begin();
    while(iteratorList != measure.end()){
        absoluteValue = *iteratorList - mean;
        oneSD = oneSD + pow(absoluteValue,2);
        iteratorList++;
    }
    if(measure.size() != 0){
    	int size = measure.size();
    	oneSD = oneSD / size ;
    }else{
    	oneSD = 0;
    }
    oneSD = sqrt(oneSD);
    float SD = round(oneSD * 100) /100;
    return SD;
}

