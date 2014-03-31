#include "road.hpp"
#include "obstacle_manager.hpp"
#include "car.hpp"

void print(Transform t){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%.2f ", t[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool getch_async(char& c){
	if (kbhit()){
		c = getch();
		if(c == 0){ //Handle arrow key
			c = getch();
			printf("Char: %d\n", c);
		}
		
		return true;
	}else{
		return false;
	}
}


int main(){

	init_graph();
	
	//draw_ellipse(10, 10, 30, 80, 255);
	Car car;
	Road r;
	Quad q (-100, -100, -50, -50);
	Transform t = createScale(0.01, 0.01);
	
	q.applyTransform(t);
	
	t = createScale(1.1, 1.1);
	
	ObstacleManager OM;
	
	char c;
	while (c != 'q'){
		cleardevice();
		// draw phase
		r.draw();
		car.draw();
		OM.draw();
		
		//q.draw(WHITE);
		
		// update phase
		r.update();
		car.update(c);
		OM.update();
		//q.applyTransform(t);
		c = 0;
		delay(100);
		
		getch_async(c);
	}
	
	
	return 0;

}