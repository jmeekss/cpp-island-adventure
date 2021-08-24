/*
 * Author:      J Meeks
 * Purpose:     This program allows the user to play a survival adventure game with the goal
 *              of escaping an island in 100 days or less
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <array>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>

//Class Header Files
#include "playerClasses.h"
#include "enemyClasses.h"
#include "recipeClasses.h"
#include "mapClasses.h"

//Function Header Files
#include "adventureIn.h"
#include "recipeBook.h"
#include "enemyBattle.h"
#include "gameVisuals.h"

using namespace std;

//file names for IO
string playerFileName = "player.txt";
string mapFileName = "map.txt";

//Functions for daily activities
int exploreOption(playerClasses::player& p, mapClasses::islandMap& map);
void craftOption(playerClasses::player& p, array<recipeClasses::craftingRecipe, 63>craftables, array<recipeClasses::cookingRecipe, 63>cookables);
void fireOption(playerClasses::player& p);
void mapOption(playerClasses::player& p, mapClasses::islandMap& map);
void inventoryOption(playerClasses::player& p);
void sleepOption(playerClasses::player& p);
void quitOption(playerClasses::player& p, mapClasses::islandMap& map);

int main() {
    //default variables for creating player and map
    string name = "Player";
    int day = 0, h = 100, e = 100;
    array<int, 63> inv = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};
    array<int, 49> blankMap = {0};
    array<int, 49> blankMapExplore = {0};
    char choice;
    
    //inititates the recpies for craftable and cookable items
    array<recipeClasses::craftingRecipe, 63> craftables;
    recipeBook::set_craftables(craftables);
    array<recipeClasses::cookingRecipe, 63> cookables;
    recipeBook::set_cookables(cookables);
    
    //Welcomes the player to the game
    cout << visuals::clearScreen();
    visuals::welcome();
    
    //Asks the player if they want to load data or start a new game
    char startOption = adventureInputs::startNew();
    if(startOption == 'n'){ //gets name and plays intro sequence if starting a new game
        cout << "Please enter your name: ";
        cin >> name;
        visuals::introSequence();
    } else if(startOption == 'l'){ //loads data from file if player deicdes to resume game
        string line;
        //open file
        ifstream playerFile;
        playerFile.open(playerFileName);
        
        if(playerFile){
            
            //go through file line by line, storing info in respective variables
            if(getline(playerFile, line)){
                istringstream ss(line);
                getline(ss, name, '\t');
                ss >> day;
                ss >> h;
                ss >> e;
            }
            //store player inventory data
            while(getline(playerFile, line)){
                
                istringstream ss(line);
                for(unsigned int i = 0; i < 63; i++){
                    ss >> inv[i];
                }
            }
            playerFile.close();
            
            //loads map file data
            ifstream mapFile;
            mapFile.open(mapFileName);
            
            if(mapFile){
                getline(mapFile, line);
                
                istringstream ss1(line);
                for(unsigned int i = 0; i < 49; i++){
                    ss1 >> blankMap[i];
                }
                getline(mapFile, line);
                
                istringstream ss2(line);
                for(unsigned int i = 0; i < 49; i++){
                    ss2 >> blankMapExplore[i];
                }
            }
            mapFile.close();
        }
        cout << "× Game Data Successfully Loaded In ×\n";
    } else {
        cout << "Game Data Loading Error: Starting new game";
    }
    
    //creates the player and island map
    mapClasses::islandMap map = mapClasses::mapIO::create_map(blankMap, blankMapExplore, startOption);
    playerClasses::player p = playerClasses::playerIO::create_player(name, day, h, e, inv);
    
    //loop for main body of program
    while(p.get_day() <= 100 && p.get_quantity(40) == 0){
        //updates stats and resets player's location at the start of every day
        p.update_stats();
        p.set_location(24);
        
        //displays player stats, and asks for daily activity
        cout << p;
        choice = adventureInputs::askDaily();
        cout << visuals::clearScreen();
        
        //reacts accordingly to daily activity
        if(choice == 'e'){
            int e = exploreOption(p, map);
            if(e > 0){
                continue;
            }
        } else if(choice == 'c') {//User chooses to craft
            craftOption(p, craftables, cookables);
            continue;
        } else if(choice == 'v'){ //View Map
            mapOption(p, map);
            continue;
        } else if(choice == 'q'){ //Save and Quit
            quitOption(p, map);
            cout << visuals::clearScreen() << "Your game data has been saved. Thank you for playing.\n";
            return 0;
        } else if(choice == 'f'){ //Light Fire
            fireOption(p);
            continue;
        } else if(choice == 'i'){//view Inventory
            inventoryOption(p);
            continue;
        } else if(choice == 's'){//sleep
            sleepOption(p);
            continue;
        }
        
        //if player makes it through day alive, sleeps
        if(p.next_day() == 1){
            cout << visuals::clearScreen() << "\nYou slept soundly and safely through the night and regained health and energy\n";
        } else {
            cout << visuals::clearScreen() << "\nAn animal attacked your camp in the night, so you didn't regain any health or energy\n";
        }
    }
    
    //once main program loop has ended, displays corresponding game ending dependg if player won or lost
    if(p.get_day() > 100){
        visuals::lose();
    } else {
        visuals::win();
    }
    
    //returns 0 to indicate normal program exit
    return 0;
}

//function for if the user chooses to explore
int exploreOption(playerClasses::player& p, mapClasses::islandMap& map){
    //displays minimap and player stats after each move
    cout << "\n" << map.get_minimap(p.get_location()) << "\nHealth: " << p.display_health() << " " << p.get_health() << "/100\n" <<
    "Energy: " << p.display_energy() << " " << p.get_energy() << "/100\n\n";
    
    //asks for the wanted action and reacts accordingly
    char move = adventureInputs::askFirstMovement();
    while(move != 'r'){
        if(move == 'w' || move == 'a' || move == 's' || move == 'd'){//Moves player location on the map
            string ogSquare = map.get_square(p.get_location()).get_squareName();
            if(p.move_location(move)){
                p.lose_energy(5);
                if(p.get_energy() == 0 || p.get_health() == 0) break; //if player runs out of energy, exits loop
                
                //gets and updates the newly visited mapsquare
                mapClasses::mapSquare curSquare = map.get_square(p.get_location());
                bool visited = curSquare.get_explored();
                map.get_square(p.get_location()).set_explored(true);
                curSquare.set_explored(true);
                
                //gets whether or not player disturbs an enemy
                int disturbed = curSquare.disturb();
                
                //creates the exploration message for the player, including if it's a new square, and if there's an enemy
                string message = visuals::clearScreen() + "You moved from the " + ogSquare;
                if(!visited){
                    message = message + " and discovered a new " + curSquare.get_squareName();
                } else {
                    message = message + " to a " + curSquare.get_squareName();
                }
                enemyClasses::Enemy curEnemy = curSquare.get_enemy(2);
                if(disturbed == 2){
                    message = message + " but got attacked by a strong " + curSquare.get_enemy(2).get_enemy_type();
                    curEnemy = curSquare.get_enemy(2);
                } else if(disturbed == 1){
                    message = message + " but got attacked by a weak " + curSquare.get_enemy(1).get_enemy_type();
                    curEnemy = curSquare.get_enemy(1);
                }
                message += "\n";
                cout << message;
                
                //if an enemy was disturbed, battles with enemy
                if(disturbed > 0){
                    enemyBattles::enemyBattle(curEnemy, p);
                    if(p.get_energy() == 0 || p.get_health() == 0) break;
                }
                //displays minimap and player stats
                cout << "\n" << map.get_minimap(p.get_location()) << "\nHealth: " << p.display_health() << " " << p.get_health() << "/100\n" <<
                "Energy: " << p.display_energy() << " " << p.get_energy() << "/100\n";
            } else { //if player can't move to a square, notifies them and displays stats
                cout << visuals::clearScreen() << "You can't move there!\n";
                cout << "Health: " << p.display_health() << " " << p.get_health() << "/100\n" <<
                "Energy: " << p.display_energy() << " " << p.get_energy() << "/100\n\n";
            }
        } else if(move == 'e'){ //eats
            cout << p.eat();
        } else if(move == 'f'){ //forages square
            p.lose_energy(5);
            
            //gets a random number of item that the user found from foraging
            mapClasses::mapSquare curSquare = map.get_square(p.get_location());
            int itemFound = curSquare.forage();
            if(p.get_energy() == 0 || p.get_health() == 0) break;
            
            srand(static_cast<unsigned int>(time(0)));
            int numItems = rand() % 3 + 1;
            
            //notifies user of what they found and adds it to inventory
            cout << visuals::clearScreen() << "You foraged the " + curSquare.get_squareName() + " and found ×" + to_string(numItems) + " " +  curSquare.get_resources(itemFound) + "\n";
            for(int i = 0; i < numItems; i++){
                p.add_item(itemFound + (curSquare.get_squareNameID()) * 5);
            }
            //outputs minimap and stats
            cout << "\n" << map.get_minimap(p.get_location()) << "\nHealth: " << p.display_health() << " " << p.get_health() << "/100\n" <<
            "Energy: " << p.display_energy() << " " << p.get_energy() << "/100\n";
        } else { //return the player to the camp
            p.lose_energy(10);
            if(p.get_energy() == 0 || p.get_health() == 0) break;
            p.set_location(24);
            break;
        }
        
        //continues asking for movement until theyre out of health
        if(p.get_energy() == 0 || p.get_health() == 0) break;
        move = adventureInputs::askMovement();
    }
    //if player dies, adjusts stats accordingly, and notifies them
    if(p.get_health() == 0){
        p.set_day(p.get_day() + 5);
        p.set_health(25);
        p.set_energy(25);
        string lostItems = p.lose_items(10);
        cout << "\nYou ran out of health and blacked out, only to awake 10 days later missing many of your items, and still not feeling fully refreshed\n";
        return 2;
    }
    
    //if player runs out of energy, adjusts stats, and notifies them
    if(p.get_energy() == 0){
        p.set_day(p.get_day() + 5);
        p.set_health(75);
        p.set_energy(50);
        p.set_location(24);
        string lostItems = p.lose_items(5);
        cout << "\nYou ran out of energy and passed out, only to awake 5 days later missing some of your items, still not fully energized\n";
        return 1;
    }
    return 0;
}

//function for if user crafts
void craftOption(playerClasses::player& p, array<recipeClasses::craftingRecipe, 63>craftables, array<recipeClasses::cookingRecipe, 63>cookables){
    string list = visuals::clearScreen();
    char option = ' ';
    while(option != 'q'){ //loop for what the user chooses to view/craft
        
        //clears screen and asks user what they want to view
        list = visuals::clearScreen();
        option = adventureInputs::askCraftType();
        if(option == 'q'){
            break;
        }
        int ind = 1, craftChoice = 0;
        
        //displays all recipes corresponding to type user specified
        list += "══════════════════════════════════════════════════════════════════════════════════════════════════\n\n";
        if(option == 'i'){
            for(unsigned int i = 30; i < 41; i++, ind++){
                list = list + to_string(ind) + ") " + craftables[i].get_recipe(p) + "\n";
            }
        } else if(option == 'w'){
            for(unsigned int i = 42; i < 46; i++, ind++){
                list = list + to_string(ind) + ") " + craftables[i].get_recipe(p) + "\n";
            }
        } else if(option == 'c'){
            for(unsigned int i = 47; i < 51; i++, ind++){
                list = list + to_string(ind) + ") " + craftables[i].get_recipe(p) + "\n";
            }
        } else if(option == 'p'){
            for(unsigned int i = 52; i < 56; i++, ind++){
                list = list + to_string(ind) + ") " + craftables[i].get_recipe(p) + "\n";
            }
        } else if(option == 'f'){
            for(unsigned int i = 58; i < 63; i++, ind++){
                list = list + to_string(ind) + ") " + cookables[i].get_recipe(p) + "\n";
            }
        }
        list += "══════════════════════════════════════════════════════════════════════════════════════════════════\n\n";
        cout << setw(20) << left << list;
        
        //asks the user for what recipe they want to craft, and either crafts it, or tells them they can't craft it
        if(option == 'i'){
            craftChoice = adventureInputs::getInt(11);
            if(craftChoice == 0){
                continue;
            } else {
                if(craftables[29+craftChoice].craft_item(p)){
                    cout << visuals::clearScreen() << "You crafted ×1 " << p.get_item_name(29+craftChoice) << "\n";
                } else {
                    cout << visuals::clearScreen() << p.get_item_name(29+craftChoice) << " could not be crafted (Insufficient Materials)\n";
                }
            }
        } else if(option == 'w'){
            craftChoice = adventureInputs::getInt(4);
            if(craftChoice == 0){
                continue;
            } else {
                if(craftables[41+craftChoice].craft_item(p)){
                    cout << visuals::clearScreen() << "You crafted ×1 " << p.get_item_name(41+craftChoice) << "\n\n";
                } else {
                    cout << visuals::clearScreen() << p.get_item_name(42+craftChoice) << " could not be crafted (Insufficient Materials)\n";
                }
            }
        } else if(option == 'c'){
            craftChoice = adventureInputs::getInt(4);
            if(craftChoice == 0){
                continue;
            } else {
                if(craftables[46+craftChoice].craft_item(p)){
                    cout << visuals::clearScreen() << "You crafted ×1 " << p.get_item_name(46+craftChoice) << "\n";
                } else {
                    cout << visuals::clearScreen() << p.get_item_name(46+craftChoice) << " could not be crafted (Insufficient Materials)\n";
                }
            }
        } else if(option == 'p'){
            craftChoice = adventureInputs::getInt(4);
            if(craftChoice == 0){
                continue;
            } else {
                if(craftables[51+craftChoice].craft_item(p)){
                    cout << visuals::clearScreen() << "You crafted ×1 " << p.get_item_name(51+craftChoice) << "\n";
                } else {
                    cout << visuals::clearScreen() << p.get_item_name(51+craftChoice) << " could not be crafted (Insufficient Materials)\n";
                }
            }
        } else if(option == 'f'){
            craftChoice = adventureInputs::getInt(5);
            if(craftChoice == 0){
                continue;
            } else {
                if(cookables[57+craftChoice].craft_item(p)){
                    cout << visuals::clearScreen() << "You crafted ×1 " << p.get_item_name(57+craftChoice) << "\n";
                } else {
                    cout << visuals::clearScreen() << p.get_item_name(57+craftChoice) << " could not be crafted (Insufficient Materials)\n";
                }
            }
        }
    }
    return;
}

//displays users inventory
void inventoryOption(playerClasses::player& p){
    cout << p.get_inventory();
}

//lights campfire, uses energy, or tells player fire is already lit
void fireOption(playerClasses::player& p){
    if(p.get_quantity(56) > 0){
        cout << "\nThe campfire is already lit.\n";
    } else {
        cout << "\nYou lit the campfire\n";
        p.lose_energy(10);
        p.set_inventory(56, 1);
    }
}

//displays full map
void mapOption(playerClasses::player& p, mapClasses::islandMap& map){
    cout << map;
}

//lets player sleep and lets them know how they slept
void sleepOption(playerClasses::player& p){
    if(p.next_day() == 1){
        cout << visuals::clearScreen() << "\nYou slept soundly and safely through the night and regained health and energy\n";
    } else {
        cout << visuals::clearScreen() << "\nAn animal attacked your camp in the night, so you didn't regain any health or energy\n";
    }
}

//saves all player and map data to file
void quitOption(playerClasses::player& p, mapClasses::islandMap& map){
    mapClasses::mapIO::save_map(map);
    playerClasses::playerIO::save_player(p);
}
