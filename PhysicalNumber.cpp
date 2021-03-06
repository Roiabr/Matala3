#include "PhysicalNumber.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace ariel;
using namespace std;

//////////////////////constructor//////////////////////
//constructor
PhysicalNumber::PhysicalNumber (double a,Unit unit){
	this->value=a;
	this->unit=unit;
}
//copy constructor
PhysicalNumber::PhysicalNumber (const PhysicalNumber& obj){
	this->value=obj.value;
	this->unit=obj.unit;
}

///////////////////////////private functions////////////////////////////////

//the function find the type of the PhysicalNumber and send
// it to the correct convert function
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
                other.value = (other.value*100);
            if((int)other.unit == 6)// other type is KM
            {
                other.value = (other.value*100000);
            }
            break;
        case 3://if this is M
            if((int)other.unit== 0){
			    other.value = (other.value/100); //other is CM
		    }
		    if((int)other.unit== 6){
			    other.value = (other.value*1000); //other is KM
		    }
        break; 
        
        case 6://if this is KM
            if((int)other.unit == 0) // other CM
                other.value = (other.value/(100000));
            if((int)other.unit == 3){ // other M
                other.value = (other.value/1000);
            }
    }
}
//the function convert the PhysicalNumber to the correct unit type in Time
void PhysicalNumber::convTime(int cases, PhysicalNumber& other) const
{
    switch (cases)
    {
        case 1://sec
            if((int)other.unit == 4)//MIN
                other.value = (other.value*60);
            if((int)other.unit == 7)//HOUR
            {
                other.value = (other.value*(60*60));
            }
            if((int)other.unit == 1)
            {
                return;
            }
            break;
        case 4://MIN
            if((int)other.unit == 1)
            {//SEC
                other.value = (other.value*60);
            }
            if((int)other.unit == 7)
            {//HOUR
                other.value = (other.value*60);
            }
            if((int)other.unit == 4)
            {
                return;
            }
            
        case 7://HOUR
            if((int)other.unit == 1)//SEC
                other.value = (other.value/(60*60));
            if((int)other.unit == 4)
            {//MIN
                other.value = (other.value/60);
            }
            if((int)other.unit == 7)
            {
                return;
            } 
    }
}
//the function convert the PhysicalNumber to the correct unit type in weight
void PhysicalNumber::convWig(int cases, PhysicalNumber& other) const
{
    switch (cases)
    {
        case 2://G
            if((int)other.unit == 5)//KG
                other.value = (other.value*1000);
            if((int)other.unit == 8){//TON
                other.value = (other.value*1000*1000);
            }
            if((int)other.unit == 2)
            {
                return;
            }
            break;
        case 5://KG
            if((int)other.unit == 2)//G
                other.value = (other.value*(1000));
            if((int)other.unit == 8){//TON
                other.value = (other.value*1000);
            }
            if((int)other.unit == 5)
            {
                return;
            }
 
        case 8://TON
            if((int)other.unit == 2)//G
                other.value = (other.value/(1000*1000));
            if((int)other.unit == 5){//KG
                other.value = (other.value/1000);
            }
            if((int)other.unit == 8)
            {
                return;
            }
            
    }
}
///////////////////////////////// '+' operators///////////////////////////////////////
PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& other )const
{
    if((int)this->unit % 3 != (int)other.unit % 3)
    {//cant do the operator on diffrent unit type
       throw std::invalid_argument("Exception,they must be from the same type ");
    }

    PhysicalNumber p1(other);
    convertByType(p1);
    return PhysicalNumber(this->value+(p1.value),this->unit);
}

PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber& other )
{
    if((int)this->unit % 3 != (int)other.unit % 3)
    {//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type ");
    }

    PhysicalNumber p1(other);
    this->convertByType(p1); 
    this->value = this->value + p1.value;
    return *this;
}

PhysicalNumber PhysicalNumber::operator+() const 
{
    return PhysicalNumber((this->value),this->unit);
}
//////////////////////// '-' operators ///////////////////////////////////////////
PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& other )const
{
    if((int)this->unit % 3 != (int)other.unit % 3)
    {//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type ");
    }
    
    PhysicalNumber p1(other);
    this->convertByType(p1); 
    return PhysicalNumber(this->value-(p1.value),this->unit);  
}
PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& other )
{
    if((int)this->unit % 3 != (int)other.unit % 3)
    {//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type ");
    }
    
    PhysicalNumber p1(other);
    this->convertByType(p1); 
     this->value = this->value-p1.value;
    return *this;
}

