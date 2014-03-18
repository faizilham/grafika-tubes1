#ifndef LIBGRAPH_H
#define LIBGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

static int midx, midy;

void init_graph();
void paintpix(int x, int y, int color);
void draw_line(int x1, int y1, int x2, int y2, int color);

#endif