#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Structures.h"
#include "Item.h"


struct Color;
class Item;

void set_color(Color c, bool fg);
void reset_colors();
string reset();
string bg(Color c);
string fg(Color c);
void display_items(vector<Item> items, string title);
void print_text(string text);
void sleep(int milli);
void wait_for_input();