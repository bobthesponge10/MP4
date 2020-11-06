#pragma once
using namespace std;
#include <vector>
#include "Item.h"
#include "Functions.h"

class Item;

struct Color{
	Color();
	Color(int r_, int g_, int b_);
	int r;
	int g;
	int b;
};


class Inventory{
public:
	Inventory();
	vector<Item> get_items();
	void print_items();
	Item get_item(int i);
	void print_item(int i);
	void add_item(Item i);
	void remove_item(int index);
	void set_inv_name(string name);
	string get_inv_name();
	int set_inv_size();
private:
	string inventory_name;
	vector<Item> inventory;
};