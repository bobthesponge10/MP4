#include "Player.h"


const vector<string> up_        {"w", "up"};
const vector<string> down_      {"s", "down"};
const vector<string> left_      {"a", "left"};
const vector<string> right_     {"d", "right"};

const vector<string> inventory_ {"i", "inventory", "inv"};
const vector<string> view_      {"v", "view", "interact"};
const vector<string> get_       {"g", "get", "take", "grab"};
const vector<string> put_       {"p", "put", "place"};
const vector<string> fight_     {"f", "fight", "battle", "attack"};
const vector<string> equip_     {"equip"};
const vector<string> unequip_   {"unequip"};
const vector<string> weapon_    {"w", "weapon"};
const vector<string> armor_     {"a", "armor"};



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
			print_text("Got " + i.get_name() + " from chest.\n");
			wait_for_input();
		}else{
			print_text("Incorrect index of item in chest.\n");
			wait_for_input();
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
			print_text("Put " + i.get_name() + " into chest.\n");
			wait_for_input();
		}else{
			print_text("Incorrect index of item in inventory.\n");
			wait_for_input();
		}
	}
}
void Player::fight(int x, int y){

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
		}
		else if(contains(args[0], inventory_)){
			print_text("---------Equipped--------\n");
			print_text("Weapon: " + weapon.get_name() + "\n");
			print_text("Armor:  " + armor.get_name()  + "\n");

			print_items();
			wait_for_input();
		}
	}

	if(args.size()>1){
		if(contains(args[0], view_)){
			view_tile(nx, ny);
		} 
		else if(contains(args[0], unequip_)){
			if(contains(args[1], weapon_)){
				unequip_weapon();
			} else if(contains(args[1], armor_)){
				unequip_armor();
			}
		}
	}

	if(args.size()>2){
		if(contains(args[0], get_) && is_integer(args[2])){
			index = stoi(args[2]);
			get_item_from_tile(nx, ny, index);
		}
		else if(contains(args[0], put_) && is_integer(args[2])){
			index = stoi(args[2]);
			put_item_to_tile(nx, ny, index);
		}
		else if(contains(args[0], equip_) && is_integer(args[2])){
			index = stoi(args[2]);
			if(contains(args[1], weapon_)){
				equip_weapon(index);
			}else if(contains(args[1], armor_)){
				equip_armor(index);
			}
		}
	}
}
void Player::render_window(int w, int h, bool clear){
	int w_ = get_map()->get_w();
	int h_ = get_map()->get_h();

	if(w > w_){ w = w_; }
	if(h > h_){ h = h_; }

	int x = get_x() - w / 2;
	if(x < 0){ x = 0; }
	if(x + w > w_){ x = w_ - w; }
	int y = get_y() - h / 2;
	if(y < 0){ y = 0; }
	if(y + h > h_){ y = h_ - h; }


	string s = get_map()->render(x, y, w, h, false);
	if(clear){ clear_screen(); }
	cout << s;
}
void Player::unequip_armor(){
	if(armor.get_name()!=""){
		add_item(armor);
		print_text("You unequipped the " + armor.get_name() + "\n");
		armor = Item();
	}else{
		print_text("No armor currently equipped\n");
	}
	wait_for_input();
}
void Player::unequip_weapon(){
	if(weapon.get_name()!=""){
		add_item(weapon);
		print_text("You unequipped the " + weapon.get_name() + "\n");
		weapon = Item();
	}else{
		print_text("No weapon currently equipped\n");
	}
	wait_for_input();
}
void Player::equip_weapon(int index){
	if(weapon.get_name()!=""){
		print_text("Weapon already equipped\n");
		wait_for_input();
		return;
	}
	Item i = get_item(index);
	if(i.get_attribute("Type") == "Weapon"){
		weapon = i;
		print_text("You equipped the " + i.get_name() + "\n");
		remove_item(index);
	}else{
		print_text("Not a valid weapon\n");
	}
	wait_for_input();
}
void Player::equip_armor(int index){
	if(armor.get_name() != ""){
		print_text("Armor already equipped\n");
		wait_for_input();
		return;
	}
	Item i = get_item(index);
	if(i.get_attribute("Type") == "Armor"){
		weapon = i;
		print_text("You equipped the " + i.get_name() + "\n");
		remove_item(index);
	}else{
		print_text("Not a valid armor\n");
	}
	wait_for_input();
}