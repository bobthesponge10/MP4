#pragma once
using namespace std;
#include <sstream>
#include <algorithm>
#include <string>
#include "Entity.h"
#include "Structures.h"
#include "Tiles.h"

class Player : public Entity, public Inventory{
public:
	Player();
	void update();
	void view_tile(int x, int y);
	void get_item_from_tile(int x, int y, int index);
	void put_item_to_tile(int x, int y, int index);
	void parse_input(string input);
	void render_window(int w, int h);
private:
};