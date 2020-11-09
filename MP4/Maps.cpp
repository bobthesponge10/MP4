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
	e.set_coords(7, 1);
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

Level1::Level1() :Map(20, 20){

	// Sets Walls and floor
	{
		for(int y = 0; y < get_h(); y++){
			for(int x = 0; x < get_w(); x++){
				if(y == 0 || x == 0 || y == get_h()-1 || x == get_w() - 1){
					set_tile(x, y, &s);
				}else{
					set_tile(x, y, &st);
				}
			}
		}
		set_tile(8, 1, &s);
		set_tile(8, 2, &s);
		set_tile(8, 3, &s);
		set_tile(8, 4, &s);

		set_tile(10, 2, &s);
		set_tile(10, 3, &s);
		set_tile(10, 4, &s);
		set_tile(10, 5, &s);

		for(int i = 0; i < 13; i++){
			set_tile(1 + i, 6, &s);
		}

		set_tile(16, 6, &s);
		set_tile(17, 6, &s);
		set_tile(18, 6, &s);
		set_tile(19, 6, &s);

		set_tile(0, 10, &s);
		set_tile(1, 10, &s);
		set_tile(2, 10, &s);
		set_tile(3, 10, &s);

		for(int i = 0; i < 14; i++){
			set_tile(5 + i, 10, &s);
		}

		set_tile(17, 15, &s);
		set_tile(17, 16, &s);
		set_tile(17, 17, &s);
		set_tile(17, 18, &s);
	}

	// Defines Items
	{
		Item Sword1, Armor1, Key1, Potion1, Bomb1, Tri1;

		Sword1.set_name("Rusty Sword");
		Sword1.set_desc("An old and rusty sword");
		Sword1.add_attribute("Damage", "3");
		Sword1.add_attribute("Type", "Weapon");

		Armor1.set_name("Worn Armor");
		Armor1.set_desc("An old set of worn down leather armor");
		Armor1.add_attribute("Protection", "10");
		Armor1.add_attribute("Type", "Armor");

		Key1.set_name("Basic Key");
		Key1.set_desc("A very basic key, can be used to open things");
		Key1.add_attribute("Type", "Key");

		Potion1.set_name("Small Health Potion");
		Potion1.set_desc("A small bottle filled with a dull red liquid");
		Potion1.add_attribute("Regen", "7");
		Potion1.add_attribute("Type", "Consumable");

		Bomb1.set_name("Small Bomb");
		Bomb1.set_desc("A rudimentary explosive");
		Bomb1.add_attribute("Damage", "10");
		Bomb1.add_attribute("Type", "Consumable");

		Tri1.set_name("Triforce of POWER");
		Tri1.set_desc("TRONGLE!!");
		Tri1.add_attribute("Type", "Artifact");

		c1.add_item(Sword1);
		c1.add_item(Key1);
		c2.add_item(Potion1);
		c3.add_item(Bomb1);
		c4.add_item(Armor1);

		k1.set_open_key(Key1);
		k2.set_open_key(Tri1);

		g1.add_item(Potion1);
		b1.add_item(Tri1);
	}

	// Sets Heal Station
	{
		set_tile(17, 8, &hp);
	}

	// Sets Chests
	{
		set_tile(1, 5, &c1);
		set_tile(1, 7, &c2);
		set_tile(1, 8, &c3);
		set_tile(1, 9, &c4);
	}

	// Sets Signs
	{	
		s1.set_coords(7, 4);
		s1.set_text("Danger Goat Ahead");
		add_entity(&s1);
	}

	// Sets Gates
	{
		k1.set_gate(false);
		k1.set_coords(8, 5);
		k1.set_use_item(true);
		add_entity(&k1);

		k2.set_gate(false);
		k2.set_coords(18, 15);
		k2.set_use_item(false);
		add_entity(&k2);

		e1.set_gate(true);
		e1.set_coords(10, 1);
		e1.set_close_right(true);
		add_entity(&e1);

		e2.set_gate(true);
		e2.set_coords(4, 10);
		e2.set_close_down(true);
		add_entity(&e2);

		e3.set_gate(false);
		e3.set_coords(14, 6);
		e3.add_open_enemy(&g1);
		add_entity(&e3);

		e4.set_gate(false);
		e4.set_coords(15, 6);
		e4.add_open_enemy(&g1);
		add_entity(&e4);
	}

	// Sets portal
	{
		p1.set_index(1);
		set_tile(18, 18, &p1);
	}

	// Sets enemies
	{
		g1.set_coords(15, 3);
		add_entity(&g1);

		b1.set_coords(13, 14);
		add_entity(&b1);
	}

	// Sets players starting position
	set_default_coords(1, 1);
}

