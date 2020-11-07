#pragma once
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>
#include <string>

#include "Functions.h"
using namespace std;
using namespace chrono;
using namespace this_thread;
class Cutscene {
	public:
		Cutscene();
		Cutscene(string f, int s, int h, int w);
		int get_width();
		int get_height();
		void video();
		void video(bool clear);
		void next();
		void displayFrame(int f);
	private:
		string file;
		vector<string> frames;
		fstream newfile;
		int second, height, width, current;
};
