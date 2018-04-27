/*
 * EWGResult.h
 *
 *  Created on: 28 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CONTROLLER_CPP_EWGRESULT_H_
#define CONTROLLER_CPP_EWGRESULT_H_

/**
 * @defgroup EWGResult
 * @details result of a Westgard evaluation can take 10 differents values :
 *  - Westgard_ok if all the rule's evaluation don't raise an error
 *  - Failed_1_2s if the Rule_1_2s' evaluation raise an error
 *  - Failed_1_3s if the Rule_1_3s' evaluation raise an error
 *  - Failed_2_2s if the Rule_2_2s' evaluation raise an error
 *  - Failed_2of3_2s if the Rule_2of3_2s' evaluation raise an error
 *  - Failed_R_4s if the Rule_R_4s' evaluation raise an error
 *  - Failed_X_1s if the Rule_X_1s' evaluation raise an error
 *  - Failed_Xx if the Rule_Xx's evaluation raise an error
 *  - Failed_XT if the Rule_XT's evaluation raise an error
 *  - Failed_No_Value if the list of Measure is empty
 *
 */
enum EWGResult {
	WESTGARD_OK,
	FAILED_1_2S,
	FAILED_1_3S,
	FAILED_2_2S,
	FAILED_2OF3_2S,
	FAILED_R_4S,
	FAILED_X_1S,
	FAILED_XX,
	FAILED_XT,
	FAILED_NO_VALUE
	};

#endif
