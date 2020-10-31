#pragma once
using namespace std;
#include "Tile.h"
#include "Entity.h"
#include <vector>

class Entity;

class Map{
public:
	Map();
	Map(int w_, int h_);
	Tile* get_tile_p(int x, int y);
	void set_tile(int x, int y, Tile* t);
	void add_entity(Entity* e);
	int get_entity(int x, int y);
	int get_w();
	int get_h();
	bool check_solid(int x, int y);
	void update();
	void render();
	void render(int x, int y, int w_, int h_);
private:
	int w;
	int h;
	vector<Tile*> tiles;
	vector<Entity*> entities;
	Tile empty = Tile();
};
