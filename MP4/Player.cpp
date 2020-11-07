#include "Player.h"

const vector<string> help_      {"h", "help", "?", "what", "why"};

const vector<string> up_        {"w", "up"};
const vector<string> down_      {"s", "down"};
const vector<string> left_      {"a", "left"};
const vector<string> right_     {"d", "right"};

const vector<string> inventory_ {"i", "inventory", "inv"};
const vector<string> view_      {"v", "view", "interact", "see"};
const vector<string> stats_     {"stats", "stat"};

const vector<string> get_       {"g", "get", "take", "grab"};
const vector<string> put_       {"p", "put", "place"};
const vector<string> fight_     {"f", "fight", "battle", "attack"};

const vector<string> equip_     {"e", "equip"};
const vector<string> unequip_   {"ue", "unequip"};
const vector<string> weapon_    {"w", "weapon"};
const vector<string> armor_     {"a", "armor"};
const vector<string> flee_      {"flee", "escape", "run"};
const vector<string> use_		{"use", "item"};


Player::Player(){
	set_char('@');
	set_fg(Color(0, 0, 255));
	set_type("player");
	set_inv_name("Inventory");
	max_hp = 10;
	hp = max_hp;
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
	else if(type == "heal_station"){
		hp = max_hp;
		print_text("Healed to full health\n\n");
		wait_for_input();
	}
	int i = get_map()->find_entity(x, y);
	if(i != -1){
		Entity* e = get_map()->get_entity(i);
		if(e->get_type() == "enemy"){
			Enemy* en = (Enemy*)e;
			print_text("----Enemy----\n");
			print_text("Name:   " + en->get_name() + "\n");
			print_text("Health: " + to_string(en->get_hp()) + "/" + to_string(en->get_max_hp()) + "\n");
			print_text("-------------\n\n");
			wait_for_input();
		}
		else if(e->get_type() == "enemy_gate"){
			print_text("Defeat all enemies to open the gate.\n\n");
			wait_for_input();
		}
		else if(e->get_type() == "key_gate"){
			KeyGate* en = (KeyGate*)e;
			Item key = en->get_key();
			int index = -1;
			for(int i = 0; i < get_inv_size(); i++){
				if(key.is_equal(get_item(i))){
					index = i;
				}
			}
			if(index == -1){
				print_text(key.get_name() + " needed to open the gate\n\n");
				wait_for_input();
			}else{
				print_text("Used " + key.get_name() + " to open the gate\n\n");
				en->open_gate();
				if(en->get_use_item()){
					remove_item(index);
				}
				wait_for_input();
			}
		}
		else if(e->get_type() == "sign"){
			Sign* en = (Sign*)e;
			print_text("----Sign----\n");
			print_text(en->get_text() + "\n");
			print_text("------------\n\n");
			wait_for_input();
		}
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
			print_text("Got " + i.get_name() + " from the chest.\n\n");
			wait_for_input();
		}else{
			print_text("Incorrect index of item in chest.\n\n");
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
			print_text("Put " + i.get_name() + " into the chest.\n\n");
			wait_for_input();
		}else{
			print_text("Incorrect index of item in inventory.\n\n");
			wait_for_input();
		}
	}
}
bool Player::use_item(int index, Enemy* e){
	bool used = false;
	bool usedT = false;
	int temp1 = 0;
	string temp2 = "";
	Item i = get_item(index);
	string type = i.get_attribute("Type");
	if(type=="Consumable"){
		temp2 = i.get_attribute("Regen");
		if(temp2!=""){
			if(is_integer(temp2)){
				temp1 = stoi(temp2);
				used = true;
				usedT = true;
				hp += temp1;
			}
		}
		if(usedT){
			remove_item(index);
		}
	}
	usedT = false;
	if(hp > max_hp){ hp = max_hp; }
	if(used){
		print_text("Used the " + i.get_name() + "\n\n");
		return true;
	}
	return false;
}

void Player::print_enemy(Enemy* enemy){
	int w = enemy->get_width();
	clear_screen();
	cout << string(w, '=') << endl;

	enemy->view();

	cout << string(w, '=') << endl;

	cout << (enemy->get_name() + ": " + to_string(enemy->get_hp()) + "/" + to_string(enemy->get_max_hp()) + " Hp\n");
	cout << ("Player: " + to_string(hp) + "/" + to_string(max_hp) + " Hp\n");
	cout << (string(w, '=') + "\n");
}

