// Maps.h

#pragma once
#include "Map.h"
#include "Tile.h"
#include "Tiles.h"
#include "Enemy.h"
#include "Enemies.h"
#include "Entities.h"

class DemoMap : public Map{
public:
	DemoMap();
private:
	Grass g;
	Dirt  d;
	StoneBrick s;
	Chest c;
	Enemy e;
	HealStation hp;
	EnemyGate gate;
	KeyGate gate2;
	Sign si;
};

class Level1 : public Map{
public:
	Level1();
private:
	StoneBrick s;

	HealStation hp;

	Stone st;

	Chest c1, c2, c3, c4;

	KeyGate k1, k2;

	EnemyGate e1, e2, e3, e4;

	Sign s1;

	Portal p1;

	Enemy_Goat g1;

	Enemy_BossGoomba b1;
};

class Level2 : public Map{
public:
	Level2();
private:
	StoneBrick s;

	Stone st;

	HealStation hp;

	Item sword1, armor1, potion1, bomb1, tri2;

	EnemyGate e1, e2, e3, e4, e5;

	KeyGate k1;

	Chest c1, c2;

	Sign s1, s2, s3, s4;

	Portal p1;

	Enemy_Minion m1, m2, m3, m4;

	Enemy_BossGru g1;
};

class Level3 : public Map{
public:
	Level3();
private:
	StoneBrick s;

	Stone st;

	Item potion1, key1, key2, bomb1, armor1, sword1, tri3;

	Chest c1, c2, c3, c4;

	HealStation h1;

	KeyGate k1, k2;

	EnemyGate e1;

	Sign s1;

	Enemy_Cactus ca1, ca2, ca3, ca4, ca5;

	Enemy_BossGarfield g1;

	Portal p1;
};

class Level4 : public Map{
public:
	Level4();
private:
	StoneBrick w;

	Grass g;

	Dirt d;

	Stone st;

	Enemy_BossBAF baf;

	Item tri1, tri2, tri3;

	Chest c;
};