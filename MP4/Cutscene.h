#pragma once
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
using namespace this_thread;
class Cutscene {
	public:
		Cutscene(string f, int s, int h);
		void video();
		void next();
		void displayFrame(int f);
	private:
		string file;
		vector<string> frames;
		fstream newfile;
		int second, height, current;
};
