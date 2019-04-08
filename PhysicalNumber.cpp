#include <iostream>
#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;


PhysicalNumber::PhysicalNumber (double a,Unit unit){
	this->a=a;
	this->u=unit;
}
//copy constructor
PhysicalNumber::PhysicalNumber (const PhysicalNumber& obj){
	this->a=obj.a;
	this->u=obj.u;
}


PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& PHnum )const{
    return PhysicalNumber(0,this->u);
}
PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& PHnum )const{
    return PhysicalNumber(0,this->u);    
}
const PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& PHnum ){
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber& PHnum ){
    return *this;
}

PhysicalNumber PhysicalNumber::operator+() const {
    return *this;
}
PhysicalNumber PhysicalNumber::operator-(){
    return *this;
}

//compare operators
bool PhysicalNumber::operator!= ( const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator==(const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator<=(const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator>=(const PhysicalNumber& PHnum){
    return true;
}

bool PhysicalNumber::operator>(const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator<(const PhysicalNumber& PHnum){
    return true;
}


PhysicalNumber& PhysicalNumber::operator++(){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    return *this;
}

//friends functions:
ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& obj){
	return stream;
}

istream& ariel::operator>>(std::istream& is, const PhysicalNumber& other){
	return is;
}
