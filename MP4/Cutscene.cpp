// Cutscene.cpp

#include "Cutscene.h"

Cutscene::Cutscene(){

	// Sets default values for cutscene
	second = 0;
	width = 0;
	height = 0;
}
Cutscene::Cutscene(string f, int s, int w, int h) {		// File reading

	// Sets values for cutscene
	file = f;
	second = s;
	height = h;
	width = w;
	current = 0;

	// Opens file
	newfile.open(file, ios::in);

	string tp, temp;
	int count = 1;

	// Reads in frames of video
	while (!newfile.eof() && !newfile.fail()) {
		getline(newfile, tp);
		if (count % height == 0) {
			frames.push_back(temp);
			temp = "";
		}
		temp += tp + "\n";
		count++;
	}

	// Closes file
	newfile.close();
}
int Cutscene::get_width(){								// Definition of function with return
	return width;
}
int Cutscene::get_height(){
	return height;
}

void Cutscene::video() {								// Function that calls another function	

	// Loops over frames and displays them
	for (int i = 0; i < int(frames.size()); i++) {		// For loop
		displayFrame(i);
		sleep_for(milliseconds(second));
	}
	clear_screen();
}

void Cutscene::video(bool clear){						// Definition of function	

	// Loops over frames and displays them
	for(int i = 0; i < int(frames.size()); i++){
		displayFrame(i);
		sleep_for(milliseconds(second));
	}

	// Cleares screen if needed
	if(clear)
	clear_screen();
}

void Cutscene::next() {

	// Displays current frame and adds 1 to frame counter
	displayFrame(current++);
}

void Cutscene::displayFrame(int f) {					// Definition of function with parameters

	// Prints frame if index is valid
	if(f >= 0 && f < frames.size()){
		cout << frames[f];
		current = f;
	}
}
