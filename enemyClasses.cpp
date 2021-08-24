/*
 * Author   J Meeks
 * Purpose  implementation file for classes relating to the enemy
 */

#include <stdio.h>
#include <string>
#include "enemyClasses.h"

namespace enemyClasses {
Enemy::Enemy(std::string type, std::string strong, std::string weak, int d){//constructor for the Enemy class to fill with specified information
    enemyType = type;
    enemyStrongAttack = strong;
    enemyWeakAttack = weak;
    enemyDifficulty = d;
    enemyHealth = enemyDifficulty * 50;
}

std::string Enemy::get_enemy_type() const { //returns the type/name of the enemy
    return enemyType;
}

void Enemy::set_enemy_type(std::string t){ //sets the type/name of the enemy
    enemyType = t;
}

std::string Enemy::get_strong() const { //gets the strong attack of the enemy
    return enemyStrongAttack;
}

void Enemy::set_strong(std::string s) { //sets the strong attack of the enemy
    enemyStrongAttack = s;
}

std::string Enemy::get_weak() const { //gets the weak attack of the enemy
    return enemyWeakAttack;
}

void Enemy::set_weak(std::string w) { //sets the weak attack of the enemy
    enemyWeakAttack = w;
}

int Enemy::get_difficulty() const { //gest the difficulty of the enemy
    return enemyDifficulty;
}

void Enemy::set_difficulty(int d){ //sets the difficulty of the enemy
    enemyDifficulty = d;
}

int Enemy::get_health() const { //gets the health of the enemy
    return enemyHealth;
}

void Enemy::set_health(int h) { //sets the health of the enemy
    enemyHealth = h;
}

std::string Enemy::display_health() const { //returns representation of enemies health
    //number of bars to represent amount of health
    int fullBars = enemyHealth/10;
    int halfBars = enemyHealth%10;
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


int Enemy::get_speed() const { //calcualtes and returns speed of the enemy
    return (enemyHealth / (enemyDifficulty*100)) * 25 + (enemyDifficulty/2) * 25;
}
}

