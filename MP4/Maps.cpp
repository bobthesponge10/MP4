#include "Maps.h"

DemoMap::DemoMap() :Map(30, 15){
	g = Grass();
	d = Dirt();
	s = StoneBrick();
	hp = HealStation();
	gate = EnemyGate();

	for(int y = 0; y < get_h(); y++){
		for(int x = 0; x < get_w(); x++){
			set_tile(x, y, &d);
		}
	}
	for(int y = 0; y < get_h() - 5; y++){
		for(int x = 0; x < get_w() - 5; x++){
			set_tile(x + 3, y + 4, &g);
		}
	}

	set_tile(0, 0, &s);
	set_tile(0, 1, &s);
	set_tile(0, 2, &s);
	set_tile(0, 3, &s);
	set_tile(1, 3, &s);
	set_tile(2, 3, &s);
	set_tile(4, 3, &s);
	set_tile(4, 2, &s);
	set_tile(4, 1, &s);
	set_tile(4, 0, &s);
	set_tile(6, 3, &s);
	set_tile(7, 3, &s);
	set_tile(8, 3, &s);
	set_tile(9, 3, &s);
	set_tile(9, 2, &s);
	set_tile(9, 1, &s);
	set_tile(9, 0, &s);

	set_tile(0, 4, &hp);

	Item sword, armor, potion;

	sword.set_name("Iron Sword");
	sword.set_desc("A simple sword made of iron.");
	sword.add_attribute("Type", "Weapon");
	sword.add_attribute("Damage", "5");

	armor.set_name("Leather armor");
	armor.set_desc("A piece of old, worn out leather armor");
	armor.add_attribute("Type", "Armor");
	armor.add_attribute("Protection", "20");

	potion.set_name("Health Potion");
	potion.set_desc("A bottle containing red liquid");
	potion.add_attribute("Type", "Consumable");
	potion.add_attribute("Regen", "10");

	c = Chest();
	c.add_item(sword);
	c.add_item(potion);

	set_tile(1, 0, &c);

	e = Enemy_Jeff();
	e.add_item(armor);

	add_entity(&e);


	gate.set_coords(5, 3);
	gate.set_close_up(true);
	gate.add_open_enemy(&e);

	add_entity(&gate);

	gate2.set_coords(5, 5);
	gate2.set_close_left(true);
	gate2.set_open_key(potion);
	gate2.set_use_item(false);

	add_entity(&gate2);


	si = Sign();
	si.set_text("Bee Movie Scrip\nPog");
	si.set_coords(0, 5);

	add_entity(&si);

	set_default_coords(2, 1);
}