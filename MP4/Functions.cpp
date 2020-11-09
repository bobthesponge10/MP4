// Functions.cpp

#include "Functions.h";


// Sets console color
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

// Resets console color
void reset_colors(){
	string s = "";
	s.push_back(0x1b);
	s += "[0;39;49m";

	cout << s;
}

// Gives console reset string
string reset(){
	string s = "";
	s.push_back(0x1b);
	s += "[0;39;49m";

	return s;
}

// Gives string to set background
string bg(Color c){
	string s = "";

	s.push_back(0x1b);

	s += "[48;2;";
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	return s;
}

// Gives string to set foreground
string fg(Color c){
	string s = "";

	s.push_back(0x1b);

	s += "[38;2;";
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	return s;
}

// Displays vector of items
void display_items(vector<Item> items, string title){			// Function definition with vector as paramater
	string s = "";
	s += "--------" + title + "--------\n";
	for(int i = 0; i < items.size(); i++){
		s += to_string(i) + ": ";
		s += items[i].get_display("   ") + "\n";
	}
	s += string(16 + title.length(), '-') + "\n\n";
	print_text(s);
}

// prints text with waiting in between each character
void print_text(string text){
	for(int i = 0; i < text.length(); i++){
		sleep(5);
		cout << text[i];										 // Uses string like array
	}
}

// Waits for a given ammount of time
void sleep(int milli){
	chrono::high_resolution_clock::time_point t1;
	chrono::high_resolution_clock::time_point t2;
	chrono::duration<double> time_span;

	t1 = chrono::high_resolution_clock::now();
	t2 = t1;
	time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	while(time_span.count() <= milli/1000.0){
		t2 = chrono::high_resolution_clock::now();
		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	}

	//this_thread::sleep_for(chrono::milliseconds(milli));
	//Sleep(milli/10);
}

// Waits for the user to press enter
void wait_for_input(){
	cout << "Press enter to continue: ";
	cin.ignore(1, '\n');
}

// Checks if string in vector
bool contains(string key, vector<string> values){
	for(int i = 0; i < values.size(); i++){
		if(key==values[i]){
			return true;
		}
	}
	return false;
}

// Clears screen
void clear_screen(){
	system("CLS");
}

// Checks if string is integer
bool is_integer(string s){
	for(int i = 0; i < s.length(); i++)
		if(isdigit(s[i]) == false){
			return false;
		}
	return true;
}