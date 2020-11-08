#include "Enemies.h"

Enemy_Jeff::Enemy_Jeff(): Enemy(){
	set_damage(5);
	set_char('A');
	set_fg(Color(255, 0, 0));
	set_ai(2);
	set_name("Linus");
	set_cutscene("Jeff2.ans", 40, 16);
	set_max_hp(10);
	set_hp(10);
}

Enemy_Goat::Enemy_Goat(): Enemy(){
	set_damage(5);
	set_char('G');
	set_fg(Color(224, 191, 122));
	set_ai(1);
	set_name("Goat");
	set_cutscene("goat.txt", 40, 16);
	set_max_hp(10);
	set_hp(10);
}

Enemy_BossGoomba::Enemy_BossGoomba(): Enemy(){
	set_damage(5);
	set_char('G');
	set_fg(Color(255, 0, 0));
	set_ai(0);
	set_name("Boss Goomba");
	set_cutscene("goomba.txt", 33, 20);
	set_max_hp(35);
	set_hp(35);
	turn = 0;
	set_escape_chance(0);
}
void Enemy_BossGoomba::battle_turn(Player* p){
	int d;
	if(turn % 4 == 0){
		d = get_damage()- get_damage() * (p->get_protection() / 100.0);

		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	else if(turn % 4 == 1){
		print_text(get_name() + " is charging a large attack\n\n");
	}
	else if(turn % 4 == 2){
		print_text(get_name() + " is charging a large attack\n\n");
	}
	else{
		print_text(get_name() + " unleashed a large attack\n");
		
		d = get_damage()*3 - get_damage() * (p->get_protection() / 100.0);

		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	turn++;
	wait_for_input();
}

Enemy_Minion::Enemy_Minion() : Enemy(){
	set_damage(7);
	set_char('M');
	set_fg(Color(224, 224, 60));
	set_ai(1);
	set_name("Minion");
	set_cutscene("minion.txt", 27, 16);
	set_max_hp(15);
	set_hp(15);
	set_escape_chance(40);
}

Enemy_BossGru::Enemy_BossGru(): Enemy(){
	set_damage(10);
	set_char('G');
	set_fg(Color(0, 0, 0));
	set_ai(0);
	set_name("Boss Gru");
	set_cutscene("gru.txt", 78, 14);
	set_max_hp(50);
	set_hp(50);
	turn = 0;
	set_escape_chance(0);
}
void Enemy_BossGru::add_minion(Enemy_Minion* m){
	minions.push_back(m);
}
void Enemy_BossGru::battle_turn(Player* p){
	int alive = 0;
	int d = 0;
	for(int i = 0; i < minions.size(); i++){
		if(minions[i]->is_alive()){ alive++; }
	}

	if(alive == 0){
		d = get_damage() / 3;
		print_text(get_name() + " is weakened without his minions.\n");

		d = d - d * (p->get_protection() / 100.0);

		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	else if(alive == 1){
		d = get_damage() / 2;
		print_text(get_name() + " is weakened without his minions.\n");

		d = d - d * (p->get_protection() / 100.0);

		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	else if(alive == 3){
		d = get_damage();
		print_text("With his minions power, " + get_name() + " attacks.\n");

		d = d - d * (p->get_protection() / 100.0);

		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	else if(alive == 4){
		d = get_damage();
		print_text("With his minions power, " + get_name() + " is at full strength.\n");

		d = d * 1.5 - d * (p->get_protection() / 100.0);

		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	wait_for_input();
}