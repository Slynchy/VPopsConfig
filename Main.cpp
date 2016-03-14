/*
	VPopsConfig
	 A tool for compiling/decompiling __sce_menuinfo for 
	 the PSVita PSOne emulator

	"If someone could show me how to do software licenses,
	that'd be amazeballs."

	By Sam Lynch
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>

#include "./include/Files.h"

const char nil = 0;

std::string flagStr[2] = { "-c", "-d" };

enum FLAGS
{
	COMPILE = 0x00,
	DECOMPILE = 0x01
};

int main(int argc, char* argv[])
{
	std::cout << "\nVPopsConfig - For decompiling/recompiling __sce_menuinfo into readable format\nBy Sam Lynch\n\n";
	FLAGS MODE;
	PopsConfiguration* OUTPUT = new PopsConfiguration;
	std::string filename;

	// Check parameter was passed
    if (argc < 3) {
		std::cout << "Usage: \n " << argv[0] << " -c [decompiled __sce_menuinfo]\n " << argv[0] << " -d __sce_menuinfo\n";
		delete OUTPUT;
		return -1;
    }
	else
	{
		filename = argv[2];
		if(argv[1] == flagStr[0])
		{
			MODE = FLAGS(0);
		}
		else
		{
			MODE = FLAGS(1);
		};
	};

	std::fstream file;
	uint32_t len = 0;
	std::string dummyLine;
	int button_assignment[POPS_BUTTON_ASSIGN_NUMBERS]; 
	int front_touch_assignment[POPS_TOUCH_ASSIGN_NUMBERS]; 
	int back_touch_assignment[POPS_TOUCH_ASSIGN_NUMBERS]; 

	switch(MODE)
	{
		case DECOMPILE:
			file.open(filename, std::ifstream::binary | std::ifstream::in);
			if(!file)
			{
				std::cerr << "Failed to open " << filename << "! Shutting down...";
				return -1;
			};

			// Get length
			file.seekg (0, file.end);
			len = uint32_t(file.tellg());
			file.seekg (0, file.beg);
			
			file.read((char*)&OUTPUT->magic_1,4);
			file.read((char*)&OUTPUT->magic_2,4);
			file.read((char*)&OUTPUT->version,4);
			file.read((char*)&OUTPUT->unk,4);
			file.read((char*)&OUTPUT->disc_load_speed,4);
			file.read((char*)&OUTPUT->volume_level,4);
			file.read((char*)&OUTPUT->controller_number,4);
			file.read((char*)&OUTPUT->controller_mode,2);
			file.read((char*)&OUTPUT->buttons_assignment_mode,2);
			file.read((char*)&OUTPUT->use_bilinear_filtering,4);
			file.read((char*)&OUTPUT->screen_mode,4);
			file.read((char*)&OUTPUT->custom_screen,sizeof(OUTPUT->custom_screen));
			file.read((char*)&OUTPUT->button_assignment,sizeof(OUTPUT->button_assignment));
			file.read((char*)&OUTPUT->front_touch_assignment,sizeof(OUTPUT->front_touch_assignment));
			file.read((char*)&OUTPUT->back_touch_assignment,sizeof(OUTPUT->back_touch_assignment));
			file.close();

			file.open (filename+".modified", std::fstream::binary | std::fstream::out);
			file << "magic_1: " << std::hex << OUTPUT->magic_1 << '\n';
			file << "magic_2: " << std::hex << OUTPUT->magic_2 << '\n';
			file << "version: " << std::dec << OUTPUT->version << '\n';
			file << "unk: " << OUTPUT->unk << '\n';
			file << "disc_load_speed: " << OUTPUT->disc_load_speed << '\n';
			file << "volume_level: " << OUTPUT->volume_level << '\n';
			file << "controller_number: " << OUTPUT->controller_number << '\n';
			file << "controller_mode: " << OUTPUT->controller_mode << '\n';
			file << "buttons_assignment_mode: " << (short int)OUTPUT->buttons_assignment_mode << '\n';
			file << "use_bilinear_filtering: " << OUTPUT->use_bilinear_filtering << '\n';
			file << "screen_mode: " << OUTPUT->screen_mode << '\n';
			file << "custom_screen_X: " << OUTPUT->custom_screen.x << '\n';
			file << "custom_screen_Y: " << OUTPUT->custom_screen.y << '\n';
			file << "custom_screen_W: " << OUTPUT->custom_screen.width << '\n';
			file << "custom_screen_H: " << OUTPUT->custom_screen.height << '\n';
			file << "POPS_BUTTON_ASSIGN_UP: " << (int)OUTPUT->button_assignment[0] << '\n';
			file << "POPS_BUTTON_ASSIGN_DOWN: " << (int)OUTPUT->button_assignment[1] << '\n';
			file << "POPS_BUTTON_ASSIGN_LEFT: " << (int)OUTPUT->button_assignment[2] << '\n';
			file << "POPS_BUTTON_ASSIGN_RIGHT: " << (int)OUTPUT->button_assignment[3] << '\n';
			file << "POPS_BUTTON_ASSIGN_TRIANGLE: " << (int)OUTPUT->button_assignment[4] << '\n';
			file << "POPS_BUTTON_ASSIGN_CIRCLE: " << (int)OUTPUT->button_assignment[5] << '\n';
			file << "POPS_BUTTON_ASSIGN_CROSS: " << (int)OUTPUT->button_assignment[6] << '\n';
			file << "POPS_BUTTON_ASSIGN_SQUARE: " << (int)OUTPUT->button_assignment[7] << '\n';
			file << "POPS_BUTTON_ASSIGN_L: " << (int)OUTPUT->button_assignment[8] << '\n';
			file << "POPS_BUTTON_ASSIGN_R: " << (int)OUTPUT->button_assignment[9] << '\n';
			file << "POPS_BUTTON_ASSIGN_L_UP: " << (int)OUTPUT->button_assignment[10] << '\n';
			file << "POPS_BUTTON_ASSIGN_L_DOWN: " << (int)OUTPUT->button_assignment[11] << '\n';
			file << "POPS_BUTTON_ASSIGN_L_LEFT: " << (int)OUTPUT->button_assignment[12] << '\n';
			file << "POPS_BUTTON_ASSIGN_L_RIGHT: " << (int)OUTPUT->button_assignment[13] << '\n';
			file << "POPS_BUTTON_ASSIGN_R_UP: " << (int)OUTPUT->button_assignment[14] << '\n';
			file << "POPS_BUTTON_ASSIGN_R_DOWN: " << (int)OUTPUT->button_assignment[15] << '\n';
			file << "POPS_BUTTON_ASSIGN_R_LEFT: " << (int)OUTPUT->button_assignment[16] << '\n';
			file << "POPS_BUTTON_ASSIGN_R_RIGHT: " << (int)OUTPUT->button_assignment[17] << '\n';
			file << "FRONT_POPS_TOUCH_ASSIGN_TOP_LEFT: " << (int)OUTPUT->front_touch_assignment[0] << '\n';
			file << "FRONT_POPS_TOUCH_ASSIGN_TOP_RIGHT: " << (int)OUTPUT->front_touch_assignment[1] << '\n';
			file << "FRONT_POPS_TOUCH_ASSIGN_BOTTOM_LEFT: " << (int)OUTPUT->front_touch_assignment[2] << '\n';
			file << "FRONT_POPS_TOUCH_ASSIGN_BOTTOM_RIGHT: " << (int)OUTPUT->front_touch_assignment[3] << '\n';
			file << "BACK_POPS_TOUCH_ASSIGN_TOP_LEFT: " << (int)OUTPUT->back_touch_assignment[0] << '\n';
			file << "BACK_POPS_TOUCH_ASSIGN_TOP_RIGHT: " << (int)OUTPUT->back_touch_assignment[1] << '\n';
			file << "BACK_POPS_TOUCH_ASSIGN_BOTTOM_LEFT: " << (int)OUTPUT->back_touch_assignment[2] << '\n';
			file << "BACK_POPS_TOUCH_ASSIGN_BOTTOM_RIGHT: " << (int)OUTPUT->back_touch_assignment[3] << '\n';
			file.close();

			break;
		case COMPILE:
			file.open (filename, std::fstream::in);
			if(!file)
			{
				std::cerr << "Failed to open " << filename << "! Shutting down...";
				return -1;
			};
			
			file >> dummyLine;
			file >> std::hex >> OUTPUT->magic_1;
			file >> dummyLine;
			file >> std::hex >> OUTPUT->magic_2;
			file >> dummyLine;
			file >> OUTPUT->version;
			file >> dummyLine;
			file >> std::hex >> OUTPUT->unk;
			file >> std::dec >> dummyLine;
			file >> OUTPUT->disc_load_speed;
			file >> dummyLine;
			file >> OUTPUT->volume_level;
			file >> dummyLine;
			file >> OUTPUT->controller_number;
			file >> dummyLine;
			file >> OUTPUT->controller_mode;
			file >> dummyLine;
			file >> OUTPUT->buttons_assignment_mode;
			file >> dummyLine;
			file >> OUTPUT->use_bilinear_filtering;
			file >> dummyLine;
			file >> OUTPUT->screen_mode;
			file >> dummyLine;
			file >> OUTPUT->custom_screen.x;
			file >> dummyLine;
			file >> OUTPUT->custom_screen.y;
			file >> dummyLine;
			file >> OUTPUT->custom_screen.width;
			file >> dummyLine;
			file >> OUTPUT->custom_screen.height;

			for(int i = 0; i < POPS_BUTTON_ASSIGN_NUMBERS; i++)
			{
				file >> dummyLine;
				file >> button_assignment[i];
				OUTPUT->button_assignment[i] = button_assignment[i];
			};

			for(int i = 0; i < POPS_TOUCH_ASSIGN_NUMBERS; i++)
			{
				file >> dummyLine;
				file >> front_touch_assignment[i];
				OUTPUT->front_touch_assignment[i] = front_touch_assignment[i];
			};

			for(int i = 0; i < POPS_TOUCH_ASSIGN_NUMBERS; i++)
			{
				file >> dummyLine;
				file >> back_touch_assignment[i];
				OUTPUT->back_touch_assignment[i] = back_touch_assignment[i];
			};

			file.close();

			file.open(filename + ".compiled", std::fstream::out | std::fstream::binary);

			file.write((char*)&OUTPUT->magic_1,sizeof(OUTPUT->magic_1));
			file.write((char*)&OUTPUT->magic_2,sizeof(OUTPUT->magic_2));
			file.write((char*)&OUTPUT->version,sizeof(OUTPUT->version));
			file.write((char*)&OUTPUT->unk,sizeof(OUTPUT->unk));
			file.write((char*)&OUTPUT->disc_load_speed,sizeof(OUTPUT->disc_load_speed));
			file.write((char*)&OUTPUT->volume_level,sizeof(OUTPUT->volume_level));
			file.write((char*)&OUTPUT->controller_number,sizeof(OUTPUT->controller_number));
			file.write((char*)&OUTPUT->controller_mode,2);
			file.write((char*)&OUTPUT->buttons_assignment_mode,2);
			file.write((char*)&OUTPUT->use_bilinear_filtering,sizeof(OUTPUT->use_bilinear_filtering));
			file.write((char*)&OUTPUT->screen_mode,sizeof(OUTPUT->screen_mode));
			file.write((char*)&OUTPUT->custom_screen.x,sizeof(OUTPUT->custom_screen.x));
			file.write((char*)&OUTPUT->custom_screen.y,sizeof(OUTPUT->custom_screen.y));
			file.write((char*)&OUTPUT->custom_screen.width,sizeof(OUTPUT->custom_screen.width));
			file.write((char*)&OUTPUT->custom_screen.height,sizeof(OUTPUT->custom_screen.height));
			for(int i = 0; i < POPS_BUTTON_ASSIGN_NUMBERS; i++)
			{
				file.write((char*)&OUTPUT->button_assignment[i],sizeof(OUTPUT->button_assignment[i]));
			};
			for(int i = 0; i < POPS_TOUCH_ASSIGN_NUMBERS; i++)
			{
				file.write((char*)&OUTPUT->front_touch_assignment[i],sizeof(OUTPUT->front_touch_assignment[i]));
			};
			for(int i = 0; i < POPS_TOUCH_ASSIGN_NUMBERS; i++)
			{
				file.write((char*)&OUTPUT->back_touch_assignment[i],sizeof(OUTPUT->back_touch_assignment[i]));
			};

			//Padding to 1024bytes 
			while(file.tellg() < 1024)
			{
				file.write((char*)&nil,1);
			};

			file.close();
			break;
	};

	delete OUTPUT;
	return 0;
};