#include "Tiles.h"

Grass::Grass(){
	set_char('*');
	set_bg(Color(0, 200, 0));
	set_fg(Color(191, 147, 13));
	set_solid(false);
}

Dirt::Dirt(){
	set_char('*');
	set_fg(Color(138, 75, 28));
	set_bg(Color(219, 148, 94));
	set_solid(false);
}

StoneBrick::StoneBrick(){
	set_char(206);
	set_fg(Color(50, 50, 50));
	set_bg(Color(150, 150, 150));
	set_solid(true);
}

Chest::Chest(){
	set_char(240);
	set_fg(Color(0, 0, 0));
	set_bg(Color(255, 0, 0));
	set_solid(true);
	set_type("chest");
	set_inv_name("Chest");
}