// Enemies.h

#pragma once
#include "Enemy.h"


class Enemy_Jeff : public Enemy{
public:
	Enemy_Jeff();
};

class Enemy_Goat : public Enemy{
public:
	Enemy_Goat();
};

class Enemy_BossGoomba : public Enemy{
public:
	Enemy_BossGoomba();
	void battle_turn(Player* p);
private:
	int turn;
};

class Enemy_Minion : public Enemy{
public:
	Enemy_Minion();
};

class Enemy_BossGru : public Enemy{
public:
	Enemy_BossGru();
	void add_minion(Enemy_Minion* m);
	void battle_turn(Player* p);
private:
	vector<Enemy_Minion*> minions;
	int turn;
};

class Enemy_Cactus : public Enemy{
public:
	Enemy_Cactus();
};

class Enemy_BossGarfield : public Enemy{
public:
	Enemy_BossGarfield();
	void battle_turn(Player* p);
private:
	int turn;
};

class Enemy_BossBAF : public Enemy{
public:
	Enemy_BossBAF();
	void battle_turn(Player* p);
	void die();
	bool use_item(Item i);
	void set_a1(Item i);
	void set_a2(Item i);
	void set_a3(Item i);
private:
	Item a1, a2, a3;
	bool a;
	int turn;
	int artifacts;
};