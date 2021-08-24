/*
 * Author   J Meeks
 * Purpose  Header file for classes relating to enemy battle
 */

#include <stdio.h>
#include <array>
#include "enemyClasses.h"
#include "playerClasses.h"
#include <string>
#include <iostream>
#include "adventureIn.h"

namespace enemyBattles{
//Friend Functions
std::string enemy_attacks(enemyClasses::Enemy& e, playerClasses::player& p){ //friend function for when the enemy attacks the player
    std::string desc = "\nThe " + e.get_enemy_type() + " tries to attack you but misses";
    //gest the strength of the enemy's attack
    srand(static_cast<unsigned int>(time(0)));
    int strength = rand() % 10 + 1;
    int healthLost = e.get_difficulty() * strength;
    //determines message depending on strength of the enemy's attack
    if(strength > 5){
        desc = "\nThe " + e.get_enemy_type() + " forcefully " + e.get_strong() + " you, dealing [" + std::to_string(healthLost) + "HP] of damage";
        p.lose_health(healthLost);
    } else {
        desc = "\nThe " + e.get_enemy_type() + " weakly " + e.get_strong() + " you, dealing [" + std::to_string(healthLost) + "HP] of damage";
        p.lose_health(healthLost);
    }
    //adds to message if enemy killed player
    if(p.get_health() == 0){
        desc = desc + ", causing you to lose so much blood that you pass out.";
    }
    
    return desc;
}
std::string player_attacks(enemyClasses::Enemy& e, playerClasses::player& p, int t){ //friend function for when player attacks the enemy
    std::string desc, clearScreen = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //gest the strength of the enemy's attack
    srand(static_cast<unsigned int>(time(0)));
    int strength = rand() % 10 + 1;
    if(t == 0){ //ads string representation of players attack, based on their choice of attack, and updates their energy, and enemy's health
        desc = clearScreen + "You cautiously swipe at the " + e.get_enemy_type() + ", dealing [" + std::to_string(strength*p.get_damage()) + "HP] of damage";
        p.lose_energy(5);
        e.set_health(e.get_health() - (strength*p.get_damage()));
    } else {
        desc = clearScreen + "You confidently attack the " + e.get_enemy_type() + ", dealing [" + std::to_string(3*strength*p.get_damage()) + "HP] of damage";
        p.lose_energy(10);
        e.set_health(e.get_health() - (3*strength*p.get_damage()));
    }
    //if player over exerts themself, adds to attack message
    if(p.get_energy() == 0){
        desc = desc + " but suddenly you feel weak and everything fades to black.";
        return desc;
    }
    
    //if player manages to kill enemy, gets random amount of meat, adds it to inventory, and adds to attack message
    if(e.get_health() <= 0){
        srand(static_cast<unsigned int>(time(0)));
        int numMeat = rand() % 4;
        desc = desc + ", killing it, and obtaining ×" + std::to_string(numMeat) + " Raw Meat";
        for(int i = 0; i < numMeat; i++){
            p.add_item(57);
        }
    }
    
    return desc;
}

bool player_run(enemyClasses::Enemy& e, playerClasses::player& p){ //function that returns whether or not player was able to run from the battle
    srand(static_cast<unsigned int>(time(0)));
    int enemySpeed = rand() % e.get_health();
    return(enemySpeed > p.get_speed()); //success chance based on player health and energy, and enemy health
}

bool enemyBattle(enemyClasses::Enemy& e, playerClasses::player& p){ //function that handles battling between player and enemies
    std::string clearScreen = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    e.set_health(100);
    //updates health of enemy based on difficulty
    if(e.get_difficulty() == 1){
        e.set_health(50);
    }
    int fightStatus = 1;
    char attack;
    //displays start of fight info and stats before entering loop
    std::cout << "\n×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤\n\nYou engage in battle with the " << e.get_enemy_type() << std::endl;
    std::cout << "\nYour health: " << p.display_health() << " " << p.get_health() << "/100\n" <<
    "Your energy: " << p.display_energy() << " " << p.get_energy() << "/100\n\n";
    std::cout << e.get_enemy_type() << "'s health: " <<  e.display_health() << " " << e.get_health() << "/" << (e.get_difficulty() * 50);
    while(fightStatus == 1){ //main loop for fight, asks for players action, handles actions, gets enemy response, and repeat
        attack = adventureInputs::askAttack();
        std::cout << clearScreen;
        if(attack == 'w'){ //player does  weak attack
            std::cout << player_attacks(e, p, 0);
        } else if(attack == 's'){ //player does strong attack
            std::cout << player_attacks(e, p, 1);
        } else if(attack == 'r'){ //player tries to run, notifies the user of success/failure, updates energy
            if(player_run(e, p)){
                fightStatus = 0;
                std::cout << "\nYou manage to outrun the " + e.get_enemy_type() +" and escape\n\n×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤\n";
                p.lose_energy(20);
                return true;
            }
            std::cout << "\nYou tried to escape, but the " + e.get_enemy_type() + " blocks your path";
            p.lose_energy(20);
        }
        
        //check if player is out of energy/health and respinds accordingly
        if(p.get_health() == 0 || p.get_energy() == 0){
            std::cout << "\n\n×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤\n";
            return false;
        } else if(e.get_health() <= 0){
            std::cout << "\n\n×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤\n";
            return true;
        }
        
        //displays's enemy stats
        std::cout << "\n\n" << e.get_enemy_type() << "'s health: " <<  e.display_health() << " " << e.get_health() << "/" << (e.get_difficulty() * 50) << "\n";
        
        //lets enemy attack if it is still alive, then displays stats
        if(fightStatus == 1 && e.get_health() > 0){
            std::cout << enemy_attacks(e, p);
            std::cout << "\n\nYour health: " << p.display_health() << " " << p.get_health() << "/100\n" <<
            "Your energy: " << p.display_energy() << " " << p.get_energy() << "/100";
        }
        
        //checks if player is dead/has no energy and reacts accordingly
        if(p.get_health() == 0 || p.get_energy() == 0){
            std::cout << "\n\n×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×¤×n";
            return false;
        }
    }
    
    return false;
}
}
