/*
 * Author   J Meeks
 * Purpose  Header file for classes relating to the player
 */

#ifndef playerClasses_h
#define playerClasses_h

#include <string>
#include <array>
#include <fstream>
#include "enemyClasses.h"

namespace playerClasses{

//pre defines Enemy class for use in player
class Enemy;

//Camp class for storing info on the player's camp
class Camp {
    //declares private data members of Camp
private:
    int campComfort;
    int campProtection;
    //declares public functions of Camp
public:
    Camp();
    int get_comfort () const;
    void set_comfort(int c);
    int get_protection() const;
    void set_protection(int p);
};

//player class for storing player information
class player {
    //declares private data members for player
private:
    std::string playerName;
    int playerDay;
    int playerHealth;
    int playerEnergy;
    int playerLocation;
    int playerDamage;
    std::array<int, 63> playerInventory;
    std::array<std::string, 63> inventoryNames = {"Stick", "Leaf Pile", "Berry", "Log", "Fern", "Clay", "Mud", "Snail", "Perch", "Bass", "Stone", "Flint", "Iron", "Old Rope", "Ancient Tablet", "Long Grass", "Flower", "Animal Bones", "Fur Clump", "Meteor Fragment", "Shells", "Crab", "Driftwood", "Coral", "Hidden Treasure", "Steel Sheet", "Cloth", "Iron Shavings", "Plane Food", "Cushion", "Cloth Sheet", "Cementing Paste", "Watertight Base", "Sail", "Rudder", "Food Stores", "Circuits", "Speaker", "Radio Chip", "Communication Device", "Sturdy Boat", "Fist", "Sharpened Stick", "Stone Spear", "Iron Blade", "Meteorite Dagger", "Dirt", "Leaf Pile Bed", "Covered Leaf Bed", "Flower Bed with Fur Blanket", "Cushioned Twin Bed with Fur Blanket", "Air", "Mud Fence", "Stick Fence", "Log Fence", "Cross & Bones Fence", "Fire", "Raw Meat", "Fish Stew", "Cooked Meat", "Berry Jelly", "Snail Soup", "Seafood BBQ"};
    Camp baseCamp;
    
    //declares public functions for player
public:
    player(std::string name);
    player(std::string name, int d, int h, int e, std::array<int, 63>& i);
    std::string get_name() const;
    void set_name(std::string name);
    int get_day() const;
    void set_day(int d);
    int next_day();
    int get_health() const;
    void set_health(int h);
    std::string display_health() const;
    void lose_health(int d);
    void sleep();
    int get_energy() const;
    void set_energy(int e);
    std::string display_energy() const;
    void lose_energy(int e);
    void gain_energy(int e);
    int get_location() const;
    void set_location(int l);
    bool move_location(char d);
    std::string eat();
    std::string get_inventory() const;
    void set_inventory(int i, int q);
    int get_quantity(int i) const;
    void add_item(int i);
    std::string lose_items(int q);
    std::string get_item_name(int i);
    int get_damage() const;
    void set_damage(int d);
    int get_speed() const;
    void update_stats();
    Camp get_camp() const;
    
    //declares friend functions for player
    friend std::string enemy_attacks(Enemy& e, player& p);
    friend std::string player_attacks(Enemy& e, player& p, int t);
    friend bool player_run(Enemy& e, player& p);
    
    friend std::ostream& operator<< (std::ostream& out, const player& thisPlayer);
};

//class for reading/writing player data to a file
class playerIO {
    //declares public functions for playerIO
public:
    static player create_player(std::string name, int day, int h, int e, std::array<int, 63>& inv){ //creates a new player with specified info by sending to constructor and return object
        player newPlayer(name, day, h, e, inv);
        return newPlayer;
    }
    
    static void save_player(player p){ //saves player by writing formatted data to a string, and then writing that string to a file
        //writes formatted data
        std::string playerFileOut = p.get_name() + "\t" + std::to_string(p.get_day()) + "\t" + std::to_string(p.get_health()) + "\t" + std::to_string(p.get_energy()) + "\n";
        for(unsigned int i = 0; i < 63; i++){
            playerFileOut += (std::to_string(p.get_quantity(i)) + "\t");
        }
        //opens file, clears it, adds formatted string, and closes it
        std::ofstream outPlayer;
        outPlayer.open("player.txt", std::ios::trunc);
        outPlayer << playerFileOut;
        outPlayer.close();
    }
};

}

#endif /* playerClasses_h */
