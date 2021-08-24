/*
 * Author   J Meeks
 * Purpose  Header file for classes relating to the map
 */

#ifndef mapClasses_h
#define mapClasses_h

#include "enemyClasses.h"
#include <string>
#include <vector>
#include <fstream>

namespace mapClasses {

//class for individual squares on the island map
class mapSquare {
    
    //private variables for mapSquare
private:
    bool explored;
    std::string squareName;
    int squareNameID;
    int squareID;
    std::vector<std::string> squarePicture;
    std::vector<std::string> squareResources;
    std::vector<enemyClasses::Enemy> squareEnemies;
    
    //public functions for mapSquare
public:
    mapSquare(int t, int i);
    bool get_explored ();
    void set_explored (bool e);
    std::string get_squareName();
    void set_squareName(std::string n);
    int get_squareNameID();
    void set_squareNameID(int i);
    int get_squareID();
    void set_squareID(int i);
    std::string get_squarePicture(int l);
    void set_squarePicture(std::string p, int l);
    std::string get_resources(int i);
    void set_resources(std::string r);
    std::string get_enemies();
    enemyClasses::Enemy& get_enemy(int d);
    void set_enemies(enemyClasses::Enemy e);
    int forage();
    int disturb();
};

//Class for the entire island
class islandMap {
    
    //private data members for islandMap
private:
    std::vector<mapSquare> map;
    
    //public functions for islandMap
public:
    std::string get_map(int l);
    void add_square(mapSquare m);
    mapSquare& get_square(int i);
    std::string get_minimap(int l);
    friend std::ostream& operator<< (std::ostream& out, islandMap& thisIsland);
};

//class for creating/saving the map
class mapIO {
    
public:
    //creates a map object based in input
    static islandMap create_map(std::array<int, 49> m, std::array<int, 49> e, char c){
        islandMap newIsland;
        int id = 0;
        if(c == 'l'){ //creates a map from save data that is passed in
            for(unsigned int i = 0; i < 49; i++){
                mapSquare newSquare(m[i], i);
                newSquare.set_explored(e[i]);
                newIsland.add_square(newSquare);
            }
        } else { //creates a new random map, guanrentees 1 of each biome spawns, and places beaches in correct spots
            srand(static_cast<unsigned int>(time(0)));
            int crashID = rand() % 8;
            for(int r = 0; r < 7; r++){
                for(int c = 0; c < 7; c++, id++){
                    if(r == 0 || r == 6 || c == 0 || c == 6){
                        mapSquare newSquare(4, id);
                        newIsland.add_square(newSquare);
                    } else if(r == 3 && c == 3){
                        mapSquare newSquare(6, id);
                        newIsland.add_square(newSquare);
                    } else if(crashID == 0 && r == 2 && c == 2){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(crashID == 1 && r == 2 && c == 3){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(crashID == 2 && r == 2 && c == 4){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(crashID == 3 && r == 2 && c == 2){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(crashID == 4 && r == 2 && c == 4){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(crashID == 5 && r == 2 && c == 2){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(crashID == 6 && r == 2 && c == 3){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(crashID == 7 && r == 2 && c == 4){
                        mapSquare newSquare(5, id);
                        newIsland.add_square(newSquare);
                        crashID = -1;
                    } else if(r == 1 && c == 1){
                        mapSquare newSquare(0, id);
                        newIsland.add_square(newSquare);
                    } else if(r == 1 && c == 5){
                        mapSquare newSquare(1, id);
                        newIsland.add_square(newSquare);
                    } else if(r == 5 && c == 1){
                        mapSquare newSquare(2, id);
                        newIsland.add_square(newSquare);
                    } else if(r == 5 && c == 5){
                        mapSquare newSquare(3, id);
                        newIsland.add_square(newSquare);
                    } else {
                        mapSquare newSquare((rand() % 4), id);
                        newIsland.add_square(newSquare);
                    }
                }
            }
        }
        //returns the map object
        return newIsland;
    }
    
    //saves the map to a file
    static void save_map(islandMap map){
        std::string mapFileOut;
        for(unsigned int i = 0; i < 49; i++){ //saves all of the biome ids
            mapFileOut += (std::to_string(map.get_square(i).get_squareNameID()) + "\t");
        }
        mapFileOut += "\n";
        for(unsigned int i = 0; i < 49; i++){ //saves all of the exploration ids
            mapFileOut += (std::to_string(map.get_square(i).get_explored()) + "\t");
        }
        //updates file and closes it
        std::ofstream outMap;
        outMap.open("map.txt", std::ios::trunc);
        outMap << mapFileOut;
        outMap.close();
    }
};
}


#endif /* mapClasses_h */
