#include "result.hpp"

Result::Result(){
	firsttime = true;
	resultframe = 0;
}

void Result::showResultWin(int score){

	int left = -320;
	int right = 320;
	int top = 240;
	int bot = -240;
	char strbuffer[64];
	// W
	Point pow1(left+60,top-80);
	Point pow2(left+140+5,bot+220);
	Point pow3(left+180+5,bot+300);
	Point pow4(left+220+5,bot+220);
	Point pow5(left+300+10,top-80);
	Point pow6(left+260+5,top-80);
	Point pow7(left+220+5,top-160);
	Point pow8(left+180+5,top-80);
	Point pow9(left+140+5,top-160);
	Point pow10(left+100+5,top-80);
	Point powc((pow1.x+pow5.x)/2,(pow1.y+pow2.y)/2);
	vector<Point> pow;
	pow.push_back(pow1);
	pow.push_back(pow2);
	pow.push_back(pow3);
	pow.push_back(pow4);
	pow.push_back(pow5);
	pow.push_back(pow6);
	pow.push_back(pow7);
	pow.push_back(pow8);
	pow.push_back(pow9);
	pow.push_back(pow10);
	if (firsttime){
		pol_w.setCorner(pow);
		pol_w.setCenter(powc);
		Transform scale = createScale(0.1, 0.1);
		pol_w.applyTransform(scale);
	}

	// I
	Point poi1(left+340,top-80);
	Point poi2(left+340,bot+220);
	Point poi3(left+390,bot+220);
	Point poi4(left+390,top-80);
	Point poic((poi1.x+poi3.x)/2,(poi1.y+poi3.y)/2);
	vector<Point> poi;
	poi.push_back(poi1);
	poi.push_back(poi2);
	poi.push_back(poi3);
	poi.push_back(poi4);
	if (firsttime){
		pol_i.setCorner(poi);
		pol_i.setCenter(poic);
		Transform scale = createScale(0.1, 0.1);
		pol_i.applyTransform(scale);
	}

	// N
	Point pon1(left+420,top-80);
	Point pon2(left+420,bot+220);
	Point pon3(left+470,bot+220);
	Point pon4(left+470,top-170);
	Point pon5(left+530,bot+220);
	Point pon6(left+580,bot+220);
	Point pon7(left+580,top-80);
	Point pon8(left+530,top-80);
	Point pon9(left+530,bot+310);
	Point pon10(left+470,top-80);
	Point ponc((pon1.x+pon6.x)/2,(pon1.y+pon6.y)/2);
	vector<Point> pon;
	pon.push_back(pon1);
	pon.push_back(pon2);
	pon.push_back(pon3);
	pon.push_back(pon4);
	pon.push_back(pon5);
	pon.push_back(pon6);
	pon.push_back(pon7);
	pon.push_back(pon8);
	pon.push_back(pon9);
	pon.push_back(pon10);
	if (firsttime){
		pol_n.setCorner(pon);
		pol_n.setCenter(ponc);
		Transform scale = createScale(0.1, 0.1);
		pol_n.applyTransform(scale);
	}


	// Other
	Point pot1(left+60, top-40);
	Point pot2(right-60, top-40);
	Point pot3(right-60, top-60);
	Point pot4(left+60, top-60);
	Point potc((pot1.x+pot2.x)/2,(pot2.x+pot3.x)/2);
	vector<Point> pot;
	pot.push_back(pot1);
	pot.push_back(pot2);
	pot.push_back(pot3);
	pot.push_back(pot4);
	if (firsttime){
		pol_pot1.setCorner(pot);
		pol_pot1.setCenter(potc);
		Transform scale = createScale(0.1, 0.1);
		pol_pot1.applyTransform(scale);
	}
	

	pot1.set(left+60, bot+180);
	pot2.set(right-60, bot+180);
	pot3.set(right-60, bot+200);
	pot4.set(left+60, bot+200);
	potc.set((pot1.x+pot2.x)/2,(pot2.x+pot3.x)/2);
	pot.clear();
	pot.push_back(pot1);
	pot.push_back(pot2);
	pot.push_back(pot3);
	pot.push_back(pot4);
	if (firsttime){
		pol_pot2.setCorner(pot);
		pol_pot2.setCenter(potc);
		Transform scale = createScale(0.1, 0.1);
		pol_pot2.applyTransform(scale);
	}
	

	resultframe++;
	if (resultframe >= 25)
		resultframe = 25;
	else {
		Transform scale = createScale(1.1, 1.1);
		pol_pot1.applyTransform(scale);
		pol_pot2.applyTransform(scale);
		pol_w.applyTransform(scale);
		pol_i.applyTransform(scale);
		pol_n.applyTransform(scale);
	}
	pol_w.draw(WHITE);
	fill_polygon(pol_w[0].x, pol_w[3].y, pol_w[4].x, pol_w[0].y,WHITE,WHITE);
	pol_i.draw(WHITE);
	fill_polygon(pol_i[0].x, pol_i[2].y, pol_i[2].x, pol_i[0].y,WHITE,WHITE);
	pol_n.draw(WHITE);
	fill_polygon(pol_n[0].x, pol_n[5].y, pol_n[5].x, pol_n[0].y,WHITE,WHITE);
	pol_pot1.draw(WHITE);
	pol_pot2.draw(WHITE);

	settextstyle(7,0,40);
	setcolor(WHITE);
	sprintf(strbuffer,"%d",score);
	outtextxy(getmaxx()/2-50, getmaxy()/2+100, strbuffer);
	firsttime = false;
}


