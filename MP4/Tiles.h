// Tiles.h

#pragma once
#include "Tile.h"
#include "Structures.h"

class Grass : public Tile{
public:
	Grass();
};

class Dirt : public Tile{
public:
	Dirt();
};

class StoneBrick : public Tile{
public:
	StoneBrick();
};

class Stone : public Tile{
public:
	Stone();
};

class Chest : public Tile, public Inventory{
public:
	Chest();
};

class HealStation : public Tile{
public:
	HealStation();
};

class Portal : public Tile{
public:
	Portal();
	void set_index(int i);
	int get_index();
private:
	int index;
};