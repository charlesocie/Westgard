/*
 * WestgardInterface.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef WESTGARDBRICK_WESTGARDINTERFACE_H
#define WESTGARDBRICK_WESTGARDINTERFACE_H

#include "Controller/ERulesName.h"
#include "Controller/EWGResult.h"
#include "Controller/Measure.h"
#include "Model/IRule.h"
#include "Controller/EvaluateController.h"
#include "Controller/EUpdateResult.h"
#include "Controller/WestgardResult.h"
#include <list>

class WestgardInterface {

private:

    /*ATTRIBUTS*/
    /** WestgardInterface instance*/
    static WestgardInterface *ms_instance;
    /** instance of EvaluateController*/
    static EvaluateController ms_evaluateController;

protected:
    /*CONSTRUCTOR*/
    WestgardInterface();

public:
    /*DESTRUCTOR*/
    ~WestgardInterface();

    /*METHODES*/
    WestgardResult WGevaluateWithListOnly(const list<Measure> listMeasure)const ;
    WestgardResult WGevaluateWithListMeanAnd1SD(const list<Measure> listMeasure, const float mean, const float oneSD)const ;
    WestgardResult WGevaluateWithListTargetAndTolerance(const list<Measure> listMeasure, const float target, const float tolerance)const ;
    EUpdateResult updateWithNameAndStatement(const ERulesName ruleName, const bool statement);
    EUpdateResult updateWithNameStatementAndValue(const ERulesName ruleName, const bool statement, const int value);
    EUpdateResult updateEvaluateParameterizableRulesIf1_2sSucceed(const bool isActive);
    WestgardConfiguration getWestgardConfiguration()const ;

    /*GETTER*/
    static WestgardInterface *getInstance();
};

#endif /* CONTROLLER_CPP_WESTGARDINTERFACE_H_ */