void Player::fight(int x, int y){
	int e = get_map()->find_entity(x, y);
	if(e == -1 || get_map()->get_entity(e)->get_type() != "enemy"){
		print_text("Not a valid target\n");
		wait_for_input();
		return;
	}
	Entity* enemy_ = get_map()->get_entity(e);
	Enemy* enemy = (Enemy*)enemy_;

	print_text("Begun battle with " + enemy->get_name() + "\n\n");
	wait_for_input();

	srand(time(0));
	bool fight_happening = true;
	int temp;
	int damage = 0;
	int index = 0;
	string inp;
	stringstream ss;
	bool success;
	bool enemy_attack = false;


	while(fight_happening){
		print_enemy(enemy);
		print_text("Choices: Attack, Use/Item, Flee\n");

		enemy_attack = false;

		cout << ":";
		getline(cin, inp);
		ss << inp;
		inp == "";
		ss >> inp;
		ss.clear();



		if(contains(inp, fight_)){
			damage = get_damage();
			enemy->set_hp(enemy->get_hp() - damage);

			print_text("You did " + to_string(damage) + " damage to " + enemy->get_name() + "\n\n");
			wait_for_input();

			enemy_attack = true;
		} 
		else if(contains(inp, use_) && get_inv_size() == 0){
			print_text("Your inventory is empty\n\n");
			wait_for_input();
		}
		else if(contains(inp, use_)){
			print_items();
			print_text("Enter index of item to use: ");
			getline(cin, inp);
			ss << inp;
			index = -1;
			ss >> index;
			ss.clear();

			if(index >= 0 && index < get_inv_size()){
				if(use_item(index, enemy)){
					enemy_attack = true;
				}else{
					print_text("Unable to use item\n\n");
				}
			}else{
				print_text("Not a valid index\n\n");
			}
			wait_for_input();
		}
		else if(contains(inp, flee_)){
			temp = rand() % 100 + 1;
			success = temp <= enemy->get_escape_chance();
			if(success){
				print_text("You successfully escaped " + enemy->get_name() + "\n\n");
				fight_happening = false;
			}else{
				print_text("You failed to escape " + enemy->get_name() + "\n\n");
				enemy_attack = true;
			}
			wait_for_input();
		}

		if(enemy->get_hp()<=0){
			print_enemy(enemy);
			enemy->die();
			print_text("You defeated " + enemy->get_name() + "\n\n");
			if(enemy->get_inv_size()>0){
				enemy->set_inv_name("You got");
				enemy->print_items();
			}
			for(int i = 0; i < enemy->get_inv_size(); i++){
				add_item(enemy->get_item(0));
				enemy->remove_item(0);
			}
			fight_happening = false;
			wait_for_input();
		}

		if(fight_happening && enemy_attack){
			print_enemy(enemy);
			enemy->battle_turn(this);
		}

		if(hp <= 0){
			print_enemy(enemy);
			print_text(enemy->get_name() + " killed you\n\n");
			get_map()->add_flag("die");
			fight_happening = false;
			wait_for_input();
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
		}
		else if(contains(args[0], inventory_)){
			print_text("---------Equipped--------\n");
			print_text("Weapon: " + weapon.get_name() + "\n");
			print_text("Armor:  " + armor.get_name()  + "\n");

			print_items();

			wait_for_input();
		}
		else if(contains(args[0], stats_)){
			int damage = get_damage();
			int prot = get_protection();

			print_text("----------Stats----------\n");
			print_text("Health:     " + to_string(hp) + "/" + to_string(max_hp) + "\n");
			print_text("Damage:     " + to_string(damage) + "\n");
			print_text("Protection: " + to_string(prot) + "\n");
			print_text("-------------------------\n\n");
			wait_for_input();
		}
		else if(contains(args[0], help_)){
			print_text("Good luck\n\n");
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
		else if(contains(args[0], fight_)){
			fight(nx, ny);
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
		print_text("You unequipped the " + armor.get_name() + "\n\n");
		armor = Item();
	}else{
		print_text("No armor currently equipped\n\n");
	}
	wait_for_input();
}
void Player::unequip_weapon(){
	if(weapon.get_name()!=""){
		add_item(weapon);
		print_text("You unequipped the " + weapon.get_name() + "\n\n");
		weapon = Item();
	}else{
		print_text("No weapon currently equipped\n\n");
	}
	wait_for_input();
}
void Player::equip_weapon(int index){
	if(weapon.get_name()!=""){
		print_text("Weapon already equipped\n\n");
		wait_for_input();
		return;
	}
	Item i = get_item(index);
	if(i.get_attribute("Type") == "Weapon"){
		weapon = i;
		print_text("You equipped the " + i.get_name() + "\n\n");
		remove_item(index);
	}else{
		print_text("Not a valid weapon\n\n");
	}
	wait_for_input();
}
void Player::equip_armor(int index){
	if(armor.get_name() != ""){
		print_text("Armor already equipped\n\n");
		wait_for_input();
		return;
	}
	Item i = get_item(index);
	if(i.get_attribute("Type") == "Armor"){
		armor = i;
		print_text("You equipped the " + i.get_name() + "\n\n");
		remove_item(index);
	}else{
		print_text("Not a valid armor\n\n");
	}
	wait_for_input();
}
int Player::get_damage(){
	string t = weapon.get_attribute("Damage");
	int i = 1;
	if(is_integer(t) && t != ""){
		i = stoi(t);
		return i;
	}
	return i;
}
int Player::get_protection(){
	string t = armor.get_attribute("Protection");
	int i = 0;
	if(is_integer(t) && t != ""){
		i = stoi(t);
		return i;
	}
	return i;
}
void Player::set_hp(int a){
	if(a < 0){
		hp = 0;
		return;
	}
	hp = a;
}
int Player::get_hp(){
	return hp;
}