#include "Structures.h";

Color::Color(){
		r = 0;
		g = 0;
		b = 0;
}
Color::Color(int r_, int g_, int b_){
		r = r_;
		g = g_;
		b = b_;
}



Inventory::Inventory(){
}
vector<Item> Inventory::get_items(){
	return inventory;
}
void Inventory::print_items(){
	display_items(inventory, inventory_name);		// Functoin call with vector paramater
}
Item Inventory::get_item(int i){
	if(i >= 0 && i < inventory.size()){
		return inventory[i];
	}
	return Item();
}
void Inventory::print_item(int i){
	inventory[i].display("");
}
void Inventory::add_item(Item i){
	inventory.push_back(i);
}
void Inventory::remove_item(int index){
	if(index >= 0 && index < inventory.size()){
		inventory.erase(inventory.begin() + index);
	}
}
void Inventory::set_inv_name(string name){
	inventory_name = name;
}
string Inventory::get_inv_name(){
	return inventory_name;
}
int Inventory::get_inv_size(){
	return inventory.size();								// Uses vector functonality
}