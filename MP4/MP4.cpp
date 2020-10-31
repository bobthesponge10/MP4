#include "MP4.h"

class Grass : public Tile{
public:
	Grass(){
		set_char('*');
		set_bg(Color(0, 200, 0));
		set_fg(Color(191, 147, 13));
		set_solid(false);
	}
};

class Dirt : public Tile{
public:
	Dirt(){
		set_char('*');
		set_fg(Color(138, 75, 28));
		set_bg(Color(219, 148, 94));
		set_solid(false);
	}
};

class StoneBrick : public Tile{
public:
	StoneBrick(){
		set_char(206);
		set_fg(Color(50, 50, 50));
		set_bg(Color(150, 150, 150));
		set_solid(true);
	}
};

class Chest : public Tile, public Inventory{
public:
	Chest(){
		set_char(240);
		set_fg(Color(0, 0, 0));
		set_bg(Color(255, 0, 0));
		set_solid(true);
		set_type("chest");
		set_inv_name("Chest");
	}
private:
};

class Player : public Entity, public Inventory{
public:
	Player(){
		set_char('@');
		set_fg(Color(0, 0, 255));
		set_inv_name("Inventory");
	}
	void update(){
	}
	void view_tile(int x, int y){
		Tile* t = get_map()->get_tile_p(x, y);
		string type = t->get_type();
		if(type=="chest"){
			Chest* c = (Chest*)t;
			c->print_items();
		}
	}
	void get_item_from_tile(int x, int y, int index){
		Tile* t = get_map()->get_tile_p(x, y);
		string type = t->get_type();
		if(type == "chest"){
			Chest* c = (Chest*)t;
			Item i = c->get_item(index);
			if(i.get_name() != ""){
				c->remove_item(index);
				add_item(i);
			}
		}
	}
	void put_item_to_tile(int x, int y, int index){
		Tile* t = get_map()->get_tile_p(x, y);
		string type = t->get_type();
		if(type == "chest"){
			Chest* c = (Chest*)t;
			Item i = get_item(index);
			if(i.get_name() != ""){
				remove_item(index);
				c->add_item(i);
			}
		}
	}
private:
};



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

	char inp;

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

	wait_for_input();

	while(true){
		m.update();
		system("CLS");
		m.render(0, 0, m.get_w(), m.get_h());
		reset_colors();
		cout << ":";
		cin >> inp;
		cin.ignore(INT_MAX, '\n');
		if(inp=='u'){
			p.move_up();
		}else if(inp=='d'){
			p.move_down();
		}else if(inp=='l'){
			p.move_left();
		}else if(inp=='r'){
			p.move_right();
		}else if(inp == 'i'){
			p.print_items();
			wait_for_input();
		}else if(inp == 'v'){
			p.view_tile(p.get_x() - 1, p.get_y());
			wait_for_input();
		}else if(inp == 'g'){
			p.get_item_from_tile(p.get_x() - 1, p.get_y(), 0);
			wait_for_input();
		} else if(inp == 'p'){
			p.put_item_to_tile(p.get_x() - 1, p.get_y(), 0);
			wait_for_input();
		}
	}
}