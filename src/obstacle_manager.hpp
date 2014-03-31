#ifndef OBSTACLE_MANAGER_HPP
#define OBSTACLE_MANAGER_HPP

#include "shapes.hpp"
#include "obstacle.hpp"

class KotakKayu : public Obstacle{
	private:
		Quad q, orig;
		Transform left, right;
	public:
		KotakKayu();
		virtual void applyTransform(Transform& trans);
		virtual void setLane(int lane); //0 left, 1 middle, 2 right
		virtual void reset();
		virtual void draw();
};

class Tree : public Obstacle{
	private:
		Quad q,orig;
		Transform left, right;
		//Circle cir;
	public:
		Tree();
		virtual void applyTransform(Transform& trans);
		virtual void setLane(int lane); //0 left, 1 middle, 2 right
		virtual void reset();
		virtual void draw();
};

class ObstacleManager{
	private:
		Obstacle *obs[3];
		Transform move, reset;

	public:
		ObstacleManager();
		~ObstacleManager();
		
		void draw();
		void update();
};

#endif