Level2::Level2(): Map(52, 28){
	s.set_bg(Color(112, 28, 42));
	st.set_bg(Color(207, 107, 124));

	// Sets Walls and floor
	{
		for(int y = 0; y < get_h(); y++){
			for(int x = 0; x < get_w(); x++){
				if(y == 0 || x == 0 || y == get_h() - 1 || x == get_w() - 1){
					set_tile(x, y, &s);
				} else{
					set_tile(x, y, &st);
				}
			}
		}

		for(int i = 0; i < 48; i++){
			set_tile(2+i, 2, &s);
		}

		set_tile(4, 3, &s);
		set_tile(4, 4, &s);
		set_tile(4, 5, &s);
		set_tile(3, 5, &s);
		set_tile(2, 5, &s);

		set_tile(47, 3, &s);
		set_tile(47, 4, &s);
		set_tile(47, 5, &s);
		set_tile(48, 5, &s);
		set_tile(49, 5, &s);

		for(int i = 0; i < 7; i++){
			set_tile(i + 1, 8, &s);
			set_tile(i + 44, 8, &s);
		}
		set_tile(7, 7, &s);
		set_tile(7, 6, &s);
		set_tile(44, 7, &s);
		set_tile(44, 6, &s);

		for(int i = 0; i < 38; i++){
			set_tile(i + 7, 5, &s);
		}

		set_tile(27, 5, &st);

		set_tile(25, 24, &s);
		set_tile(26, 24, &s);
		set_tile(28, 24, &s);
		set_tile(29, 24, &s);

		set_tile(25, 25, &s);
		set_tile(25, 26, &s);

		set_tile(29, 25, &s);
		set_tile(29, 26, &s);

		set_tile(18, 2, &st);
		set_tile(17, 3, &s);
		set_tile(18, 3, &s);
		set_tile(19, 3, &s);
	}

	// Defines Items
	{
		sword1.set_name("Iron Sword");
		sword1.set_desc("A sturdy sword made of iron");
		sword1.add_attribute("Damage", "7");
		sword1.add_attribute("Type", "Weapon");

		armor1.set_name("Iron Armor");
		armor1.set_desc("A strong armor made of iron");
		armor1.add_attribute("Protection", "25");
		armor1.add_attribute("Type", "Armor");

		potion1.set_name("Medium Health Potion");
		potion1.set_desc("A medium bottle filled with a bright red liquid");
		potion1.add_attribute("Regen", "12");
		potion1.add_attribute("Type", "Consumable");

		bomb1.set_name("Medium Bomb");
		bomb1.set_desc("A medium sized bomb");
		bomb1.add_attribute("Damage", "15");
		bomb1.add_attribute("Type", "Consumable");

		tri2.set_name("Triforce of COURAGE");
		tri2.set_desc("TRINGLE!?!");
		tri2.add_attribute("Type", "Artifact");

		k1.set_open_key(tri2);
	}

	// Sets Health Station
	{
		set_tile(8, 6, &hp);
	}

	// Sets Chests
	{
		c1.add_item(sword1);
		c1.add_item(potion1);
		set_tile(3, 3, &c1);

		c2.add_item(armor1);
		c2.add_item(bomb1);
		set_tile(48, 3, &c2);
	}

	// Sets Signs
	{
		s1.set_text("Head down and to the right.");
		s1.set_coords(3, 4);
		add_entity(&s1);

		s2.set_text("Head down and to the left.");
		s2.set_coords(48, 4);
		add_entity(&s2);

		s3.set_text("He draws strength from his minions.");
		s3.set_coords(27, 3);
		add_entity(&s3);

		s4.set_text("Will you go left or right\nit's your choice");
		s4.set_coords(18, 2);
		add_entity(&s4);
	}

	// Sets Gates
	{
		e1.set_gate(true);
		e1.set_coords(1, 2);
		e1.set_close_down(true);
		add_entity(&e1);

		e2.set_gate(true);
		e2.set_coords(1, 5);
		e2.set_close_down(true);
		add_entity(&e2);

		e3.set_gate(true);
		e3.set_coords(50, 2);
		e3.set_close_down(true);
		add_entity(&e3);

		e4.set_gate(true);
		e4.set_coords(50, 5);
		e4.set_close_down(true);
		add_entity(&e4);

		e5.set_gate(true);
		e5.set_coords(27, 5);
		e5.set_close_down(true);
		add_entity(&e5);

		k1.set_gate(false);
		k1.set_coords(27, 24);
		add_entity(&k1);
	}

	// Sets Portal
	{
		p1.set_index(2);
		set_tile(27, 26, &p1);
	}

	// Sets Enemies
	{
		m1.set_coords(14, 8);
		add_entity(&m1);

		m2.set_coords(39, 8);
		add_entity(&m2);

		m3.set_coords(3, 12);
		add_entity(&m3);

		m4.set_coords(48, 12);
		add_entity(&m4);

		g1.set_coords(27, 20);
		g1.add_item(tri2);
		g1.add_minion(&m1);
		g1.add_minion(&m2);
		g1.add_minion(&m3);
		g1.add_minion(&m4);
		add_entity(&g1);
	}

	// Set players starting position
	set_default_coords(18, 1);
}

