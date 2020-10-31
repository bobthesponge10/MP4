#include "Item.h"

Item::Item(){}

void Item::set_name(string name_){
	name = name_;
}
string Item::get_name(){
	return name;
}
void Item::set_desc(string desc_){
	desc = desc_;
}
string Item::get_desc(){
	return desc;
}
void Item::add_attribute(string key, string value){
	attributes[key] = value;
}
string Item::get_attribute(string key){
	if(attributes.count(key) > 0){
		return attributes[key];
	}
	return "";
}
void Item::display(){
	string s = "";
	s+= name + "\n";
	s+= desc + "\n";
	for(auto const& element : attributes){
		s+= element.first + ": " + element.second + "\n";
	}
	print_text(s);
}
string Item::get_display(){
	string s = "";
	s += name + "\n";
	s += desc + "\n";
	for(auto const& element : attributes){
		s += element.first + ": " + element.second + "\n";
	}
	return s;
}