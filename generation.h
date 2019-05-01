// Created by Sarah Nadzan for CSIS 2605's Final Project.
// Dotted lines are to keep the code separated and easy to read.

// ---------------------------------------------------------------------------------------------------------------------

// G E N E R A T I O N

// T A B L E  O F  C O N T E N T S

// Player Animal Diety.

// Monsters in Dungeons.

// Creatures in Dungeons.

// ---------------------------------------------------------------------------------------------------------------------

#ifndef generation
#define generation

// Include libraries.

/* #include <string>
#include <iostream> */

// ---------------------------------------------------------------------------------------------------------------------

// Generate player's Animal.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variable.

std::string playerAnimal;

void animalRandom()
{

    // Declaring variables.

    srand(time(NULL)); // Random chance generation.
    int mainChance = (rand() % 10); // Random chance generation.

    if (mainChance <= 2)
        // 20% chance of finding Squirrel.
    {
        playerAnimal = "Squirrel";
    } // End of Little Forest Squirrel.

    if ((mainChance <= 4) && (mainChance > 2))
        // 20% chance of finding Rabbit.
    {
        playerAnimal = "Rabbit";
    } // End of Little Forest Rabbit.

    if ((mainChance <= 6) && (mainChance > 4))
        // 15% chance of finding Deer.
    {
        playerAnimal = "Deer";
    } // End of Little Forest Deer.

    if ((mainChance <= 8) && (mainChance > 6))
        // 15% chance of finding Fox.
    {
        playerAnimal = "Fox";
    } // End of Little Forest Fox.

    if ((mainChance <= 9) && (mainChance > 8))
        // 15% chance of finding Wolf.
    {
        playerAnimal = "Wolf";
    } // End of Little Forest Wolf.

    if ((mainChance <= 10) && (mainChance > 9))
        // 15% chance of finding Bear.
    {
        playerAnimal = "Bear";
    } // End of Little Forest Bear.

} // End of player animal.

// ---------------------------------------------------------------------------------------------------------------------

// Generating the monsters in dungeons.

// ---------------------------------------------------------------------------------------------------------------------

// Declaring Variables.

std::string monsterFound = "None";

// Loop

void generateMonster()

{

    srand(time(NULL)); // Put into int main ()

    int mainChance = (rand() % 10); // Random chance generator.

    if (mainChance <= 6)

// 60% chance of finding Tiny Shadow.

    {
        monsterFound = "Tiny Shadow";
    }

    else

// 40% chance of finding Small Shadow.
    {
        monsterFound = "Small Shadow";
    }

    std::cout << "You have encountered a " << monsterFound << "! \n";

} // End of Monster Generation.

// ---------------------------------------------------------------------------------------------------------------------

// Generating the creatures in dungeons.

// ---------------------------------------------------------------------------------------------------------------------

std::string creatureFound; // Declare the variable.

void generateWishCreature () {

    // Declaring variables.

    srand(time(NULL)); // Random chance generation.
    int mainChance = (rand() % 10); // Random chance generation.

    // Chance.

    if (mainChance < 5)
        // 50% chance of finding Squirrel.
    {
        creatureFound = "Squirrel";
    } // End of Wish Plains Squirrel.

    else // 50% chance of finding Rabbit.
    {
        creatureFound = "Rabbit";
    } // End of Wish Plains Rabbit.

    std::cout << "You have encountered a " << creatureFound << "! \n";

} // End of Wish Plains Generation.

// Little Forest Generation.

void generateForestCreature()
{
    srand(time(NULL)); // Random chance generation.
    int mainChance = (rand() % 10); // Random chance generation.

    if (mainChance <= 2)
        // 20% chance of finding Squirrel.
    {
        creatureFound = "Squirrel";
    } // End of Little Forest Squirrel.

    if ((mainChance <= 4) && (mainChance > 2))
        // 20% chance of finding Rabbit.
    {
        creatureFound = "Rabbit";
    } // End of Little Forest Rabbit.

    if ((mainChance <= 6) && (mainChance > 4))
        // 15% chance of finding Deer.
    {
        creatureFound = "Deer";
    } // End of Little Forest Deer.

    if ((mainChance <= 8) && (mainChance > 6))
        // 15% chance of finding Fox.
    {
        creatureFound = "Fox";
    } // End of Little Forest Fox.

    if ((mainChance <= 9) && (mainChance > 8))
        // 15% chance of finding Wolf.
    {
        creatureFound = "Wolf";
    } // End of Little Forest Wolf.

    else
        // 15% chance of finding Bear.
    {
        creatureFound = "Bear";
    } // End of Little Forest Bear.

    std::cout << "You have encountered a " << creatureFound << "! \n";

} // End of Little Forest Generation.

// End of Creature Generator.

// ---------------------------------------------------------------------------------------------------------------------

#endif //generation

// ---------------------------------------------------------------------------------------------------------------------
