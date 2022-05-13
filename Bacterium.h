#ifndef BACTERIUM
#define BACTERIUM
#include <cmath>
#include <cstdlib>
#include<cstdio>
#include "Objects.h"



class Bacterium : public Object
{
private:
	float size; // радиус бактерии
	float velocity; // скорость бактерии
	float orientation; // ориентация бактерии
	int food; // число съеденных питательных частиц
	float x_last = 0; // координата x
	float y_last = 0; // координата y

public:
	friend class Growth_medium;
	Bacterium(float x = 1 , float y = 5, float orientation = 0.25, int food = 0, float size = 1, float velocity = 2, int status = 1)
		: Object(x, y) {
		this->x = x;
		this->y = y;
		//this->status = status;
		this->orientation = orientation;
		this->food = food;
		this->size = size;
		this->velocity = velocity;
	}
	inline float get_x() const {
		return x;
	}
	float get_y() const {
		return y;
	}
	float get_x_last() const {
		return x_last;
	}
	float get_y_last() const {
		return y_last;
	}
	float get_q() const {
		return orientation;
	}
	virtual int get_status() const {
		return 1;
	}
	int get_n() const {
		return food;
	}
	float get_s() {
		return (size);
	}
	float get_v() const {
		return velocity;
	}

	bool one_active_step(); 
	bool brownian_motion();
	void print() const;
	void bacterium_creating(float a, float b);
	//virtual ~Bacterium();
};
#endif
