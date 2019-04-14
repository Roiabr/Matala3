#include "Unit.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace ariel{
class PhysicalNumber{
private:
Unit unit;
double num;
void convDis(int cases ,PhysicalNumber& other) const;
void convTime(int cases ,PhysicalNumber& other) const;
void convWig(int cases, PhysicalNumber& other) const;
void convertByType(PhysicalNumber& other) const;
string find_which_type(PhysicalNumber& obj);

public:
//constructor
PhysicalNumber (double a,Unit unit);
//copy constructor
PhysicalNumber (const PhysicalNumber& obj);

Unit getType() const{
    return unit;
}
double getValue() const{
    return num;
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