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

void KotakKayu::reset(){
	q = orig;
}

void KotakKayu::draw(){
	q.draw(WHITE);
	fill_polygon(q.corner[0].x, q.corner[0].y, q.corner[2].x, q.corner[2].y,BROWN,WHITE);
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

Tree::Tree() : orig(-70, -80, -50, -30){
	Point p(-60,-30);
	Circle cc(p,0.2,0.2);
	origc = cc;
	reset();
	
	float absx = abs(orig.center.x);
	
	left = createTranslation(-absx, 0);
	right = createTranslation(absx, 0);
}

void Tree::applyTransform(Transform& trans){
	q.applyTransform(trans);
	c.applyTransform(trans);
}

void Tree::reset(){
	q = orig;
	c = origc;
}

void Tree::draw(){
	q.draw(WHITE);
	c.draw(WHITE);
	fill_polygon(q.corner[0].x, q.corner[0].y, q.corner[2].x, q.corner[2].y,BROWN,WHITE);
}

void Tree::setLane(int lane){
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
	obs[1] = new Tree();
	obs[2] = new Tree();//harusnya batu besar
	
	for (int i = 0; i < 3; i++){	
		obs[i]->applyTransform(reset);
		obs[i]->frame = i * -30;
	}
}

ObstacleManager::~ObstacleManager(){
	for (int i = 0; i < 3; i++)
		delete obs[i];
}

void ObstacleManager::draw(){
	for (int i = 0; i < 3; i++)
		if (obs[i]->frame >= 0)
			obs[i]->draw();
}

void ObstacleManager::update(){
	for (int i = 0; i < 3; i++){
		if (obs[i]->frame >= 75){
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