/*
 * Author   J Meeks
 * Purpose  implementation file for inputs from user
*/

#include <stdio.h>
#include "adventureIn.h"
#include <limits>
#include <iostream>
#include "gameVisuals.h"

namespace adventureInputs{

//asks the user what movement they want to do on exploration
char askMovement(){
    //variables for valid selection and choice user enters
    int validSelection = 0;
    char choice;
    
    //loops until user enters valid choice
    while(validSelection == 0){
        //ask user for choice, and clears buffer after they enter it
        std::cout <<
        "\n╔════════════════════════════════════════════════╗"<<
        "\n║ What would you like to do on your exploration? ║" <<
        "\n╠════════════════════════════════════════════════╣" <<
        "\n║ w/a/s/d: Move [-5EP]                           ║" <<
        "\n║ f: Forage [-5EP]                               ║" <<
        "\n║ e: Eat [+15EP]                                 ║" <<
        "\n║ r: Return to camp [-10EP]                      ║" <<
        "\n╚════════════════════════════════════════════════╝" <<
        "\nSelection: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Tells user if their choice is invalid
        if(tolower(choice) != 'w' && tolower(choice) != 'a' && tolower(choice) != 's' && tolower(choice) != 'd' && tolower(choice) != 'r' && tolower(choice) != 'f' && tolower(choice) != 'e'){
            std::cout  << visuals::clearScreen()<< "Invalid command\n";
        } else {
            std::cout << visuals::clearScreen();
            return tolower(choice);
        }
    }
    std::cout << visuals::clearScreen();
    return 'r';
}

//asks user for first movement on exploration
char askFirstMovement(){
    int validSelection = 0;
    char choice;
    
    //loops until user enters valid choice
    while(validSelection == 0){
        //ask user for choice, and clears buffer after they enter it
        std::cout <<
        "╔═════════════════════════════════════╗"<<
        "\n║ Where would you like to move first? ║" <<
        "\n╠═════════════════════════════════════╣" <<
        "\n║ w: Up [-5EP]                        ║" <<
        "\n║ a: Left [-5EP]                      ║" <<
        "\n║ s: Down [-5EP]                      ║" <<
        "\n║ d: Right [-5EP]                     ║" <<
        "\n╚═════════════════════════════════════╝" <<
        "\nSelection: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Tells user if their choice is invalid
        if(tolower(choice) != 'w' && tolower(choice) != 'a' && tolower(choice) != 's' && tolower(choice) != 'd'){
            std::cout  << visuals::clearScreen()<< "Invalid command\n";
        } else {
            std::cout << visuals::clearScreen();
            return tolower(choice);
        }
    }
    std::cout << visuals::clearScreen();
    return 'r';
}

//asks user for daily activity option
char askDaily(){
    int validSelection = 0;
    char choice;
    
    //loops until user enters valid choice
    while(validSelection == 0){
        //ask user for choice, and clears buffer after they enter it
        std::cout <<
        "\n\n╔═════════════════════════╗"<<
        "\n║ What do you want to do? ║" <<
        "\n╠═════════════════════════╣" <<
        "\n║ e: explore              ║" <<
        "\n║ c: craft/cook           ║" <<
        "\n║ v: view map             ║" <<
        "\n║ i: view inventory       ║" <<
        "\n║ f: light fire [10 EP]   ║" <<
        "\n║ s: sleep                ║" <<
        "\n║ q: save and quit        ║" <<
        "\n╚═════════════════════════╝" <<
        "\nSelection: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Tells user if their choice is invalid
        if(tolower(choice) != 'e' && tolower(choice) != 'c' && tolower(choice) != 'i' && tolower(choice) != 'q' && tolower(choice) != 'v' && tolower(choice) != 's' && tolower(choice) != 'f'){
            std::cout  << visuals::clearScreen()<< "Invalid command\n";
        } else {
            std::cout << visuals::clearScreen();
            return tolower(choice);
        }
    }
    std::cout << visuals::clearScreen();
    return 'q';
}

//asks user what type of recipe they want to craft
char askCraftType(){
    //variables for valid selection and choice user enters
    int validSelection = 0;
    char choice;
    //loops until user enters valid choice
    while(validSelection == 0){
        //ask user for choice, and clears buffer after they enter it
        std::cout<<
        "\n╔═══════════════════════════════════╗"<<
        "\n║ What recipes do you want to view? ║" <<
        "\n╠═══════════════════════════════════╣" <<
        "\n║ i: escape items                   ║" <<
        "\n║ w: weapons                        ║" <<
        "\n║ c: camp comfort upgrades          ║" <<
        "\n║ p: camp protection upgrades       ║" <<
        "\n║ f: food                           ║" <<
        "\n║ q: exit crafting                  ║" <<
        "\n╚═══════════════════════════════════╝" <<
        "\nSelection: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Tells user if their choice is invalid
        if(tolower(choice) != 'w' && tolower(choice) != 'c' && tolower(choice) != 'q' && tolower(choice) != 'p' && tolower(choice) != 'f' && tolower(choice) != 'i'){
            std::cout  << visuals::clearScreen()<< "Invalid command\n";
        } else {
            std::cout << visuals::clearScreen();
            return tolower(choice);
        }
    }
    std::cout << visuals::clearScreen();
    return 'q';
}

//asks user how they want to react to an enemy
char askAttack(){
    //variables for valid selection and choice user enters
    int validSelection = 0;
    char choice;
    
    //loops until user enters valid choice
    while(validSelection == 0){
        //ask user for choice, and clears buffer after they enter it
        std::cout <<
        "\n\n╔═════════════════════════╗"<<
        "\n║ What do you want to do? ║" <<
        "\n╠═════════════════════════╣" <<
        "\n║ w: weak attack [5EP]    ║" <<
        "\n║ s: strong attack [10EP] ║" <<
        "\n║ r: run [20EP]           ║" <<
        "\n╚═════════════════════════╝" <<
        "\nSelection: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Tells user if their choice is invalid
        if(tolower(choice) != 'w' && tolower(choice) != 's' && tolower(choice) != 'r'){
            std::cout  << visuals::clearScreen()<< "Invalid command\n";
        } else {
            std::cout << visuals::clearScreen();
            return tolower(choice);
        }
    }
    std::cout << visuals::clearScreen();
    return 'q';
}

//Asks user what action they want to take at beginning of game
char startNew(){
    //variables for valid selection and choice user enters
    int validSelection = 0;
    char choice;
    
    //loops until user enters valid choice
    while(validSelection == 0){
        //ask user for choice, and clears buffer after they enter it
        std::cout << "\n╔════════════════════════════╗\n"
                    << "║ What would you like to do? ║" <<
                    "\n╠════════════════════════════╣" <<
                    "\n║ n: Start new game          ║" <<
                    "\n║ l: Load saved game         ║" <<
                    "\n║ q: Quit                    ║" <<
                    "\n╚════════════════════════════╝" <<
                    "\nSelection: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Tells user if their choice is invalid
        if(tolower(choice) != 'n' && tolower(choice) != 'l' && tolower(choice) != 'q'){
            std::cout << visuals::clearScreen() << "Invalid command\n";
        } else {
            std::cout << visuals::clearScreen();
            return tolower(choice);
        }
    }
    std::cout << visuals::clearScreen();
    return 'q';
}

//gets valid integer input from the user
int getInt(int max){
    //variables for valid selection and the number chosen by the user
    int validSelection = 0, number;
    //loops until a valid selection is chosen
    while(validSelection == 0){
        //asks for integer from user, and checks to make sure a number is entered, then clears buffer
        if(max > 9){
            std::cout
            <<  "╔════════════════════════════╗" <<
                "\n║ What would you like to do? ║" <<
                "\n╠════════════════════════════╣" <<
                "\n║ 0: Go back                 ║" <<
                "\n║ 1-" << max << ": Craft item           ║" <<
                "\n╚════════════════════════════╝" <<
                        "\nSelection: ";
        } else {
            std::cout
            <<  "╔════════════════════════════╗" <<
                "\n║ What would you like to do? ║" <<
                "\n╠════════════════════════════╣" <<
                "\n║ 0: Go back                 ║" <<
                "\n║ 1-" << max << ": Craft item            ║" <<
                "\n╚════════════════════════════╝" <<
                        "\nSelection: ";
        }
        if(!(std::cin >> number)){
            number = -1;
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Tells user if their number is invalid, or returns valid number
        if(number < 0 || number > max){
            std::cout  << visuals::clearScreen()<< "\nInvalid selection\n";
        } else {
            std::cout << visuals::clearScreen();
            return number;
        }
    }
    std::cout << visuals::clearScreen();
    return 0;
}
}
