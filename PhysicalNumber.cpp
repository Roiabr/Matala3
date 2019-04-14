#include <iostream>
#include "PhysicalNumber.h"
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

//////////////////////constructor//////////////////////
//constructor
PhysicalNumber::PhysicalNumber (double a,Unit unit){
	this->num=a;
	this->unit=unit;
}
//copy constructor
PhysicalNumber::PhysicalNumber (const PhysicalNumber& obj){
	this->num=obj.num;
	this->unit=obj.unit;
}

/////////////////////////////////operators///////////////////////////////////////
PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& other )const
{
    if((int)this->unit % 3 != (int)other.unit % 3)
    {//cant do the operator on diffrent unit type
       throw std::invalid_argument("Exception,they must be from the same type");
    }

    PhysicalNumber p1(other);
    this->convertByType(p1);
    return PhysicalNumber(this->num+(p1.num),this->unit);
}

PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber& other ){
    
    if((int)this->unit % 3 != (int)other.unit % 3){//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type");
    }

    PhysicalNumber p1(other);
    this->convertByType(p1); 
    this->num = this->num + p1.num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator+() const {
    return PhysicalNumber((this->num),this->unit);
}
//////////////////////// - operators ///////////////////////////////////////////
PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& other )const{
    if((int)this->unit % 3 != (int)other.unit % 3){//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type");
    }
    
    PhysicalNumber p1(other);
    this->convertByType(p1); 
    return PhysicalNumber(this->num-(p1.num),this->unit);  
}
PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& other )
{
    if((int)this->unit % 3 != (int)other.unit % 3){//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type");
    }
    
    PhysicalNumber p1(other);
    this->convertByType(p1); 
     this->num = this->num-p1.num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator-(){
    return PhysicalNumber(-1*(this->num),this->unit);
}

/////////////////////////////////compare operators/////////////////////////////////////////////////
bool PhysicalNumber::operator!= ( const PhysicalNumber& other){
    if((int)this->unit % 3 != (int)other.unit % 3){//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type");
    }

    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->num != p1.num)
        return true;
    return false;
}

bool PhysicalNumber::operator== (const PhysicalNumber& other){
    if((int)this->unit % 3 != (int)other.unit % 3){//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type");
    }

    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->num == p1.num)
        return true;
    return false;
}

bool PhysicalNumber::operator<= (const PhysicalNumber& other)
{
    if((int)this->unit % 3 != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type");
    }
    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->num <= p1.num)
        return true;
    return false;
}

bool PhysicalNumber::operator>= (const PhysicalNumber& other)
{
    if((int)this->unit % 3 != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type");
    }

     PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->num >= p1.num)
        return true;
    return false;
}

bool PhysicalNumber::operator> (const PhysicalNumber& other)
{
    if((int)this->unit % 3 != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type");
    }
    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->num > p1.num)
        return true;
    return false;
}

bool PhysicalNumber::operator< (const PhysicalNumber& other)
{
    if((int)this->unit % 3 != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type");
    }
    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->num < p1.num)
        return true;
    return false;
}

PhysicalNumber& PhysicalNumber::operator++()
{
   this->num++;
   return *this;
}
PhysicalNumber& PhysicalNumber::operator--()
{
    this->num--;
    return *this;
}
const PhysicalNumber PhysicalNumber::operator++(int)
{
   PhysicalNumber copy = *this;
   this->num++;
   return copy;
}
const PhysicalNumber PhysicalNumber::operator--(int)
{
    PhysicalNumber copy = *this;
    this->num--;
    return copy;
}

///////////////////////////friends functions:input && output ///////////////////////

string find_which_type(const PhysicalNumber& obj)
{
    switch((int)(obj.getType()))
    {
		case 2: return "g";
		break;
		case 5: return "kg";
		break;
		case 8: return "ton";
		break;
		case 0: return "cm";
		break;
		case 3: return "m";
		break;
		case 6: return "km";
		break;
		case 1: return "sec";
		break;
		case 4: return "min";
		break;
		case 7: return "hour";
		break;
    }
	return "";
}

ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& obj)
{
    stream<< obj.getValue() << "[" << find_which_type(obj) << "]";
    return stream;
}

