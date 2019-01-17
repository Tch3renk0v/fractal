/*
 * Fractale.cpp
 *
 *  Created on: 17 janv. 2019
 *      Author: tcherenkov
 */

#include "Fractale.h"

bool Fractale::mandelbrot(long double &R_current, long double &Im_current,const long double R_old, const long double Im_old)
{
   const long double m1 = R_current*R_current - Im_current*Im_current;
   const long double m2 = 2 * R_current * Im_current;

   R_current = m1+R_old;
   Im_current = m2+ Im_old;

   if( (R_current + Im_current) > (const long double)30)
       return true;
   else
       return false;
}
