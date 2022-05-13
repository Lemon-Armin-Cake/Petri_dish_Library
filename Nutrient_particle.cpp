#include<cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "Growth_medium.h"
#include "Nutrient_particle.h"  


 const float a = 20; //линейный размер среды вдоль оси X
 const float b = 10; //линейный размер среды вдоль оси Y
 const float p = 55; //линейный размер среды вдоль оси X

 
 void Nutrient_particle::print() const
 {
	 static int k = 0;
	 printf(" Particle # %d \n", k);
	 printf("the status is %d \n", (this->get_status()));
	 printf("w = %f \n", x);
	 printf("z = %f \n", y);
	 printf("f = %d \n", f);
	 k++;
 }

 