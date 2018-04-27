/*
 * EvaluateControllerTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */

#include "gtest/gtest.h"
#include "../Controller/EvaluateController.h"
#include "../Model/Rule_X_1s.h"
#include "../Model/Rule_Xx.h"
#include "../Model/Rule_XT.h"
#include "../Model/Rule_1_2s.h"
#include "../Model/Rule_1_3s.h"
#include "../Model/Rule_2_2s.h"
#include "../Model/Rule_2of3_2s.h"
#include "../Model/Rule_R_4s.h"
#include <ctime>

namespace{
	class EvaluateControllerTest : public :: testing::Test{

     protected:

        EvaluateController* controller = EvaluateController::getInstance();
        WestgardResult* westgardResult = new WestgardResult();
	    time_t currenttime = time(0);
		struct tm d1;
		struct tm d2;
		struct tm d3;
		struct tm d4;
		struct tm d5;
        struct tm d6;
        struct tm d7;
        Measure* m1 = NULL;
        Measure* m2 = NULL;
        Measure* m3 = NULL;
        Measure* m4 = NULL;
        Measure* m5 = NULL;
        Measure* m6 = NULL;
        Measure* m7 = NULL;



		void setwestgardResult(){
			d1=*localtime(&currenttime);
			d2=*localtime(&currenttime);
			d3=*localtime(&currenttime);
			d4=*localtime(&currenttime);
			d5=*localtime(&currenttime);
			d1=*localtime(&currenttime);
		    d1=*localtime(&currenttime);
		    d1.tm_hour = 12;
		    d1.tm_min = 12;
		    d1.tm_sec = 12;
		    d1.tm_mday = 01;
		    d1.tm_mon = 01;
		    d1.tm_year = 2018;
		    d2.tm_hour = 12;
		    d2.tm_min = 12;
		    d2.tm_sec = 12;
		    d2.tm_mday = 02;
		    d2.tm_mon = 01;
		    d2.tm_year = 2018;
		    d3.tm_hour = 12;
		    d3.tm_min = 12;
		    d3.tm_sec = 12;
		    d3.tm_mday = 03;
		    d3.tm_mon = 01;
		    d3.tm_year = 2018;
		    d4.tm_hour = 12;
		    d4.tm_min = 12;
		    d4.tm_sec = 12;
		    d4.tm_mday = 04;
		    d4.tm_mon = 01;
		    d4.tm_year = 2018;
		    d5.tm_hour = 12;
		    d5.tm_min = 12;
		    d5.tm_sec = 12;
		    d5.tm_mday = 05;
		    d5.tm_mon = 01;
		    d5.tm_year = 2018;
		    westgardResult->setMean(10);
		    westgardResult->setOneSD(1);
		    Rule_1_2s::getInstance()->setIsActive(true);
		    Rule_1_3s::getInstance()->setIsActive(true);
		    Rule_2_2s::getInstance()->setIsActive(true);
		    Rule_2of3_2s::getInstance()->setIsActive(true);
		    Rule_R_4s::getInstance()->setIsActive(true);
		    Rule_X_1s::getInstance()->setIsActive(true);
		    Rule_Xx::getInstance()->setIsActive(true);
		    Rule_XT::getInstance()->setIsActive(true);
		    Rule_X_1s::getInstance()->setValue(3);
		    Rule_Xx::getInstance()->setValue(3);
		    Rule_XT::getInstance()->setValue(5);
		}


	};



TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(false);
    m1 = new Measure(1, d2);
    m2 = new Measure(10.2, d3);
    m3 = new Measure(14, d1);
    list<Measure> listMeasure;
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasseANDParameterizableRulesdontHaveEnoughtValuesOnRule_X_1s ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_X_1s::getInstance()->setValue(5);
    Rule_Xx::getInstance()->setValue(3);
    Rule_XT::getInstance()->setValue(3);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(1, d2);
    m2 = new Measure(10.2, d3);
    m3 = new Measure(14, d1);
    list<Measure> listMeasure;
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasseANDParameterizableRulesdontHaveEnoughtValuesOnRule_Xx ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_X_1s::getInstance()->setValue(3);
    Rule_Xx::getInstance()->setValue(5);
    Rule_XT::getInstance()->setValue(3);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(1, d2);
    m2 = new Measure(10.2, d3);
    m3 = new Measure(14, d1);
    list<Measure> listMeasure;
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasseANDParameterizableRulesdontHaveEnoughtValuesOnRule_XT ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_X_1s::getInstance()->setValue(3);
    Rule_Xx::getInstance()->setValue(3);
    Rule_XT::getInstance()->setValue(5);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(1, d2);
    m2 = new Measure(10.2, d3);
    m3 = new Measure(14, d1);
    list<Measure> listMeasure;
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasseANDParameterizableRulesPasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_X_1s::getInstance()->setValue(5);
    Rule_Xx::getInstance()->setValue(5);
    Rule_XT::getInstance()->setValue(5);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(1, d1);
    m2 = new Measure(10.2, d2);
    m3 = new Measure(14, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasseANDParameterizableRulesIsTrueANDRule_X_1sFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_X_1S);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(13, d1);
    m2 = new Measure(15, d2);
    m3 = new Measure(12, d3);
    m4 = new Measure(11.1, d4);
    m5 = new Measure(12, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasseANDParameterizableRulesIsTrueANDRule_XxFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_XX);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(16, d1);
    m2 = new Measure(15, d2);
    m3 = new Measure(10.2, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}


TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationPasseANDParameterizableRulesIsTrueANDRule_XTFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_XT);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(9, d2);
    m3 = new Measure(10, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_1_2S);
    Rule_XT::getInstance()->setValue(5);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(10, d1);
    m2 = new Measure(9, d2);
    m3 = new Measure(8, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailedANDRule_1_3sFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_1_3S);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(10, d1);
    m2 = new Measure(9, d2);
    m3 = new Measure(8, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(15, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailedANDRule2_2sFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_2_2S);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(10, d1);
    m2 = new Measure(9, d2);
    m3 = new Measure(8, d3);
    m4 = new Measure(12.5, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailedANDRule_2of3_2sFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_2OF3_2S);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(10, d1);
    m2 = new Measure(9, d2);
    m3 = new Measure(12.5, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailedANDRule_R_4sFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_R_4S);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(10, d1);
    m2 = new Measure(9, d2);
    m3 = new Measure(8, d3);
    m4 = new Measure(7.5, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailedANDRule_X_1sFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_X_1S);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(12, d1);
    m2 = new Measure(14, d2);
    m3 = new Measure(11.9, d3);
    m4 = new Measure(11.2, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailedANDRule_XxFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_XX);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(10.2, d1);
    m2 = new Measure(15, d2);
    m3 = new Measure(11.5, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sEvaluationFailedANDRule_XTFailed ){
    setwestgardResult();
    westgardResult->setEWGResult(FAILED_XT);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(9, d2);
    m3 = new Measure(10, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sDisableANDAllRulePasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_1_3sDisableANDAllRulePasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_1_3s::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(15.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_2_2sANDRules2_of3_2sDisableANDAllRulePasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_2_2s::getInstance()->setIsActive(false);
    Rule_2of3_2s::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9, d3);
    m4 = new Measure(12.7, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_2_2sANDRule_2of3_2sDisableANDAllRulePasse2ValueTesting ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_2_2s::getInstance()->setIsActive(false);
    Rule_2of3_2s::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9, d3);
    m4 = new Measure(16, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_2of3_2sDisableANDAllRulePasse3ValueTesting ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_2of3_2s::getInstance()->setIsActive(false);
    Rule_Xx::getInstance()->setValue(5);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(19, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_R_4sDisableANDAllRulePasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_R_4s::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(8, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9, d3);
    m4 = new Measure(7.5, d4);
    m5 = new Measure(12.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_X_1sDisableANDAllRulePasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_X_1s::getInstance()->setIsActive(false);
    Rule_Xx::getInstance()->setValue(5);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(18, d1);
    m2 = new Measure(8, d2);
    m3 = new Measure(15, d3);
    m4 = new Measure(11.4, d4);
    m5 = new Measure(11.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_XxDisableANDAllRulePasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_Xx::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(10.00001, d1);
    m2 = new Measure(10.5, d2);
    m3 = new Measure(12, d3);
    m4 = new Measure(11, d4);
    m5 = new Measure(11.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, Rule_1_2sANDRule_XTDisableANDAllRulePasse ){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_1_2s::getInstance()->setIsActive(false);
    Rule_Xx::getInstance()->setValue(5);
    Rule_XT::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(15, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9.5, d3);
    m4 = new Measure(9, d4);
    m5 = new Measure(8.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, calculatMeanAndSDTest){
    setwestgardResult();
    westgardResult->setEWGResult(WESTGARD_OK);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(11.5, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9.5, d3);
    m4 = new Measure(10.5, d4);
    m5 = new Measure(8.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateWestgard(listMeasure), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, evaluateWithTargetAndTolerance){
    setwestgardResult();
    westgardResult->setOneSD(1);
    westgardResult->setEWGResult(WESTGARD_OK);
    Rule_Xx::getInstance()->setIsActive(true);
    Rule_XT::getInstance()->setIsActive(false);
    controller->setEvaluateParameterizableRulesIf1_2sSucceed(true);
    m1 = new Measure(11.5, d1);
    m2 = new Measure(10, d2);
    m3 = new Measure(9.5, d3);
    m4 = new Measure(10.5, d4);
    m5 = new Measure(8.5, d5);
    list<Measure> listMeasure;
    listMeasure.push_back(*m1);
    listMeasure.push_back(*m2);
    listMeasure.push_back(*m3);
    listMeasure.push_back(*m4);
    listMeasure.push_back(*m5);
    EXPECT_EQ(controller->evaluateRulesWithTargetAndTolerance(listMeasure, 10, 2), *westgardResult);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}

TEST_F(EvaluateControllerTest, updateWithNameAndStatement1_2s){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_1_2S,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameAndStatement1_3s){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_1_3S,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameAndStatement2_2s){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_2_2S,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameAndStatement2of3_2s){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_2OF3_2S,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameAndStatementR_4s){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_R_4S,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameAndStatementX_1s){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_X_1S,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameAndStatementXx){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_XX,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}


TEST_F(EvaluateControllerTest, updateWithNameAndStatementXT){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameAndStatement(RULE_XT,false), UPDATE_OK);
    IRule* rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameStatementAndValueX_1s){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameStatementAndValue(RULE_X_1S,false,4), UPDATE_OK);
    IRule* rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, updateWithNameStatementAndValueXx){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameStatementAndValue(RULE_XX,false,4), UPDATE_OK);
    IRule* rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  true);
}


TEST_F(EvaluateControllerTest, updateWithNameStatementAndValueXT){
    setwestgardResult();
    EXPECT_EQ(controller->updateRuleWithNameStatementAndValue(RULE_XT,false,4), UPDATE_OK);
    IRule* rule = controller->getRuleList(7);
    EXPECT_EQ(rule->getIsActive(),  false);
    rule = controller->getRuleList(1);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(2);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(3);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(4);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(5);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(6);
    EXPECT_EQ(rule->getIsActive(),  true);
    rule = controller->getRuleList(0);
    EXPECT_EQ(rule->getIsActive(),  true);
}

TEST_F(EvaluateControllerTest, testAllDateAreEquals){
        time_t currenttime = time(0);
        d1 = *localtime(&currenttime);
        d2 = *localtime(&currenttime);
        d3 = *localtime(&currenttime);
        d4 = *localtime(&currenttime);
        d5 = *localtime(&currenttime);
        d6 = *localtime(&currenttime);
        d7 = *localtime(&currenttime);
        m1 = new Measure(19,d1);
        m2 = new Measure(19,d2);
        m3 = new Measure(19,d3);
        m4 = new Measure(19,d4);
        m5 = new Measure(10,d5);
        m6 = new Measure(10,d6);
        m7 = new Measure(10,d7);
        list<Measure> listMeasure;
        listMeasure.push_back(*m1);
        listMeasure.push_back(*m2);
        listMeasure.push_back(*m3);
        listMeasure.push_back(*m4);
        listMeasure.push_back(*m5);
        listMeasure.push_back(*m6);
        listMeasure.push_back(*m7);
        setwestgardResult();
        westgardResult->setEWGResult(WESTGARD_OK);
        EXPECT_EQ(controller->evaluateRulesWithMeanAnd1SD(listMeasure,10,1),*westgardResult);
}
}


