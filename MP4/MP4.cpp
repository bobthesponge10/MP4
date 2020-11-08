#include "MP4.h"


int main(){

	// Creates vector to store flags from the map
	vector<string> flags;

	// Creates string 
	string inp;

	// Loads cutscenes
	print_text("Loading . . .\n");
	Cutscene Title = Cutscene("Title.txt", 1000 / 5, 1, 30);
	Cutscene Teleport = Cutscene("portal.txt", 1000 / 30, 1, 30);
	Cutscene BadEnd;// = Cutscene("rick.txt", 1000 / 25, 1, 30);

	// Clears the screen and plays the intro cutscene
	clear_screen();
	//Title.video(false);
	//wait_for_input();

	// Clears the screen and gives the initial story
	clear_screen();
	print_text("You are transported to an unknown location\n\n");
	//wait_for_input();

	// Clears the screen and plays the teleportation cutscene
	clear_screen();
	//Teleport.video(false);

	// Creates an instance of a player
	Player p = Player();

	// 
	DemoMap test = DemoMap();
	Level1 l1 = Level1();
	Level2 l2 = Level2();
	Level3 l3 = Level3();

	vector<Map*> maps{&l1, &l2, &l3, &test};

	Map* m = maps[2];


	m->set_player(&p);
	m->move_player();

	while(true){
		m->update();
		p.render_window(45, 15, true);
		reset_colors();
		cout << ":";
		getline(cin, inp);
		p.parse_input(inp);
		flags = m->get_flags();
		for(int i = 0; i < flags.size(); i++){
			if(flags[i] == "die"){
				clear_screen();
				BadEnd.video();
				wait_for_input();
				return 0;
			}
			else if(flags[i] == "win"){
			}
			else if(flags[i].substr(0,1) == "m"){
				Map* m = maps[stoi(flags[i].substr(1,1))];
				m->set_player(&p);
				m->move_player();
				Teleport.video(true);
			}
		}
	}
}