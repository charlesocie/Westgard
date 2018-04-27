/*
 * Rule_2of3_2sTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../Model/Rule_2of3_2s.h"


namespace{
	class Rule_2of3_2sTest : public :: testing::Test{
	protected:
		Rule_2of3_2s* rule = Rule_2of3_2s::getInstance();
		list<float> listfloat;

	};


TEST_F(Rule_2of3_2sTest, DisableRule) {
    rule->setIsActive(false);
    EXPECT_EQ(rule->getIsActive(), false);
}

TEST_F(Rule_2of3_2sTest, EnableRule) {
    rule->setIsActive(true);
    EXPECT_EQ(rule->getIsActive(), true);
}

TEST_F(Rule_2of3_2sTest, EvaluateDisableRule) {
    rule->setIsActive(false);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(9.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureIn2SDUnderMeanWithLast2) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(9);
    listfloat.push_back(8.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureIn2SDOverMeanWithLast2) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(10.5);
    listfloat.push_back(11.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOn2SDOverMeanWithLast2) {

    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(12);
    listfloat.push_back(12);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOn2SDUnderMeanWithLast2) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(8);
    listfloat.push_back(8);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOutside2SDUnderMeanWithLast2) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(4);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}


TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOutside2SDOverMeanWithLast2) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(18);
    listfloat.push_back(15);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOutside2SDOneOverMeanOneUnderMeanWithLast2) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(15);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureIn2SDUnderMeanWith1And3) {
    rule->setIsActive(true);
    listfloat.push_back(9);
    listfloat.push_back(10);
    listfloat.push_back(8.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureIn2SDOverMeanWith1And3) {
    rule->setIsActive(true);
    listfloat.push_back(10.5);
    listfloat.push_back(10);
    listfloat.push_back(11.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOn2SDWith1And3OverMean) {
    rule->setIsActive(true);
    listfloat.push_back(12);
    listfloat.push_back(10);
    listfloat.push_back(12);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOn2SDWith1And3UnderMean) {
    rule->setIsActive(true);
    listfloat.push_back(8);
    listfloat.push_back(10);
    listfloat.push_back(8);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOutside2SDUnderMeanWith1And3) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(10);
    listfloat.push_back(4);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}


TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOutside2SDOverMeanWith1And3) {
    rule->setIsActive(true);
    listfloat.push_back(14);
    listfloat.push_back(10);
    listfloat.push_back(15);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}

TEST_F(Rule_2of3_2sTest, EvaluateLastMeasureOutside2SDOneOnMeanOneUnderMeanWith1And3) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(10);
    listfloat.push_back(15);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}
}
