#include "obstacle_manager.hpp"

TestObstacle::TestObstacle() : orig(-70, -80, -50, -30){
	reset();
	
	float absx = abs(orig.center.x);
	
	left = createTranslation(-absx, 0);
	right = createTranslation(absx, 0);
}

void TestObstacle::applyTransform(Transform& trans){
	q.applyTransform(trans);
}

void TestObstacle::reset(){
	q = orig;
}

void TestObstacle::draw(){
	q.draw(WHITE);
}

void TestObstacle::setLane(int lane){
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

ObstacleManager::ObstacleManager(){
	srand(time(NULL));
	
	
	move = createScale(1.1, 1.1);
	reset = createScale(0.01, 0.01);
	
	for (int i = 0; i < 3; i++){
		obs[i] = new TestObstacle();
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