Level3::Level3(): Map(20, 20){
	s.set_fg(Color(70, 135, 49));

	st.set_bg(Color(181, 152, 71));

	// Sets Walls and floor
	{
		for(int y = 0; y < get_h(); y++){
			for(int x = 0; x < get_w(); x++){
				if(y == 0 || x == 0 || y == get_h() - 1 || x == get_w() - 1){
					set_tile(x, y, &s);
				} else{
					set_tile(x, y, &st);
				}
			}
		}

		for(int i = 0; i < 16; i++){
			set_tile(i + 2, 2, &s);
			set_tile(i + 2, 4, &s);
			set_tile(i + 2, 6, &s);
			set_tile(i + 2, 8, &s);
			set_tile(i + 2, 10, &s);
			set_tile(i + 2, 13, &s);
			set_tile(i + 2, 15, &s);
		}

		set_tile(2, 2, &st);
		set_tile(2, 3, &s);
		set_tile(4, 3, &s);
		set_tile(17, 3, &s);
		set_tile(2, 5, &s);
		set_tile(4, 5, &s);
		set_tile(8, 5, &s);
		set_tile(10, 5, &s);
		set_tile(16, 5, &s);

		set_tile(5, 2, &st);
		set_tile(3, 4, &st);
		set_tile(5, 4, &st);
		set_tile(9, 4, &st);
		set_tile(11, 4, &st);

		set_tile(3, 6, &st);
		set_tile(9, 6, &st);
		set_tile(11, 6, &st);
		set_tile(15, 6, &st);
		set_tile(17, 6, &st);
		set_tile(18, 6, &s);

		set_tile(2, 7, &s);
		set_tile(16, 7, &s);
		set_tile(18, 7, &s);
		set_tile(17, 8, &st);
		set_tile(18, 8, &s);

		set_tile(13, 9, &s);
		set_tile(18, 9, &s);

		set_tile(1, 10, &s);
		set_tile(18, 10, &s);
		set_tile(2, 10, &st);
		set_tile(4, 10, &st);
		set_tile(8, 10, &st);
		set_tile(12, 10, &st);
		set_tile(14, 10, &st);

		set_tile(1, 11, &s);
		set_tile(3, 11, &s);
		set_tile(5, 11, &s);
		set_tile(6, 11, &s);
		set_tile(7, 11, &s);
		set_tile(9, 11, &s);
		set_tile(11, 11, &s);
		set_tile(13, 11, &s);

		set_tile(1, 12, &s);
		set_tile(3, 12, &s);
		set_tile(7, 12, &s);
		set_tile(9, 12, &s);
		set_tile(11, 12, &s);
		set_tile(13, 12, &s);
		set_tile(15, 12, &s);
		set_tile(16, 12, &s);
		set_tile(17, 12, &s);
		set_tile(1, 12, &s);

		set_tile(1, 13, &s);
		set_tile(2, 13, &st);
		set_tile(8, 13, &st);
		set_tile(10, 13, &st);
		set_tile(14, 13, &st);

		set_tile(1, 14, &s);
		set_tile(7, 14, &s);
		set_tile(9, 14, &s);
		set_tile(17, 14, &s);

		set_tile(1, 15, &s);
		set_tile(8, 15, &st);
		set_tile(18, 15, &s);

		set_tile(2, 18, &s);
		set_tile(2, 16, &s);
	}

	// Defines Items
	{
		sword1.set_name("Master Sword");
		sword1.set_desc("You know, the one from Zelda");
		sword1.add_attribute("Damage", "7");
		sword1.add_attribute("Type", "Weapon");

		armor1.set_name("Master Armor");
		armor1.set_desc("You know, the one from Zelda");
		armor1.add_attribute("Protection", "30");
		armor1.add_attribute("Type", "Armor");

		potion1.set_name("Medium Health Potion");
		potion1.set_desc("A medium bottle filled with a bright red liquid");
		potion1.add_attribute("Regen", "12");
		potion1.add_attribute("Type", "Consumable");

		bomb1.set_name("Medium Bomb");
		bomb1.set_desc("A medium sized bomb");
		bomb1.add_attribute("Damage", "15");
		bomb1.add_attribute("Type", "Consumable");

		key1.set_name("Comically large Key");
		key1.set_desc("A very large key, comically large some might say");
		key1.add_attribute("Type", "Key");

		key2.set_name("Master Key");
		key2.set_desc("You know, the one from Zelda");
		key2.add_attribute("Type", "Key");

		tri3.set_name("Triforce of GAMING");
		tri3.set_desc("!!TRANGLE??");
		tri3.add_attribute("Type", "Artifact");
	}

	// Sets Health Station
	{
		set_tile(12, 12, &h1);
	}

	// Sets Chests
	{
		c1.add_item(potion1);
		set_tile(7, 5, &c1);

		c2.add_item(key1);
		c2.add_item(bomb1);
		set_tile(3, 3, &c2);

		c3.add_item(armor1);
		c3.add_item(key2);
		set_tile(18, 14, &c3);

		c4.add_item(sword1);
		set_tile(6, 14, &c4);
	}

	// Sets Signs
	{
		s1.set_coords(2, 2);
		s1.set_text("Solve the maze for treasures");
		add_entity(&s1);
	}

	// Sets Gates
	{
		k1.set_coords(18, 13);
		k1.set_gate(false);
		k1.set_open_key(key1);
		add_entity(&k1);

		k2.set_coords(3, 14);
		k2.set_gate(false);
		k2.set_open_key(key2);
		add_entity(&k2);

		e1.set_coords(2, 17);
		e1.set_gate(false);
		e1.add_open_enemy(&g1);

		add_entity(&e1);
	}

	// Sets Portal
	{
		p1.set_index(3);
		set_tile(1, 18, &p1);
	}

	// Sets Enemies
	{
		ca1.set_coords(3, 4);
		add_entity(&ca1);

		ca2.set_coords(15, 3);
		add_entity(&ca2);

		ca3.set_coords(14, 7);
		add_entity(&ca3);

		ca4.set_coords(10, 11);
		add_entity(&ca4);

		ca5.set_coords(6, 12);
		add_entity(&ca5);

		g1.set_coords(12, 17);
		g1.add_item(tri3);
		add_entity(&g1);
	}

	// Set players starting position
	set_default_coords(1, 1);
}

