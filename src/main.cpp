#include "road.hpp"
#include "obstacle_manager.hpp"

bool getch_async(char& c){
	// non-blocking getch
	
	if (kbhit()){
		c = getch();
		return true;
	}else{
		return false;
	}
}


int main(){
	init_graph();
	
	Road r;	
	ObstacleManager OM;
	
	char c = 0;
	
	// the game loop
	while (c != 'q'){
		cleardevice();
		
		// draw phase
		r.draw();
		OM.draw();
		
		// update phase
		r.update();
		OM.update();
		
		delay(100);
		getch_async(c);
	}
	
	
	return 0;

}