// Entity.cpp

#include "Entity.h"


Entity::Entity(){

	// Initializes variables to default values
	x = 0;
	y = 0;
	c = ' ';
	b_c = false;
}
void Entity::render(Tile* tile){

	// Checks if entity's background gets rendered
	if(b_c){

		// Sets forground color to entity's color
		// Sets background to entity's background
		// Renders entity's character
		cout << fg(f_color) << bg(b_color) << c;
	}else{
	
		// Sets forground color to entity's color
		// Sets background to tile's background
		// Renders entity's character
		cout << fg(f_color) << bg(tile->get_bg()) << c;
	}
}
string Entity::r_render(Tile* tile){

	// Checks if entity's background gets rendered
	if(b_c){

		// Sets forground color to entity's color
		// Sets background to tile's background
		// Returns string of colored character
		return fg(f_color) + bg(b_color) + c;
	}else{
	
		// Sets forground color to entity's color
		// Sets background to entity's background
		// Returns string of colored character
		return fg(f_color) + bg(tile->get_bg()) + c;
	}
}
void Entity::set_char(char c_){
	c = c_;
}
void Entity::set_fg(Color color_){
	f_color = color_;
}
void Entity::set_bg(Color color_){
	b_color = color_;
}
char Entity::get_char(){
	return c;
}
Color Entity::get_fg(){
	return f_color;
}
Color Entity::get_bg(){
	return b_color;
}
void Entity::set_x(int x_){
	x = x_;
}
void Entity::set_y(int y_){
	y = y_;
}
void Entity::set_coords(int x_, int y_){
	x = x_;
	y = y_;
}
int Entity::get_x(){
	return x;
}
int Entity::get_y(){
	return y;
}
void Entity::set_map(Map* m){
	map = m;
}
Map* Entity::get_map(){
	return map;
}
void Entity::set_type(string t){
	type = t;
}
string Entity::get_type(){
	return type;
}
string Entity::get_name(){
	return name;
}
void Entity::set_name(string n){
	name = n;
}
void Entity::set_render_background(bool b){
	b_c = b;
}
bool Entity::move_up(){

	// Gets entity's x and y
	int x = get_x();
	int y = get_y();

	// Checks if space above is not solid
	if(!get_map()->check_solid(x, y - 1)){
		set_y(y - 1);
		return true;
	}
	return false;
}
bool Entity::move_down(){

	// Gets entity's x and y
	int x = get_x();
	int y = get_y();

	// Checks if space below is not solid
	if(!get_map()->check_solid(x, y + 1)){
		set_y(y + 1);
		return true;
	}
	return false;
}
bool Entity::move_left(){

	// Gets entity's x and y
	int x = get_x();
	int y = get_y();

	// Checks if space to the left is not solid
	if(!get_map()->check_solid(x - 1, y)){
		set_x(x - 1);
		return true;
	}
	return false;
}
bool Entity::move_right(){

	// Gets entity's x and y
	int x = get_x();
	int y = get_y();

	// Checks if space to the right is not solid
	if(!get_map()->check_solid(x + 1, y)){
		set_x(x + 1);
		return true;
	}
	return false;
}
void Entity::update(){}