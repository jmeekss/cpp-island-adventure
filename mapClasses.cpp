/*
 * Author   J Meeks
 * Purpose  implementation file for classes relating to the map
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include "enemyClasses.h"
#include "mapClasses.h"

namespace mapClasses {
mapSquare::mapSquare(int t, int i){ //constructor for mapSquare, contains all of the default square info, and chooses what info to save based on input
    //TropicalForest: 0, Lake: 1, Mountain: 2, Plains: 3, Beach: 4, CrashSight: 5
    explored = 0;
    squareID = i;
    if(t == 0) { //data for tropical forest(image, items, enemies)
        squareName = "Tropical Forest";
        squareNameID = 0;
        squarePicture.clear();
        squarePicture.push_back("░░░░░░░▓▓▓░░░░░░░░");
        squarePicture.push_back("░░░░░░▓▓▓▓▓░░░░░░░");
        squarePicture.push_back("░░░░░░░▓▓▓░▓▓▓▓▓░░");
        squarePicture.push_back("░▓▓▓▓▓░░█░▓▓▓▓▓▓▓░");
        squarePicture.push_back("▓▓▓▓▓▓▓░█░░▓▓▓▓▓░░");
        squarePicture.push_back("░▓▓▓▓▓░░░░░░░█░░░░");
        squarePicture.push_back("░░░█░░░░░░░░░█░░░░");
        squarePicture.push_back("░░░█░░░░░░░░░░░░░░");
        squarePicture.push_back("░░░░ Forest ░░░░░░");
        squareResources.clear();
        squareResources.push_back("Stick");
        squareResources.push_back("Leaf Pile");
        squareResources.push_back("Berry");
        squareResources.push_back("Log");
        squareResources.push_back("Fern");
        squareEnemies.clear();
        enemyClasses::Enemy newEnemy1("Monkey", "slaps", "punches", 1);
        squareEnemies.push_back(newEnemy1);
        enemyClasses::Enemy newEnemy2("Panther", "scratches", "bites", 2);
        squareEnemies.push_back(newEnemy2);
    } else if(t == 1) { //data for lake(image, items, enemies)
        squareName = "Lake";
        squareNameID = 1;
        squarePicture.clear();
        squarePicture.push_back("░░░░░░░██████░░░░░");
        squarePicture.push_back("░░░░░██▓▓▓▓▓▓██░░░");
        squarePicture.push_back("░░░██▓▓▒▒▒▒▒▒▓▓██░");
        squarePicture.push_back("░░░██▓▓▒▒▒▒▒▒▓▓██░");
        squarePicture.push_back("░██▓▓▒▒▒▒▒▒▒▒▓▓██░");
        squarePicture.push_back("░██▓▓▒▒▒▒▒▒▓▓▓▓██░");
        squarePicture.push_back("░██▓▓▓▓▓▓▓▓████░░░");
        squarePicture.push_back("░░░████████░░░░░░░");
        squarePicture.push_back("░░░░░░ Lake ░░░░░░");
        squareResources.clear();
        squareResources.push_back("Clay");
        squareResources.push_back("Mud");
        squareResources.push_back("Snail");
        squareResources.push_back("Perch");
        squareResources.push_back("Bass");
        squareEnemies.clear();
        enemyClasses::Enemy newEnemy1("Piranha", "bites", "chomps down violently", 1);
        squareEnemies.push_back(newEnemy1);
        enemyClasses::Enemy newEnemy2("School of Piranhas", "bites", "violently swarms", 2);
        squareEnemies.push_back(newEnemy2);
    } else if(t == 2) {//data for mountain(image, items, enemies)
        squareName = "Mountain";
        squareNameID = 2;
        squarePicture.clear();
        squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
        squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
        squarePicture.push_back("░░░░░░░░░░▒▒░░░░░░");
        squarePicture.push_back("░░░░░░░░░▒▒▒▒░░░░░");
        squarePicture.push_back("░░░░▒▒░░▒▒▓▓▒▒░░░░");
        squarePicture.push_back("░░░▒▒▒▒▓▓▓▓▓▓▓▓░░░");
        squarePicture.push_back("░░▓▓▓▓▓▓████▓▓▓▓░░");
        squarePicture.push_back("░████████████████░");
        squarePicture.push_back("░░░ Mountains ░░░░");
        squareResources.clear();
        squareResources.push_back("Stone");
        squareResources.push_back("Flint");
        squareResources.push_back("Iron");
        squareResources.push_back("Old Rope");
        squareResources.push_back("Ancient Tablet");
        squareEnemies.clear();
        enemyClasses::Enemy newEnemy1("Snake", "bites", "strangles", 1);
        squareEnemies.push_back(newEnemy1);
        enemyClasses::Enemy newEnemy2("Bear", "thrashes", "scratches and bites", 2);
        squareEnemies.push_back(newEnemy2);
    } else if(t == 3) {//data for plains(image, items, enemies)
        squareName = "Plains";
        squareNameID = 3;
        squarePicture.clear();
        squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
        squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
        squarePicture.push_back("░░░░░░░░░░░▓▓▓░░░░");
        squarePicture.push_back("░░░░░░░░░░░▓▓▓░░░░");
        squarePicture.push_back("░░░░░░░░░░░░█░░░░░");
        squarePicture.push_back("░░░▓▓▓░░░░░░░░░░░░");
        squarePicture.push_back("░░░▓▓▓░░░░░░░░░░░░");
        squarePicture.push_back("░░░░█░░░░░░░░░░░░░");
        squarePicture.push_back("░░░░ Plains ░░░░░░");
        squareResources.clear();
        squareResources.push_back("Long Grass");
        squareResources.push_back("Flower");
        squareResources.push_back("Animal Bones");
        squareResources.push_back("Fur Clump");
        squareResources.push_back("Meteor Fragment");
        squareEnemies.clear();
        enemyClasses::Enemy newEnemy1("Rabid Squirrel", "trips", "bites", 1);
        squareEnemies.push_back(newEnemy1);
        enemyClasses::Enemy newEnemy2("Fox", "scratches", "bites", 2);
        squareEnemies.push_back(newEnemy2);
    } else if(t == 4) {//data for beach, including all orientations (image, items, enemies)
        squareName = "Beach";
        squareNameID = 4;
        if(i == 0){//tl
            squarePicture.clear();
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████▓▓▓▓");
            squarePicture.push_back("██████████▓▓▓▓▒▒▒▒");
            squarePicture.push_back("████████▓▓▒▒▒▒░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
        } else if(i > 0 && i < 6){ //top
            squarePicture.clear();
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("███████████▓▓▓▓███");
            squarePicture.push_back("▓▓▓████▓▓▓▓▒▒▒▒▓▓▓");
            squarePicture.push_back("▒▒▒▓▓▓▓▒▒▒▒░░░░▒▒▒");
            squarePicture.push_back("░░░▒▒▒▒░░░░░░░░░░░");
            squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
            squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
            squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
        } else if(i == 6){ //tr
            squarePicture.clear();
            squarePicture.clear();
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("▓▓▓▓██████████████");
            squarePicture.push_back("▒▒▒▒▓▓▓▓██████████");
            squarePicture.push_back("░░░░▒▒▒▒▓▓████████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
        } else if(i == 42){ //bl
            squarePicture.clear();
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("████████▓▓▒▒▒▒░░░░");
            squarePicture.push_back("██████████▓▓▓▓▒▒▒▒");
            squarePicture.push_back("██████████████▓▓▓▓");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
        } else if(i > 42 && i < 48){ //bottom
            squarePicture.clear();
            squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
            squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
            squarePicture.push_back("░░░░░░░░░░░░░░░░░░");
            squarePicture.push_back("░░░▒▒▒▒░░░░░░░░░░░");
            squarePicture.push_back("▒▒▒▓▓▓▓▒▒▒▒░░░░▒▒▒");
            squarePicture.push_back("▓▓▓████▓▓▓▓▒▒▒▒▓▓▓");
            squarePicture.push_back("███████████▓▓▓▓███");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
        } else if(i == 48){//br
            squarePicture.clear();
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░▒▒▒▒▓▓████████");
            squarePicture.push_back("▒▒▒▒▓▓▓▓██████████");
            squarePicture.push_back("▓▓▓▓██████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
            squarePicture.push_back("██████████████████");
        } else if((i % 7) == 0){ //l
            squarePicture.clear();
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("████▓▓▒▒░░░░░░░░░░");
            squarePicture.push_back("████▓▓▒▒░░░░░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("████████▓▓▒▒░░░░░░");
            squarePicture.push_back("████████▓▓▒▒░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
            squarePicture.push_back("██████▓▓▒▒░░░░░░░░");
        } else if((i % 7) == 6){ //r
            squarePicture.clear();
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░░░░░░░▒▒▓▓████");
            squarePicture.push_back("░░░░░░░░░░▒▒▓▓████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░░░▒▒▓▓████████");
            squarePicture.push_back("░░░░░░▒▒▓▓████████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
            squarePicture.push_back("░░░░░░░░▒▒▓▓██████");
        }
        squareResources.clear();
        squareResources.push_back("Shells");
        squareResources.push_back("Crab");
        squareResources.push_back("Driftwood");
        squareResources.push_back("Coral");
        squareResources.push_back("Hidden Treasure");
        squareEnemies.clear();
        enemyClasses::Enemy newEnemy1("Puffer Fish", "pokes", "stabs", 1);
        squareEnemies.push_back(newEnemy1);
        enemyClasses::Enemy newEnemy2("Shark", "charges", "bites", 2);
        squareEnemies.push_back(newEnemy2);
    } else if(t == 5) { //data for the crash sight (image, items, enemies)
        squareName = "Crash Sight";
        explored = 1;
        squareNameID = 5;
        squarePicture.clear();
        squarePicture.push_back("░░░░░██░░░██░░░░░░");
        squarePicture.push_back("░░██░░░░░░████░░░░");
        squarePicture.push_back("░░░░░░░░██▓▓▓▓░░░░");
        squarePicture.push_back("░░░░░░██▒▒▒▒▓▓██░░");
        squarePicture.push_back("░░░░██▒▒▒▒░░▒▒██░░");
        squarePicture.push_back("░░░░██▒▒░░░░▒▒██░░");
        squarePicture.push_back("░░░░██░░░░▒▒██░░░░");
        squarePicture.push_back("░░░░░░██████░░░░░░");
        squarePicture.push_back("░░ Crash  Sight ░░");
        squareResources.clear();
        squareResources.push_back("Steel Sheet");
        squareResources.push_back("Cloth");
        squareResources.push_back("Iron Shavings");
        squareResources.push_back("Plane Food");
        squareResources.push_back("Cushion");
        squareEnemies.clear();
        enemyClasses::Enemy newEnemy1("Vulture", "pecked", "clawed", 1);
        squareEnemies.push_back(newEnemy1);
        enemyClasses::Enemy newEnemy2("Hyena", "scratched", "jumped on", 2);
        squareEnemies.push_back(newEnemy2);
    } else if(t == 6) { //data for the camp, primarily just the image because camp is not interacted with
        squareName = "Camp";
        explored = 1;
        squareNameID = 6; //█  ▓  ▒  ░
        squarePicture.clear();
        squarePicture.push_back("░░░░░░░████░░░░░░░");
        squarePicture.push_back("░░░░░██░░░░██░░░░░");
        squarePicture.push_back("░░░██░░░░░░░░██░░░");
        squarePicture.push_back("░██░░░░░░░░░░░░██░");
        squarePicture.push_back("░░░██░░░░░░░░██░░░");
        squarePicture.push_back("░░░██░░░▒▒░░░██░░░");
        squarePicture.push_back("░░░██░░░▒▒░░░██░░░");
        squarePicture.push_back("░░░████████████░░░");
        squarePicture.push_back("░░░░░░ Camp ░░░░░░");
        squareResources.clear();
        squareEnemies.clear();
    } else { //if invalid input is sent in
        std::cout << "INVALID MAPSQUARE";
    }
}

bool mapSquare::get_explored (){ //returns the explored state of square
    return explored;
}

void mapSquare::set_explored (bool e){ //sets explored state of square
    explored = e;
}

std::string mapSquare::get_squareName(){ //gets the name of the square
    return squareName;
}

void mapSquare::set_squareName(std::string n){ //sets the name of the square
    squareName = n;
}

int mapSquare::get_squareNameID(){ //gets the name ID of the square
    return squareNameID;
}

void mapSquare::set_squareNameID(int i){ //sets the name ID of the square
    squareNameID = i;
}

int mapSquare::get_squareID(){ //gets the id of the square
    return squareID;
}

void mapSquare::set_squareID(int i){ //sets the ID of the square
    squareID = i;
}

std::string mapSquare::get_resources(int i){
    if(i > 4){
        return squareResources[0];
    }
    return squareResources[i];
}

std::string mapSquare::get_squarePicture(int l){ //gets the specified line of the picture of the square
    if(explored){
        return squarePicture[l];
    }
    return "░░░░░░░░░░░░░░░░░░";
}

void mapSquare::set_squarePicture(std::string p, int l){ //sets the specified line of the picture of the square
    squarePicture[l] = p;
}

enemyClasses::Enemy& mapSquare::get_enemy(int d){ //gets and returns the enemy of the specified diffult on the square
    if(d==2){
        return squareEnemies[1];
    }
    return squareEnemies[0];
}

void mapSquare::set_enemies(enemyClasses::Enemy e){ //adds enemies to square
    squareEnemies.push_back(e);
}

int mapSquare::forage(){//forages the square for items and return what rarity item is found
    srand(static_cast<unsigned int>(time(0)));
    int rarity = rand() % 101;
    if(rarity > 90){
        return 4;
    } else if(rarity > 75){
        return 3;
    } else if(rarity > 60){
        return 2;
    } else if(rarity > 30){
        return 1;
    }
    return 0;
}

int mapSquare::disturb(){ //disturbs the square and return the enemy type, if any, that is found
    srand(static_cast<unsigned int>(time(0)));
    int enemyID = rand() % 101;
    if(enemyID > 90){
        return 2;
    } else if(enemyID > 70){
        return 1;
    }
    return 0;
}

std::string islandMap::get_map(int l){ //gets the string representation of the map, hides squares that have no been visited
    std::string line;
    if(l == 0){
        line = "╔════════════════════╦════════════════════╦════════════════════╦════════════════════╦════════════════════╦════════════════════╦════════════════════╗";
    } else {
        line = "╠════════════════════╬════════════════════╬════════════════════╬════════════════════╬════════════════════╬════════════════════╬════════════════════╣";
    }
    
    for(int i = 0; i < 9; i++){
        line = line + "\n║ " + map[7*l + 0].get_squarePicture(i) + " ║ " + map[7*l + 1].get_squarePicture(i) + " ║ " + map[7*l + 2].get_squarePicture(i) + " ║ " + map[7*l + 3].get_squarePicture(i) + " ║ " + map[7*l + 4].get_squarePicture(i) + " ║ " + map[7*l + 5].get_squarePicture(i) + " ║ " + map[7*l + 6].get_squarePicture(i) + " ║ ";
    }
    line = line + "\n";
    return line;
}

void islandMap::add_square(mapSquare m){ //adds a square to the map
    map.push_back(m);
}

mapSquare& islandMap::get_square(int i){ //gets square of the specified id on the map
    return map[i];
}

std::string islandMap::get_minimap(int l){ //gets the mini version of the map, hides squares that haven't been visited, and indicates current square player is on
    std::string map = "╔══╦══╦══╦══╦══╦══╦══╗\n";
    for(int i = 0; i < 7; i++){
        map += "║";
        for(unsigned int j = 0; j < 7; j++){//»« //TropicalForest: 0, Lake: 1, Mountain: 2, Plains: 3, Beach: 4, CrashSight: 5
            if(get_square(7*i + j).get_explored()){
                if(7*i+j == l){
                    map = map + "»«║";
                } else
                    //adds mini square data to map
                    if(get_square(7*i + j).get_squareNameID() == 0){
                        map = map + "TF║";
                    } else if(get_square(7*i + j).get_squareNameID() == 1){
                        map = map + "LK║";
                    } else if(get_square(7*i + j).get_squareNameID() == 2){
                        map = map + "MT║";
                    } else if(get_square(7*i + j).get_squareNameID() == 3){
                        map = map + "PL║";
                    } else if(get_square(7*i + j).get_squareNameID() == 4){
                        map = map + "BC║";
                    } else if(get_square(7*i + j).get_squareNameID() == 5){
                        map = map + "CR║";
                    } else if(get_square(7*i + j).get_squareNameID() == 6){
                        map = map + "CA║";
                    } else {
                        map = map + "░░║";
                    }
            } else {
                map = map + "░░║";
            }
        }
        map += "\n";
    }
    map += "╚══╩══╩══╩══╩══╩══╩══╝\n";
    return map;
}

std::ostream& operator<< (std::ostream& out, islandMap& thisIsland){ //overloads the output operator for the island and displays it to the map
    std::string mapString = "";
    for(int i = 0; i < 7; i++){
        mapString = mapString + thisIsland.get_map(i);
    }
    
    mapString += "╚════════════════════╩════════════════════╩════════════════════╩════════════════════╩════════════════════╩════════════════════╩════════════════════╝\n\n";
    out << mapString;
    return out;
}
}
