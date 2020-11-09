#include "MP4.h"


int main(){

	// Creates vector to store flags from the map
	vector<string> flags;

	// Creates string 
	string inp;

	// Loads cutscenes
	print_text("Loading . . .\n");
	Cutscene Title    =  Cutscene("Title.txt",    1000 / 5,  1, 30);
	Cutscene Teleport =  Cutscene("portal.txt",   1000 / 30, 1, 30);
	Cutscene BadEnd   =  Cutscene("rick.txt",     1000 / 25, 1, 30);
	Cutscene YouDidIt =  Cutscene("congrats.txt", 1000 / 5,  1, 29);
	Cutscene GoodEnd  =  Cutscene("he.txt",       1000 / 25, 1, 30);

	// Clears the screen and plays the intro cutscene
	clear_screen();
	Title.video(false);
	wait_for_input();

	// Clears the screen and gives the initial story
	clear_screen();
	print_text("You are transported to an unknown location\n\n");
	wait_for_input();

	// Clears the screen and plays the teleportation cutscene
	clear_screen();
	Teleport.video(false);

	// Creates an instance of a player
	Player p = Player();

	// Creates levels
	DemoMap test = DemoMap();
	Level1 l1 = Level1();
	Level2 l2 = Level2();
	Level3 l3 = Level3();
	Level4 l4 = Level4();

	// Creates a vector to hold all the levels
	vector<Map*> maps{&l1, &l2, &l3, &l4, &test};

	// Sets the current map
	Map* m = maps[0];

	// Sets the player to the first map
	m->set_player(&p);
	m->move_player();

	// Starts the main loop
	while(true){

		// Updates the map and renders the area around the player
		m->update();
		p.render_window(45, 15, true);

		// Sets the colors back to normal and gets input from the player
		reset_colors();
		cout << ":";
		getline(cin, inp);
		p.parse_input(inp);

		// Gets flags from the current map
		flags = m->get_flags();

		// Loops over all the flags
		for(int i = 0; i < flags.size(); i++){

			// Checks if the player died
			if(flags[i] == "die"){

				// Clears screen, plays death animation and closes the program
				clear_screen();
				BadEnd.video();
				wait_for_input();
				return 0;
			}

			// checks if the player wins
			else if(flags[i] == "win"){

				// Tells the user what happend
				clear_screen();
				print_text("You defeated Baphomet with the Triforce (you know the one from Zelda)\n");
				print_text("You then escaped the island to your freedom or something idk.\n\n");
				wait_for_input();

				// Plays the the first ending cutscene
				YouDidIt.video(false);
				wait_for_input();

				// Plays the second ending cutscene
				GoodEnd.video(true);
				wait_for_input();

				// Exits the program
				return 0;
			}

			// Checks if the level changed
			else if(flags[i].substr(0,1) == "m"){

				// Sets the current map to the new level
				m = maps[stoi(flags[i].substr(1,1))];

				// Moves the player to the new location
				m->set_player(&p);
				m->move_player();

				// Plays the telport cutscene
				Teleport.video(true);
			}
		}
	}
}