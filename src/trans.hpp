#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <math.h>

typedef struct{
	float data[3][3];
} matrix_t;

matrix_t mmultiply(matrix_t m1, float* data, int col);

class Transform{
	public:
		matrix_t mat;
		
		Transform();
		Transform(matrix_t mat);
		
		Transform& operator= (matrix_t mat);
		float* operator[] (int row);
		
		matrix_t operator* (matrix_t mat);
		friend matrix_t operator* (matrix_t mat, Transform trans);
		matrix_t operator* (Transform trans);	
		
};

Transform createTranslation(int dx, int dy);
Transform createRotation(float deg);
Transform createScale(float sx, float sy);

#endif