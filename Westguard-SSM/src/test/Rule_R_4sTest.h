/*
 * Rule_R_4sTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */




#include "gtest/gtest.h"
#include "../Model/Rule_R_4s.h"


namespace{
	class Rule_R_4sTest : public :: testing::Test{
	protected:
		Rule_R_4s* rule = Rule_R_4s::getInstance();
		list<float> listfloat;

	};

	TEST_F(Rule_R_4sTest, DisableRule) {
	    rule->setIsActive(false);
	    EXPECT_EQ(rule->getIsActive(), false);
	}

	TEST_F(Rule_R_4sTest, EnableRule) {
	    rule->setIsActive(true);
	    EXPECT_EQ(rule->getIsActive(), true);
	}

	TEST_F(Rule_R_4sTest, EvaluateDisableRule) {
	    rule->setIsActive(false);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureIn2SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(9);
	    listfloat.push_back(8.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureIn2SDOverMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(10.5);
	    listfloat.push_back(11.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOn2SDOverMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(12);
	    listfloat.push_back(12);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOn2SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(8);
	    listfloat.push_back(8);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDUnderMeanAndSecondLastIn2SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(9);
	    listfloat.push_back(4);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDUnderMeanAndSecondLastUnder2SD) {
	    Rule_R_4s* rule = Rule_R_4s::getInstance();
	    rule->setIsActive(true);
	    list<float> listfloat;
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(4);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDUnderMeanAndSecondLastOver2SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(15);
	    listfloat.push_back(4);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDUnderMeanAndSecondLastOn2SDMin) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(8);
	    listfloat.push_back(4);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDUnderMeanAndSecondLastOn2SDMax) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(12);
	    listfloat.push_back(4);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDOverMeanAndSecondLastIn2SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(11);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDOverMeanAndSecondLastOver2SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(14);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDOverMeanAndSecondLastUnder2SD) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(7);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}

	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDOverMeanAndSecondLastOn2SDMax) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(12);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}
	TEST_F(Rule_R_4sTest, EvaluateLastMeasureOutside2SDOverMeanAndSecondLastOn2SDMin) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(8);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}
}
