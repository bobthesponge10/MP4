//Tile.cpp
//
#include "Tile.h"


Tile::Tile(){
	
	// Sets basic values for empty tile
	c = ' ';
}
Tile::Tile(char c_, Color f_color_, Color b_color_){

	// Sets character and color to specified values
	c = c_;
	f_color = f_color_;
	b_color = b_color_;
}
void Tile::set_char(char c_){
	c = c_;
}
void Tile::set_fg(Color color_){
	f_color = color_;
}
void Tile::set_bg(Color color_){
	b_color = color_;
}
Color Tile::get_fg(){
	return f_color;
}
Color Tile::get_bg(){
	return b_color;
}
void Tile::set_solid(bool b){
	solid = b;
}
bool Tile::get_solid(){
	return solid;
}
void Tile::set_type(string t){
	type = t;
}
string Tile::get_type(){
	return type;
}
void Tile::render(){

	// Sets colors and renders character to screen
	cout << fg(f_color) + bg(b_color) + c;
}
string Tile::r_render(){

	// Sets colors and returns rendered string
	return fg(f_color) + bg(b_color) + c;
}