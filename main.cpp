#include "hash.h"

int main(int argc, char** argv) 
{    
    hash hashOb;
    hashOb.AddItem("Paul", "Whiskey");
    hashOb.AddItem("Kim", "Scotch");
    hashOb.AddItem("Emma", "Vodka");
    hashOb.AddItem("Annie", "Rum");
    hashOb.AddItem("Sarah", "White wine");
    hashOb.AddItem("Pepper", "Beer");
    hashOb.AddItem("Mike", "Brandy");
    hashOb.AddItem("Steve", "Moonshine");
    hashOb.AddItem("Bill", "Red wine");
    hashOb.AddItem("Marie", "Tequila");
    hashOb.AddItem("Susan", "Absinthe");
    hashOb.AddItem("Joe", "Water");
    
    hashOb.RemoveItem("Paul");

    return 0;
}