Level4::Level4(): Map(21, 20){
	w.set_bg(Color(74, 134, 232));
	w.set_char(' ');

	d.set_bg(Color(255, 242, 204));

	d.set_char(' ');
	g.set_char(' ');

	// Defines Items
	{
		tri1.set_name("Triforce of POWER");
		tri1.set_desc("TRONGLE!!");
		tri1.add_attribute("Type", "Artifact");

		tri2.set_name("Triforce of COURAGE");
		tri2.set_desc("TRINGLE!?!");
		tri2.add_attribute("Type", "Artifact");

		tri3.set_name("Triforce of GAMING");
		tri3.set_desc("!!TRANGLE??");
		tri3.add_attribute("Type", "Artifact");

	}

	// Sets environment
	{
		for(int y = 0; y < get_h(); y++){
			for(int x = 0; x < get_w(); x++){
				set_tile(x, y, &w);
			}
		}

		 vector<int> width {5, 9, 11, 13, 13, 15, 15, 15, 15, 15, 13, 13, 11, 9, 5};
		for(int y = 0; y < 15; y++){
			for(int w = 0; w < width[y]; w++){
				set_tile(10 - (width[y] / 2) + w, y + 2, &d);
			}
		}

		width = {3, 7, 9, 11, 11, 13, 13, 13, 11, 11, 9, 7, 3};
		for(int y = 0; y < 13; y++){
			for(int w = 0; w < width[y]; w++){
				set_tile(10 - (width[y] / 2) + w, y + 3, &g);
			}
		}
	}

	// Sets boss
	baf.set_coords(10, 7);
	baf.set_a1(tri1);
	baf.set_a2(tri2);
	baf.set_a3(tri3);
	add_entity(&baf);


	c.add_item(tri1);
	c.add_item(tri2);
	c.add_item(tri3);
	set_tile(8, 13, &c);

	// Set players starting position
	set_default_coords(10, 14);

}