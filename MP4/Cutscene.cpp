#include "Cutscene.h"

Cutscene::Cutscene(){
	second = 0;
	width = 0;
	height = 0;
}
Cutscene::Cutscene(string f, int s, int w, int h) {		// File reading
	file = f;
	second = s;
	height = h;
	width = w;
	current = 0;
	newfile.open(file, ios::in);
	string tp, temp;
	int count = 1;
	while (!newfile.eof() && !newfile.fail()) {
		getline(newfile, tp);
		if (count % height == 0) {
			frames.push_back(temp);
			temp = "";
		}
		temp += tp + "\n";
		count++;
	}
	newfile.close();
}
int Cutscene::get_width(){								// Definition of function with return
	return width;
}
int Cutscene::get_height(){
	return height;
}

void Cutscene::video() {								// Function that calls another function		
	for (int i = 0; i < int(frames.size()); i++) {		// For loop
		displayFrame(i);
		sleep_for(milliseconds(second));
	}
	clear_screen();
}

void Cutscene::video(bool clear){						// Definition of function	
	for(int i = 0; i < int(frames.size()); i++){
		displayFrame(i);
		sleep_for(milliseconds(second));
	}
	if(clear)
	clear_screen();
}

void Cutscene::next() {
	displayFrame(current++);
}

void Cutscene::displayFrame(int f) {					// Definition of function with parameters
	if(f >= 0 && f < frames.size()){
		cout << frames[f];
		current = f;
	}
}
