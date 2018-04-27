/*
 * WestgardInterface.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */


#include "WestgardInterface.h"


/** @class WestgardInterface
 * @details Interface of communication with the IHM
 */

WestgardInterface *WestgardInterface::ms_instance = nullptr;

/** @details Constructor*/
WestgardInterface::WestgardInterface(){
	// TODO Auto-generated constructor stub
    ms_evaluateController.getInstance();
}

/** @details Destructor*/
WestgardInterface::~WestgardInterface() {
	// TODO Auto-generated destructor stub
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
WestgardInterface *WestgardInterface::getInstance(){
	if (nullptr == ms_instance)
	{
		ms_instance =  new WestgardInterface();
	}
	return ms_instance;
}

/**
 * @details Evaluate a list of \a Measure with the Westgard algorythm
 * @param listMeasure list of \a Measure don't need to be sort
 * @param mean mean of \a listMeasure
 * @param oneSD standard deviation of \a listMeasure
 * @return WestgardResult which is the result of Westgard algorithm evaluation, the mean and the SD
 */
WestgardResult WestgardInterface::WGevaluateWithListMeanAnd1SD(const list<Measure> listMeasure, const float mean, const float oneSD)const {
		return ms_evaluateController.getInstance()->evaluateRulesWithMeanAnd1SD(listMeasure, mean, oneSD);
}

/**
 * @details Evaluate a list of \a Measure with the Westgard algorythm
 * @param listMeasure list of \a Measure don't need to be sort
 * @param target target of \a listMeasure
 * @param tolerance tolerance of \a listMeasure
 * @return WestgardResult which is the result of Westgard algorithm evaluation, the mean and the SD
 */
WestgardResult WestgardInterface::WGevaluateWithListTargetAndTolerance(const list<Measure> listMeasure, const float target, const float tolerance)const {
    return ms_evaluateController.getInstance()->evaluateRulesWithTargetAndTolerance(listMeasure, target, tolerance);
}

/**
 * @details Update a rule's statement (Works for all the Westgard's rule)
 * @param ruleName Name of the rule
 * @param statement rule's statement
 * @return EUpdateResult which is the result of the update
 */
EUpdateResult WestgardInterface::WGupdateWithNameAndStatement(const ERulesName ruleName, const bool statement){
   	return ms_evaluateController.getInstance()->updateRuleWithNameAndStatement(ruleName, statement);

}

/**
 * @details Update a rule's statement (Works only for Rule_X_1s, Rule_Xx and Rule_XT)
 * @param ruleName Name of the rule
 * @param statement rule's statement
 * @param value nomber of value the user want to check
 * @return EUpdateResult which is the result of the update
 */
EUpdateResult WestgardInterface::WGupdateWithNameStatementAndValue(const ERulesName ruleName, const bool statement,
																   const int value){
    return ms_evaluateController.getInstance()->updateRuleWithNameStatementAndValue(ruleName, statement, value);

}

/**
 * @details Update \a evaluateParameterizableRulesIf1_2sSucceed
 * @param isActive statement of evaluateParameterizableRulesIf1_2sSucceed
 * @return EUpdateResult which is the result of the update
 */
EUpdateResult WestgardInterface::WGupdateEvaluateParameterizableRulesIf1_2sSucceed(const bool isActive){
	return ms_evaluateController.getInstance()->updateEvaluateParameterizableRulesIf1_2sSucceed(isActive);
}

/**
 * @details Evaluate the Westgard algorithm only with a list of Measure, calcule is own mean and SD
 * @param listMeasure the list a the measure to evaluate
 * @return WestgardResult of the evaluate rule
 */
WestgardResult WestgardInterface::WGevaluateWithListOnly(const list<Measure> listMeasure)const {
 	return ms_evaluateController.getInstance()->evaluateWestgard(listMeasure);
}

/**
 * @details read the XML file
 * @return the setting of all the rule inside a WestgardConfiguration class
 */
WestgardConfiguration WestgardInterface::getWestgardConfiguration()const {
	return  ms_evaluateController.getInstance()->getWestgardConfiguration();
}
