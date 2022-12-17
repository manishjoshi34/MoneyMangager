#pragma once

#include <iostream>
#include <string>
#include <vector>

class Command {
    private:
        std::string             _name;
        std::string             _header;
	    std::string             _footer;
        std::vector<Command*>   _subCommands;


    public:
        Command(std::string name,
		std::string header,
		std::string footer);

	    virtual ~Command() {}

        void Menu();
	    void run();

        void setHeader(std::string header) { _header = header; }
	    void setFooter(std::string footer) { _footer = footer; }

	    virtual void execute() = 0;
	    virtual void addCommands() = 0;

};





