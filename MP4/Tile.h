// Tile.h

#pragma once
using namespace std;
#include "Structures.h"
#include "Functions.h"
#include <iostream>
#include <string>

class Color;

class Tile{
public:
	Tile();
	Tile(char c_, Color f_color_, Color b_color_);
	void set_char(char c_);
	void set_fg(Color color_);
	void set_bg(Color color_);
	Color get_fg();
	Color get_bg();
	void set_solid(bool b);
	bool get_solid();
	void set_type(string type);
	string get_type();
	void render();
	string r_render();
private:
	char c;
	Color f_color;
	Color b_color;
	bool solid;
	string type;
};