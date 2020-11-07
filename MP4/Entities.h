#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "Item.h"

class Enemy;

class EnemyGate : public Entity{
public:
	EnemyGate();
	void set_coords(int x, int y);
	void set_gate(bool b);
	void add_open_enemy(Enemy* p);
	void set_close_up(bool b);
	void set_close_down(bool b);
	void set_close_left(bool b);
	void set_close_right(bool b);
	void update();
private:
	bool open;
	int x, y;
	vector<Enemy*> open_condition;
	bool close_up;
	bool close_down;
	bool close_left;
	bool close_right;
};

class KeyGate : public Entity{
public:
	KeyGate();
	void set_coords(int x, int y);
	void set_gate(bool b);
	void set_use_item(bool b);
	bool get_use_item();
	void open_gate();
	void set_open_key(Item i);
	Item get_key();
	void set_close_up(bool b);
	void set_close_down(bool b);
	void set_close_left(bool b);
	void set_close_right(bool b);
	void update();
private:
	bool open;
	bool opened;
	bool use_item;
	int x, y;
	Item key;
	bool close_up;
	bool close_down;
	bool close_left;
	bool close_right;
};

class Sign : public Entity{
public:
	Sign();
	void set_text(string t);
	string get_text();
private:
	string text;
};