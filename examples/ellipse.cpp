/**
 * @file   example4.cpp
 * @author Sebastien Fourey (GREYC)
 *
 * @brief  Sample drawing using the board library.
 *
 * This source code is part of the Board project, a C++ library whose
 * purpose is to allow simple drawings in EPS, FIG or SVG files.
 * Copyright (C) 2007 Sebastien Fourey <http://foureys.users.greyc.fr>
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Board.h"

using namespace LibBoard;

int main( int, char *[] )
{
  Board board;
  board.clear( Color(200,255,200) );
  double angle = M_PI * 110/180.0;
  Group g;

  g << Rectangle( 0, 50, 100, 50, Color::Black, Color::Null, 1 );
  g << Line( 0, 25, 100, 25, Color(0,0,255), 1 );
  g << Ellipse( 50, 25, 50, 25, Color::Red, Color::Null, 1 );
  g.translate( 30, 30 );
  g.rotate( angle );
  g.scale( 1.5, 2 );
  board << g;
  std::cerr << board.boundingBox(Shape::UseLineWidth) << std::endl;
  board.saveEPS( "ellipse.eps" );
  board.saveFIG( "ellipse.fig" );
  board.saveSVG( "ellipse.svg" );
}
