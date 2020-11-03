#pragma once
#include "Entity.h"

class Enemy : public Entity{
public:
	Enemy();
	int get_hp();
	void set_hp(int a);
	int get_ai();
	void set_ai(int a);
	void update();
	void die();
private:
	int ai;
	int hp;
	int y_v;
	int x_v;
	bool alive;
};
