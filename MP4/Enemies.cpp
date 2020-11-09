// Enemies.cpp

#include "Enemies.h"

// Creates test enemy
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

// Creates goat enemy
Enemy_Goat::Enemy_Goat(): Enemy(){
	set_damage(5);
	set_char('G');
	set_fg(Color(112, 80, 4));
	set_ai(1);
	set_name("Goat");
	set_cutscene("goat.txt", 40, 16);
	set_max_hp(10);
	set_hp(10);
}

// Creates goomba boss
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

// Sets boss goombas attack pattern
void Enemy_BossGoomba::battle_turn(Player* p){
	int d;

	// Does a different attack depending on the turn
	if(turn % 4 == 0){														// % opperator
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
		
		d = get_damage()*1.5	 - get_damage() * (p->get_protection() / 100.0);

		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	turn++;
	wait_for_input();
}


// Creates minion enemy
Enemy_Minion::Enemy_Minion() : Enemy(){
	set_damage(6);
	set_char('M');
	set_fg(Color(224, 224, 60));
	set_ai(1);
	set_name("Minion");
	set_cutscene("minion.txt", 27, 16);
	set_max_hp(12);
	set_hp(12);
	set_escape_chance(40);
}

// Creates boss gru
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

// Adds a minion to gru
void Enemy_BossGru::add_minion(Enemy_Minion* m){
	minions.push_back(m);
}

// Sets boss gru battle turn
void Enemy_BossGru::battle_turn(Player* p){
	int alive = 0;
	int d = 0;

	// Finds the # of minions alive
	for(int i = 0; i < minions.size(); i++){
		if(minions[i]->is_alive()){ alive++; }
	}

	// Does a different move depending on the # of minions alive
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

// Creates cactus enemy
Enemy_Cactus::Enemy_Cactus(){
	set_damage(6);
	set_char('C');
	set_fg(Color(0, 220, 20));
	set_ai(0);
	set_name("Cactus");
	set_cutscene("cactus.txt", 21, 16);
	set_max_hp(12);
	set_hp(12);
	set_escape_chance(40);
}

// Creates garfield boss
Enemy_BossGarfield::Enemy_BossGarfield(){
	set_damage(100);
	set_char('G');
	set_fg(Color(255, 174, 0));
	set_ai(0);
	set_name("Boss Garfield");
	set_cutscene("garf.txt", 26, 20);
	set_max_hp(60);
	set_hp(60);
	turn = 0;
	set_escape_chance(0);
}

// Sets garfields battle turn
void Enemy_BossGarfield::battle_turn(Player* p){
	int wait = 11;

	// Checks if garfield is awake
	if(turn < wait){
		print_text("Garfield is asleep\n\n");
	}
	else if(turn == wait){
		print_text("Garfield wakes up\n\n");
	}else{
		print_text("Annoyed that you woke him up from his nap, Garfield gets serious\n");
		print_text(get_name() + " did " + to_string(get_damage()) + " damage\n\n");
		p->set_hp(p->get_hp() - get_damage());
	}

	turn++;
	wait_for_input();
}

// Creates the final boss
Enemy_BossBAF::Enemy_BossBAF(){
	set_damage(5);
	set_char('B');
	set_fg(Color(128, 4, 18));
	set_ai(0);
	set_name("Baphomet");
	set_cutscene("demon.txt", 41, 25);
	set_max_hp(1000);
	set_hp(1000);
	turn = 0;
	artifacts = 0;
	set_escape_chance(0);
}

// Sets the bosses battle turn
void Enemy_BossBAF::battle_turn(Player* p){
	int d = 0;
	switch(turn){													// Switch statement
	case 0:
		d = 5;
		print_text("So you made it this far.\n\n");
		break;
	case 1:
		d = 5;
		print_text("You almost escaped.\n\n");
		break;
	case 2:
		d = 5;
		print_text("You got so close just be squashed right at the end.\n");
		break;
	case 3:
		d = 5;
		print_text("You must be filled with dread right now.\n");
		break;
	case 4:
		d = 5;
		print_text("Knowing that you have no choise but to die here\n");
		break;
	case 5:
		d = 1000;
		print_text("I have grown bored of you, time to end this.\n\n");
		break;
	default:
		break;
	}
	turn++;
	if(d > 0){
		d = d - d * (p->get_protection() / 100.0);
		print_text(get_name() + " did " + to_string(d) + " damage\n\n");
		p->set_hp(p->get_hp() - d);
	}
	wait_for_input();
}

// Sets what happens when the boss dies
void Enemy_BossBAF::die(){
	Enemy::die();
	get_map()->add_flag("win");
}

// Sets the ability to use items on the boss
bool Enemy_BossBAF::use_item(Item i){
	if(artifacts == 0){
		if(i.is_equal(a1)){
			print_text("Used the artifact against " + get_name() + " doing 333 damage\n");
			set_hp(get_hp() - 333);

			artifacts++;
			return true;
		}
	}
	else if(artifacts == 1){
		if(i.is_equal(a2)){
			print_text("Used the artifact against " + get_name() + " doing 333 damage\n");
			set_hp(get_hp() - 333);

			artifacts++;
			return true;
		}
	}
	else if(artifacts == 2){
		if(i.is_equal(a3)){
			print_text("Used the artifact against " + get_name() + " doing 333 damage\n");
			set_hp(get_hp() - 333);

			return true;
		}
	}
	return false;
}

// Sets artifacts for the boss
void Enemy_BossBAF::set_a1(Item i){
	a1 = i;
}
void Enemy_BossBAF::set_a2(Item i){
	a2 = i;
}
void Enemy_BossBAF::set_a3(Item i){
	a3 = i;
}