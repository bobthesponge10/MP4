#include "MP4.h"


int main(){

	string inp;

	DemoMap test = DemoMap();

	Map* m = &test;

	Player p = Player();

	p.set_x(2);
	p.set_y(1);

	m->add_entity(&p);

	while(true){
		m->update();
		p.render_window(20, 10, true);
		reset_colors();
		cout << ":";
		getline(cin, inp);
		p.parse_input(inp);
	}
}