void Result::showResultLose(int score){
	int left = -320;
	int right = 320;
	int top = 240;
	int bot = -240;
	char strbuffer[64];
	// L
	Point pol1(left+60,top-80);
	Point pol2(left+60,bot+220);
	Point pol3(left+180,bot+220);
	Point pol4(left+180,bot+270);
	Point pol5(left+110,bot+270);
	Point pol6(left+110,top-80);
	Point polc((pol1.x+pol3.x)/2,(pol1.y+pol3.y)/2);
	vector<Point> pol;
	pol.push_back(pol1);
	pol.push_back(pol2);
	pol.push_back(pol3);
	pol.push_back(pol4);
	pol.push_back(pol5);
	pol.push_back(pol6);
	if (firsttime){
		pol_l.setCorner(pol);
		pol_l.setCenter(polc);
		Transform scale = createScale(0.1, 0.1);
		pol_l.applyTransform(scale);
	}

	// O
	Point poo1(left+190,top-80);
	Point poo2(left+190,bot+220);
	Point poo3(left+310,bot+220);
	Point poo4(left+310,top-80);
	Point poo5(left+230,top-120);
	Point poo6(left+230,bot+260);
	Point poo7(left+270,bot+260);
	Point poo8(left+270,top-120);
	Point pooc((poo1.x+poo3.x)/2,(poo1.y+poo3.y)/2);
	vector<Point> poo, poov;
	poo.push_back(poo1);
	poo.push_back(poo2);
	poo.push_back(poo3);
	poo.push_back(poo4);
	poov.push_back(poo5);
	poov.push_back(poo6);
	poov.push_back(poo7);
	poov.push_back(poo8);
	if (firsttime){
		pol_o.setCorner(poo);
		pol_o.setCenter(pooc);
		pol_o1.setCorner(poov);
		pol_o1.setCenter(pooc);
		Transform scale = createScale(0.1, 0.1);
		pol_o.applyTransform(scale);
		pol_o1.applyTransform(scale);
	}
	// S
	Point pos1(left+320,top-80);
	Point pos2(left+320,top-190);
	Point pos3(left+410,top-190);
	Point pos4(left+410,top-220);
	Point pos5(left+320,top-220);
	Point pos6(left+320,top-260);
	Point pos7(left+450,top-260);
	Point pos8(left+450,top-150);
	Point pos9(left+360,top-150);
	Point pos10(left+360,top-120);
	Point pos11(left+450,top-120);
	Point pos12(left+450,top-80);
	Point posc((pos1.x+pos7.x)/2,(pos1.y+pos7.y)/2);
	vector<Point> pos;
	pos.push_back(pos1);
	pos.push_back(pos2);
	pos.push_back(pos3);
	pos.push_back(pos4);
	pos.push_back(pos5);
	pos.push_back(pos6);
	pos.push_back(pos7);
	pos.push_back(pos8);
	pos.push_back(pos9);
	pos.push_back(pos10);
	pos.push_back(pos11);
	pos.push_back(pos12);
	if (firsttime){
		pol_s.setCorner(pos);
		pol_s.setCenter(posc);
		Transform scale = createScale(0.1, 0.1);
		pol_s.applyTransform(scale);
	}
	

	// E
	Point poe1(left+460,top-80);
	Point poe2(left+460,bot+220);
	Point poe3(left+580,bot+220);
	Point poe4(left+580,bot+260);
	Point poe5(left+510,bot+260);
	Point poe6(left+510,bot+290);

	Point poe7(left+580,bot+220+70);
	Point poe8(left+580,bot+260+70);
	Point poe9(left+510,bot+260+70);
	Point poe10(left+510,bot+290+70);

	Point poe11(left+580,bot+220+140);
	Point poe12(left+580,bot+260+140);
	Point poec((poe1.x+poe3.x)/2,(poe1.y+poe3.y)/2);
	vector<Point> poe;
	poe.push_back(poe1);
	poe.push_back(poe2);
	poe.push_back(poe3);
	poe.push_back(poe4);
	poe.push_back(poe5);
	poe.push_back(poe6);
	poe.push_back(poe7);
	poe.push_back(poe8);
	poe.push_back(poe9);
	poe.push_back(poe10);
	poe.push_back(poe11);
	poe.push_back(poe12);
	if (firsttime){
		pol_e.setCorner(poe);
		pol_e.setCenter(poec);
		Transform scale = createScale(0.1, 0.1);
		pol_e.applyTransform(scale);
	}

	

	// Other
	Point pot1(left+60, top-40);
	Point pot2(right-60, top-40);
	Point pot3(right-60, top-60);
	Point pot4(left+60, top-60);
	Point potc((pot1.x+pot2.x)/2,(pot2.x+pot3.x)/2);
	vector<Point> pot;
	pot.push_back(pot1);
	pot.push_back(pot2);
	pot.push_back(pot3);
	pot.push_back(pot4);
	if (firsttime){
		pol_pot1.setCorner(pot);
		pol_pot1.setCenter(potc);
		Transform scale = createScale(0.1, 0.1);
		pol_pot1.applyTransform(scale);
	}
	

	pot1.set(left+60, bot+180);
	pot2.set(right-60, bot+180);
	pot3.set(right-60, bot+200);
	pot4.set(left+60, bot+200);
	potc.set((pot1.x+pot2.x)/2,(pot2.x+pot3.x)/2);
	pot.clear();
	pot.push_back(pot1);
	pot.push_back(pot2);
	pot.push_back(pot3);
	pot.push_back(pot4);
	if (firsttime){
		pol_pot2.setCorner(pot);
		pol_pot2.setCenter(potc);
		Transform scale = createScale(0.1, 0.1);
		pol_pot2.applyTransform(scale);
	}
	

	resultframe++;
	if (resultframe >= 25)
		resultframe = 25;
	else {
		Transform scale = createScale(1.1, 1.1);
		pol_pot1.applyTransform(scale);
		pol_pot2.applyTransform(scale);
		pol_l.applyTransform(scale);
		pol_o.applyTransform(scale);
		pol_o1.applyTransform(scale);
		pol_s.applyTransform(scale);
		pol_e.applyTransform(scale);
	}
	pol_l.draw(WHITE);
	fill_polygon(pol_l[0].x, pol_l[2].y, pol_l[2].x, pol_l[0].y,WHITE,WHITE);
	pol_o.draw(WHITE);
	fill_polygon(pol_o[0].x, pol_o[2].y, pol_o[2].x, pol_o[0].y,WHITE,WHITE);
	pol_o1.draw(BLACK);
	fill_polygon(pol_o1[0].x, pol_o1[2].y, pol_o1[2].x, pol_o1[0].y,BLACK,BLACK);	
	pol_s.draw(WHITE);
	fill_polygon(pol_s[0].x, pol_s[6].y, pol_s[6].x, pol_s[0].y,WHITE,WHITE);
	pol_e.draw(WHITE);
	fill_polygon(pol_e[0].x, pol_e[2].y, pol_e[2].x, pol_e[0].y,WHITE,WHITE);
	pol_pot1.draw(WHITE);
	pol_pot2.draw(WHITE);

	settextstyle(7,0,40);
	setcolor(WHITE);
	sprintf(strbuffer,"%d",score);
	outtextxy(getmaxx()/2-50, getmaxy()/2+100, strbuffer);
	firsttime = false;
}
