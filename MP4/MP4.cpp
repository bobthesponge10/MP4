#include "MP4.h"


int main(){
	vector<string> flags;
	string inp;

	//Cutscene BadEnd = Cutscene("rick.txt", 1000/25, 1, 30);

	Player p = Player();
	DemoMap test = DemoMap();

	Map* m = &test;

	m->set_player(&p);
	m->move_player();

	while(true){
		m->update();
		p.render_window(20, 10, true);
		reset_colors();
		cout << ":";
		getline(cin, inp);
		p.parse_input(inp);
		flags = m->get_flags();
		for(int i = 0; i < flags.size(); i++){
			if(flags[i] == "die"){
				clear_screen();
				//BadEnd.video();
				return 0;
			}
		}
	}
}