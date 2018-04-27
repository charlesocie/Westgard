#ifndef CONTROLLER_MEASURE_H_
#define CONTROLLER_MEASURE_H_

#include <ctime>
#include<iostream>

using namespace std;

class Measure {

private:
	/*ATTRIBUTS*/
	/** @details value of the Measure */
	 float m_value;
	/** @details Date of the Measure */
	 struct tm m_date;

public:

	/*CONSTRUCTOR*/
	Measure(float value, struct tm date);

	/*DESTRUCTOR*/
	virtual ~Measure();

	/*GETTER*/
	/**
	 * @details get the Date of the current Measure
	 * @return the Date
	 */
	inline struct tm getDate() const {return m_date;}

	/**
	 * @details get the value of the current Measure
	 * @return an integer as the value
	 */
	inline float getValue() const {return m_value;}

	/*SETTER*/
	/**
	 * @details set the value of the current Measure
	 * @param value value to update
	 */
	inline void setValue(const float value){this->m_value =value;}

	/*OPERATOR*/
	friend ostream& operator<<( ostream& , const Measure&);
	bool operator< (const Measure& m) const;
};

#endif /* CONTROLLER_CPP_MEASURE_H_ */
