// Map.h

#pragma once
using namespace std;
#include "Tile.h"
#include "Entity.h"
#include <vector>

class Entity;

class Tile;

class Map{
public:
	Map();
	Map(int w_, int h_);
	Tile* get_tile_p(int x, int y);
	void set_tile(int x, int y, Tile* t);
	void add_entity(Entity* e);
	int find_entity(int x, int y);
	Entity* get_entity(int i);
	int get_w();
	int get_h();
	bool check_solid(int x, int y);
	void update();
	void add_flag(string flag);
	string get_flag();
	vector<string> get_flags();
	void render();
	string render(int x, int y, int w_, int h_, bool out);
	void set_player(Entity* p);
	void set_default_coords(int x, int y);
	void move_player();
private:
	int w, h;
	int d_x, d_y;
	vector<Tile*> tiles;
	vector<Entity*> entities;
	Entity* player;
	Tile empty = Tile();
	vector<string> flags;
};
