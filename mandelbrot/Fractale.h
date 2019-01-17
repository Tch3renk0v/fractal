/*
 * Fractale.h
 *
 *  Created on: 17 janv. 2019
 *      Author: tcherenkov
 */

#ifndef FRACTALE_H_
#define FRACTALE_H_

namespace Fractale{
//Test de condition de div de mandelbrot
  bool mandelbrot(long double  &R_current, long double &Im_current, const long double R_old, const long double Im_old);
}

#endif /* FRACTALE_H_ */
