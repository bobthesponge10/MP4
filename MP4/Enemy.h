#pragma once
#include "Entity.h"
#include "Player.h"
#include "Cutscene.h"
#include "Structures.h"

class Player;

class Enemy : public Entity, public Inventory{
public:
	Enemy();
	int get_hp();
	void set_hp(int a);
	int get_ai();
	void set_max_hp(int a);
	int get_max_hp();
	void set_escape_chance(int a);
	int get_escape_chance();
	void set_ai(int a);
	void set_current_frame(int f);
	void update();
	void die();
	void view();
	void battle_turn(Player* p);
	void set_cutscene(string file, int w, int s);
	int get_width();
	bool is_alive();
private:
	int ai;
	int hp;
	int max_hp;
	int escape_chance;

	Cutscene cut;
	int current_frame;

	int y_v;
	int x_v;
	bool alive;
};
