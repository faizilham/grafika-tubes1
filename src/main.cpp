#include "road.hpp"
#include "obstacle_manager.hpp"
#include "car.hpp"
#include "result.hpp"

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
	Car car;
	Road r;	
	ObstacleManager OM;
	bool gameover = false;
	
	char c = 0;
	
	// the game loop
	while (c != 'q'){
		cleardevice();
		if (gameover){
			showResultLose(0);
		}
		else {
			// draw phase
			r.draw();
			car.draw();
			OM.draw();		

			// update phase
			r.update();
			car.update(c);
			OM.update();

			c = 0;
			delay(100);
		}
		getch_async(c);
	}
	
	
	return 0;

}