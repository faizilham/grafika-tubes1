#include "trans.hpp"

matrix_t mmultiply(matrix_t m1, float* data, int col){
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

Transform::Transform(){
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			mat.data[i][j] = (float) (i == j);
}

Transform::Transform(matrix_t mat){
	this->mat = mat;
}

Transform& Transform::operator= (matrix_t mat){
	this->mat = mat;
	return *this;
}

float* Transform::operator[] (int row){
	return mat.data[row];
}

matrix_t Transform::operator* (matrix_t mat){
	return mmultiply(this->mat, (float*) mat.data, 3);
}

matrix_t operator* (matrix_t mat, Transform trans){
	return trans * mat;
}

matrix_t Transform::operator* (Transform trans){
	return (*this) * trans.mat;
}

Transform createTranslation(int dx, int dy){
	Transform trans;
	
	trans[0][2] = dx;
	trans[1][2] = dy;
	
	return trans;
}

Transform createRotation(float deg){
	float rad = deg * M_PI / 180.f;
	float st = sin(rad); float ct = cos(rad);
	
	Transform trans;
	
	trans[0][0] = ct; trans[0][1] = -st;
	trans[1][0] = st; trans[1][1] = ct;
	
	return trans;
}

Transform createScale(float sx, float sy){
	Transform trans;
	
	trans[0][0] = sx; trans[1][1] = sy;
	return trans;
}