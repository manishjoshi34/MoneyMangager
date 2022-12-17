#include "Commands/MainMenu.h"
#include "Commands/CreateAccount.h"
#include "Database.h"



void
MainMenu::execute()
{
    Database* database = Database::getDatabase();
    if(!database) {
        //TO DO add error
        return;
    }
    Command::run();
}

void 
MainMenu::addCommands()
{
    this->_subCommands.push_back(new CreateAccountCmd("Create Account"));
}