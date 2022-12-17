#include "Commands/commands.h"


void
Command::Menu()
{
    std::cout << "\n\t\t" << _header << "\t\t\n";
	std::cout << "........................................\n";
	int index = 1;
	for (auto command : _subCommands) {
		std::cout << index << ")\t\t" << command->_name << std::endl;
		index++;
	}
	std::cout << index << ")\t\t" << _footer << "\n\n";

}

void 
Command::run() {
	this->addCommands();
	Menu();
	while (true) {
		int userSlelection;
		std::cin >> userSlelection;
		if (userSlelection > _subCommands.size()) return;
		Command* current = _subCommands[userSlelection - 1];
		current->execute();
		Menu();
	}
}

Command::Command(std::string name,
	std::string header,
	std::string footer) :
	_name(name),
	_header(header),
	_footer(footer)
{
	//_database = Database::getDataBase();
}


