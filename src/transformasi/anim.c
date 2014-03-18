#include "quad.h"
#include <dos.h>

quad_t q; int i;

int main(){
	init_graph();

	q = create_rect(0, 0, 50, 50);

	for (i = 0; i < 90 * 2; i++){
		//cleardevice();

		draw_quad(q, 255);
		//print_quad(q);
		delay(20);
		//translate(&q, -q.mid.x, -q.mid.y);
		rotate_quad(&q, 4);
		
		if ((i + 1) % 90 == 0){
			scale(&q, 2);
		}
	}

	// pause
	getch();
	return 0;	
}