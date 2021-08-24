/*
 * Author   J Meeks
 * Purpose  Header file for functions relating to the recipe book
 */

#ifndef recipeBook_h
#define recipeBook_h

#include <array>
#include "recipeClasses.h"

namespace recipeBook{
void set_craftables(std::array<recipeClasses::craftingRecipe, 63>& itemRecipes);
void set_cookables(std::array<recipeClasses::cookingRecipe, 63>& foodRecipes);
}
#endif /* recipeBook_h */
