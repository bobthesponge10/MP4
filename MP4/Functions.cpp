#include "Functions.h";

void set_color(Color c, bool fg){
	string s = "";

	s.push_back(0x1b);

	s += '[';

	if(fg){
		s += "38;2;";
	} else{
		s += "48;2;";
	}
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	cout << s;
}

void reset_colors(){
	string s = "";
	s.push_back(0x1b);
	s += "[0;39;49m";

	cout << s;
}

string reset(){
	string s = "";
	s.push_back(0x1b);
	s += "[0;39;49m";

	return s;
}

string bg(Color c){
	string s = "";

	s.push_back(0x1b);

	s += "[48;2;";
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	return s;
}

string fg(Color c){
	string s = "";

	s.push_back(0x1b);

	s += "[38;2;";
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	return s;
}

void display_items(vector<Item> items, string title){
	string s = "";
	s += "--------" + title + "--------\n";
	for(int i = 0; i < items.size(); i++){
		s += to_string(i) + ": ";
		s += items[i].get_display("   ") + "\n";
		s += "\n";
	}
	print_text(s);
}

void print_text(string text){
	for(int i = 0; i < text.length(); i++){
		sleep(30);
		cout << text[i];
	}
}

void sleep(int milli){
	this_thread::sleep_for(chrono::milliseconds(milli));
}

void wait_for_input(){
	cout << ": ";
	cin.ignore(1, '\n');
}
bool contains(string key, vector<string> values){
	for(int i = 0; i < values.size(); i++){
		if(key==values[i]){
			return true;
		}
	}
	return false;
}

void clear_screen(){
	system("CLS");
}

bool is_integer(string s){
	for(int i = 0; i < s.length(); i++)
		if(isdigit(s[i]) == false){
			return false;
		}
	return true;
}