PhysicalNumber PhysicalNumber::operator-() const
{
    return PhysicalNumber(-1*(this->value),this->unit);
}

/////////////////////////////////compare operators/////////////////////////////////////////////////
bool PhysicalNumber::operator!= ( const PhysicalNumber& other)
{
    if((int)this->unit % 3 != (int)other.unit % 3)
    {//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type ");
    }

    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->value != p1.value)
        return true;
    return false;
}

bool PhysicalNumber::operator== (const PhysicalNumber& other)
{
    if((int)this->unit % 3 != (int)other.unit % 3)
    {//cant do the operator on diffrent unit type
        throw std::invalid_argument("Exception,they must be from the same type ");
    }

    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->value == p1.value)
        return true;
    return false;
}

bool PhysicalNumber::operator<= (const PhysicalNumber& other)
 {
    if((int)this->unit % 3 != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type  ");
    }
    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->value <= p1.value)
        return true;
    return false;
}

bool PhysicalNumber::operator>= (const PhysicalNumber& other)
{
    if((int)this->unit % 3 != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type ");
    }

     PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->value >= p1.value)
        return true;
    return false;
}

bool PhysicalNumber::operator> (const PhysicalNumber& other)
{
    if((int)this->unit % 3  != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type ");
    }
    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->value > p1.value)
        return true;
    return false;
}

bool PhysicalNumber::operator< (const PhysicalNumber& other)
{
    
    if((int)this->unit % 3 != (int)other.unit % 3)//cant do the operator on diffrent unit type
    {
        throw std::invalid_argument("Exception,they must be from the same type ");
    }
    PhysicalNumber p1(other);
    this->convertByType(p1);
    if(this->value < p1.value)
        return true;
    return false;
}

PhysicalNumber& PhysicalNumber::operator++()
{
   this->value++;
   return *this;
}
PhysicalNumber& PhysicalNumber::operator--()
{
    this->value--;
    return *this;
}
const PhysicalNumber PhysicalNumber::operator++(int)
{
   PhysicalNumber copy = *this;
   this->value++;
   return copy;
}
const PhysicalNumber PhysicalNumber::operator--(int)
{
    PhysicalNumber copy = *this;
    this->value--;
    return copy;
}

///////////////////////////friends functions:input && output ///////////////////////


string find_which_type(const PhysicalNumber& obj)
{
    switch((int)(obj.unit))
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

ostream& ariel::operator<<(ostream& stream,const PhysicalNumber& obj)
{
    stream << obj.value << "[" << find_which_type(obj) << "]";
    return stream;
}

istream& ariel::operator>> (istream& stream,PhysicalNumber& other)
{ //based on the 04-const-friend-operators folder in the complex.cpp file for the >> operator
    ios::pos_type startPosition = stream.tellg();
    double num = 0;
    string st = " ";
    stream >> num;
    stream >> st;

    if(num < 0 )
    {
          auto errorState = stream.rdstate();
          stream.clear(); // clear error so seekg will work
          stream.seekg(startPosition); // rewind
          stream.clear(errorState); // set back the error flag
          return stream;
    }   
    else
    {
        Unit unit;
        if(st.compare("[sec]") == 0)
            unit=Unit::SEC;
        else if(st.compare("[min]") == 0)
            unit=Unit::MIN;
        else if(st.compare("[hour]") == 0)
            unit=Unit::HOUR;
        else if(st.compare("[g]") == 0)
            unit=Unit::G;
        else if(st.compare("[kg]") == 0)
            unit=Unit::KG;
        else if(st.compare("[ton]") == 0)
            unit=Unit::TON;
        else if(st.compare("[cm]") == 0)
            unit=Unit::CM;
        else if(st.compare("[m]") == 0)
            unit=Unit::M;
        else if(st.compare("[km]") == 0)
            unit=Unit::KM;
        else// if cant find any of the type should throw flag
        {
          auto errorState = stream.rdstate();
          stream.clear(); // clear error so seekg will work
          stream.seekg(startPosition); // rewind
          stream.clear(errorState); // set back the error flag
          return stream;
        }
    other.unit = unit;
    other.value = num;
    }
    return stream;
}



