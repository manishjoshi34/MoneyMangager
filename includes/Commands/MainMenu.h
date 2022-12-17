#include "commands.h"

class MainMenu : public Command
{
	public:
    	MainMenu(std::string name) :
			Command(name, name, "Exit")
		{}


		void addCommands();

		void execute();

};