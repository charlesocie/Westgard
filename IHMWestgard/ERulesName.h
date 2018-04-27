/*
 * ERulesName.h
 *
 *  Created on: 28 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CONTROLLER_CPP_ERULESNAME_H_
#define CONTROLLER_CPP_ERULESNAME_H_

/**
 * @defgroup ERulesName
 * @details The Rule's name can take 8 differents values :
 *  - RULE_1_2S
 *  - RULE_1_3S
 *  - RULE_2_2S
 *  - RULE_2OF3_2S
 *  - RULE_R_4S
 *  - RULE_X_1S
 *  - RULE_XX
 *  - RULE_XT
 */

enum ERulesName {
	RULE_1_2S,
	RULE_1_3S,
	RULE_2_2S,
	RULE_2OF3_2S,
	RULE_R_4S,
	RULE_X_1S,
	RULE_XX,
	RULE_XT,
	FALSE_RULE
};

#endif /* CONTROLLER_CPP_ERULESNAME_H_ */
