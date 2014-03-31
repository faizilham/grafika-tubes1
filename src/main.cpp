#include "road.hpp"
#include "obstacle_manager.hpp"
#include "car.hpp"

bool getch_async(char& c){
	// non-blocking getch
	
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
	
<<<<<<< HEAD
	//draw_ellipse(10, 10, 30, 80, 255);
	Car car;
	Road r;
	Quad q (-100, -100, -50, -50);
	Transform t = createScale(0.01, 0.01);
	
	q.applyTransform(t);
	
	t = createScale(1.1, 1.1);
	
	ObstacleManager OM;
	
	char c;
=======
	Road r;	
	ObstacleManager OM;
	
	char c = 0;
	
	// the game loop
>>>>>>> 197faf57e83e6be4f410afabdd12d1338ccaef05
	while (c != 'q'){
		cleardevice();
		
		// draw phase
		r.draw();
		car.draw();
		OM.draw();
<<<<<<< HEAD
		
		//q.draw(WHITE);
=======
>>>>>>> 197faf57e83e6be4f410afabdd12d1338ccaef05
		
		// update phase
		r.update();
		car.update(c);
		OM.update();
<<<<<<< HEAD
		//q.applyTransform(t);
		c = 0;
=======
		
>>>>>>> 197faf57e83e6be4f410afabdd12d1338ccaef05
		delay(100);
		getch_async(c);
	}
	
	
	return 0;

}