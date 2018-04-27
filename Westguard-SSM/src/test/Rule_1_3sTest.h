/*
 * Rule_1_3s.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../Model/Rule_1_3s.h"


namespace{
	class Rule_1_3sTest : public :: testing::Test{
	protected:
		Rule_1_3s* rule = Rule_1_3s::getInstance();
		list<float> listfloat;

	};

	TEST_F(Rule_1_3sTest, DisableRule) {
	    rule->setIsActive(false);
	    EXPECT_EQ(rule->getIsActive(), false);
	}

	TEST_F(Rule_1_3sTest, EnableRule) {
	    rule->setIsActive(true);
	    EXPECT_EQ(rule->getIsActive(), true);
	}

	TEST_F(Rule_1_3sTest, EvaluateDisableRule) {
	    rule->setIsActive(false);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
	}

	TEST_F(Rule_1_3sTest, EvaluateLastMeasureIn3SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(7.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_1_3sTest, EvaluateLastMeasureIn3SDOverMean) {
	    Rule_1_3s* rule = Rule_1_3s::getInstance();
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(12.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_1_3sTest, EvaluateLastMeasureOn3SDOverMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(13);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_1_3sTest, EvaluateLastMeasureOn3SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(7);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_1_3sTest, EvaluateLastMeasureOutside3SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(4);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}


	TEST_F(Rule_1_3sTest, EvaluateLastMeasureOutside3SDOverMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}
}
