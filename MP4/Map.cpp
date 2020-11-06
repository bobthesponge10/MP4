//Map.cpp
//
#include "Map.h"

Map::Map(){
	// Sets basic values for an empty map
	w = 0; h = 0;
	d_x = 0; d_y = 0;
	player = NULL;
}
Map::Map(int w_, int h_){

	// Pushes an empty tile pointer for each location in the map
	for(int i = 0; i < w_ * h_; i++){
		tiles.push_back(&empty);
	}

	// Sets the maps width and height
	w = w_;
	h = h_;

	// Sets the empty to be solid
	empty.set_solid(true);

	// Sets default coords to 0, 0 and player pointer to NULL
	d_x = 0; d_y = 0;
	player = NULL;
}
Tile* Map::get_tile_p(int x, int y){
	
	// Checks if the requested coordinate is within the map
	// Returns a pointer to an empty cell if not
	if(x < 0 || x >= w){ return &empty; }
	if(y < 0 || y >= h){ return &empty; }

	// Gets pointer to requested tile and returns it
	Tile* p = tiles[y * w + x];
	return p;
}
void Map::set_tile(int x, int y, Tile* t){

	// Checks if the requested coordinate is within the map
	// Returns a pointer to an empty cell if not
	if(x < 0 || x >= w){ return; }
	if(y < 0 || y >= h){ return; }

	// Sets the tile in the map to the inputed tile
	tiles[y * w + x] = t;

	//Tile* old = get_tile_p(x, y);
	//delete old;
}
void Map::add_entity(Entity* e){

	// Adds the entity pointer to the vector
	entities.push_back(e);

	// Sets the entities map to the current map
	e->set_map(this);
}
int Map::find_entity(int x, int y){

	// Initializes e to be a pointer to an entity
	Entity* e = NULL;

	// Loops over every entity in the map
	for(int i = 0; i < entities.size(); i++){

		// Sets e to the pointer of the entity being checked
		e = entities[i];

		// Checks if the entity as at the given x and y values
		if(e->get_x() == x && e->get_y() == y){

			// Returns the index of the found entity
			return i;
		}
	}

	// Returns -1 if no entity was found
	return -1;
}
Entity* Map::get_entity(int i){
	if(i >= 0 && i < entities.size()){
		return entities[i];
	}
	return NULL;
}
int Map::get_w(){
	return w;
}
int Map::get_h(){
	return h;
}
bool Map::check_solid(int x, int y){

	// Returns true if coordinate is out of bounds
	if(x < 0 || x >= w){ return true; }
	if(y < 0 || y >= w){ return true; }

	// Gets tile at coordinate
	Tile* p = get_tile_p(x, y);

	if(find_entity(x, y) != -1){ return true; }

	// Returns if tile is solid
	return p->get_solid();
}
void Map::update(){

	// Loops over all the entities in the map
	for(int i = 0; i < entities.size(); i++){

		// Updates the entity
		entities[i]->update();
	}
}
void Map::add_flag(string flag){
	flags.push_back(flag);
}
string Map::get_flag(){
	if(flags.size() > 0){
		string out = flags[0];
		flags.erase(flags.begin());
		return out;
	}
	return "";
}
vector<string> Map::get_flags(){
	vector<string> out(flags);
	flags.clear();
	return out;
}
void Map::render(){

	// Loops over all the tiles in the map
	for(int i = 0; i < w * h; i++){

		// Renders the tile
		tiles[i]->render();

		// Checks if a full row has been rendered
		if((i + 1) % w == 0){

			// If so, print a new line
			cout << endl;
		}
	}
}
string Map::render(int x, int y, int w_, int h_, bool out){

	// Initializes variables
	int x_, y_, e;
	Tile* t = NULL;
	string s;

	// Loops over every row
	for(int i = 0; i < h_; i++){

		// Loops over every coord in row
		for(int j = 0; j < w_; j++){

			// Calculates the x and y coord of current tile
			x_ = x + j;
			y_ = y + i;

			// Checks if coordinate is in map
			if(x_ >= 0 && x_ < w && y_ >= 0 && y_ < h){

				// Checks if an entity is on this coordinate
				e = find_entity(x_, y_);

				// Gets tile for given coordinate
				t = tiles[x_ + y_ * (w)];

				// If entity is not on current coord
				if(e == -1){

					// Renders tile t to string
					s += t->r_render();
				} else{

					// Renders entity to string
					s += entities[e]->r_render(t);
				}
			}
		}

		// Adds new line to string for each row
		s += reset() + "\n";
	}

	// Prints string to screen if specified
	if(out){
		cout << s;
	}
	return s;
}

void Map::set_player(Entity* p){
	if(player==NULL){
		add_entity(p);
	}
	player = p;
	p->set_map(this);
}

void Map::set_default_coords(int x, int y){
	d_x = x;
	d_y = y;
}

void Map::move_player(){
	player->set_x(d_x);
	player->set_y(d_y);
}