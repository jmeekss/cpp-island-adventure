/*
 * Author   J Meeks
 * Purpose  Header file for inputs from user
*/

#ifndef adventureIn_h
#define adventureIn_h
namespace adventureInputs{
    char askMovement();
    char askFirstMovement();
    char askDaily();
    char askCraftType();
    int getInt(int max);
    char startNew();
    char askAttack();
}
#endif /* adventureIn_h */
