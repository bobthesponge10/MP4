#include "MP4.h"


int main(){
	Grass g = Grass();
	Dirt d = Dirt();
	StoneBrick s = StoneBrick();
	Map m = Map(30, 15);
	for(int y = 0; y < m.get_w(); y++){
		for(int x = 0; x < m.get_h(); x++){
			m.set_tile(x, y, &d);
		}
	}
	for(int y = 0; y < 5; y++){
		for(int x = 0; x < 5; x++){
			m.set_tile(x+3, y+3, &g);
		}
	}

	m.set_tile(0, 0, &s);
	m.set_tile(0, 1, &s);
	m.set_tile(0, 2, &s);
	m.set_tile(0, 3, &s);
	m.set_tile(1, 3, &s);
	m.set_tile(2, 3, &s);
	m.set_tile(4, 3, &s);
	m.set_tile(4, 2, &s);
	m.set_tile(4, 1, &s);
	m.set_tile(4, 0, &s);
	m.set_tile(6, 3, &s);
	m.set_tile(7, 3, &s);
	m.set_tile(8, 3, &s);
	m.set_tile(9, 3, &s);
	m.set_tile(9, 2, &s);
	m.set_tile(9, 1, &s);
	m.set_tile(9, 0, &s);


	Player p = Player();

	p.set_x(2);
	p.set_y(1);

	m.add_entity(&p);

	string inp;

	Item sword;

	sword.set_name("Iron Sword");
	sword.set_desc("A simple sword made of iron.");
	sword.add_attribute("Damage", "5");
	sword.add_attribute("Durability", "50");
	//sword.display();

	//p.add_item(sword);

	Chest c = Chest();
	c.add_item(sword);

	m.set_tile(1, 0, &c);

	Enemy e = Enemy();
	e.set_char('A');
	e.set_fg(Color(255, 0, 0));
	e.set_x(7);
	e.set_y(1);
	e.set_ai(2);

	m.add_entity(&e);

	while(true){
		m.update();
		p.render_window(30, 15, true);
		reset_colors();
		cout << ":";
		getline(cin, inp);
		p.parse_input(inp);
	}
}