#pragma once
#include "Map.h"
#include "Tile.h"
#include "Tiles.h"
#include "Enemy.h"

class DemoMap : public Map{
public:
	DemoMap();
private:
	Grass g;
	Dirt  d;
	StoneBrick s;
	Chest c;
	Enemy e;
};