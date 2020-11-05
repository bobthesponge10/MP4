#include "Enemy.h"


Enemy::Enemy(){
	hp = -1;
	ai = 0;
	x_v = 0;
	y_v = 0;
	alive = true;
	set_type("enemy");
}
int Enemy::get_hp(){
	return hp;
}
void Enemy::set_hp(int a){
	hp = a;
}
int Enemy::get_ai(){
	return ai;
}
void Enemy::set_ai(int a){
	ai = a;
}

void Enemy::update(){
	switch(ai){
	case 0:
		y_v = 0;
		x_v = 0;
		break;
	case 1:
		y_v = 0;

		if(x_v == -1){
			if(!move_left()){ x_v = 1; }
		}else{
			if(!move_right()){ x_v = -1; }
		}
		break;
	case 2:
		x_v = 0;

		if(y_v == -1){
			if(!move_up()){ y_v = 1; }
		} else{
			if(!move_down()){ y_v = -1; }
		}
		break;
	default:
		break;
	}
}

void Enemy::die(){
	set_x(-1);
	set_y(-1);
	alive = false;
}