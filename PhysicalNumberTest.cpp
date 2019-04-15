/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int x,y,z;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    ////////Weight////////////////
    PhysicalNumber aa(2, Unit::TON);
    PhysicalNumber bb(2000, Unit::KG);
    PhysicalNumber cc(2, Unit::TON);
    PhysicalNumber dd(20000, Unit::G);

    //////////////Time////////////////
    PhysicalNumber aaa(2, Unit::HOUR);
    PhysicalNumber bbb(120, Unit::MIN);
    PhysicalNumber ccc(2, Unit::HOUR);
    PhysicalNumber ddd(360, Unit::SEC);

    ////////////Distance///////////////
    PhysicalNumber aaaa(1, Unit::KM);
    PhysicalNumber bbbb(1000, Unit::M);
    PhysicalNumber cccc(2, Unit::KM);
    PhysicalNumber dddd(100000, Unit::CM);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
   
      .setname("Basic output")
      .CHECK_OUTPUT(aa, "2[ton]")
      .CHECK_OUTPUT(bb, "2000[kg]")
      .CHECK_OUTPUT(cc, "2[ton]")
      .CHECK_OUTPUT(dd, "20000[g]")
      .CHECK_OUTPUT(aaa, "2[hour]")
      .CHECK_OUTPUT(bbb, "120[min]")
      .CHECK_OUTPUT(ccc, "2[hour]")
      .CHECK_OUTPUT(ddd, "360[sec]")
      .CHECK_OUTPUT(aaaa, "1[km]")
      .CHECK_OUTPUT(bbbb, "1000[m]")
      .CHECK_OUTPUT(cccc, "2[km]")
      .CHECK_OUTPUT(dddd, "100000[cm]")
      
    .setname("Operator '+' binary ")
    .CHECK_OUTPUT(aa+aa, "4[ton]")
    .CHECK_OUTPUT(aa+bb, "4[ton]")
    .CHECK_OUTPUT(bb+dd, "2020[kg]")
    .CHECK_OUTPUT(aaa+bbb, "4[hour]")
    .CHECK_OUTPUT(bbb+aaa, "240[min]")
    .CHECK_OUTPUT(aaa+ccc, "4[hour]")
    .CHECK_OUTPUT(ccc+ddd, "2.1[hour]") 
    .CHECK_OUTPUT(ddd+aaa, "7560[sec]")
    .CHECK_OUTPUT(aaaa+bbbb, "2[km]") 
    .CHECK_OUTPUT(bbbb+aaaa, "2000[m]") 
    .CHECK_OUTPUT(cccc+dddd, "3[km]")
    .CHECK_OUTPUT(dddd+cccc, "300000[cm]") 

    .setname("Operator '-' binary ")
    .CHECK_OUTPUT(aa-aa, "0[ton]")
    .CHECK_OUTPUT(aa-bb, "0[ton]")
    .CHECK_OUTPUT(bb-dd, "1980[kg]")
    .CHECK_OUTPUT(aaa-bbb, "0[hour]") 
    .CHECK_OUTPUT(bbb-aaa, "0[min]")
    .CHECK_OUTPUT(aaa-ccc, "0[hour]")
    .CHECK_OUTPUT(ccc-ddd, "1.9[hour]")
    .CHECK_OUTPUT(aaaa-bbbb, "0[km]") 
    .CHECK_OUTPUT(bbbb-aaaa, "0[m]") 
    .CHECK_OUTPUT(cccc-dddd, "1[km]")
    
    .setname("Operator '+=' binary ")
    .CHECK_OUTPUT((aa+=aa), "4[ton]")
    .CHECK_OUTPUT((aa+=bb), "6[ton]")
    .CHECK_OUTPUT((bb+=dd), "2020[kg]")
    .CHECK_OUTPUT((aaa+=bbb), "4[hour]")
    .CHECK_OUTPUT((bbb+=aaa), "360[min]")
    .CHECK_OUTPUT((aaa+=ccc), "6[hour]")
    .CHECK_OUTPUT((ccc+=ddd), "2.1[hour]") 

    .setname("Operator '-=' binary ")
    .CHECK_OUTPUT((aa-=bb), "3.98[ton]")
    .CHECK_OUTPUT((aa-=bb), "1.96[ton]")
    .CHECK_OUTPUT((bb-=dd), "2000[kg]")
    .CHECK_OUTPUT((aaa-=ccc), "3.9[hour]")
    .CHECK_OUTPUT((aaa-=ccc), "1.8[hour]")
    .CHECK_OUTPUT((ccc-=ddd), "2[hour]") 

    .setname("Operator '+' binary - Incompatible dimensions")
    .CHECK_THROWS(aa+bbb)
    .CHECK_THROWS(bbbb+cc)
    .CHECK_THROWS(cccc+aa)
    .CHECK_THROWS(ddd+cc)

    .setname("Operator '-' binary - Incompatible dimensions")
    .CHECK_THROWS(aa-bbb)
    .CHECK_THROWS(bbbb-cc)
    .CHECK_THROWS(cccc-aa)
    .CHECK_THROWS(ddd-cc)

    .setname("Operator '+=' binary - Incompatible dimensions")
    .CHECK_THROWS(aa+=bbb)
    .CHECK_THROWS(bbbb+=cc)
    .CHECK_THROWS(cccc+=aa)
    .CHECK_THROWS(ddd+=cc)

    .setname("Operator '-=' binary - Incompatible dimensions")
    .CHECK_THROWS(aa -= bbb)
    .CHECK_THROWS(bbbb -= cc)
    .CHECK_THROWS(cccc -= aa)
    .CHECK_THROWS(ddd -= cc)

    ////////////////Booolean operators//////////
    .setname("Operator '==' binary - Compatible dimensions")
    .CHECK_EQUAL(aa==aa,true)
    .CHECK_EQUAL(ddd==PhysicalNumber(360,Unit::SEC),true)
    .CHECK_EQUAL(bbb==bbb,true)
    .CHECK_EQUAL(dddd==PhysicalNumber(100000,Unit::CM),true)
    
    .setname("Operator '!=' binary - Compatible dimensions")
    .CHECK_EQUAL(aa != dd,true)
    .CHECK_EQUAL(aa != PhysicalNumber(1,Unit::TON),true)
    .CHECK_EQUAL(ddd != PhysicalNumber(36,Unit::SEC),true)
    .CHECK_EQUAL(bbb != ccc,true)
    .CHECK_EQUAL(dddd != PhysicalNumber(100,Unit::CM),true)

    .setname("Operator '<' binary")
    .CHECK_EQUAL(aa < dd,false)
    .CHECK_EQUAL(aa < PhysicalNumber(90,Unit::TON),true)
    .CHECK_EQUAL(ddd < PhysicalNumber(3500,Unit::SEC),true)
    .CHECK_EQUAL(aaa < ddd ,false)
    .CHECK_EQUAL(dddd < PhysicalNumber(1000000,Unit::CM),true)

    .setname("Operator '<=' binary")
    .CHECK_EQUAL(aa <= aa,true)
    .CHECK_EQUAL(aa <= PhysicalNumber(9,Unit::TON),true)
    .CHECK_EQUAL(ddd <= PhysicalNumber(36,Unit::SEC),false)
    .CHECK_EQUAL(ddd <= ddd ,true)
    .CHECK_EQUAL(dddd <= PhysicalNumber(1000000,Unit::CM),true)

    .setname("Operator '>=' binary")
    .CHECK_EQUAL(aa >= aa,true)
    .CHECK_EQUAL(aa >= PhysicalNumber(9,Unit::TON),false)
    .CHECK_EQUAL(ddd >= PhysicalNumber(36,Unit::SEC),true)
    .CHECK_EQUAL(ddd >= ddd ,true)
    .CHECK_EQUAL(dddd >= PhysicalNumber(1000000,Unit::CM),false)
    
    .setname("Operator '>=' binary")
    .CHECK_EQUAL(aa >= aa,true)
    .CHECK_EQUAL(aa >= PhysicalNumber(9,Unit::TON),false)
    .CHECK_EQUAL(ddd >= PhysicalNumber(36,Unit::SEC),true)
    .CHECK_EQUAL(ddd >= ddd ,true)
    .CHECK_EQUAL(dddd >= PhysicalNumber(1000000,Unit::CM),false)

    .setname("Operator '<' binary - Incompatible dimensions")
    .CHECK_THROWS(aa < bbb)
    .CHECK_THROWS(bbbb < cc)
    .CHECK_THROWS(cccc < aa)
    .CHECK_THROWS(ddd < cc)

    .setname("Operator '>' binary - Incompatible dimensions")
    .CHECK_THROWS(aa > bbb)
    .CHECK_THROWS(bbbb > cc)
    .CHECK_THROWS(cccc > aa)
    .CHECK_THROWS(ddd > cc)

    .setname("Operator '<=' binary - Incompatible dimensions")
    .CHECK_THROWS(aa <= bbb)
    .CHECK_THROWS(bbbb <= cc)
    .CHECK_THROWS(cccc <= aa)
    .CHECK_THROWS(ddd <= cc)

    .setname("Operator '>=' binary - Incompatible dimensions")
    .CHECK_THROWS(aa <= bbb)
    .CHECK_THROWS(bbbb <= cc)
    .CHECK_THROWS(cccc <= aa)
    .CHECK_THROWS(ddd <= cc)

    .setname("Operator '++'")
    .CHECK_OUTPUT(bb++,"2000[kg]")
    .CHECK_OUTPUT(cc++,"2[ton]")
    .CHECK_OUTPUT(dd++,"20000[g]")
    .CHECK_OUTPUT(bbb--,"360[min]")
    .CHECK_OUTPUT(ccc--,"2[hour]")
    .CHECK_OUTPUT(ddd--,"360[sec]")
    .CHECK_OUTPUT(++aaaa,"2[km]")
    .CHECK_OUTPUT(++bbbb,"1001[m]")
    .CHECK_OUTPUT(++cccc,"3[km]")
    .CHECK_OUTPUT(++dddd,"100001[cm]")
    .CHECK_OUTPUT(--a,"1699[kg]")
    .CHECK_OUTPUT(--bb,"2000[kg]")
    .CHECK_OUTPUT(--dddd,"100000[cm]")

    .print(cout, /*show_grade=*/false);
    grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;

}