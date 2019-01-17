/*
 * main.cpp
 *
 *  Created on: 17 janv. 2019
 *      Author: tcherenkov
 */


#include <iostream>
#include "Window.h"
#include "Fractale.h"



template<class T> inline T map(T value ,T inMin,T inMax, T outMin, T outMax)
{return (value - inMin ) * (outMax - outMin)/(inMax - inMin) + outMin ;}

int main(int argc, char *argv[])
{
  const int window_width  = 800,
	    window_height = 800,
	    fractal_width = 800,
	    fractal_height = 800;


  Window window("maFenetre",window_width, window_height);
  window.clear();

 // window.fillBackground(0,0,0, 255);
 // window.blitRectangle(0, 0, 200, 200, 255, 0, 0, 255);
 // window.addPixel((unsigned int)width/2, (unsigned int)height/2, 255, 255, 255, 255);


  while(!window.isClosed())
    {
      //window.fillBackground(0,0,0, 255);

      for(int i=0; i< window_width; i++)
	{
	 long double R_old = map((long double)i ,
					(const long double)0 , (const long double)fractal_width,
					(const long double)-2 , (const long double)2 );
	 for(int j=0; j< window_height; j++ )
	   {
	     long double Im_old = map((long double)j ,
					   (const long double)0 , (const long double)fractal_height,
					   (const long double)-2 , (const long double)2 );
	     long double R_current = R_old;
	     long double Im_current = Im_old;



	     int n = 0;

	     for( int f=0; f < 100; f++)
	       {

		 if(Fractale::mandelbrot(R_current, Im_current, R_old,  Im_old))
		   {break;}

		++n;
	       }
	     int bright = map(n, 0, 100, 0,255);
	     if(n==100 || n< 20)
	       bright = 0;

	     window.addPixel(i,j, bright, bright, bright, bright);

	   }
	 window.pollEvents();


	}






						//We poll event before presenting the renderer
									//to make sure the window is created (waiting for initialisation).
	window.presentRenderer();
	window.fillBackground(0,0,0,255);

    }




  std::cout<< "Done !" << std::endl;
  return 0;
}

