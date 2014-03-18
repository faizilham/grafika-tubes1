#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <math.h>
#include "point.h"

typedef struct{
	float data[3][3];
} matrix_t;

static matrix_t mmultiply(matrix_t m1, float* data, int col){
	matrix_t m;
	int i, j, k;
	for (i = 0; i < 3; i++)
		for (j = 0; j < col; j++){
			m.data[i][j] = 0;
			for (k = 0; k < 3; k++)
				m.data[i][j] += m1.data[i][k] * data[k*col + j];
		}
	
	return m;
}

static matrix_t combine(matrix_t* trans, int ntrans){
	int i; matrix_t m = trans[ntrans - 1];
	for (i = ntrans - 2; i >= 0; i--){
		m = mmultiply(m, (float*) trans[i].data, 3);
	}
	
	return m;
}

static matrix_t midentity(){
	matrix_t m; int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			m.data[i][j] = (float) (i == j);
	
	return m;
}

static matrix_t mtranslate(int dx, int dy){
	matrix_t m = midentity();
	
	m.data[0][2] = dx;
	m.data[1][2] = dy;
	
	return m;
}

static matrix_t mrotate(int deg){
	float rad = deg * M_PI / 180.f;
	float st = sin(rad); float ct = cos(rad);
	
	matrix_t m = midentity();
	
	m.data[0][0] = ct; m.data[0][1] = -st;
	m.data[1][0] = st; m.data[1][1] = ct;
	
	return m;
}

static matrix_t mscale(float sx, float sy){
	matrix_t m = midentity();
	m.data[0][0] = sx; m.data[1][1] = sy;
	return m;
}

static point_t transform(matrix_t m, point_t p){
	int i, j; matrix_t res; point_t p1;
	float pdata[3][1]; pdata[0][0] = p.x; pdata[1][0] = p.y; pdata[2][0] = 1;
	
	res = mmultiply(m, (float*) pdata, 1);
	p1.x = res.data[0][0]; p1.y = res.data[1][0];
	
	return p1;
}



#endif