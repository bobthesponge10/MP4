#include "Enemy.h"


Enemy::Enemy(){
	damage = 0;
	hp = -1;
	max_hp = -1;
	ai = 0;
	x_v = 0;
	y_v = 0;
	alive = true;
	escape_chance = 100;
	current_frame = 0;
	set_type("enemy");
}
int Enemy::get_hp(){
	return hp;
}
void Enemy::set_hp(int a){
	if(a < 0){
		a = 0;
	}
	hp = a;
}
void Enemy::set_damage(int i){
	damage = i;
}
int Enemy::get_damage(){
	return damage;
}
int Enemy::get_max_hp(){
	return max_hp;
}
void Enemy::set_max_hp(int a){
	max_hp = a;
}
void Enemy::set_escape_chance(int a){
	escape_chance = a;
}
int Enemy::get_escape_chance(){
	return escape_chance;
}
int Enemy::get_ai(){
	return ai;
}
void Enemy::set_ai(int a){
	ai = a;
}
void Enemy::set_current_frame(int f){
	current_frame = f;
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
void Enemy::view(){
	if(cut.get_height()>0){
		cut.displayFrame(current_frame);
	}
	reset_colors();
}
void Enemy::battle_turn(Player* p){
	int d = damage - damage * (p->get_protection()/100.0);

	print_text(get_name() + " did " + to_string(d) + " damage\n\n");
	p->set_hp(p->get_hp()-d);
	wait_for_input();
}

void Enemy::set_cutscene(string file, int w, int s){
	cut = Cutscene(file, 1, w, s);
}
int Enemy::get_width(){
	return cut.get_width();
}
bool Enemy::is_alive(){
	return alive;
}
bool Enemy::use_item(Item i){
	return false;
}