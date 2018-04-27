/*
 * ERulesName.h
 *
 *  Created on: 28 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CONTROLLER_CPP_ERULESTATEMENT_H_
#define CONTROLLER_CPP_ERULESTATEMENT_H_

/**
 * @defgroup ERuleStatement
 * @details statement of a Rule can takes 4 different values :
 *  - WESTGARD_RULE_OK if the evaluation don't raise an error
 *  - WESTGARD_RULE_FAILED if the evaluation raise an error
 *  - WESTGARD_RULE_DISABLE if the Rule is disable for the Westgard algorithm evaluation
 *  - NOT_ENOUGH_VALUE_TO_EVALUATE only for the Parameterizable_Rules if the value is higher than the size of the \a listValues
 */
enum ERuleStatement {
	WESTGARD_RULE_OK,
	WESTGARD_RULE_FAILED,
	WESTGARD_RULE_DISABLE
};

#endif /* CONTROLLER_CPP_ERULESTATEMENT_H_ */
