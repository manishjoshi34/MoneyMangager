#pragma once

#include "commands.h"

class Database;

class CreateAccountCmd : public Command
{
        public:
            CreateAccountCmd(std::string name) :
                Command(name,"Create Account","Return")
                {}
           void addCommands() ; 
           void execute() ;
              
};