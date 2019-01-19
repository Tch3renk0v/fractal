/*
 * main.cpp
 *
 *  Created on: 17 janv. 2019
 *      Author: tcherenkov
 */


#include <iostream>
#include <omp.h>
#include "Window.h"
#include "Fractale.h"



template<class T> inline const T map(const T value ,const T inMin,const T inMax,const  T outMin,const  T outMax)
{return (value - inMin ) * (outMax - outMin)/(inMax - inMin) + outMin ;}

int main(int argc, char *argv[])
{

  const int window_width  = 1920,
	    window_height  = 1080,
	    fractal_width  = 800,
	    fractal_height = 800;

  int max_it = 100;

  long double max_f  = 2.0,
	      min_f  = -2.0,
	      factor = 1.0;

  Window window("maFenetre",window_width, window_height);
  window.clear();

 // window.fillBackground(0,0,0, 255);
 // window.blitRectangle(0, 0, 200, 200, 255, 0, 0, 255);
 // window.addPixel((unsigned int)width/2, (unsigned int)height/2, 255, 255, 255, 255);

  int frame = 0;

  while(!window.isClosed())
    {
      //window.fillBackground(0,0,0, 255);


      for(int j=0; j< window_height; j++ )
	   {

	     long double Im_old = map((long double)j ,
					   (const long double)0 , (const long double)fractal_height,
					   min_f, max_f );
	   int i=0;

	     for(i=0; i< window_width; i++)
	       {
		  int n	    = 0;
		  int bright = 0;
		 long double R_old = map((long double)i ,
	 		      (const long double)0 , (const long double)fractal_width,
			      min_f, max_f );

		 long double R_current  = R_old  ;
		 long double Im_current = Im_old ;





	     for( int f=0; f < max_it; f++)
	       {
		 // The julia set recurence function. set R_c = R_old and Im_c = R_Im to get the mandebrot set
		 if(Fractale::juliaset(R_current, Im_current, 0.285,  0.01))
		   {break;}

		++n;
	       }
	     bright = map(n, 0, max_it, 0, 255);
	     if(n < 0.2*max_it || n==max_it )
	       bright = 0;

	     window.addPixel(i,j, map(bright*bright, 0, 6502, 0, 255), bright, map((long double)sqrt(bright), (long double)0, (long double)15.968719422671, (long double)0, (long double)255), 255);

	     n = 0;

	   }







	     window.pollEvents();
       }
      					//We poll event before presenting the renderer
									//to make sure the window is created (waiting for initialisation).
	window.presentRenderer();
	window.fillBackground(0,0,0,255);
	frame++;

	max_f -= 0.10 * factor;
	min_f += 0.15 * factor;
	factor *= 0.9349;


	    max_it += (unsigned int)factor*0.1;


    }




  std::cout<< "Done !" << std::endl;
  return 0;
}

