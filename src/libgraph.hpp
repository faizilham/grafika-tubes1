#ifndef LIBGRAPH_HPP
#define LIBGRAPH_HPP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>


/** Graphic Primitive **/

void init_graph();
void paintpix(int x, int y, int color);

/** Graphics Algorithms **/

void draw_line(int x1, int y1, int x2, int y2, int color);

#endif