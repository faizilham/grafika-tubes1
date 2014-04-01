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
			//printf("Char: %d\n", c);
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
	Result result;
	
	bool gameover = false;
	TextCountdown txt = TextCountdown(100,80,140);
	char strbuffer[64];
	
	char c = 0;
	
	OM.setCar(&car);
	
	// the game loop
	while (c != 'q' && c != 'Q'){
		
		if (txt.counter <= 0){
			gameover = true;
		}

		if (gameover){
			if (txt.counter <= 0 && result.resultframe <25){
				cleardevice();
				result.showResultWin(5000);
			}
			else if (result.resultframe <25){
				cleardevice();
				result.showResultLose(20-txt.counter*10);
			}
		}
		else {
			cleardevice();
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
			
			if(OM.isCollided()){
				gameover = true;
			}

			c = 0;
			delay(100);
		}
		getch_async(c);
	}
	
	
	return 0;

}