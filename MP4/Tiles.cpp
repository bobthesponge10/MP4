// Tiles.cpp

#include "Tiles.h"

Grass::Grass(){
	set_char('*');
	set_bg(Color(0, 200, 0));
	set_fg(Color(191, 147, 13));
	set_solid(false);
}

Dirt::Dirt(){
	set_char('*');
	set_fg(Color(138, 75, 28));				// Function call with struct
	set_bg(Color(219, 148, 94));
	set_solid(false);
}

StoneBrick::StoneBrick(){
	set_char(206);							// ASCII character
	set_fg(Color(50, 50, 50));
	set_bg(Color(150, 150, 150));
	set_solid(true);
}

Stone::Stone(){
	set_char(' ');
	set_fg(Color(150, 150, 150));
	set_bg(Color(183, 190, 235));
	set_solid(false);
}

Chest::Chest(){
	set_char(240);
	set_fg(Color(0, 0, 0));
	set_bg(Color(171, 126, 3));
	set_solid(true);
	set_type("chest");
	set_inv_name("Chest");
}

HealStation::HealStation(){
	set_char('+');
	set_bg(Color(122, 201, 60));
	set_fg(Color(255, 0, 0));
	set_solid(true);
	set_type("heal_station");
}

Portal::Portal(){
	set_char('0');
	set_fg(Color(255, 0, 255));
	set_bg(Color(89, 47, 89));
	set_solid(true);
	set_type("portal");
}
int Portal::get_index(){
	return index;
}
void Portal::set_index(int i){
	index = i;
}