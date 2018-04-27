/*
 * Measure.cpp
 *
 *  Created on: 28 f�vr. 2018
 *      Author: charles.socie
 */

#include "Measure.h"

/** @class Measure
* @details Class Measure is build with one value and a Date
*/


/**
 * @details Constructor
 * @param value value of the Measure
 * @param date Date of the Measure
 */
Measure::Measure(float value, struct tm date) : m_value(value), m_date(date) {
	// TODO Auto-generated constructor stub

}

/**
 * @details Destructor
 */
Measure::~Measure() {
	// TODO Auto-generated destructor stub
}

/**
 * @details operator < overloading to compare two Measure
 * @param m Measure to compare with the current Measure
 * @return a boolean depending of the Measure's Date comparison
 */
bool Measure::operator<(const Measure& m) const{
	bool result;
    if(m_date.tm_year == m.m_date.tm_year){
        if(m_date.tm_mon == m.m_date.tm_mon){
        	if(m_date.tm_mday == m.m_date.tm_mday){
        		if(m_date.tm_hour == m.m_date.tm_hour){
					if(m_date.tm_min == m.m_date.tm_min){
						result = m_date.tm_sec < m.m_date.tm_sec;
					}
					result = m_date.tm_min < m.m_date.tm_min;
        		}
        		result = m_date.tm_hour < m.m_date.tm_hour;
        	}
        	result = m_date.tm_mday < m.m_date.tm_mday;
        }
        else{
        	result = m_date.tm_mon < m.m_date.tm_mon;
        }
    }else{
    	result = m_date.tm_year < m.m_date.tm_year;
    }
    return result;
}


/**
 * @details operator << overloading to write a Measure on an output stream
 * @param o output stream
 * @param measure Measure needs to be write on the ostream
 * @return the current Measure writing structure
 */
ostream&  operator<<( ostream& o,const Measure& measure) {
    o << "Value = " << to_string(measure.m_value) << endl;
    o << "date = " << measure.m_date.tm_mday << "/" << measure.m_date.tm_mon << "/" << measure.m_date.tm_year << endl;
    o << "heure = " << measure.m_date.tm_hour << ":" << measure.m_date.tm_min << ":" << measure.m_date.tm_sec << endl;
    return o;
}
