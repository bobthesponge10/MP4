#include "Player.h"


const vector<string> up_   {"w", "up"};
const vector<string> down_ {"s", "down"};
const vector<string> left_ {"a", "left"};
const vector<string> right_{"d", "right"};

const vector<string> inventory_{"i", "inventory"};
const vector<string> view_     {"v", "view", "interact"};
const vector<string> get_      {"g", "get", "take"};
const vector<string> put_      {"p", "put", "place"};

Player::Player(){
	set_char('@');
	set_fg(Color(0, 0, 255));
	set_inv_name("Inventory");
}
void Player::update(){
}
void Player::view_tile(int x, int y){
	Tile* t = get_map()->get_tile_p(x, y);
	string type = t->get_type();
	if(type == "chest"){
		Chest* c = (Chest*)t;
		c->print_items();
		wait_for_input();
	}
}
void Player::get_item_from_tile(int x, int y, int index){
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
void Player::put_item_to_tile(int x, int y, int index){
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
void Player::parse_input(string input){
	stringstream ss;
	ss << input;
	vector<string> args;
	string temp;

	while(!ss.eof()){
		ss >> temp;
		if(!ss.fail()){
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			args.push_back(temp);
		}
	}

	int x = get_x();
	int y = get_y();

	int nx = x;
	int ny = y;

	int index = 0;

	if(args.size()>1){
		if(contains(args[1], up_)){
			ny = y - 1;
		} else if(contains(args[1], down_)){
			ny = y + 1;
		} else if(contains(args[1], left_)){
			nx = x - 1;
		} else if(contains(args[1], right_)){
			nx = x + 1;
		}
	}


	if(args.size()>0){
		if(contains(args[0], up_)){
			move_up();
		}
		else if(contains(args[0], down_)){
			move_down();
		}
		else if(contains(args[0], left_)){
			move_left();
		}
		else if(contains(args[0], right_)){
			move_right();
		}else if(contains(args[0], inventory_)){
			print_items();
			wait_for_input();
		}
	}
	if(args.size()>1){
		if(contains(args[0], view_)){
			view_tile(nx, ny);
		}
	}
	if(args.size()>1){
		if(contains(args[0], get_)){
			if(args.size()>2){
				index = stoi(args[2]);
			}
			get_item_from_tile(nx, ny, index);
		}
		else if(contains(args[0], put_)){
			if(args.size() > 2){
				index = stoi(args[2]);
			}
			put_item_to_tile(nx, ny, index);
		}
	}
}
void Player::render_window(int w, int h){
	
}