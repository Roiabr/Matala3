#include <iostream>
#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;


PhysicalNumber::PhysicalNumber (long double a,Unit unit){
	this->num=a;
	this->unit=unit;
}
//copy constructor
PhysicalNumber::PhysicalNumber (const PhysicalNumber& obj){
	this->num=obj.num;
	this->unit=obj.unit;
}


PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& PHnum )const{
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1);
    return PhysicalNumber(this->getValue()+(p1.getValue()),this->getType());
}
PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& PHnum )const{
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1); 
    return PhysicalNumber(this->getValue()-(p1.getValue()),this->getType());  
}
PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& PHnum )
{
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1); 
    this->setValue(this->getValue()-p1.getValue());
    return *this;
}
PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber& PHnum ){
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1); 
    this->setValue(this->getValue()+p1.getValue());
    return *this;
}

PhysicalNumber PhysicalNumber::operator+() const {
    return PhysicalNumber((this->getValue()),this->getType());
}
PhysicalNumber PhysicalNumber::operator-(){
    return PhysicalNumber(-1*(this->getValue()),this->getType());
}

//compare operators
bool PhysicalNumber::operator!= ( const PhysicalNumber& PHnum){
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1);
    if(this->getValue() != p1.getValue())
        return true;
    return false;
}
bool PhysicalNumber::operator== (const PhysicalNumber& PHnum){
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1);
    if(this->getValue() == p1.getValue())
        return true;
    return false;
}
bool PhysicalNumber::operator<=(const PhysicalNumber& PHnum){
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1);
    if(this->getValue() <= p1.getValue())
        return true;
    return false;
}
bool PhysicalNumber::operator>=(const PhysicalNumber& PHnum){
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
     PhysicalNumber p1(PHnum);
    this->convertByType(p1);
    if(this->getValue() >= p1.getValue())
        return true;
    return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber& PHnum){
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1);
    if(this->getValue() > p1.getValue())
        return true;
    return false;
}
bool PhysicalNumber::operator<(const PhysicalNumber& PHnum){
    if((int)this->getType() % 3 != (int)PHnum.getType() % 3){
        ::__throw_bad_exception();
    }
    PhysicalNumber p1(PHnum);
    this->convertByType(p1);
    if(this->getValue() < p1.getValue())
        return true;
    return false;
}


PhysicalNumber& PhysicalNumber::operator++(){
   this->num++;
   return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    this->num--;
    return *this;
}
const PhysicalNumber PhysicalNumber::operator++(int)
{
   PhysicalNumber copy = *this;
    this->num++;
    return copy;
}
 const PhysicalNumber PhysicalNumber::operator--(int){
    PhysicalNumber copy = *this;
    this->num--;
    return copy;
}

//friends functions:
ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& obj){
    switch((int)(obj.getType())){
		case 2: stream<<obj.getValue()<<"[g]";
		break;
		case 5: stream<<obj.getValue()<<"[kg]";
		break;
		case 8: stream<<obj.getValue()<<"[ton]";
		break;
		case 0: stream<<obj.getValue()<<"[cm]";
		break;
		case 3: stream<<obj.getValue()<<"[m]";
		break;
		case 6: stream<<obj.getValue()<<"[km]";
		break;
		case 1: stream<<obj.getValue()<<"[sec]";
		break;
		case 4: stream<<obj.getValue()<<"[min]";
		break;
		case 7: stream<<obj.getValue()<<"[hour]";
		break;
}
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
        ::__throw_bad_exception();
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
        ::__throw_bad_exception();
    }
    other.unit=unit;
    other.num=num;
    }
    return is;
}



void ariel::PhysicalNumber::convertByType(PhysicalNumber& other) const{
	if((int)this->getType() % 3 == 0){
		this->convDis((int)this->getType() ,other);
    }
	else if((int)this->getType() % 3 == 1){
		this->convTime((int)this->getType(), other);
	}
	else{
		this->convWig((int)this->getType(), other);
	}

}
void PhysicalNumber::convDis (int cases, PhysicalNumber& other) const
{
    
    switch (cases)
    {
        case 0://if this is CM
            if((int)other.getType() == 3)// other type is M
                other.setValue(other.getValue()*100);
            if((int)other.getType() == 6)// other type is KM
            {
                other.setValue(other.getValue()*100000);
            }
            break;
        case 3://if this is M
            if((int)other.getType()== 0){
			    other.setValue(other.getValue()/100);
		    }
		    if((int)other.getType()== 6){
			    other.setValue(other.getValue()*1000);
		    }
        break; 
        
        case 6:
            if((int)other.getType() == 0)
                other.setValue(other.getValue()/(100000));
            if((int)other.getType() == 3){
                other.setValue(other.getValue()/1000);
            }


    }

}
void PhysicalNumber::convTime(int cases, PhysicalNumber& other) const
{
    switch (cases)
    {
        case 1:
            if((int)other.getType() == 4)
                other.setValue(other.getValue()*60);
            if((int)other.getType() == 7){
                other.setValue(other.getValue()*(60*60));
            }
            break;
        case 4:
            if((int)other.getType() == 1){
                other.setValue(other.getValue()*60);
            }
            if((int)other.getType() == 7){
                other.setValue(other.getValue()*60);
            }
            if((int)other.getType() == 4)
            {
                return;
            }
            
        case 7:
            if((int)other.getType() == 1)
                other.setValue(other.getValue()/(60*60));
            if((int)other.getType() == 4){
                other.setValue(other.getValue()/60);
            }
            if((int)other.getType() == 7)
            {
                return;
            }
            
    }

}
void PhysicalNumber::convWig(int cases, PhysicalNumber& other) const
{
    switch (cases)
    {
        case 2:
            if((int)other.getType() == 5)
                other.setValue(other.getValue()*1000);
            if((int)other.getType() == 8){
                other.setValue(other.getValue()*1000*1000);
            }
            if((int)other.getType() == 2)
            {
                return;
            }
          

            break;
        case 5:
            if((int)other.getType() == 2)
                other.setValue(other.getValue()/(1000));
            if((int)other.getType() == 8){
                other.setValue(other.getValue()*1000);
            }
            if((int)other.getType() == 5)
            {
                return;
            }
 
        case 8:
            if((int)other.getType() == 2)
                other.setValue(other.getValue()/(1000*1000));
            if((int)other.getType() == 5){
                other.setValue(other.getValue()/1000);
            }
            if((int)other.getType() == 8)
            {
                return;
            }
            
    }

}