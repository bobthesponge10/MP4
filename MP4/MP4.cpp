#include "MP4.h"


int main(){
	Grass g = Grass();
	Dirt d = Dirt();
	StoneBrick s = StoneBrick();
	Map m = Map(30, 15);
	for(int y = 0; y < 15; y++){
		for(int x = 0; x < 30; x++){
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

	p.view_tile(1, 0);

	while(true){
		m.update();
		system("CLS");
		m.render(0, 0, m.get_w(), m.get_h());
		reset_colors();
		cout << ":";
		getline(cin, inp);
		p.parse_input(inp);
	}
}