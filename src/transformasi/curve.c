#include "linelib.h"
#include "point.h"

point_t get_bezier(point_t* p, int start, int n, float t){
	if (n == 0){
		return p[0];
	}else{
		return add_point(mul_point(get_bezier(p, start, n-1, t), 1-t), mul_point(get_bezier(p, start+1,n-1), t));
	}
}

void paint_point(point_t p){
	paintpix(p.x, p.y, WHITE);
}

void bezier_curve(point_t* p, int n){
	float t, dt; point_t p;
	dt = 0.02; t = 0;
	
	while (t < 1){
		paint_point(get_bezier(p, 0, n, t));
		t += dt;
	}	
}

int main(){
	point_t p[4]; int i;
	init_graph();
	
	p[0] = make_point(0,0); p[1] = make_point(2,2);
	p[2] = make_point(3,1); p[3] = make_point(4,2);
	
	bezier_curve(p, 4);
	for (i = 0; i < 4; i++)
		paint_point(p[i]);		
	
	// pause
	getch();
	return 0;
}