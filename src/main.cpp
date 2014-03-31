#include "road.hpp"
#include "obstacle_manager.hpp"
#include "car.hpp"
#include "result.hpp"
#include "text_countdown.hpp"

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
<<<<<<< HEAD
	bool gameover = true;
	TextCountdown txt = TextCountdown(20,80,140);
	char strbuffer[64];
=======
	bool gameover = false;
>>>>>>> f2fc6342732363c36d08fe138ccf020d99a3d27a
	
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
			/* countdown text*/
			settextstyle(txt.style,0,txt.size);
			setcolor(txt.color);
			sprintf(strbuffer,"%d",txt.counter);
			outtextxy(getmaxx()/2 + txt.x, getmaxy()/2 - txt.y, strbuffer);
			/* end of countdown text*/

			// update phase
			r.update();
			car.update(c);
			OM.update();
			txt.update();

			c = 0;
			delay(100);
		}
		getch_async(c);
	}
	
	
	return 0;

}