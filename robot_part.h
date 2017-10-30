#ifndef __ROBOT_PART_H
#define __ROBOT_PART_H

#include <iostream>
#include <string>

using namespace std;

class Robot_part {
	protected:
		string name;
		int model_number;
		double cost;
		string description;
		string image_filename;
	public:
		Robot_part(	string _name, 
					int _model_number, 
					double _cost, 
					string _description, 
					string _image_filename) : 
					
					name(_name),
					model_number(_model_number),
					cost(_cost),
					description(_description),
					image_filename(_image_filename) { }
		friend ostream& operator<<(ostream& os, const Robot_part& robot_part);
};
#endif
