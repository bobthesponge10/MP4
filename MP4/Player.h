#pragma once
using namespace std;
#include <sstream>
#include <algorithm>
#include <string>
#include "Entity.h"
#include "Structures.h"
#include "Tiles.h"
#include "Enemy.h"

class Player : public Entity, public Inventory{
public:
	Player();
	void update();
	void view_tile(int x, int y);
	void get_item_from_tile(int x, int y, int index);
	void put_item_to_tile(int x, int y, int index);
	void fight(int x, int y);
	void parse_input(string input);
	void render_window(int w, int h, bool clear);
	void unequip_armor();
	void unequip_weapon();
	void equip_armor(int index);
	void equip_weapon(int index);
private:
	Item armor;
	Item weapon;
};