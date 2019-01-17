/*
 * Window.cpp
 *
 *  Created on: 17 janv. 2019
 *      Author: tcherenkov
 */

#include "Window.h"

Window::Window (const std::string &title, int width, int height):
  m_title(title), m_height(height), m_width(width)

{
  //If SDL not initialized, then quit.

    m_closed = !init();



}

void Window::pollEvents()
{
    SDL_Event event;

    if(SDL_PollEvent(&event))
      {
	  switch(event.type){
		  case SDL_QUIT:
		    m_closed=true;
		    break;
		  case SDL_KEYDOWN:
		    m_closed=true;
		    break;
		  default:
		    break;
	  }
      }

}

void Window::blitRectangle( int xPos, int yPos, int h, int w, int C_red, int C_green, int C_blue, int C_alpha) const
{
  SDL_Rect rect;

  rect.h=h;
  rect.w=w;
  rect.x=xPos;
  rect.y=yPos;

  SDL_SetRenderDrawColor(m_renderer, C_red, C_green, C_blue, C_alpha);
  SDL_RenderFillRect(m_renderer,&rect);
}

void Window::addPixel(int xPos, int yPos, int C_red, int C_green, int C_blue, int C_alpha) const
{
    SDL_SetRenderDrawColor(m_renderer, C_red, C_green, C_blue, C_alpha);
    SDL_RenderDrawPoint(m_renderer, xPos, yPos);
}

void Window::fillBackground(int C_red, int C_green, int C_blue, int C_alpha) const
{
  SDL_SetRenderDrawColor(m_renderer, C_red, C_green, C_blue, C_alpha);			//Choose to render black color with maximum opacity
  SDL_RenderClear(m_renderer);						//Clear everything on the renderer
}

void Window::clear() const
{
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);			//Choose to render black color with maximum opacity
  SDL_RenderClear(m_renderer);						//Clear everything on the renderer noSkip!
  SDL_RenderPresent(m_renderer);					//Blit the renderer onto the window
}

void Window::presentRenderer() const
{
  SDL_RenderPresent(m_renderer);
}


bool Window::init()
{
  if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      std::cerr<< "Error, failed to initialize SDL." << std::endl;
      return 0;
    }

  m_window = SDL_CreateWindow(m_title.c_str(),
			      SDL_WINDOWPOS_CENTERED,
			      SDL_WINDOWPOS_CENTERED,
			      m_width,
			      m_height,
			      0
			      );
  if(m_window == nullptr)
    {
      std::cerr << "SDL failed to create window" << std::endl;
      return 0;
    }

  m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED);

  if(m_renderer == nullptr)
    {
      std::cerr<< "Failed to create renderer." << std::endl;
      return 0;
    }


  return 1;
}


Window::~Window ()
{
  SDL_DestroyWindow(m_window);
  SDL_DestroyRenderer(m_renderer);
  SDL_Quit();
}

