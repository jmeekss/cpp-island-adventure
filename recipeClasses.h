/*
 * Author   J Meeks
 * Purpose  Header file for classes relating to recipes
 */

#ifndef recipeClasses_h
#define recipeClasses_h

#include "playerClasses.h"
#include <string>
#include <array>

namespace recipeClasses{
//Recipe class, virtual, for storing recipe info/functions
class Recipe {
public:
    virtual bool craft_item(playerClasses::player& p) = 0;
};

//craftingRecipe class, which inherits recipe, for storing crafting recipes
class craftingRecipe: public Recipe {
    //declares private data members for craftingRecipe class
private:
    std::array<int, 63> recipeItems;//num_items
    std::array<std::string, 63> itemNames = {"Stick", "Leaf Pile", "Berry", "Log", "Fern", "Clay", "Mud", "Snail", "Perch", "Bass", "Stone", "Flint", "Iron", "Old Rope", "Ancient Tablet", "Long Grass", "Flower", "Animal Bones", "Fur Clump", "Meteor Fragment", "Shells", "Crab", "Driftwood", "Coral", "Hidden Treasure", "Steel Sheet", "Cloth", "Iron Shavings", "Plane Food", "Cushion", "Cloth Sheet", "Cementing Paste", "Watertight Base", "Sail", "Rudder", "Food Stores", "Circuits", "Speaker", "Radio Chip", "Communication Device", "Sturdy Boat", "Fist", "Sharpened Stick", "Stone Spear", "Iron Blade", "Meteorite Dagger", "Dirt", "Leaf Pile Bed", "Covered Leaf Bed", "Flower Bed with Fur Blanket", "Cushioned Twin Bed with Fur Blanket", "Air", "Mud Fence", "Stick Fence", "Log Fence", "Cross & Bones Fence", "Fire", "Raw Meat", "Fish Stew", "Cooked Meat", "Berry Jelly", "Snail Soup", "Seafood BBQ"};
    std::string recipeDescription;
    int index;
    //declares public functions for craftingrecipe class
public:
    craftingRecipe();
    craftingRecipe(std::array<int, 63> a, int n, std::string s);
    bool is_craftable(playerClasses::player& p) const;
    bool craft_item(playerClasses::player& p);
    std::string get_recipe(playerClasses::player& p) const;
    void set_recipe(std::array<int, 63> a, int n, std::string s);
};

//cookinggRecipe class, which inherits recipe, for storing cooking recipes
class cookingRecipe: public Recipe {
    //declares private data members for cookingrecipe class
private:
    std::array<int, 63> recipeItems;//num_items
    std::array<std::string, 63> itemNames = {"Stick", "Leaf Pile", "Berry", "Log", "Fern", "Clay", "Mud", "Snail", "Perch", "Bass", "Stone", "Flint", "Iron", "Old Rope", "Ancient Tablet", "Long Grass", "Flower", "Animal Bones", "Fur Clump", "Meteor Fragment", "Shells", "Crab", "Driftwood", "Coral", "Hidden Treasure", "Steel Sheet", "Cloth", "Iron Shavings", "Plane Food", "Cushion", "Cloth Sheet", "Cementing Paste", "Watertight Base", "Sail", "Rudder", "Food Stores", "Circuits", "Speaker", "Radio Chip", "Communication Device", "Sturdy Boat", "Fist", "Sharpened Stick", "Stone Spear", "Iron Blade", "Meteorite Dagger", "Dirt", "Leaf Pile Bed", "Covered Leaf Bed", "Flower Bed with Fur Blanket", "Cushioned Twin Bed with Fur Blanket", "Air", "Mud Fence", "Stick Fence", "Log Fence", "Cross & Bones Fence", "Fire", "Raw Meat", "Fish Stew", "Cooked Meat", "Berry Jelly", "Snail Soup", "Seafood BBQ"};
    int index;
    std::string recipeDescription;
    //declares public functions for cookingrecipe class
public:
    cookingRecipe();
    cookingRecipe(std::array<int, 63> a, int n, std::string s);
    int get_energyRes() const;
    void set_energyRes(int e);
    bool is_craftable(playerClasses::player& p);
    bool craft_item(playerClasses::player& p);
    std::string get_recipe(playerClasses::player& p);
    void set_recipe(std::array<int, 63> a, int n, std::string s);
};
}

#endif /* recipeClasses_h */
