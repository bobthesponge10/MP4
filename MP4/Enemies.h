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