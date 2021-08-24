/*
 * Author   J Meeks
 * Purpose  implementation file for classes relating to the player
 */

#include <stdio.h>
#include <string>
#include <array>
#include "playerClasses.h"

namespace playerClasses{

Camp::Camp(){ //constructor for camp that sets default values
    campComfort = 1;
    campProtection = 1;
}

int Camp::get_comfort () const { //gets the comfort of the camp
    return campComfort;
}

void Camp::set_comfort(int c){ //sets the comfort of the camp
    campComfort = c;
}

int Camp::get_protection() const { //gets the protection of the camp
    return campProtection;
}

void Camp::set_protection(int p){ //sets the protection of the camp
    campProtection = p;
}


player::player(std::string name){ //constructor for that player that only includes name, all other values set to default
    playerName = name;
    playerDay = 0;
    playerHealth = 100;
    playerEnergy = 100;
    playerLocation = 24;
    playerDamage = 1;
    playerInventory = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};
}

player::player(std::string name, int d, int h, int e, std::array<int, 63>& i){ //constructor for play that sends in data from a previous save, and add it to player
    playerName = name;
    playerDay = d;
    playerHealth = h;
    playerEnergy = e;
    playerLocation = 24;
    playerDamage = 1;
    playerInventory = i;
    
    //ensures health and energy arent too high
    if(playerHealth > 100){
        playerHealth = 100;
    } else if(playerHealth < 0){
        playerHealth = 0;
    }
    
    if(playerEnergy > 100){
        playerEnergy = 100;
    } else if(playerEnergy < 0){
        playerEnergy = 0;
    }
}

std::string player::get_name() const { //gets the player name
    return playerName;
}

void player::set_name(std::string name){ //sets the player name
    playerName = name;
}

int player::get_day() const { //gets the player day
    return playerDay;
}

void player::set_day(int d){ //sets the player day
    playerDay = d;
}

int player::next_day() { //increment the day forward and adjusts all of the players stats
    playerDay++; //adds day
    srand(static_cast<unsigned int>(time(0)));
    int encounter = rand() % 51;
    if((30+4*baseCamp.get_protection()) >= encounter){ //if no enemy attacks camp at night, sleeps, and extinguishes fire
        playerInventory[56] = 0;
        sleep();
        return 1;
    }
    //if an enemy attacks, player doesnt get to sleep, and fire gets extinguished
    playerLocation = 24;
    playerInventory[56] = 0;
    return 0;
}

int player::get_health() const { //gets health of player
    return playerHealth;
}

void player::set_health(int h) { //sets health of player
    playerHealth = h;
}

std::string player::display_health() const { //gets visual representation of players health
    //represents health in bars, with full bars equal to 10, half bars equal to 5, and no bars equal to 0
    int fullBars = playerHealth/10;
    int halfBars = playerHealth%10;
    std::string health = "";
    for(int i = 0; i < fullBars; i++){
        health += "█";
    }
    
    if(halfBars >= 3 && halfBars <= 7){
        fullBars++;
        health += "▒";
    }
    
    for(int i = 0; i < (10-fullBars); i++){
        health += "░";
    }
    return health;
}

void player::lose_health(int d){ //makes player lose health, but wont let it drop below 0
    if((playerHealth-d) <0){
        playerHealth = 0;
    } else {
        playerHealth -= d;
    }
}

void player::sleep() { //lets player sleep and adds health/energy based on comfort of camp
    playerHealth += (25*baseCamp.get_comfort());
    playerEnergy += (25*baseCamp.get_comfort());
    //wont let health of energy exceed 100
    if(playerHealth > 100){
        playerHealth = 100;
    }
    if(playerEnergy > 100){
        playerEnergy = 100;
    }
}

int player::get_energy() const { //gets energy of player
    return playerEnergy;
}

void player::set_energy(int e){ //sets energy of player
    playerEnergy = e;
}

std::string player::display_energy() const { //gets visual representation of players energy in bars
    //represents energy in bars, with full bars equal to 10, half bars equal to 5, and no bars equal to 0
    int fullBars = playerEnergy/10;
    int halfBars = playerEnergy%10;
    std::string energy = "";
    for(int i = 0; i < fullBars; i++){
        energy += "█";
    }
    
    if(halfBars >= 3 && halfBars <= 7){
        fullBars++;
        energy += "▒";
    }
    
    for(int i = 0; i < (10-fullBars); i++){
        energy += "░";
    }
    return energy;
}

void player::lose_energy(int e){ //makes player lose energy, but wont let it drop below 0
    if((playerEnergy-e) <0){
        playerEnergy = 0;
    } else {
        playerEnergy -= e;
    }
}

void player::gain_energy(int e){ //makes player gain energy, but wont let it exceed 100
    if((playerEnergy+e) > 100){
        playerEnergy = 100;
    } else {
        playerEnergy += e;
    }
}

int player::get_location() const { //gets location ID of player
    return playerLocation;
}

void player::set_location(int l){ //sets location id of player
    playerLocation = l;
}

bool player::move_location(char d){ //moves player in location depending on char
    if(d == 'w'){ //moves up if possible, or notifies if not
        if(playerLocation - 7 < 0 || playerLocation - 7 == 24){
            return false;
        } else {
            playerLocation -= 7;
            return true;
        }
    } else if(d == 'a'){//moves left if possible, or notifies if not
        if(playerLocation % 7 == 0 || playerLocation % 7 == 24){
            return false;
        } else {
            playerLocation -= 1;
            return true;
        }
    } else if(d == 's'){//moves down if possible, or notifies if not
        if(playerLocation + 7 > 48 || playerLocation + 7 == 24){
            return false;
        } else {
            playerLocation += 7;
            return true;
        }
    } else if(d == 'd'){//moves right if possible, or notifies if not
        if(playerLocation % 7 == 6 || playerLocation % 7 == 24){
            return false;
        } else {
            playerLocation += 1;
            return true;
        }
    }
    return false;
}

