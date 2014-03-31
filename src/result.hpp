#ifndef RESULT_HPP
#define RESULT_HPP

#include "shapes.hpp"

class Result{
	public:
		int resultframe;
		bool firsttime;
		Polygon pol_pot1,pol_pot2;
		Polygon pol_w,pol_i,pol_n;
		Polygon pol_l,pol_o,pol_o1,pol_s,pol_e;
		Result();
		void showResultWin(int score);
		void showResultLose(int score);
};
#endif