istream& ariel::operator>> (istream& is,PhysicalNumber& other)
{
    double num=-99999;
    string st=" ";
    is>>num;
    is>>st;

    if(num == -99999)
    {
        throw std::invalid_argument("Exception,they must be from the same type");
    }   
    else
    {

    Unit unit;
    if(st.compare("[g]")==0)
        unit=Unit::G;
    else if(st.compare("[kg]")==0)
    {
        unit=Unit::KG;
    }
    else if(st.compare("[ton]")==0)
        unit=Unit::TON;
    else if(st.compare("[cm]")==0)
        unit=Unit::CM;
    else if(st.compare("[m]")==0)
        unit=Unit::M;
    else if(st.compare("[km]")==0)
        unit=Unit::KM;
    else if(st.compare("[sec]")==0)
        unit=Unit::SEC;
    else if(st.compare("[min]")==0)
        unit=Unit::MIN;
    else if(st.compare("[hour]")==0)
        unit=Unit::HOUR;
    else{
        throw std::invalid_argument("Exception,they must be from the same type");
    }
    other.unit=unit;
    other.num=num;
    }
    return is;
}



void ariel::PhysicalNumber::convertByType(PhysicalNumber& other) const
{
	if((int)this->unit % 3 == 0)//this is the distance unit
    {
		this->convDis((int)this->unit ,other);
    }
	else if((int)this->unit % 3 == 1)// this is the time unit
    {
		this->convTime((int)this->unit, other);
	}
	else//the Weight unit
    {
		this->convWig((int)this->unit, other);
	}

}
//the function convert the PhysicalNumber to the correct unit type in distance
void PhysicalNumber::convDis (int cases, PhysicalNumber& other) const 
{
    switch (cases)
    {
        case 0://if this is CM
            if((int)other.unit == 3)// other type is M
                other.num = (other.num*100);
            if((int)other.unit == 6)// other type is KM
            {
                other.num = (other.num*100000);
            }
            break;
        case 3://if this is M
            if((int)other.unit== 0){
			    other.num = (other.num/100); //other is CM
		    }
		    if((int)other.unit== 6){
			    other.num = (other.num*1000); //other is KM
		    }
        break; 
        
        case 6://if this is KM
            if((int)other.unit == 0) // other CM
                other.num = (other.num/(100000));
            if((int)other.unit == 3){ // other M
                other.num = (other.num/1000);
            }
    }
}

void PhysicalNumber::convTime(int cases, PhysicalNumber& other) const
//the function convert the PhysicalNumber to the correct unit type in Time
{
    switch (cases)
    {
        case 1://sec
            if((int)other.unit == 4)//MIN
                other.num = (other.num*60);
            if((int)other.unit == 7)//HOUR
            {
                other.num = (other.num*(60*60));
            }
            if((int)other.unit == 1)
            {
                return;
            }
            break;
        case 4://MIN
            if((int)other.unit == 1){//SEC
                other.num = (other.num*60);
            }
            if((int)other.unit == 7){//HOUR
                other.num = (other.num*60);
            }
            if((int)other.unit == 4)
            {
                return;
            }
            
        case 7://HOUR
            if((int)other.unit == 1)//SEC
                other.num = (other.num/(60*60));
            if((int)other.unit == 4){//MIN
                other.num = (other.num/60);
            }
            if((int)other.unit == 7)
            {
                return;
            } 
    }
}

void PhysicalNumber::convWig(int cases, PhysicalNumber& other) const
//the function convert the PhysicalNumber to the correct unit type in weight
{
    switch (cases)
    {
        case 2://G
            if((int)other.unit == 5)//KG
                other.num = (other.num*1000);
            if((int)other.unit == 8){//TON
                other.num = (other.num*1000*1000);
            }
            if((int)other.unit == 2)
            {
                return;
            }
            break;
        case 5://KG
            if((int)other.unit == 2)//G
                other.num = (other.num*(1000));
            if((int)other.unit == 8){//TON
                other.num = (other.num*1000);
            }
            if((int)other.unit == 5)
            {
                return;
            }
 
        case 8://TON
            if((int)other.unit == 2)//G
                other.num = (other.num/(1000*1000));
            if((int)other.unit == 5){//KG
                other.num = (other.num/1000);
            }
            if((int)other.unit == 8)
            {
                return;
            }
            
    }

}