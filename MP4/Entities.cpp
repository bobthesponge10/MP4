// Entities.cpp

#include "Entities.h"

// Creates the enemy locked gate
EnemyGate::EnemyGate(){

	// Sets initial values
	open = true;
	x = -1; y = -1;
	set_x(-1);
	set_y(-1);
	set_char('#');
	set_type("enemy_gate");
	set_fg(Color(0,0,0));
	close_down = false;
	close_up = false;
	close_left = false;
	close_right = false;
}
void EnemyGate::set_coords(int x_, int y_){
	x = x_;
	y = y_;
}
void EnemyGate::set_gate(bool b){
	open = b;
}
void EnemyGate::add_open_enemy(Enemy* p){
	open_condition.push_back(p);
}
void EnemyGate::set_close_up(bool b){
	close_up = b;
}
void EnemyGate::set_close_down(bool b){
	close_down = b;
}
void EnemyGate::set_close_left(bool b){
	close_left = b;
}
void EnemyGate::set_close_right(bool b){
	close_right = b;
}
int EnemyGate::get_size(){
	return open_condition.size();
}
void EnemyGate::update(){
	Map* m = get_map();
	int u, d, l,r;
	bool temp;

	// Checks if the gate should close on the player
	u = m->find_entity(x, y - 1);
	d = m->find_entity(x, y + 1);
	l = m->find_entity(x - 1, y);
	r = m->find_entity(x + 1, y);
	if(close_up && u != -1 && m->get_entity(u)->get_type() == "player"){
		open = false;
	}
	else if(close_down && d != -1 && m->get_entity(d)->get_type() == "player"){
		open = false;
	}
	else if(close_left && l != -1 && m->get_entity(l)->get_type() == "player"){
		open = false;
	}
	else if(close_right && r != -1 && m->get_entity(r)->get_type() == "player"){
		open = false;
	}

	// Checks if the gate should open
	temp = open_condition.size() > 0;
	for(int i = 0; i < open_condition.size(); i++){
		if(open_condition[i]->is_alive()){
			temp = false;
		}
	}
	if(temp){ open = true; }

	// Sets the gate to open or close
	if(open){
		set_x(-1);
		set_y(-1);
	}else{
		set_x(x);
		set_y(y);
	}

}

KeyGate::KeyGate(){

	// Sets initial values
	open = true;
	opened = false;
	x = -1; y = -1;
	set_x(-1);
	set_y(-1);
	set_char('#');
	set_type("key_gate");
	set_fg(Color(0, 0, 0));
	close_down = false;
	close_up = false;
	close_left = false;
	close_right = false;
}
void KeyGate::set_coords(int x_, int y_){
	x = x_;
	y = y_;
}
void KeyGate::set_gate(bool b){
	open = b;
}
void KeyGate::open_gate(){
	opened = true;
}
void KeyGate::set_open_key(Item i){
	key = i;
}
void KeyGate::set_use_item(bool b){
	use_item = b;
}
bool KeyGate::get_use_item(){
	return use_item;
}
Item KeyGate::get_key(){
	return key;
}
void KeyGate::set_close_up(bool b){
	close_up = b;
}
void KeyGate::set_close_down(bool b){
	close_down = b;
}
void KeyGate::set_close_left(bool b){
	close_left = b;
}
void KeyGate::set_close_right(bool b){
	close_right = b;
}
void KeyGate::update(){
	Map* m = get_map();
	int u, d, l, r;
	bool temp;

	// Checks if the gate should close on the player
	u = m->find_entity(x, y - 1);
	d = m->find_entity(x, y + 1);
	l = m->find_entity(x - 1, y);
	r = m->find_entity(x + 1, y);
	if(close_up && u != -1 && m->get_entity(u)->get_type() == "player"){
		open = false;
	} else if(close_down && d != -1 && m->get_entity(d)->get_type() == "player"){
		open = false;
	} else if(close_left && l != -1 && m->get_entity(l)->get_type() == "player"){
		open = false;
	} else if(close_right && r != -1 && m->get_entity(r)->get_type() == "player"){
		open = false;
	}

	// Checks if the gate should be open
	if(opened){ open = true; }


	// Sets the gate to open or close
	if(open){
		set_x(-1);
		set_y(-1);
	} else{
		set_x(x);
		set_y(y);
	}

}

// Creates sign
Sign::Sign(){

	// Sets initial values
	set_char('8');
	set_fg(Color(107, 90, 46));
	set_type("sign");
}
void Sign::set_text(string t){
	text = t;
}
string Sign::get_text(){
	return text;
}