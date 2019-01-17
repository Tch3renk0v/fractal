/*
 * Window.h
 *
 *  Created on: 17 janv. 2019
 *      Author: tcherenkov
 */

#ifndef WINDOW_H_
#define WINDOW_H_
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Window
{
public:
  Window (const std::string &title, int width, int height);
  inline bool isClosed() const {return m_closed;}
  void fillBackground(int C_red, int C_green, int C_blue, int C_alpha) const;
  void addPixel(int xPos, int yPos, int C_red, int C_green, int C_blue, int C_alpha) const;
  void blitRectangle( int xPos, int yPos, int h, int w,int C_red, int C_green, int C_blue, int C_alpha) const;
  void pollEvents();
  void presentRenderer() const;
  void clear() const;
  ~Window ();
private:
  bool init();


private:
  bool m_closed = true;
  std::string m_title;
  int	      m_width=800,
	      m_height=600;
  SDL_Window   *m_window   = nullptr;
  SDL_Renderer *m_renderer = nullptr;


};

#endif /* WINDOW_H_ */
