#include "Unit.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace ariel{
class PhysicalNumber{
public:
Unit u;
double a;
//constructor
PhysicalNumber (double a,Unit unit);
//copy constructor
PhysicalNumber (const PhysicalNumber& obj);

PhysicalNumber operator+ (const PhysicalNumber& PHnum )const;
PhysicalNumber operator- (const PhysicalNumber& PHnum )const;

//unery operators
PhysicalNumber operator-();
PhysicalNumber operator+() const;

const PhysicalNumber& operator-= (const PhysicalNumber& PHnum );
const PhysicalNumber& operator+= (const PhysicalNumber& PHnum );


//compare operators
bool operator!= ( const PhysicalNumber& PHnum);
bool operator==(const PhysicalNumber& PHnum);
bool operator<=(const PhysicalNumber& PHnum);
bool operator>=(const PhysicalNumber& PHnum);
bool operator>(const PhysicalNumber& PHnum);
bool operator<(const PhysicalNumber& PHnum);


PhysicalNumber& operator++();
PhysicalNumber& operator--();


//friends functions:
friend istream& operator>>(istream&, const PhysicalNumber&);

friend ostream& operator<<(ostream&, const PhysicalNumber&);
};
}