std::string player::get_inventory() const{ //gets the full inventory of the player in string form
    std::string inventory = "═════════════════════════════════════════════════════════════════\nInventory:\n";
    for(int i = 0; i < playerInventory.size(); i++){
        if(playerInventory[i] > 0){
            inventory = inventory + "\t ×" + std::to_string(playerInventory[i]) + " " + inventoryNames[i] + "\n";
        }
    }
    return inventory+"═════════════════════════════════════════════════════════════════\n";
}

void player::set_inventory(int i, int q){ //sets the quantity of specified ID item
    playerInventory[i] = q;
}

int player::get_quantity(int i) const { //gest the quantity of speified item
    if(i > playerInventory.size() - 1){
        return 0;
    }
    return playerInventory[i];
}

void player::add_item(int i){ //adds 1 item of specified ID to inventory
    if(i > playerInventory.size() - 1){
        return;
    }
    playerInventory[i]++;
}

std::string player::lose_items(int q){ //makes player lose specified number of random item and returns string describing it
    srand(static_cast<unsigned int>(time(0)));
    int id = rand() % 41;
    playerInventory[id] -= q;
    if(playerInventory[id] < 0){
        playerInventory[id] = 0;
    }
    return "\t» Lost " + std::to_string(q) + " of: " + inventoryNames[id] + " «\n";
}

std::string player::get_item_name(int i){ //gets the name of the item of the specified id
    if(i > inventoryNames.size()-1){
        return inventoryNames[0];
    }
    return inventoryNames[i];
}

int player::get_damage() const { //gets the damage modifer of the player
    return playerDamage;
}

void player::set_damage(int d) { //sets the damage modifier of the player
    playerDamage = d;
}

int player::get_speed() const{ //calculates and returns speed of the player
    return ((playerHealth) * 25 + (playerEnergy) * 25)/100;
}

std::string player::eat() { //checks if the player has food, and if so, lets them eat/updates stats, returns string describing it
    for(unsigned int i = 58; i < 63; i++){
        if(playerInventory[i] > 0){ //checks if they have any food and restores energy/health
            playerInventory[i]--;
            playerHealth += 15;
            playerEnergy += 15;
            //wont let health/energy exceed 100
            if(playerHealth > 100){
                playerHealth = 100;
            }
            if(playerEnergy > 100){
                playerEnergy = 100;
            }
            return "You ate some food and regained some energy and health.\n";
        }
    }
    return "You have no food to eat.\n";
}

void player::update_stats(){ //updates the modifiers of the player and their camp
    if(playerInventory[42] > 0){ //update damage mods if modifying items are in inventory
        playerDamage = 2;
    } else if(playerInventory[43] > 0){
        playerDamage = 3;
    } else if(playerInventory[44] > 0){
        playerDamage = 4;
    } else if(playerInventory[45] > 0){
        playerDamage = 6;
    }
    
    if(playerInventory[47] > 0){ //updates comfort mods if modifying items are in inventory
        baseCamp.set_comfort(2);
    } else if(playerInventory[48] > 0){
        baseCamp.set_comfort(3);
    } else if(playerInventory[49] > 0){
        baseCamp.set_comfort(4);
    } else if(playerInventory[50] > 0){
        baseCamp.set_comfort(6);
    }
    
    if(playerInventory[52] > 0){ //updates protection mod if modifying items are found in inventory
        baseCamp.set_protection(2);
    } else if(playerInventory[53] > 0){
        baseCamp.set_protection(3);
    } else if(playerInventory[54] > 0){
        baseCamp.set_protection(4);
    } else if(playerInventory[55] > 0){
        baseCamp.set_protection(6);
    }
}

Camp player::get_camp() const { //gets the player camp object
    return baseCamp;
}

std::ostream& operator<< (std::ostream& out, const player& thisPlayer){ //overloads the output operator for the player and displays their stats(name, day, health, energy, and modifiers)
    std::string playerData;
    if(thisPlayer.get_day() > 9){
        playerData = "\n╔═══════════════════════════════════════════════════════════════╗\n║ Stats for " + thisPlayer.get_name() + " on day " + std::to_string(thisPlayer.get_day()) + "                                      \n";
    } else {
        playerData = "\n╔═══════════════════════════════════════════════════════════════╗\n║ Stats for " + thisPlayer.get_name() + " on day " + std::to_string(thisPlayer.get_day()) + "                                       \n";
    }
    playerData = playerData + "║ Health: " + thisPlayer.display_health() + "\t\t\t";
    playerData = playerData + "Energy: " + thisPlayer.display_energy() + "              \n";
    playerData = playerData + "║ Damage: x" + std::to_string(thisPlayer.get_damage()) + "        " + "Comfort: x" + std::to_string(thisPlayer.get_camp().get_comfort()) + "        " + "Camp Protection: x" + std::to_string(thisPlayer.get_camp().get_protection()) + "      \n";
    if(thisPlayer.get_quantity(56) > 0){
        playerData = playerData + "║ The campfire is lit                                           ";
    } else {
        playerData = playerData + "║ The campfire is not lit                                       ";
    }
    out << playerData + "\n╚═══════════════════════════════════════════════════════════════╝";
    return out; //outputs stats to screen
}

}
