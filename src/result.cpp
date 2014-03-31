#include "result.hpp"

void showResultWin(int score){
	int left = -320;
	int right = 320;
	int top = 240;
	int bot = -240;
	char strbuffer[64];
	// W
	draw_line(left+60,top-80,left+140+5,bot+220,WHITE);
	draw_line(left+140+5,bot+220,left+180+5,bot+300,WHITE);
	draw_line(left+180+5,bot+300,left+220+5,bot+220,WHITE);
	draw_line(left+220+5,bot+220,left+300+10,top-80,WHITE);

	draw_line(left+300+10,top-80,left+260+5,top-80,WHITE);
	draw_line(left+260+5,top-80,left+220+5,top-160,WHITE);
	draw_line(left+220+5,top-160,left+180+5,top-80,WHITE);
	draw_line(left+180+5,top-80,left+140+5,top-160,WHITE);
	draw_line(left+140+5,top-160,left+100+5,top-80,WHITE);
	draw_line(left+100+5,top-80,left+60,top-80,WHITE);

	// I
	draw_line(left+340,top-80,left+340,bot+220,WHITE);
	draw_line(left+340,bot+220,left+390,bot+220,WHITE);
	draw_line(left+390,bot+220,left+390,top-80,WHITE);
	draw_line(left+390,top-80,left+340,top-80,WHITE);

	// N
	draw_line(left+420,top-80,left+420,bot+220,WHITE);
	draw_line(left+420,bot+220,left+470,bot+220,WHITE);
	draw_line(left+470,bot+220,left+470,top-170,WHITE);
	draw_line(left+470,top-170,left+530,bot+220,WHITE);
	draw_line(left+530,bot+220,left+580,bot+220,WHITE);
	draw_line(left+580,bot+220,left+580,top-80,WHITE);
	draw_line(left+580,top-80,left+530,top-80,WHITE);
	draw_line(left+530,top-80,left+530,bot+310,WHITE);
	draw_line(left+530,bot+310,left+470,top-80,WHITE);
	draw_line(left+470,top-80,left+420,top-80,WHITE);


	// Other
	draw_line(left+60, top-40, right-60, top-40, WHITE);
	draw_line(right-60, top-40, right-60, top-60, WHITE);
	draw_line(right-60, top-60,left+60, top-60, WHITE);
	draw_line(left+60, top-60, left+60, top-40, WHITE);
	

	draw_line(left+60, bot+180, right-60, bot+180, WHITE);
	draw_line(right-60, bot+180, right-60, bot+200, WHITE);
	draw_line(right-60, bot+200, left+60, bot+200,  WHITE);
	draw_line(left+60, bot+200, left+60, bot+180, WHITE);

	settextstyle(7,0,40);
	setcolor(WHITE);
	sprintf(strbuffer,"%d",score);
	outtextxy(getmaxx()/2-50, getmaxy()/2+100, strbuffer);


}
void showResultLose(int score){
	int left = -320;
	int right = 320;
	int top = 240;
	int bot = -240;

	// L
	draw_line(left+60,top-80,left+60,bot+220,WHITE);
	draw_line(left+60,bot+220,left+180,bot+220,WHITE);
	draw_line(left+180,bot+220,left+180,bot+270,WHITE);
	draw_line(left+180,bot+270,left+110,bot+270,WHITE);
	draw_line(left+110,bot+270,left+110,top-80,WHITE);
	draw_line(left+110,top-80,left+60,top-80,WHITE);
	// O
	draw_line(left+190,top-80,left+190,bot+220,WHITE);
	draw_line(left+190,bot+220,left+310,bot+220,WHITE);
	draw_line(left+310,bot+220,left+310,top-80,WHITE);
	draw_line(left+310,top-80,left+190,top-80,WHITE);

	draw_line(left+230,top-120,left+230,bot+260,WHITE);
	draw_line(left+230,bot+260,left+270,bot+260,WHITE);
	draw_line(left+270,bot+260,left+270,top-120,WHITE);
	draw_line(left+270,top-120,left+230,top-120,WHITE);
	// S
	draw_line(left+320,top-80,left+320,top-190,WHITE);
	draw_line(left+320,top-190,left+410,top-190,WHITE);
	draw_line(left+410,top-190,left+410,top-220,WHITE);
	draw_line(left+410,top-220,left+320,top-220,WHITE);
	draw_line(left+320,top-220,left+320,top-260,WHITE);
	draw_line(left+320,top-260,left+450,top-260,WHITE);
	draw_line(left+450,top-260,left+450,top-150,WHITE);
	draw_line(left+450,top-150,left+360,top-150,WHITE);
	draw_line(left+360,top-150,left+360,top-120,WHITE);
	draw_line(left+360,top-120,left+450,top-120,WHITE);
	draw_line(left+450,top-120,left+450,top-80,WHITE);
	draw_line(left+450,top-80,left+320,top-80,WHITE);

	// E
	draw_line(left+460,top-80,left+460,bot+220,WHITE);
	draw_line(left+460,bot+220,left+580,bot+220,WHITE);
	draw_line(left+580,bot+220,left+580,bot+260,WHITE);
	draw_line(left+580,bot+260,left+510,bot+260,WHITE);
	draw_line(left+510,bot+260,left+510,bot+290,WHITE);
	draw_line(left+510,bot+290,left+580,bot+290,WHITE);

	draw_line(left+580,bot+220+70,left+580,bot+260+70,WHITE);
	draw_line(left+580,bot+260+70,left+510,bot+260+70,WHITE);
	draw_line(left+510,bot+260+70,left+510,bot+290+70,WHITE);
	draw_line(left+510,bot+290+70,left+580,bot+290+70,WHITE);

	draw_line(left+580,bot+220+140,left+580,bot+260+140,WHITE);
	draw_line(left+580,bot+260+140,left+460,top-80,WHITE);

	// Other
	draw_line(left+60, top-40, right-60, top-40, WHITE);
	draw_line(right-60, top-40, right-60, top-60, WHITE);
	draw_line(right-60, top-60,left+60, top-60, WHITE);
	draw_line(left+60, top-60, left+60, top-40, WHITE);
	

	draw_line(left+60, bot+180, right-60, bot+180, WHITE);
	draw_line(right-60, bot+180, right-60, bot+200, WHITE);
	draw_line(right-60, bot+200, left+60, bot+200,  WHITE);
	draw_line(left+60, bot+200, left+60, bot+180, WHITE);

	settextstyle(7,0,40);
	setcolor(WHITE);
	sprintf(strbuffer,"%d",score);
	outtextxy(getmaxx()/2-50, getmaxy()/2+100, strbuffer);
}
