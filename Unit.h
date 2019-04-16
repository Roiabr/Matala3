#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
enum class Unit{
    CM = 0,M = 3,KM = 6, // Mod 6 =0
	SEC = 1,MIN = 4,HOUR = 7, // Mod 6 = 1
    G =2, KG = 5,TON = 8      // Mod 6 = 2
};
} 
