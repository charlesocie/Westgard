/*
 * RuleDataMapper.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../DataMapper/RulesDataMapper.h"
#include "../../third_parties/Markup/Markup.h"
#include "../Model/Rule_1_2s.h"
#include "../Model/Rule_1_3s.h"
#include "../Model/Rule_2_2s.h"
#include "../Model/Rule_2of3_2s.h"
#include "../Model/Rule_R_4s.h"
#include "../Model/Rule_X_1s.h"
#include "../Model/Rule_Xx.h"
#include "../Model/Rule_XT.h"
#include "../Controller/EvaluateController.h"
#include <fstream>
#include <thread>


namespace{
	class RulesDataMapperTest : public :: testing::Test{
	protected:
		RulesDataMapper* r1 = new RulesDataMapper();
	    CMarkup xmlFile;
	    IRule* rulesList[8];
		bool eval = EvaluateController::getInstance()->getEvaluateParameterizableRulesIf1_2sSucceed();
		const char* gs_fileLocation = "../Westgard_Config.xml";

		void setupXMLconfig(){
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



TEST_F(RulesDataMapperTest, updaterule_1_2s) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_1_2S,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updaterule_1_3s) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_1_3S,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updaterule_2_2s) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_2_2S,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updaterule_2of3_2s) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_2OF3_2S,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updaterule_R_4s) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_R_4S,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updaterule_X_1s) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_X_1S,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updaterule_Xx) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_XX,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updaterule_XT) {
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_XT,false), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameAndStatementUpdateNoStatementInFile){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.FindElem("rule");
    xmlFile.IntoElem();
    xmlFile.FindElem("statement");
    xmlFile.RemoveElem();
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_1_2S,true), FAILED_FILE_CORRUPT);
    xmlFile.AddElem("statement", "true");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameAndStatementMissingRuleInFile){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.FindElem("rule");
    xmlFile.RemoveElem();
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_1_2S,true), FAILED_RULE_MISSING);
    xmlFile.InsertElem("rule");
    xmlFile.AddAttrib("name", "RULE_1_2S");
    xmlFile.AddChildElem("statement", "false");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameAndStatementMissingNameInRule){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.FindElem("rule");
    xmlFile.FindElem("rule");
    xmlFile.RemoveElem();
    xmlFile.AddElem("rule");
    xmlFile.AddChildElem("statement", "true");
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameAndStatement(RULE_1_3S,false), FAILED_FILE_CORRUPT);
    xmlFile.AddAttrib("name", "RULE_1_3S");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameAndStatementRule2_2sToTrueAndRule2of3_2sIsFalse){
	r1->updateWithNameAndStatement(RULE_2OF3_2S,true);
	r1->updateWithNameAndStatement(RULE_2_2S,true);
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.FindElem("rule");
    xmlFile.FindElem("rule");
    xmlFile.FindElem("rule");
    xmlFile.FindElem("rule");
    xmlFile.IntoElem();
    xmlFile.FindElem("statement");
    string statement = xmlFile.GetData();
    EXPECT_EQ(statement, "false");
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameAndStatementRule2of3_2sToTrueAndRule2_2sIsFalse){
	r1->updateWithNameAndStatement(RULE_2_2S,true);
	r1->updateWithNameAndStatement(RULE_2OF3_2S,true);
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.FindElem("rule");
    xmlFile.FindElem("rule");
    xmlFile.FindElem("rule");
    xmlFile.IntoElem();
    xmlFile.FindElem("statement");
    string statement = xmlFile.GetData();
    EXPECT_EQ(statement, "false");
    r1->updateWithNameAndStatement(RULE_2OF3_2S,false);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdaterule_X_1sWithValue){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_X_1S,true,8), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdaterule_XxWithValue){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XX,true,4), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdaterule_XTWithValue){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XT,true,5), UPDATE_OK);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdaterule_X_1sWithValueIs0){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_X_1S,true,0), FAILED_VALUE_OUT_OF_RANGE);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdaterule_XxWithValueIs0){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XX,true,0), FAILED_VALUE_OUT_OF_RANGE);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdaterule_XTWithValueIs0){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XT,true,0), FAILED_VALUE_OUT_OF_RANGE);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdatefakeruleWithValueIs0){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_1_2S,true,0), FAILED_VALUE_OUT_OF_RANGE);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdatefakeruleWithValue){
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_1_2S,true,10), FAILED_VALUE_NON_MODIFIABLE);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest,updateWithNameStatementAndValueUpdateNoValueInFile){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    for(int i=0; i<8;i++){
        xmlFile.FindElem("rule");
    }
    xmlFile.IntoElem();
    xmlFile.FindElem("value");
    xmlFile.RemoveElem();
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XT,true,10), FAILED_FILE_CORRUPT);
    xmlFile.AddElem("value", "8");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueUpdateNoStatementInFile){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    for(int i=0; i<8;i++){
        xmlFile.FindElem("rule");
    }
    xmlFile.IntoElem();
    xmlFile.FindElem("statement");
    xmlFile.RemoveElem();
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XT,true,10), FAILED_FILE_CORRUPT);
    xmlFile.AddElem("statement", "true");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueMissingRuleInFile){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    for(int i=0; i<8;i++){
        xmlFile.FindElem("rule");
    }
    xmlFile.RemoveElem();
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XT,true,7), FAILED_RULE_MISSING);
    xmlFile.AddElem("rule");
    xmlFile.AddAttrib("name", "RULE_XT");
    xmlFile.AddChildElem("statement", "true");
    xmlFile.AddChildElem("value", "8");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateWithNameStatementAndValueMissingNameInRule){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    for(int i=0; i<8;i++){
        xmlFile.FindElem("rule");
    }
    xmlFile.RemoveElem();
    xmlFile.AddElem("rule");
    xmlFile.AddChildElem("statement", "true");
    xmlFile.AddChildElem("value", "8");
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XT,true,7), FAILED_FILE_CORRUPT);
    xmlFile.AddAttrib("name", "RULE_XT");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, updateParameterizableStatementOK){
    EXPECT_EQ(r1->updateParameterizableStatement(false), UPDATE_OK);
    setupXMLconfig();
}


TEST_F(RulesDataMapperTest, updateParameterizableStatementMissingParameterizablestatement){
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.FindElem("evaluationParameterizableRulesEvaluationIf1_2sIsPasse");
    xmlFile.RemoveElem();
    xmlFile.Save(gs_fileLocation);
    EXPECT_EQ(r1->updateParameterizableStatement(true), FAILED_FILE_CORRUPT);
    xmlFile.AddElem("evaluationParameterizableRulesEvaluationIf1_2sIsPasse", "true");
    xmlFile.Save(gs_fileLocation);
    setupXMLconfig();
}


TEST_F(RulesDataMapperTest, read) {
    rulesList[0] = Rule_1_2s::getInstance();
	rulesList[1] = Rule_1_3s::getInstance();
	rulesList[2] = Rule_2_2s::getInstance();
	rulesList[3] = Rule_2of3_2s::getInstance();
	rulesList[4] = Rule_R_4s::getInstance();
	rulesList[5] = Rule_X_1s::getInstance();
	rulesList[6] = Rule_Xx::getInstance();
	rulesList[7] = Rule_XT::getInstance();
    EXPECT_EQ(r1->readToSetListRules(rulesList, &eval), true);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, controleReadValueRule_X_1s) {
    rulesList[0] = Rule_1_2s::getInstance();
    rulesList[1] = Rule_1_3s::getInstance();
    rulesList[2] = Rule_2_2s::getInstance();
    rulesList[3] = Rule_2of3_2s::getInstance();
    rulesList[4] = Rule_R_4s::getInstance();
    IParameterizable_Rules* parameterizableRules = Rule_X_1s::getInstance();
    rulesList[5] = parameterizableRules;
    rulesList[6] = Rule_Xx::getInstance();
    rulesList[7] = Rule_XT::getInstance();
    bool eval = EvaluateController::getInstance()->getEvaluateParameterizableRulesIf1_2sSucceed();
    r1->updateWithNameStatementAndValue(RULE_X_1S,true,5);
    r1->readToSetListRules(rulesList, &eval);
    EXPECT_EQ(parameterizableRules->getValue(), 5);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, controleReadValueRule_Xx) {
    rulesList[0] = Rule_1_2s::getInstance();
    rulesList[1] = Rule_1_3s::getInstance();
    rulesList[2] = Rule_2_2s::getInstance();
    rulesList[3] = Rule_2of3_2s::getInstance();
    rulesList[4] = Rule_R_4s::getInstance();
    rulesList[5] = Rule_X_1s::getInstance();
    IParameterizable_Rules* parameterizableRules = Rule_Xx::getInstance();
    rulesList[6] = parameterizableRules;
    rulesList[7] = Rule_XT::getInstance();
    bool eval = EvaluateController::getInstance()->getEvaluateParameterizableRulesIf1_2sSucceed();
    r1->updateWithNameStatementAndValue(RULE_XX,true,5);
    r1->readToSetListRules(rulesList, &eval);
    EXPECT_EQ(parameterizableRules->getValue(), 5);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, controleReadValueRuleXT) {
    rulesList[0] = Rule_1_2s::getInstance();
    rulesList[1] = Rule_1_3s::getInstance();
    rulesList[2] = Rule_2_2s::getInstance();
    rulesList[3] = Rule_2of3_2s::getInstance();
    rulesList[4] = Rule_R_4s::getInstance();
    rulesList[5] = Rule_X_1s::getInstance();
    rulesList[6] = Rule_Xx::getInstance();
    IParameterizable_Rules* parameterizableRules = Rule_XT::getInstance();
    rulesList[7] = parameterizableRules;
    bool eval = EvaluateController::getInstance()->getEvaluateParameterizableRulesIf1_2sSucceed();
    r1->updateWithNameStatementAndValue(RULE_XT,true,5);
    r1->readToSetListRules(rulesList, &eval);
    EXPECT_EQ(parameterizableRules->getValue(), 5);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, controlereadFileToGetSetting) {
    WestgardConfiguration* test = setupconfig();
    WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
    EXPECT_EQ(westgardConfiguration, *test);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, controlereadFileToGetSettingfalse1RuleMissing) {
    RuleSetting* ruleSetting = new RuleSetting(RULE_1_2S);
    list<RuleSetting> list;
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_1_3S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2OF3_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_R_4S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_X_1S);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(4);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XX);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(10);
    list.push_back(*ruleSetting);
    WestgardConfiguration* test = new WestgardConfiguration(list, true);
    WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
    EXPECT_FALSE(westgardConfiguration == *test);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, controlereadFileToGetSettingFalseTooMuchRule) {
    RuleSetting* ruleSetting = new RuleSetting(RULE_1_2S);
    list<RuleSetting> list;
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_1_3S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2OF3_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_R_4S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_X_1S);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(4);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XX);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(10);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XT);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(7);
    list.push_back(*ruleSetting);
    list.push_back(*ruleSetting);
    WestgardConfiguration* test = new WestgardConfiguration(list, true);
    WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
    EXPECT_FALSE(westgardConfiguration == *test);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, controlereadFileToGetSettingFalseStatementChanged) {
    RuleSetting* ruleSetting = new RuleSetting(RULE_1_2S);
    list<RuleSetting> list;
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_1_3S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2OF3_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_R_4S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_X_1S);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(4);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XX);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(10);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XT);
    ruleSetting->setIsActive(false);
    ruleSetting->setValue(7);
    list.push_back(*ruleSetting);
    WestgardConfiguration* test = new WestgardConfiguration(list, true);
    WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
    EXPECT_FALSE(westgardConfiguration == *test);
    setupXMLconfig();
}


TEST_F(RulesDataMapperTest, controlereadFileToGetSettingFalseValueChanged) {
    RuleSetting* ruleSetting = new RuleSetting(RULE_1_2S);
    list<RuleSetting> list;
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_1_3S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2OF3_2S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_R_4S);
    ruleSetting->setIsActive(true);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_X_1S);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(4);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XX);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(10);
    list.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XT);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(8);
    list.push_back(*ruleSetting);
    WestgardConfiguration* test = new WestgardConfiguration(list, true);
    WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
    EXPECT_FALSE(westgardConfiguration == *test);
    setupXMLconfig();
}

TEST_F(RulesDataMapperTest, MissingFile){
	ifstream infile (gs_fileLocation,ifstream::binary);
	infile.seekg(0,infile.end);
	long size = infile.tellg();
	infile.seekg (0);
	char* buffer = new char[size];
	infile.read (buffer,size);
	infile.close();
	remove(gs_fileLocation);
    EXPECT_EQ(r1->updateWithNameStatementAndValue(RULE_XT,true,10), FAILED_FILE_MISSING);
	ofstream outfile (gs_fileLocation,ofstream::binary);
	outfile.write (buffer,size);
	delete[] buffer;
	outfile.close();
	setupXMLconfig();
}

TEST_F(RulesDataMapperTest, testMultiThreadingResistanceUpdateWithNameAndStatement){
        std::thread thread1( [&]() { return r1->updateWithNameAndStatement(RULE_1_2S,false); } );
        thread1.join();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
        RuleSetting* ruleSetting = new RuleSetting(RULE_1_2S);
        ruleSetting->setIsActive(false);
        list<RuleSetting> list;
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_1_3S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_2_2S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_2OF3_2S);
        ruleSetting->setIsActive(false);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_R_4S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_X_1S);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(4);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_XX);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(10);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_XT);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(7);
        list.push_back(*ruleSetting);
        WestgardConfiguration* test = new WestgardConfiguration(list, true);
        EXPECT_EQ(westgardConfiguration ,*test);
        setupXMLconfig();
}

    TEST_F(RulesDataMapperTest, testMultiThreadingResistanceUpdateWithNameStatementAndValue){
        std::thread thread1( [&]() { return r1->updateWithNameStatementAndValue(RULE_X_1S,false,8); } );
        thread1.join();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
        RuleSetting* ruleSetting = new RuleSetting(RULE_1_2S);
        ruleSetting->setIsActive(true);
        list<RuleSetting> list;
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_1_3S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_2_2S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_2OF3_2S);
        ruleSetting->setIsActive(false);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_R_4S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_X_1S);
        ruleSetting->setIsActive(false);
        ruleSetting->setValue(8);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_XX);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(10);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_XT);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(7);
        list.push_back(*ruleSetting);
        WestgardConfiguration* test = new WestgardConfiguration(list, true);
        EXPECT_EQ(westgardConfiguration ,*test);
        setupXMLconfig();
    }

    TEST_F(RulesDataMapperTest, testMultiThreadingResistanceUpdateParameterizableStatement){
        std::thread thread1( [&]() { return r1->updateParameterizableStatement(false); } );
        thread1.join();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        WestgardConfiguration westgardConfiguration = r1->readFileToGetSetting();
        RuleSetting* ruleSetting = new RuleSetting(RULE_1_2S);
        ruleSetting->setIsActive(true);
        list<RuleSetting> list;
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_1_3S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_2_2S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_2OF3_2S);
        ruleSetting->setIsActive(false);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_R_4S);
        ruleSetting->setIsActive(true);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_X_1S);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(4);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_XX);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(10);
        list.push_back(*ruleSetting);
        ruleSetting = new RuleSetting(RULE_XT);
        ruleSetting->setIsActive(true);
        ruleSetting->setValue(7);
        list.push_back(*ruleSetting);
        WestgardConfiguration* test = new WestgardConfiguration(list, false);
        EXPECT_EQ(westgardConfiguration ,*test);
        setupXMLconfig();
    }

}




