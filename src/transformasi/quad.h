#ifndef SQUARE_H
#define SQUARE_H

#include "linelib.h"
#include "trans.h"

typedef struct{
	point_t p[4]; point_t mid;
} quad_t;

static quad_t create_rect(int x1, int y1, int x2, int y2){
	quad_t q; int i;
	for (i = 0; i < 4; i++){
		switch(i){
			case 0:{
				q.p[i].x = x1;
				q.p[i].y = y1;
			}break;
			case 1:{
				q.p[i].x = x1;
				q.p[i].y = y2;
			}break;
			case 2:{
				q.p[i].x = x2;
				q.p[i].y = y2;
			}break;
			case 3:{
				q.p[i].x = x2;
				q.p[i].y = y1;
			}break;
		}
	}
	
	q.mid.x = abs(x1 - x2) / 2;
	q.mid.y = abs(y1 - y2) / 2;
	
	return q;
}

static void scale(quad_t* quad, float scale){
	int i; matrix_t ms;
	ms = mscale(scale, scale);
	
	for(i = 0; i < 4; i++){
		quad->p[i] = transform(ms, quad->p[i]);
	}
	
	quad->mid = transform(ms, quad->mid);
}

static void translate(quad_t* quad, int x, int y){
	int i; matrix_t mt;
	
	mt = mtranslate(x,y);
	
	for(i = 0; i < 4; i++){
		quad->p[i] = transform(mt, quad->p[i]);
	}
	
	quad->mid = transform(mt, quad->mid);
}

static void rotate_quad(quad_t* quad, int deg){
	matrix_t m[3], mc; int i;
	m[0] = mtranslate(-quad->mid.x, -quad->mid.y);
	m[1] = mrotate(deg);
	m[2] = mtranslate(quad->mid.x, quad->mid.y);
	
	mc = mrotate(deg);//combine(m, 3);
	
	for(i = 0; i < 4; i++){
		quad->p[i] = transform(mc, quad->p[i]);
	}
}

static void print_quad(quad_t q){
	int i;
	for(i = 0; i < 4; i++){
		print_point(q.p[i]);
		printf(" ");
	}
	
	print_point(q.mid);
	printf("\n");
}

static void draw_quad(quad_t quad, int color){
	int i, j;
	for (i = 0; i < 4; i++){
		j = i < 3 ? i + 1 : 0;
		bresenham_line(quad.p[i].x, quad.p[i].y, quad.p[j].x, quad.p[j].y, color);
	}
}

#endif