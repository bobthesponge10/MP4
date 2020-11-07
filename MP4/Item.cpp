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
void Item::display(string s_){
	print_text(get_display(s_));
}
string Item::get_display(string s_){
	string s = "";
	s += name + "\n";
	s += s_ + desc + "\n";
	for(auto const& element : attributes){
		s += s_ + " -" + element.first + ": " + element.second + "\n";
	}
	return s;
}
bool Item::is_equal(Item a){
	if(name != a.get_name()){ return false; }

	if(desc != a.get_desc()){ return false; }

	for(auto const& element : attributes){
		if(a.get_attribute(element.first)!=element.second){ return false; }
	}

	return true;
}