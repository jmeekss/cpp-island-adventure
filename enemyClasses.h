/*
 * Author   J Meeks
 * Purpose  Header file for classes relating to enemy
 */

#ifndef enemyClasses_h
#define enemyClasses_h

#include <string>
#include "enemyClasses.h"

namespace enemyClasses {

class player; //pre defines player for use in class

class Enemy {
    //declares private data members of Enemy
private:
    std::string enemyType;
    std::string enemyStrongAttack;
    std::string enemyWeakAttack;
    int enemyDifficulty;
    int enemyHealth;
    
    //declares public functions of Enemy
public:
    Enemy(std::string type, std::string strong, std::string weak, int d);
    std::string get_enemy_type() const;
    void set_enemy_type(std::string t);
    std::string get_strong() const;
    void set_strong(std::string s);
    std::string get_weak() const;
    void set_weak(std::string w);
    int get_difficulty() const;
    void set_difficulty(int d);
    int get_health() const;
    void set_health(int h);
    std::string display_health() const;
    int get_speed() const;
    
    //declares friend functions for enemy
    friend std::string enemy_attacks(Enemy& e, player& p);
    friend std::string player_attacks(Enemy& e, player& p, int t);
    friend bool player_run(Enemy& e, player& p);
};

}

#endif /* enemyClasses_h */
