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
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber a1(2, Unit::CM);
    PhysicalNumber a2(3, Unit::KM);
    PhysicalNumber a3(4, Unit::M);
    PhysicalNumber a4(0.1, Unit::KM);

    PhysicalNumber b1(2, Unit::SEC);
    PhysicalNumber b2(3, Unit::MIN);
    PhysicalNumber b3(4, Unit::HOUR);
    PhysicalNumber b4(0.1, Unit::HOUR);

    PhysicalNumber c1(2, Unit::G);
    PhysicalNumber c2(3, Unit::KG);
    PhysicalNumber c3(4, Unit::TON);
    PhysicalNumber c4(0.1, Unit::TON);

    PhysicalNumber x(100, Unit::G);
    PhysicalNumber y(2, Unit::HOUR);
    PhysicalNumber z(10, Unit::M);
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
    .setname("Operator '-' binary - Compatible dimensions")
    .CHECK_OUTPUT(a2-a1, "3.00002[km]")
    .CHECK_OUTPUT(a3-a1, "3.98[m]")                                //4[m] - 2[cm]
    .CHECK_OUTPUT(a4-a1, "0.09998[km]")                            //0.1[km] - 2[cm]
    .CHECK_OUTPUT(a1-a2, "-299998[cm]")                            //2[cm] - 3[km]
    .CHECK_OUTPUT(b2-b1, "2.9666666667[min]")                      //3[min] - 2[sec]
    .CHECK_OUTPUT(b3-b1, "3.9994444444[hour]")                     //4[hour] - 2[sec]
    .CHECK_OUTPUT(b4-b1, "0.0994444444[hour]")                     //0.1[hour] - 2[sec]
    .CHECK_OUTPUT(b3-b2, "3.95[hour]")                             //4[hour] - 3[min]

    .setname("Operator '+' binary - Compatible dimensions")
    .CHECK_OUTPUT(a1+a2, "300002[cm]")                             //2[cm] + 3[km]
    .CHECK_OUTPUT(a1+a3, "402[cm]")                                //2[cm] + 4[m]
    .CHECK_OUTPUT(a1+a4, "10002[cm]")                              //2[cm] + 0.1[km]
    .CHECK_OUTPUT(a2+a1, "3.00002[km]")                            //3[km] + 2[cm]
    .CHECK_OUTPUT(b1+b2, "182[sec]")                               //2[sec] + 3[min]
    .CHECK_OUTPUT(b1+b3, "14402[sec]")                             //2[sec] + 4[hour]
    .CHECK_OUTPUT(b1+b4, "362[sec]")                               //2[sec] + 0.1[hour]
    .CHECK_OUTPUT(b3+b2, "4.05[hour]")                             //4[hour] + 3[min]
    .CHECK_OUTPUT(c1+c2, "3002[g]")                                //2[g] + 3[kg]
    .CHECK_OUTPUT(c1+c3, "4000002[g]")                             //2[g] + 4[ton]
    .CHECK_OUTPUT(c1+c4, "100002[g]")                              //2[g] + 0.1[ton]
    .CHECK_OUTPUT(c2+c1, "3.002[kg]")    

     .setname("Operator '-' binary - Incompatible dimensions")
    .CHECK_THROWS(a1-b1)
    .CHECK_THROWS(b1-c1)
    .CHECK_THROWS(c1-a1)
    .CHECK_THROWS(a2-c2)


    .setname("Operator '+=' binary - Compatible dimensions")
    .CHECK_OUTPUT((a1+=a2), "300002[cm]")                             //a1 = 2[cm] + 3[km]
    .CHECK_OUTPUT((b1+=b3), "14402[sec]")                             //b1 = 2[sec] + 4[hour]
    .CHECK_OUTPUT((b3+=b2), "4.05[hour]")                             //b3 = 4[hour] + 3[min]
    .CHECK_OUTPUT((c1+=c4), "100002[g]")                              //c1 = 2[g] + 0.1[ton]
    .CHECK_OUTPUT((c2+=c2), "6[kg]")                                  //c2 = 3[kg] + 3[kg]


    .setname("Operator '+=' binary - Incompatible dimensions")
    .CHECK_THROWS(a1+=b1)
    .CHECK_THROWS(b1+=c1)
    .CHECK_THROWS(c1+=a1)
    .CHECK_THROWS(a2+=c2)
    .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
