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

class Chest : public Tile, public Inventory{
public:
	Chest();
};

class HealStation : public Tile{
public:
	HealStation();
};