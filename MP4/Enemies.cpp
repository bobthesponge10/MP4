#include "Enemies.h"

Enemy_Jeff::Enemy_Jeff(): Enemy(){
	set_char('A');
	set_fg(Color(255, 0, 0));
	set_x(7);
	set_y(1);
	set_ai(2);
	set_name("Jeff");
	set_cutscene("Jeff2.ans", 40, 16);
	set_max_hp(10);
	set_hp(10);
}