#include "Unit.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace ariel{
class PhysicalNumber{
private:

void convDis(int cases ,PhysicalNumber& other) const;
void convTime(int cases ,PhysicalNumber& other) const;
void convWig(int cases, PhysicalNumber& other) const;
void convertByType(PhysicalNumber& other) const;


public:
Unit unit;
double value;
//constructor
PhysicalNumber (double a,Unit unit);
//copy constructor
PhysicalNumber (const PhysicalNumber& obj);

string find_which_type(PhysicalNumber& other);

PhysicalNumber operator+ (const PhysicalNumber& other )const;
PhysicalNumber operator- (const PhysicalNumber& other )const;

//unery operators
PhysicalNumber operator-() const;
PhysicalNumber operator+() const;

PhysicalNumber& operator-= (const PhysicalNumber& other );
PhysicalNumber& operator+= (const PhysicalNumber& other );


//compare operators
bool operator!= ( const PhysicalNumber& other);
bool operator==(const PhysicalNumber& other);
bool operator<=(const PhysicalNumber& other);
bool operator>=(const PhysicalNumber& other);
bool operator>(const PhysicalNumber& other);
bool operator<(const PhysicalNumber& other);

PhysicalNumber& operator++ ();
PhysicalNumber& operator-- ();
const PhysicalNumber operator++ (int);
const PhysicalNumber operator-- (int);


//friends functions:
friend istream& operator>>(istream&, PhysicalNumber& other);
friend ostream& operator<<(ostream&,const PhysicalNumber& other);

};
}