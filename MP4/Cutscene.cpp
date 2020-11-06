#include "Cutscene.h"

Cutscene::Cutscene(string f, int s, int h) {
	file = f;
	second = s;
	height = h;
	current = 0;
	newfile.open(file, ios::in);
	string tp, temp;
	int count;
	while (!newfile.eof()) {
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

void Cutscene::video() {
	for (int i = 0; i < int(frames.size()); i++) {
		displayFrame(i);
		sleep_for(milliseconds(second));
	}
	system("CLS");
}

void Cutscene::next() {
	displayFrame(current++);
}

void Cutscene::displayFrame(int f) {
	cout << frames[f];
	current = f;
}
