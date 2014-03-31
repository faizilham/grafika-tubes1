#ifndef OBSTACLE_MANAGER_HPP
#define OBSTACLE_MANAGER_HPP

#include "shapes.hpp"
#include "obstacle.hpp"
#include "car.hpp"

class KotakKayu : public Obstacle{
	private:
		Quad q, orig;
		Transform left, right;
	public:
		KotakKayu();
		virtual void applyTransform(Transform& trans);
		virtual void setLane(int lane); //0 left, 1 middle, 2 right
		virtual Point getFrontPoint();
		virtual void reset();
		virtual void draw();
};

class Rock : public Obstacle{
	private:
		Quad q,orig;
		Transform left, right;
		Circle c,origc;
	public:
		Rock();
		virtual void applyTransform(Transform& trans);
		virtual void setLane(int lane); //0 left, 1 middle, 2 right
		virtual Point getFrontPoint();
		virtual void reset();
		virtual void draw();
};

class Wheel : public Obstacle{
	private:
		Quad orig,q;
		Transform left, right;
		Circle c,origc;
	public:
		Wheel();
		virtual void applyTransform(Transform& trans);
		virtual void setLane(int lane); //0 left, 1 middle, 2 right
		virtual Point getFrontPoint();
		virtual void reset();
		virtual void draw();
};

class ObstacleManager{
	private:
		Car *car;
		Obstacle *obs[3];
		Transform move, reset;

	public:
		ObstacleManager();
		~ObstacleManager();
		
		void setCar(Car *car);
		void draw();
		bool isCollided();
		void update();
};

#endif