/*
 * Author   J Meeks
 * Purpose  Header file for classes relating to enemy battles
 */

#ifndef enemyBattle_h
#define enemyBattle_h

#include "enemyClasses.h"
#include "playerClasses.h"

namespace enemyBattles{
std::string enemy_attacks(enemyClasses::Enemy& e, playerClasses::player& p);
std::string player_attacks(enemyClasses::Enemy& e, playerClasses::player& p, int t);
bool player_run(enemyClasses::Enemy& e, playerClasses::player& p);
bool enemyBattle(enemyClasses::Enemy& e, playerClasses::player& p);
}

#endif /* enemyBattle_h */
