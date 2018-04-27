/*
 * Rule_X_1sTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */

#include "gtest/gtest.h"
#include "../Model/Rule_X_1s.h"


namespace{
	class Rule_X_1sTest : public :: testing::Test{
	protected:
		Rule_X_1s* rule = Rule_X_1s::getInstance();
		list<float> listfloat;

	};

	TEST_F(Rule_X_1sTest, DisableRule) {
	    rule->setIsActive(false);
	    EXPECT_EQ(rule->getIsActive(), false);
	}

	TEST_F(Rule_X_1sTest, EnableRule) {
	    rule->setIsActive(true);
	    EXPECT_EQ(rule->getIsActive(), true);
	}

	TEST_F(Rule_X_1sTest, setValue) {
	    rule->setValue(3);
	    EXPECT_EQ(rule->getValue(), 3);
	}

	TEST_F(Rule_X_1sTest, EvaluateDisableRule) {
	    rule->setIsActive(false);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
	}

	TEST_F(Rule_X_1sTest, EvaluateWithAllValueUnder1SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(8);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}

	TEST_F(Rule_X_1sTest, EvaluateWithAllValueOver1SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(15);
	    listfloat.push_back(14);
	    listfloat.push_back(13);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}


	TEST_F(Rule_X_1sTest, EvaluateWithAllValueUnder1SDOneValueOver1SDMin) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(10.5);
	    listfloat.push_back(8);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_X_1sTest, EvaluateWithAllValueOver1SDOneValueUnder1SDMax) {
		rule->setIsActive(true);
	    listfloat.push_back(15);
	    listfloat.push_back(10.5);
	    listfloat.push_back(13);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_X_1sTest, EvaluateWithAllValueUnder1SDFirstValueOver1SDMin) {
	    rule->setIsActive(true);
	    listfloat.push_back(10);
	    listfloat.push_back(1);
	    listfloat.push_back(8);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_X_1sTest, EvaluateWithAllValueOver1SDFirstValueUnder1SDMax) {
	    rule->setIsActive(true);
	    listfloat.push_back(10.5);
	    listfloat.push_back(16);
	    listfloat.push_back(13);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_X_1sTest, EvaluateWithAllValueIn1SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(10.5);
	    listfloat.push_back(10.5);
	    listfloat.push_back(10.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_X_1sTest, EvaluateWithNotEnoughtValueAllUnder1SD ){
	    rule->setIsActive(true);
	    rule->setValue(5);
	    listfloat.push_back(8.9);
	    listfloat.push_back(8.5);
	    listfloat.push_back(8);
	    listfloat.push_back(7);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}
}

