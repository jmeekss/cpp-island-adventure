/*
 * Author   J Meeks
 * Purpose  implementation file for classes relating to recipe
 */

#include <stdio.h>
#include <string>
#include <array>
#include "playerClasses.h"
#include "recipeClasses.h"

namespace recipeClasses{

craftingRecipe::craftingRecipe(){ //default constructor for recipe, fills with blank info
    recipeItems = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};
    recipeDescription = " ";
    index = 0;
}

craftingRecipe::craftingRecipe(std::array<int, 63> a, int n, std::string s){ //constructor for filling recipe with info sent in
    for(unsigned int j = 0; j < recipeItems.size(); j++){
        recipeItems[j] = a[j];
    }
    index = n;
    recipeDescription = s;
}

bool craftingRecipe::is_craftable(playerClasses::player& p) const{ //returns whether or not the player can currently craft an item
    bool craftable = true;
    
    for(unsigned int i = 0; i < 63; i++){
        if(p.get_quantity(i) < recipeItems[i]){
            craftable = false;
        }
    }
    
    return craftable;
}

bool craftingRecipe::craft_item(playerClasses::player& p){ //crafts a recipe if possible, adds the item to users inventory, consumes materials
    if(!is_craftable(p)){
        return false;
    }
    
    //updates players inventory
    for(unsigned int i = 0; i < 63; i++){
        p.set_inventory(i, p.get_quantity(i) - recipeItems[i]);
    }
    p.add_item(index);
    return true;
}

std::string craftingRecipe::get_recipe(playerClasses::player& p) const{ //gets a recipes info, including description, craft status, and materials
    std::string rec = itemNames[index] + ": " + recipeDescription;
    if(is_craftable(p)){ //gest the craft status
        rec += "     [CURRENTLY CRAFTABLE]";
    } else {
        rec += "     [NOT CURRENTLY CRAFTABLE]";
    }
    for(unsigned int i = 0; i < 63; i++){ //gets the material list
        if(recipeItems[i] > 0){
            rec = rec + "\n     ×" + std::to_string(recipeItems[i]) + " " + itemNames[i] + " (You Have: ×" + std::to_string(p.get_quantity(i)) + ")";
        }
    }
    return rec + "\n";
}

void craftingRecipe::set_recipe(std::array<int, 63> a, int n, std::string s){ //sets the recipe based on specified information
    for(unsigned int j = 0; j < recipeItems.size(); j++){
        recipeItems[j] = a[j];
    }
    recipeDescription = s;
    index = n;
}

cookingRecipe::cookingRecipe(){ //default constructor for creating blank cooking recipe
    recipeItems = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};
    index = 0;
    recipeDescription = "";
}

cookingRecipe::cookingRecipe(std::array<int, 63> a, int n, std::string s){ //constructor for creating cookingrecipe based on specified info
    for(unsigned int j = 0; j < recipeItems.size(); j++){
        recipeItems[j] = a[j];
    }
    index = n;
    recipeDescription = s;
}

bool cookingRecipe::is_craftable(playerClasses::player& p){ //returns whether or not player can currently cook item
    bool craftable = true;
    
    for(unsigned int i = 0; i < 63; i++){
        if(p.get_quantity(i) < recipeItems[i]){
            craftable = false;
        }
    }
    
    return craftable;
}

bool cookingRecipe::craft_item(playerClasses::player& p){ //allows player to craft item, returns success status, updates inventory
    if(!is_craftable(p)){
        return false;
    }
    //updates inventory after crafting
    for(unsigned int i = 0; i < 63; i++){
        p.set_inventory(i, p.get_quantity(i) - recipeItems[i]);
    }
    p.add_item(index);
    return true;
}

std::string cookingRecipe::get_recipe(playerClasses::player& p){ //gets a recipes info, including description, craft status, and materials
    std::string rec = itemNames[index] + ": " + recipeDescription;
    
    if(is_craftable(p)){
        rec += "     [CURRENTLY COOKABLE]";
    } else {
        rec += "     [NOT CURRENTLY COOKABLE]";
    }
    for(unsigned int i = 0; i < 63; i++){ //gets the material list
        if(recipeItems[i] > 0){
            rec = rec + "\n\t×" + std::to_string(recipeItems[i]) + " " + itemNames[i] + " (You Have: ×" + std::to_string(p.get_quantity(i)) + ")";
        }
    }
    return rec + "\n";
}

void cookingRecipe::set_recipe(std::array<int, 63> a, int n, std::string s){ //sets the recipe with the specified information
    for(unsigned int j = 0; j < recipeItems.size(); j++){
        recipeItems[j] = a[j];
    }
    recipeDescription = s;
    index = n;
}
}
