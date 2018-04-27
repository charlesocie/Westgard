/*
 * WestgardInterfaceTests.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../WestgardInterface.h"
#include "../../third_parties/Markup/Markup.h"
#include "../Model/Rule_1_2s.h"
#include "../Model/Rule_1_3s.h"
#include "../Model/Rule_2_2s.h"
#include "../Model/Rule_2of3_2s.h"
#include "../Model/Rule_R_4s.h"
#include "../Model/Rule_X_1s.h"
#include "../Model/Rule_Xx.h"
#include "../Model/Rule_XT.h"
#include <fstream>



namespace{
	class WestgardInterfaceTests : public :: testing::Test{
	protected:
	    WestgardInterface* WI = WestgardInterface::getInstance();
	    CMarkup xmlFile;
		WestgardResult* westgardResultExpected = new WestgardResult();
		const char* gs_fileLocation = "../Westgard_Config.xml";
		WestgardConfiguration* WC;
		struct tm d1;
		struct tm d2;
		struct tm d3;
		struct tm d4;
		struct tm d5;
		struct tm d6;
		struct tm d7;
		struct tm d8;
		struct tm d9;
		struct tm d10;
		struct tm d11;
		Measure* m1 = NULL;
		Measure* m2 = NULL;
		Measure* m3 = NULL;
		Measure* m4 = NULL;
		Measure* m5 = NULL;
		Measure* m6 = NULL;
		Measure* m7 = NULL;
		Measure* m8 = NULL;
		Measure* m9 = NULL;
		Measure* m10 = NULL;
		Measure* m11 = NULL;


	void setwestgardResultExpected(){
			westgardResultExpected->setMean(10.00);
			westgardResultExpected->setOneSD(0.82);
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
			d6.tm_hour = 12;
			d6.tm_min = 12;
			d6.tm_sec = 12;
			d6.tm_mday = 06;
			d6.tm_mon = 01;
			d6.tm_year = 2018;
			d7.tm_hour = 12;
			d7.tm_min = 12;
			d7.tm_sec = 12;
			d7.tm_mday = 07;
			d7.tm_mon = 01;
			d7.tm_year = 2018;
			d8.tm_hour = 12;
			d8.tm_min = 12;
			d8.tm_sec = 12;
			d8.tm_mday = 8;
			d8.tm_mon = 01;
			d8.tm_year = 2018;
			d9.tm_hour = 12;
			d9.tm_min = 12;
			d9.tm_sec = 12;
			d9.tm_mday = 9;
			d9.tm_mon = 01;
			d9.tm_year = 2018;
			d10.tm_hour = 12;
			d10.tm_min = 12;
			d10.tm_sec = 12;
			d10.tm_mday = 10;
			d10.tm_mon = 01;
			d10.tm_year = 2018;
			d11.tm_hour = 12;
			d11.tm_min = 12;
			d11.tm_sec = 12;
			d11.tm_mday = 11;
			d11.tm_mon = 01;
			d11.tm_year = 2018;

		}


	void setupXMLconfig(){
		CMarkup xmlFile;
	    xmlFile.Load(gs_fileLocation);
	    xmlFile.FindElem();
	    xmlFile.IntoElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("true");
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("true");
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("true");
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("false");
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("true");
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("true");
	    xmlFile.FindElem("value");
	    xmlFile.SetData(4);
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("true");
	    xmlFile.FindElem("value");
	    xmlFile.SetData(10);
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("rule");
	    xmlFile.IntoElem();
	    xmlFile.FindElem("statement");
	    xmlFile.SetData("true");
	    xmlFile.FindElem("value");
	    xmlFile.SetData(7);
	    xmlFile.OutOfElem();
	    xmlFile.FindElem("evaluationParameterizableRulesEvaluationIf1_2sIsPasse");
	    xmlFile.SetData("true");
	    xmlFile.Save(gs_fileLocation);
	}

	void delete3Measure(){
	    delete m1;
	    delete m2;
	    delete m3;
	}

	void delete6Measure(){
            delete m4;
            delete m5;
            delete m6;
            delete3Measure();
    }

    void deleteMeasure(){
	    delete6Measure();
        delete m7;
        delete m8;
        delete m9;
        delete m10;
        delete m11;
	}

	WestgardConfiguration* setupconfig(){
	    list<RuleSetting> rulelist;
	    RuleSetting* r1 = new RuleSetting(RULE_1_2S);
	    r1->setIsActive(true);
	    RuleSetting* r2 = new RuleSetting(RULE_1_3S);
	    r2->setIsActive(true);
	    RuleSetting* r3 = new RuleSetting(RULE_2_2S);
	    r3->setIsActive(true);
	    RuleSetting* r4 = new RuleSetting(RULE_2OF3_2S);
	    r4->setIsActive(false);
	    RuleSetting* r5 = new RuleSetting(RULE_R_4S);
	    r5->setIsActive(true);
	    RuleSetting* r6 = new RuleSetting(RULE_X_1S);
	    r6->setIsActive(true);
	    r6->setValue(4);
	    RuleSetting* r7 = new RuleSetting(RULE_XX);
	    r7->setIsActive(true);
	    r7->setValue(10);
	    RuleSetting* r8 = new RuleSetting(RULE_XT);
	    r8->setIsActive(true);
	    r8->setValue(7);
	    rulelist.push_back(*r1);
	    rulelist.push_back(*r2);
	    rulelist.push_back(*r3);
	    rulelist.push_back(*r4);
	    rulelist.push_back(*r5);
	    rulelist.push_back(*r6);
	    rulelist.push_back(*r7);
	    rulelist.push_back(*r8);
	    WestgardConfiguration* WC = new WestgardConfiguration(rulelist,true);
	    return WC;
	}
};


	TEST_F(WestgardInterfaceTests, Rule_1_2sEvaluationPasseWithoutEvaluateOtherRules ){
		setupXMLconfig();
		setupconfig();
		setwestgardResultExpected();
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(false);
	    m1 = new Measure(9.0, d1);
	    m2 = new Measure(10.0, d2);
	    m3 = new Measure(11, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 0.82), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 1.64), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete3Measure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sEvaluationPasseAndEvaluateXRules ){
		setwestgardResultExpected();
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(4);
	    Rule_Xx::getInstance()->setValue(4);
	    Rule_XT::getInstance()->setValue(4);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    Measure* m1 = new Measure(9.0, d1);
	    Measure* m2 = new Measure(10.0, d2);
	    Measure* m3 = new Measure(11.0, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 0.82), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 1.64), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete3Measure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sEvaluationPasseAndRule_X_1sFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setEWGResult(FAILED_X_1S);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(1);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    Measure* m1 = new Measure(9.0, d1);
	    Measure* m2 = new Measure(10.0, d2);
	    Measure* m3 = new Measure(11.0, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 0.82), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 1.64), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete3Measure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sEvaluationPasseAndRule_XxFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.50);
		westgardResultExpected->setOneSD(1.12);
		westgardResultExpected->setEWGResult(FAILED_XX);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(4);
	    Rule_Xx::getInstance()->setValue(2);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(9.0, d1);
	    m2 = new Measure(10.0, d2);
	    m3 = new Measure(10.0, d3);
	    m4 = new Measure(10.0, d4);
	    m5 = new Measure(12.0, d5);
	    m6 = new Measure(12.0, d6);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m3);
	    listMeasure.push_back(*m4);
	    listMeasure.push_back(*m5);
	    listMeasure.push_back(*m6);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.50, 1.12), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.50, 2.24), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete6Measure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sEvaluationPasseAndRule_XTFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setEWGResult(FAILED_XT);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(4);
	    Rule_Xx::getInstance()->setValue(4);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(9.0, d1);
	    m2 = new Measure(10.0, d2);
	    m3 = new Measure(11.0, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 0.82), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 1.64), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
	    delete m1;
        delete m2;
        delete m3;
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sEvaluationFailedAndallEvaluationRulesPasseWith2_2sEvaluation ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.17);
		westgardResultExpected->setOneSD(0.9);
		westgardResultExpected->setEWGResult(FAILED_1_2S);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(true);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(4);
	    Rule_Xx::getInstance()->setValue(4);
	    Rule_XT::getInstance()->setValue(4);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(9.0, d1);
	    m2 = new Measure(10.0, d2);
	    m3 = new Measure(10.0, d3);
	    m4 = new Measure(10.0, d4);
	    m5 = new Measure(10.0, d5);
	    m6 = new Measure(12.0, d6);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m3);
	    listMeasure.push_back(*m4);
	    listMeasure.push_back(*m5);
	    listMeasure.push_back(*m6);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.17, 0.90), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.17, 1.8), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete6Measure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sEvaluationFailedAndallEvaluationRulesPasseWith2of3_2sEvaluation ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.17);
		westgardResultExpected->setOneSD(0.9);
		westgardResultExpected->setEWGResult(FAILED_1_2S);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(9.0, d1);
	    m2 = new Measure(10.0, d2);
	    m3 = new Measure(10.0, d3);
	    m4 = new Measure(10.0, d4);
	    m5 = new Measure(10.0, d5);
	    m6 = new Measure(12.0, d6);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m3);
	    listMeasure.push_back(*m4);
	    listMeasure.push_back(*m5);
	    listMeasure.push_back(*m6);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.17, 0.90), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.17, 1.8), *westgardResultExpected);
	    EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete6Measure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsDisableAndallEvaluationRulesPasse ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.17);
		westgardResultExpected->setOneSD(0.9);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(true);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(9.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(12.0, d6);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.17, 0.90), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.17, 1.8), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete6Measure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsDisableAndRules_1_3sFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.91);
		westgardResultExpected->setOneSD(2.87);
		westgardResultExpected->setEWGResult(FAILED_1_3S);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(true);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(10.0, d6);
		m7 = new Measure(10.0, d7);
		m8 = new Measure(10.0, d8);
		m9 = new Measure(10.0, d9);
		m10 = new Measure(10.0, d10);
		m11 = new Measure(20.0, d11);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		listMeasure.push_back(*m7);
		listMeasure.push_back(*m8);
		listMeasure.push_back(*m9);
		listMeasure.push_back(*m10);
		listMeasure.push_back(*m11);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.91, 2.87), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.91, 5.74), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        deleteMeasure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsDisableAndRules_2_2sFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.36);
		westgardResultExpected->setOneSD(0.77);
		westgardResultExpected->setEWGResult(FAILED_2_2S);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(true);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(10.0, d6);
		m7 = new Measure(10.0, d7);
		m8 = new Measure(10.0, d8);
		m9 = new Measure(10.0, d9);
		m10 = new Measure(12.0, d10);
		m11 = new Measure(12.0, d11);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		listMeasure.push_back(*m7);
		listMeasure.push_back(*m8);
		listMeasure.push_back(*m9);
		listMeasure.push_back(*m10);
		listMeasure.push_back(*m11);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.36, 0.77), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.36, 1.54), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        deleteMeasure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsDisableAndRules_2of3_2sFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.36);
		westgardResultExpected->setOneSD(0.77);
		westgardResultExpected->setEWGResult(FAILED_2OF3_2S);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(10.0, d6);
		m7 = new Measure(10.0, d7);
		m8 = new Measure(10.0, d8);
		m9 = new Measure(12.0, d9);
		m10 = new Measure(10.0, d10);
		m11 = new Measure(12.0, d11);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		listMeasure.push_back(*m7);
		listMeasure.push_back(*m8);
		listMeasure.push_back(*m9);
		listMeasure.push_back(*m10);
		listMeasure.push_back(*m11);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.36, 0.77), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.36, 1.54), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        deleteMeasure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsEnableAndRules_R_4sFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.00);
		westgardResultExpected->setOneSD(0.85);
		westgardResultExpected->setEWGResult(FAILED_R_4S);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(true);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(10.0, d6);
		m7 = new Measure(10.0, d7);
		m8 = new Measure(10.0, d8);
		m9 = new Measure(10.0, d9);
		m10 = new Measure(8.0, d10);
		m11 = new Measure(12.0, d11);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		listMeasure.push_back(*m7);
		listMeasure.push_back(*m8);
		listMeasure.push_back(*m9);
		listMeasure.push_back(*m10);
		listMeasure.push_back(*m11);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 0.85), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 1.70), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        deleteMeasure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsEnableAndRules_X_1sFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.36);
		westgardResultExpected->setOneSD(0.77);
		westgardResultExpected->setEWGResult(FAILED_X_1S);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(2);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(10.0, d6);
		m7 = new Measure(10.0, d7);
		m8 = new Measure(10.0, d8);
		m9 = new Measure(10.0, d9);
		m10 = new Measure(12.0, d10);
		m11 = new Measure(12.0, d11);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		listMeasure.push_back(*m7);
		listMeasure.push_back(*m8);
		listMeasure.push_back(*m9);
		listMeasure.push_back(*m10);
		listMeasure.push_back(*m11);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.36, 0.77), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.36, 1.54), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        deleteMeasure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsEnableAndRules_XxFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.36);
		westgardResultExpected->setOneSD(0.77);
		westgardResultExpected->setEWGResult(FAILED_XX);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(2);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(10.0, d6);
		m7 = new Measure(10.0, d7);
		m8 = new Measure(10.0, d8);
		m9 = new Measure(10.0, d9);
		m10 = new Measure(12.0, d10);
		m11 = new Measure(12.0, d11);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		listMeasure.push_back(*m7);
		listMeasure.push_back(*m8);
		listMeasure.push_back(*m9);
		listMeasure.push_back(*m10);
		listMeasure.push_back(*m11);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.36, 0.77), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.36, 1.54), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        deleteMeasure();
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsEnableAndRules_XTFailed ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.00);
		westgardResultExpected->setOneSD(0.85);
		westgardResultExpected->setEWGResult(FAILED_XT);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(false);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(2);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.0, d1);
		m2 = new Measure(10.0, d2);
		m3 = new Measure(10.0, d3);
		m4 = new Measure(10.0, d4);
		m5 = new Measure(10.0, d5);
		m6 = new Measure(10.0, d6);
		m7 = new Measure(10.0, d7);
		m8 = new Measure(10.0, d8);
		m9 = new Measure(10.0, d9);
		m10 = new Measure(8.0, d10);
		m11 = new Measure(12.0, d11);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		listMeasure.push_back(*m2);
		listMeasure.push_back(*m3);
		listMeasure.push_back(*m4);
		listMeasure.push_back(*m5);
		listMeasure.push_back(*m6);
		listMeasure.push_back(*m7);
		listMeasure.push_back(*m8);
		listMeasure.push_back(*m9);
		listMeasure.push_back(*m10);
		listMeasure.push_back(*m11);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 0.85), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 1.70), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        deleteMeasure();
	}

	TEST_F(WestgardInterfaceTests, EvaluateAEmptyList){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.27);
		westgardResultExpected->setOneSD(0.62);
		westgardResultExpected->setEWGResult(FAILED_NO_VALUE);
	    Rule_1_2s::getInstance()->setIsActive(true);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(true);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    list<Measure> listMeasure;
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.27, 0.62), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.27, 1.24), *westgardResultExpected);
		westgardResultExpected->setMean(0);
		westgardResultExpected->setOneSD(0);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
	}

	TEST_F(WestgardInterfaceTests, Rule_1_2sIsFailedWith1Value ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.00);
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(FAILED_1_2S);
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
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(12.4, d1);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.00), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 2.00), *westgardResultExpected);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
		westgardResultExpected->setMean(12.4);
		westgardResultExpected->setOneSD(0);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
		delete m1;
	}

	TEST_F(WestgardInterfaceTests, Rule_1_3sIsFailedWith1Value ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.00);
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(FAILED_1_3S);
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
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(13.4, d1);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.00), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 2.00), *westgardResultExpected);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
		westgardResultExpected->setMean(13.4);
		westgardResultExpected->setOneSD(0);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
		delete m1;
	}

	TEST_F(WestgardInterfaceTests, WestgardAlgorithmIsOkWith1Value ){
		setwestgardResultExpected();
		westgardResultExpected->setMean(10.00);
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
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
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.4, d1);
		list<Measure> listMeasure;
		listMeasure.push_back(*m1);
		EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.00), *westgardResultExpected);
		EXPECT_EQ(WI->WGevaluateWithListTargetAndTolerance(listMeasure, 10.00, 2.00), *westgardResultExpected);
		westgardResultExpected->setMean(10.4);
		westgardResultExpected->setOneSD(0);
		EXPECT_EQ(WI->WGevaluateWithListOnly(listMeasure), *westgardResultExpected);
        delete m1;
	}

	TEST_F(WestgardInterfaceTests, getConfigurationTest){
		WC = setupconfig();
	    EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateEvaluateParameterizableRulesIf1_2sSucceedTestUpdateOK){
		WC = setupconfig();
		WC->setEvaluateParameterizableRuleIf1_2sSucceed(false);
		EXPECT_EQ(WI->WGupdateEvaluateParameterizableRulesIf1_2sSucceed(false), UPDATE_OK);
	    EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateEvaluateParameterizableRulesIf1_2sSucceedTestUpdateFailed){
		xmlFile.Load(gs_fileLocation);
		xmlFile.FindElem();
		xmlFile.IntoElem();
		xmlFile.FindElem("evaluationParameterizableRulesEvaluationIf1_2sIsPasse");
		xmlFile.RemoveElem();
		xmlFile.Save(gs_fileLocation);
		EXPECT_EQ(WI->WGupdateEvaluateParameterizableRulesIf1_2sSucceed(false), FAILED_FILE_CORRUPT);
		xmlFile.AddElem("evaluationParameterizableRulesEvaluationIf1_2sIsPasse", "true");
		xmlFile.Save(gs_fileLocation);
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRule1_2s){
		WC = setupconfig();
		WC->setrule(RULE_1_2S, false);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_1_2S, false), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRule1_3s){
		WC = setupconfig();
		WC->setrule(RULE_1_3S, false);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_1_3S, false), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRule2_2s){
		WC = setupconfig();
		WC->setrule(RULE_2_2S, false);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_2_2S, false), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRule2of3_2s){
		WC = setupconfig();
		WC->setrule(RULE_2_2S, false);
		WC->setrule(RULE_2OF3_2S, true);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_2OF3_2S, true), UPDATE_OK_RELOAD);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRuleR_4s){
		WC = setupconfig();
		WC->setrule(RULE_R_4S, false);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_R_4S, false), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRuleX_1s){
		WC = setupconfig();
		WC->setrule(RULE_X_1S, false);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_X_1S, false), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRuleXx){
		WC = setupconfig();
		WC->setrule(RULE_XX, false);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_XX, false), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRuleXT){
		WC = setupconfig();
		WC->setrule(RULE_XT, false);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_XT, false), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementUpdateOKForRule2_2sLinkedToRule_2OF3_2s){
		WC = setupconfig();
        WI->WGupdateWithNameAndStatement(RULE_2OF3_2S, true);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_2_2S, true), UPDATE_OK_RELOAD);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementRuleMissing){
		xmlFile.Load(gs_fileLocation);
		xmlFile.FindElem();
		xmlFile.IntoElem();
		xmlFile.FindElem("rule");
		xmlFile.RemoveElem();
		xmlFile.Save(gs_fileLocation);
		EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_1_2S, true), FAILED_RULE_MISSING);
		xmlFile.InsertElem("rule");
		xmlFile.AddAttrib("name", "RULE_1_2S");
		xmlFile.AddChildElem("statement", "false");
		xmlFile.Save(gs_fileLocation);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementRuleNameMissing){
	    xmlFile.Load(gs_fileLocation);
	    xmlFile.FindElem();
	    xmlFile.IntoElem();
	    xmlFile.FindElem("rule");
	    xmlFile.RemoveElem();
	    xmlFile.InsertElem("rule");
	    xmlFile.AddChildElem("statement", "false");
	    xmlFile.Save(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_1_2S, true), FAILED_FILE_CORRUPT);
	    xmlFile.AddAttrib("name", "RULE_1_2S");
	    xmlFile.Save(gs_fileLocation);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementRuleStatementMissing){
	    xmlFile.Load(gs_fileLocation);
	    xmlFile.FindElem();
	    xmlFile.IntoElem();
	    xmlFile.FindElem("rule");
	    xmlFile.RemoveElem();
	    xmlFile.InsertElem("rule");
	    xmlFile.AddAttrib("name", "RULE_1_2S");
	    xmlFile.Save(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_1_2S, true), FAILED_FILE_CORRUPT);
	    xmlFile.AddChildElem("statement", "false");
	    xmlFile.Save(gs_fileLocation);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameAndStatementFileMissing){
		ifstream infile (gs_fileLocation,ifstream::binary);
		infile.seekg(0,infile.end);
		long size = infile.tellg();
		infile.seekg (0);
		char* buffer = new char[size];
		infile.read (buffer,size);
		infile.close();
		remove(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameAndStatement(RULE_1_2S, true), FAILED_FILE_MISSING);
		ofstream outfile (gs_fileLocation,ofstream::binary);
		outfile.write (buffer,size);
		delete[] buffer;
		outfile.close();
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueUpdateOKForRuleX_1s){
		WC = setupconfig();
		WC->setrule(RULE_X_1S, false, 7);
		EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_X_1S, false, 7), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueUpdateOKForRuleXx){
		WC = setupconfig();
		WC->setrule(RULE_XX, false, 7);
		EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XX, false, 7), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueUpdateOKForRuleXT){
		WC = setupconfig();
		WC->setrule(RULE_XT, false, 8);
		EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XT, false, 8), UPDATE_OK);
		EXPECT_EQ(WI->getWestgardConfiguration(), *WC);
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueUpdateForRuleXTWithoutName){

	    xmlFile.Load(gs_fileLocation);
	    xmlFile.FindElem();
	    xmlFile.IntoElem();
	    for(int i=0; i<8; i++){
	    	xmlFile.FindElem("rule");
	    }
	    xmlFile.RemoveElem();
	    xmlFile.AddElem("rule");
	    xmlFile.AddChildElem("statement", "false");
	    xmlFile.AddChildElem("value", "8");
	    xmlFile.Save(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XT, true, 7), FAILED_FILE_CORRUPT);
	    xmlFile.AddAttrib("name", "RULE_XT");
	    xmlFile.Save(gs_fileLocation);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueUpdateForRuleXTWithoutStatement){

	    xmlFile.Load(gs_fileLocation);
	    xmlFile.FindElem();
	    xmlFile.IntoElem();
	    for(int i=0; i<8; i++){
	    	xmlFile.FindElem("rule");
	    }
	    xmlFile.RemoveElem();
	    xmlFile.AddElem("rule");
	    xmlFile.AddAttrib("name", "RULE_XT");
	    xmlFile.AddChildElem("value", "5");
	    xmlFile.Save(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XT, true, 5), FAILED_FILE_CORRUPT);
	    xmlFile.InsertChildElem("statement", "false");
	    xmlFile.Save(gs_fileLocation);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueUpdateForRuleXTWithoutValue){

	    xmlFile.Load(gs_fileLocation);
	    xmlFile.FindElem();
	    xmlFile.IntoElem();
	    for(int i=0; i<8; i++){
	    	xmlFile.FindElem("rule");
	    }
	    xmlFile.RemoveElem();
	    xmlFile.AddElem("rule");
	    xmlFile.AddAttrib("name", "RULE_XT");
	    xmlFile.AddChildElem("statement", "false");
	    xmlFile.Save(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XT, true, 5), FAILED_FILE_CORRUPT);
	    xmlFile.AddChildElem("value", "7");
	    xmlFile.Save(gs_fileLocation);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueFileMissing){
		ifstream infile (gs_fileLocation,ifstream::binary);
		infile.seekg(0,infile.end);
		long size = infile.tellg();
		infile.seekg (0);
		char* buffer = new char[size];
		infile.read (buffer,size);
		infile.close();
		remove(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XT, true, 7), FAILED_FILE_MISSING);
		ofstream outfile (gs_fileLocation,ofstream::binary);
		outfile.write (buffer,size);
		delete[] buffer;
		outfile.close();
		setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueRuleMissing){
	    xmlFile.Load(gs_fileLocation);
	    xmlFile.FindElem();
	    xmlFile.IntoElem();
	    for(int i=0; i<8; i++){
	    	xmlFile.FindElem("rule");
	    }
	    xmlFile.RemoveElem();
	    xmlFile.Save(gs_fileLocation);
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XT, true, 4), FAILED_RULE_MISSING);
	    xmlFile.AddElem("rule");
	    xmlFile.AddAttrib("name", "RULE_XT");
	    xmlFile.AddChildElem("statement", "false");
	    xmlFile.AddChildElem("value", "7");
	    xmlFile.Save(gs_fileLocation);
	    setupXMLconfig();
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueWithANonParameterizableRule){
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_1_2S, false, 4), FAILED_VALUE_NON_MODIFIABLE);
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueWithValueToHight){
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XX, false, 51), FAILED_VALUE_OUT_OF_RANGE);
	}

	TEST_F(WestgardInterfaceTests, updateWithNameStatementAndValueWithValueToLow){
	    EXPECT_EQ(WI->WGupdateWithNameStatementAndValue(RULE_XX, false, 0), FAILED_VALUE_OUT_OF_RANGE);
	}

	TEST_F(WestgardInterfaceTests, evaluateWithDisableRule1_2sDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.8, d1);
	    m2 = new Measure(9, d2);
	    m3 = new Measure(12.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}

	TEST_F(WestgardInterfaceTests, evaluateWithDisableRule1_3sDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(false);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.8, d1);
	    m2 = new Measure(9, d2);
	    m3 = new Measure(13.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}

	TEST_F(WestgardInterfaceTests, evaluateWithDisableRule2_2sDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(9, d1);
	    m2 = new Measure(19, d2);
	    m3 = new Measure(12.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}

	TEST_F(WestgardInterfaceTests, evaluateWithDisableRule2of3_2sDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(true);
	    Rule_2of3_2s::getInstance()->setIsActive(false);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(12.8, d1);
	    m2 = new Measure(9, d2);
	    m3 = new Measure(12.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}

	TEST_F(WestgardInterfaceTests, evaluateWithDisableRuleR_4sDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(false);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.8, d1);
	    m2 = new Measure(7.8, d2);
	    m3 = new Measure(12.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}


	TEST_F(WestgardInterfaceTests, evaluateWithDisableRuleX_1sDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(false);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(5);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(11.8, d1);
	    m2 = new Measure(11.5, d2);
	    m3 = new Measure(12.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}

	TEST_F(WestgardInterfaceTests, evaluateWithDisableRuleXxDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(false);
	    Rule_XT::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(10.8, d1);
	    m2 = new Measure(10.4, d2);
	    m3 = new Measure(12.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}

	TEST_F(WestgardInterfaceTests, evaluateWithDisableRuleXTDoesntFailed){
		setwestgardResultExpected();
		westgardResultExpected->setOneSD(1);
		westgardResultExpected->setEWGResult(WESTGARD_OK);
	    Rule_1_2s::getInstance()->setIsActive(false);
	    Rule_1_3s::getInstance()->setIsActive(true);
	    Rule_2_2s::getInstance()->setIsActive(false);
	    Rule_2of3_2s::getInstance()->setIsActive(true);
	    Rule_R_4s::getInstance()->setIsActive(true);
	    Rule_X_1s::getInstance()->setIsActive(true);
	    Rule_Xx::getInstance()->setIsActive(true);
	    Rule_XT::getInstance()->setIsActive(false);
	    Rule_X_1s::getInstance()->setValue(3);
	    Rule_Xx::getInstance()->setValue(3);
	    Rule_XT::getInstance()->setValue(3);
	    EvaluateController::getInstance()->setEvaluateParameterizableRulesIf1_2sSucceed(true);
	    m1 = new Measure(9, d1);
	    m2 = new Measure(9.5, d2);
	    m3 = new Measure(12.5, d3);
	    list<Measure> listMeasure;
	    listMeasure.push_back(*m2);
	    listMeasure.push_back(*m1);
	    listMeasure.push_back(*m3);
	    EXPECT_EQ(WI->WGevaluateWithListMeanAnd1SD(listMeasure, 10.00, 1.0), *westgardResultExpected);
        delete m1;
        delete m2;
        delete m3;
	}

}
