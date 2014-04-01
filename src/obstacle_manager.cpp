#include "obstacle_manager.hpp"


KotakKayu::KotakKayu() : orig(-70, -80, -50, -60){
	reset();
	float absx = abs(orig.center.x);
	
	left = createTranslation(-absx, 0);
	right = createTranslation(absx, 0);
}

void KotakKayu::applyTransform(Transform& trans){
	q.applyTransform(trans);
}

Point KotakKayu::getFrontPoint(){
	p = q.corner[0];
	return p;
}

void KotakKayu::reset(){
	q = orig;
}

void KotakKayu::draw(){
	q.draw(BROWN);
	fill_polygon(q.corner[0].x, q.corner[0].y, q.corner[2].x, q.corner[2].y,BROWN,BROWN);
}

void KotakKayu::setLane(int lane){
	Transform change;
	int diff = lane - this->lane;
	this->lane = lane;
	
	for (int i = 0; i < diff; i++)
		change = right * change;
		
	for (int i = 0; i < -diff; i++)
		change = left * change;
	
	q.applyTransform(change);
	orig.applyTransform(change);
}

Rock::Rock() : orig(-70, -80, -50, -30){
	Point p(-60,-30);
	Circle cc(p,0.2,0.2);
	origc = cc;

	reset();
	
	float absx = abs(orig.center.x);
	
	left = createTranslation(-absx, 0);
	right = createTranslation(absx, 0);
}

void Rock::applyTransform(Transform& trans){
	q.applyTransform(trans);
	c.applyTransform(trans);
}

Point Rock::getFrontPoint(){
	p = q.corner[0];
	return p;
}

void Rock::reset(){
	q = orig;
	c = origc;
}

void Rock::draw(){
	q.draw(BROWN);
	c.draw(GREEN);
	fill_polygon(q.corner[0].x, q.corner[0].y, q.corner[2].x, q.corner[2].y,BROWN,BROWN);
	fill_polygon(c.center.x - c.radx, c.center.y - c.rady, c.center.x + c.radx, c.center.y + c.rady,GREEN,GREEN);
}

void Rock::setLane(int lane){
	Transform change;
	int diff = lane - this->lane;
	this->lane = lane;
	
	for (int i = 0; i < diff; i++)
		change = right * change;
		
	for (int i = 0; i < -diff; i++)
		change = left * change;
	
	q.applyTransform(change);
	orig.applyTransform(change);
	c.applyTransform(change);
	origc.applyTransform(change);
}

Wheel::Wheel() : orig(-70, -80, -50, -30){
	Point p(-30,-30);
	Circle cc(p,0.05,0.05);
	origc = cc;

	reset();
	
	float absx = abs(p.x);
	
	left = createTranslation(-absx, 0);
	right = createTranslation(absx, 0);
}

void Wheel::applyTransform(Transform& trans){
	q.applyTransform(trans);
	c.applyTransform(trans);
}

Point Wheel::getFrontPoint(){
	p = Point(c.center.x - c.radx, c.center.y - c.rady);
	return p;
}

void Wheel::reset(){
	q = orig;
	c = origc;
}

void Wheel::draw(){
	//q.draw(WHITE);
	c.draw(RED);
	fill_polygon(c.center.x - c.radx, c.center.y - c.rady, c.center.x + c.radx, c.center.y + c.rady,7,RED);
}

void Wheel::setLane(int lane){
	Transform change;
	int diff = lane - this->lane;
	this->lane = lane;
	
	for (int i = 0; i < diff; i++)
		change = right * change;
		
	for (int i = 0; i < -diff; i++)
		change = left * change;
	
	q.applyTransform(change);
	orig.applyTransform(change);
	c.applyTransform(change);
	origc.applyTransform(change);
}

ObstacleManager::ObstacleManager(){
	srand(time(NULL));
	
	
	move = createScale(1.1, 1.1);
	reset = createScale(0.01, 0.01);
	
	
	obs[0] = new KotakKayu();
	obs[1] = new Rock();
	obs[2] = new Wheel();//harusnya batu besar
	
	for (int i = 0; i < 3; i++){	
		obs[i]->applyTransform(reset);
		obs[i]->frame = i * -30;
	}
}

ObstacleManager::~ObstacleManager(){
	for (int i = 0; i < 3; i++)
		delete obs[i];
}

void ObstacleManager::setCar(Car *_car){
	car = _car;
}

void ObstacleManager::draw(){
	for (int i = 0; i < 3; i++)
		if (obs[i]->frame >= 0)
			obs[i]->draw();
}

//Cek apakah mobil dan salah satu obstacle tabrakanzzz
bool ObstacleManager::isCollided(){
	//printf("Car lane: %d\n", car->getLane());
	
	for(int i=0;i<3;i++){
		//printf("Obstacle[%d] lane: %d\n", i, obs[i]->lane);
		//printf("obs[%d]: %d < %d\n", i, (int)(obs[i]->getFrontPoint()).y, (int)(car->getFrontPoint()).y);
		
		if(
		   (obs[i]->getFrontPoint()).y < (car->getFrontPoint()).y 
		&& (obs[i]->getFrontPoint()).y > (car->getBackPoint()).y
		&& obs[i]->lane == car->getLane()){
			return true;
		}
	}
	return false;
}

void ObstacleManager::update(){
	for (int i = 0; i < 3; i++){
		if (obs[i]->frame >= 68){
			obs[i]->frame = 0;	obs[i]->reset();
			obs[i]->setLane(rand() % 3);
			obs[i]->applyTransform(reset);
		}else{
			if (obs[i]->frame >= 0)
				obs[i]->applyTransform(move);
			obs[i]->frame++;
		}
	}
}