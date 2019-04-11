#include "Unit.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace ariel{
class PhysicalNumber{
private:
Unit unit;
long double num;
void convDis(int cases ,PhysicalNumber& other) const;
void convTime(int cases ,PhysicalNumber& other) const;
void convWig(int cases, PhysicalNumber& other) const;
void convertByType(PhysicalNumber& other) const;

public:
//constructor
PhysicalNumber (long double a,Unit unit);
//copy constructor
PhysicalNumber (const PhysicalNumber& obj);

void setValue(long double d){ //setter
		this->num = d;
}
double getValue() const { //getter
		return num;
}
Unit getType() const{ 
		return unit; 
}


PhysicalNumber operator+ (const PhysicalNumber& PHnum )const;
PhysicalNumber operator- (const PhysicalNumber& PHnum )const;

//unery operators
PhysicalNumber operator-();
PhysicalNumber operator+() const;

 PhysicalNumber& operator-= (const PhysicalNumber& PHnum );
 PhysicalNumber& operator+= (const PhysicalNumber& PHnum );


//compare operators
bool operator!= ( const PhysicalNumber& PHnum);
bool operator==(const PhysicalNumber& PHnum);
bool operator<=(const PhysicalNumber& PHnum);
bool operator>=(const PhysicalNumber& PHnum);
bool operator>(const PhysicalNumber& PHnum);
bool operator<(const PhysicalNumber& PHnum);

PhysicalNumber& operator++ ();
PhysicalNumber& operator-- ();
const PhysicalNumber operator++ (int);
const PhysicalNumber operator-- (int);


//friends functions:
friend istream& operator>>(istream&,PhysicalNumber&);

friend ostream& operator<<(ostream&, const PhysicalNumber&);
};
}