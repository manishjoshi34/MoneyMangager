#include "commands.h"

class MainMenu : public Command
{
	public:
    	MainMenu(std::string name,
			std::string footer = "Exit") :
			Command(name, name, footer)
		{}


		void addCommands();

		void execute();

};