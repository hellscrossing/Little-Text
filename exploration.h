// Created by Sarah Nadzan for CSIS 2605's Final Project.
// Dotted lines are to keep the code separated and easy to read.

// ---------------------------------------------------------------------------------------------------------------------

// E X P L O R A T I O N

// T A B L E  O F  C O N T E N T S

// W i s h  P l a i n s

// Generate Array.

// Movement Loop.

// Player Menu.

// L i t t l e  F o r e s t


// ---------------------------------------------------------------------------------------------------------------------

#ifndef exploration
#define exploration

// Include libraries.

#include "generation.h" // Generation funtions.
#include "collection.h" // Collection functions.
#include "confrontation.h" // Confrontation functions.
#include "interactions.h"

// ---------------------------------------------------------------------------------------------------------------------

// Wish Plains.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

const int MAX_WISH_ROWS = 5; // Max rows for loop.
const int MAX_WISH_COLS = 5; // Max columns for loop.
std::string wishPlains[MAX_WISH_ROWS][MAX_WISH_COLS]; // Array init.
std::string wishPlainsTiles[MAX_WISH_ROWS][MAX_WISH_COLS]; // Walked Array init.
int moveWishCol = 0; // Reset.
int moveWishRow = 0; // Reset.
int oldWishCol = 2; // Reset.
int oldWishRow = 2; // Reset.
int playerWishRow = 2; // Player start location.
int playerWishCol = 2; // Player start location.
int wishActive = 1; // Wish Active.
int forestActive = 0; // Forest Active.


// ---------------------------------------------------------------------------------------------------------------------

// Initialize Array.

// ---------------------------------------------------------------------------------------------------------------------

void initWish(){

    for (int wishRows = 0; wishRows < MAX_WISH_ROWS; wishRows++) {
        for (int wishCols = 0; wishCols < MAX_WISH_COLS; wishCols++) {

            // Loot Tiles.

            wishPlainsTiles[1][1] = "Loot"; // Left Column.
            wishPlainsTiles[2][3] = "Loot"; // Center Right Tile.
            wishPlainsTiles[2][1] = "Loot"; // Center Left Tile.
            wishPlainsTiles[3][1] = "Loot"; // Bottom Left Tile.

            // Creature Tiles.

            wishPlainsTiles[1][3] = "Creature-Lurking"; // Top Right Tile.
            wishPlainsTiles[3][2] = "Creature-Lurking"; // Bottom Middle Tile.

            // Monster Tiles.

            wishPlainsTiles[1][2] = "Monster-Lurking"; // Top Middle Tile.
            wishPlainsTiles[3][3] = "Monster-Lurking"; // Bottom Right Tile.

            // Player Start.

            wishPlainsTiles[2][2] = "Empty"; // Center Tile.

            // Block Tiles.

            wishPlainsTiles[0][wishCols] = "Blocked"; // Far Top Row.
            wishPlainsTiles[wishRows][0] = "Blocked"; // Far Left Column.
            wishPlainsTiles[4][wishCols] = "Blocked"; // Far Bottom Row.
            wishPlainsTiles[wishRows][4] = "Blocked"; // Far Right Column.

        } // End of wishPlainsTiles array.
    } // End of wishPlainsTiles array.

    for (int wishRows = 0; wishRows < MAX_WISH_ROWS; wishRows++) {
        for (int wishCols = 0; wishCols < MAX_WISH_COLS; wishCols++) {


            // Non-Walked Tiles.

            wishPlains[1][wishCols - 1] = "░"; // Top Row.
            wishPlains[wishRows - 1][1] = "░"; // Left Column.
            wishPlains[1][0] = "▓"; // Fix Exception. Blocked
            wishPlains[3][0] = "▓"; // Fix Exception. Blocked
            wishPlains[3][wishCols - 1] = "░"; // Bottom Row.
            wishPlains[wishRows - 1][3] = "░"; // Right Column.
            wishPlains[2][4] = "▓"; // Fix Exception. Blocked
            wishPlains[4][4] = "▓"; // Fix Exception. Blocked

            // Block Tiles.

            wishPlains[0][wishCols] = "▓"; // Far Top Row.
            wishPlains[wishRows][0] = "▓"; // Far Left Column.
            wishPlains[4][wishCols] = "▓"; // Far Bottom Row.
            wishPlains[wishRows][4] = "▓"; // Far Right Column.

        } // End of wishPlains array.
    } // End of wishPlains array.
} // End of InitWish()
// ---------------------------------------------------------------------------------------------------------------------

// Dungeon Loss Drop.

// ---------------------------------------------------------------------------------------------------------------------

void dungeonLoss() {

    // Resets location.

    if (wishActive = 1) // Wish Plains Reset.
    {
        playerWishRow = 2;
        playerWishCol = 2;
        wishPlains[playerWishRow][playerWishCol] = "◈";
        oldWishRow = 0;
        oldWishCol = 0;
        player.healthBar = player.healthMax;

    } // End wish if statement.

    /* if (forestActive = 1)
    {
        playerForestRow = 0;
        playerForestCol = 0;
        oldForestRow = 0;
        oldForestCol = 0;
        player.healthBar = player.healthMax;
    } // End forest if statement.
     */

    initBag(); // Resets bag.

} // End of dungeonLoss().

// ---------------------------------------------------------------------------------------------------------------------

// Flee.

// ---------------------------------------------------------------------------------------------------------------------

// Test to flee.

// Declare variable.

int fleeAttempt;

bool attemptFlee()
{
    // Declaring variables.

    srand(time(NULL)); // Random chance generation.
    int mainChance = (rand() % 10); // Random chance generation.
    int fleeAttempt; // True/false 1/0.
    int escapeChance; // Calculates based off enemy health.

    if (playerCombat = true)
    {
        int escapeChance = 20 - monsterHealthBar;
    } // End if combat.
    if (playerTaming = true)
    {
        int escapeChance = 20 - creatureHealthBar;
    }

    switch(escapeChance)
    {
        case 0:case 1:case 2:case 3:case 4:case 5:    // Case 0 - 5.
            {
                if (mainChance >=7) // 75% chance of failure.
                {
                    fleeAttempt = 0;
                } else // End success.
                {
                    fleeAttempt = 1;
                    std::cout << "Flee failed!\n";
                } // End fail.
                break;
            } // End 0 - 5.
            case 6:case 7:case 8:case 9:case 10: // 6 - 10.
            {
                if (mainChance >=5) // 50% chance of failure.
                {
                    fleeAttempt = 0;
                } else // End success.
                {
                    fleeAttempt = 1;
                    std::cout << "Flee failed!\n";
                } // End fail.
                break;
            } // End 6 - 10.
            case 11:case 12:case 13:case 14:case 15: // 11 - 15.
            {
                if (mainChance >=2) // 20% chance of failure.
                {
                    fleeAttempt = 0;
                } else // End success.
                {
                    fleeAttempt = 1;
                    std::cout << "Flee failed!\n";
                } // End fail.
                break;
            } // End 11 - 15.
            case 16:case 17:case 18:case 19:case 20: // 16 - 20.
            {
                fleeAttempt = 0; // Always works.
                break;
            } // End 16+.
    } // end escapeChance();

    return fleeAttempt; // Return value.
}
// End attemptFlee().

// Successful flee, send player back a space.

void fleeReset() {

    // Resets location.

    if (wishActive = 1) // Wish Plains Reset.
    {
        playerWishRow = oldWishRow;
        playerWishCol = oldWishCol;
        oldWishRow = oldWishRow - 1;
        oldWishCol = oldWishCol - 1;
    } // End wish if statement.
    /* if (forestActive = 1)
    {
        playerForestRow = oldForestRow;
        playerForestCol = oldForestCol;
        oldForestRow = oldForestRow - 1;
        oldForestCol = oldForestCol - 1;
    } // End forest if statement.
     */
} // End fleeReset();
// ---------------------------------------------------------------------------------------------------------------------

// Combat Function

// ---------------------------------------------------------------------------------------------------------------------

// Declare variable.

int combatMenu;

// Combat Screen.

void combatScreen() // Combat.

{

    // Declare variables.

    // Get stats.

    getMonsterStats();

    // Get moves.

    do {

        playerCombat = true;

        std::cout << "What would you like to do?\n";
        std::cout << "1 - Attack\n";
        std::cout << "2 - Bag\n";
        std::cout << "3 - Flee\n";
        std::cin >> combatMenu;

        switch (combatMenu) // Combat menu.
        {
            case 1: // Attack.
            {
                getPlayerMove();
                getMonsterMove();

                combatMenu = 0;
                break;
            } // End attack.
            case 2: // Bag.
            {
                checkBag();
                combatMenu = 0;
                break;
            } // End bag.
            case 3: // Flee.
            {
                attemptFlee();
                if (fleeAttempt = 0)
                {
                    fleeReset();
                    monsterHealthBar = 0;
                    combatMenu = 0;
                    break;
                }
                if (fleeAttempt = 1)
                {
                    getMonsterMove();
                    combatMenu = 0;
                    break;
                }
            } // End flee.
            default:
            {
                std::cout << "Please enter a valid direction!\n";
                std::cin.clear();
                std::cin.ignore(),'\n';
                std::cin >> combatMenu;
                break;
            }

        } // End combat Menu.

    } while (player.healthBar > 0 && monsterHealthBar > 0); // Keep fighting while health both parties alive.

    // Ending statements.

    if (player.healthBar <= 0) // Player Loss.
    {
        std::cout << playerName << " has no more energy to battle! You flee. \n";
        std::cout << "Your bag has been emptied, but you've managed to get out safely. \n" << std::endl;

        // Journal updates.

        if (monsterFound == tinyShadow.displayName) // Tiny Shadow
        {
            tinyShadow.encounter = true;
        }// end tinyShadow

        if (monsterFound == smallShadow.displayName) // Small Shadow
        {
            smallShadow.encounter = true;
        } // end smallShadow

        playerCombat = false;

        dungeonLoss(); // Deletes bag.

    } // End player Loss.

    if (monsterHealthBar <= 0) // Monster Loss.
    {
        playerCombat = false;
        std::cout << playerName << " has won the battle! " << monsterFound << " has disappeared.\n" << std::endl;

        // Journal updates.

        if (monsterFound == tinyShadow.displayName) // Tiny Shadow
            {
                tinyShadow.encounter = true;
                tinyShadow.defeat = true;
            }// end tinyShadow

        if (monsterFound == smallShadow.displayName) // Small Shadow
            {
                smallShadow.encounter = true;
                smallShadow.defeat = true;
            } // end smallShadow

        generateLoot();
        lootPickup();
    } // End monster Loss.

} // End of Combat Screen.

// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------

// Taming Function

// ---------------------------------------------------------------------------------------------------------------------

// Taming Screen.

void tamingScreen()
{
    // Get stats.

    getCreatureStats();

    // Get moves.

    do {
        playerTaming = true;

        std::cout << "What would you like to do?\n";
        std::cout << "1 - Attack\n";
        std::cout << "2 - Bag\n";
        std::cout << "3 - Flee\n";
        std::cin.ignore(),'\n';
        std::cin >> combatMenu;

        switch (combatMenu)
        {
            case 1: // Attack.
            {
                getPlayerMove();
                getCreatureMove();

                combatMenu = 0;
                break;
            } // End attack.
            case 2: // Bag.
            {
                checkBag();
                combatMenu = 0;
                break;
            } // End bag.
            case 3: // Flee.
            {
                attemptFlee();
                if (fleeAttempt = 0)
                {
                    fleeReset();
                    monsterHealthBar = 0;
                    combatMenu = 0;
                    break;
                }
                if (fleeAttempt = 1)
                {
                    getMonsterMove();
                    combatMenu = 0;
                    break;
                }
            } // End flee.
            default:
            {
                std::cout << "Please enter a valid choice!\n";
                std::cin.clear();
                std::cin.ignore(),'\n';
                std::cin >> combatMenu;
            }

        } // End combat Menu.

    } while (player.healthBar > 0 && creatureHealthBar > 0 && creatureTrustBar < creatureTrustMax); // Keep fighting while health both parties alive.

    // Ending statements.

    if (player.healthBar <= 0) // Player Loss.
    {
        std::cout << playerName << " has no more energy to battle! You flee. \n";
        std::cout << "Your bag has been emptied, but you've managed to get out safely. \n" << std::endl;

        // Journal updates.

        if (creatureFound == squirrel.displayName) // Squirrel
        {
            squirrel.encounter = true;
        }// end squirrel

        if (creatureFound == rabbit.displayName) // Rabbit
        {
            rabbit.encounter = true;
        } // end rabbit

        if (creatureFound == deer.displayName) // Deer
        {
            deer.encounter = true;
        } // end deer

        if (creatureFound == fox.displayName) // Fox
        {
            fox.encounter = true;
        } // end fox

        if (creatureFound == wolf.displayName) // Wolf
        {
            wolf.encounter = true;
        } // end wolf

        if (creatureFound == bear.displayName) // Bear
        {
            bear.encounter = true;
        } // end bear

        dungeonLoss(); // Deletes bag.
        playerTaming = false;

    } // End player Loss.

    if (creatureTrustBar >= creatureTrustMax) // Creature Tamed.
    {

        int nameChoice;
        playerTaming = false;
        std::cout << creatureFound << " has begun to trust " << playerName << "!\n" << std::endl;

        // Journal updates.

        if (creatureFound == squirrel.displayName) // Squirrel
        {
            squirrel.encounter = true;
            squirrel.defeat = true;
        }// end squirrel

        if (creatureFound == rabbit.displayName) // Rabbit
        {
            rabbit.encounter = true;
            rabbit.defeat = true;
        } // end rabbit

        if (creatureFound == deer.displayName) // Deer
        {
            deer.encounter = true;
            deer.defeat = true;
        } // end deer

        if (creatureFound == fox.displayName) // Fox
        {
            fox.encounter = true;
            fox.defeat = true;
        } // end fox

        if (creatureFound == wolf.displayName) // Wolf
        {
            wolf.encounter = true;
            wolf.defeat = true;
        } // end wolf

        if (creatureFound == bear.displayName) // Bear
        {
            bear.encounter = true;
            bear.defeat = true;
        } // end bear

        // Addition to party.

        tameConfirmation();

    } // End Creature Tamed.

    if (creatureHealthBar <= 0) // Creature Loss.
    {
        playerTaming = false;
        std::cout << playerName << " has won the battle! " << creatureFound << " fled.\n" << std::endl;

        // Journal updates.

        if (creatureFound == squirrel.displayName) // Squirrel
        {
            squirrel.encounter = true;
            squirrel.defeat = true;
        }// end squirrel

        if (creatureFound == rabbit.displayName) // Rabbit
        {
            rabbit.encounter = true;
            rabbit.defeat = true;
        } // end rabbit

        if (creatureFound == deer.displayName) // Deer
        {
            deer.encounter = true;
            deer.defeat = true;
        } // end deer

        if (creatureFound == fox.displayName) // Fox
        {
            fox.encounter = true;
            fox.defeat = true;
        } // end fox

        if (creatureFound == wolf.displayName) // Wolf
        {
            wolf.encounter = true;
            wolf.defeat = true;
        } // end wolf

        if (creatureFound == bear.displayName) // Bear
        {
            bear.encounter = true;
            bear.defeat = true;
        } // end bear

        generateLoot();
        lootPickup();

    } // End Creature Loss.

} // End of Taming Screen.

// ---------------------------------------------------------------------------------------------------------------------

// Move the player.

// ---------------------------------------------------------------------------------------------------------------------

// Get the Move. -------------------------------------------------------------------------------------------------------

void wishMove () {

    std::string moveWishChoice; // Declare Input Variable.
    for (;;) {

        std::cout << "\nWhich direction would you like to move?\n" << std::endl;
        std::cout << "North (n), South (s), East (e), or West (w)?\n" << std::endl;
        std::cin.ignore(), '\n';
        std::cin >> moveWishChoice;

        if (moveWishChoice == "n") // North
        {
            moveWishRow = playerWishRow - 1;
            moveWishCol = playerWishCol;

            oldWishRow = playerWishRow;
            oldWishCol = playerWishCol;
            playerWishRow = moveWishRow;
            playerWishCol = moveWishCol;

            break;
        } // End of North.

        if (moveWishChoice == "s") // South
        {
            moveWishRow = playerWishRow + 1;
            moveWishCol = playerWishCol;

            oldWishRow = playerWishRow;
            oldWishCol = playerWishCol;
            playerWishRow = moveWishRow;
            playerWishCol = moveWishCol;

            break;
        } // End of South.

        if (moveWishChoice == "e") // East
        {
            moveWishRow = playerWishRow;
            moveWishCol = playerWishCol + 1;

            oldWishRow = playerWishRow;
            oldWishCol = playerWishCol;
            playerWishRow = moveWishRow;
            playerWishCol = moveWishCol;

            break;
        } // End of East.

        if (moveWishChoice == "w") // West
        {
            moveWishRow = playerWishRow;
            moveWishCol = playerWishCol - 1;

            oldWishRow = playerWishRow;
            oldWishCol = playerWishCol;
            playerWishRow = moveWishRow;
            playerWishCol = moveWishCol;

            break;
        } // End of West.
        else {
            std::cout << "Please enter a valid direction!\n";
            std::cin.clear();
            std::cin.ignore(), '\n';
            std::cin >> moveWishChoice;
        } // End input validation.

    } // End input for loop.



} // end wishMove();

// Validate the move. --------------------------------------------------------------------------------------------------

void wishValidate() {

    if (wishPlainsTiles[moveWishRow][moveWishCol] == "Blocked") {
        std::cout
                << "The trees to this direction are too thick to get past. You might want to try somewhere else.\n";

        playerWishRow = oldWishRow; // Return player back a step.
        playerWishCol = oldWishCol; // Return player back a step.
        wishPlainsTiles[oldWishRow][oldWishCol] = "Empty";
    } // End of validation.

// Update player location. ---------------------------------------------------------------------------------------------

    if (wishPlainsTiles[moveWishRow][moveWishCol] != "Blocked") {

        wishPlains[playerWishRow][playerWishCol] = "◈";
        wishPlains[oldWishRow][oldWishCol] = "░";
        wishPlainsTiles[oldWishRow][oldWishCol] = "Empty";

        std::cout <<

                  "\n" << " | "  << wishPlains[0][0] << " | " << wishPlains[0][1] << " | " << wishPlains[0][2] << " | " << wishPlains[0][3] << " | " << wishPlains[0][4] << " | "  <<
                  "\n" <<
                  "\n" << " | "  << wishPlains[1][0] << " | " << wishPlains[1][1] << " | " << wishPlains[1][2] << " | " << wishPlains[1][3] << " | " << wishPlains[1][4] << " | "  <<
                  "\n" <<
                  "\n" << " | "  << wishPlains[0][0] << " | " << wishPlains[2][1] << " | " << wishPlains[2][2] << " | " << wishPlains[2][3] << " | " << wishPlains[2][4] << " | "  <<
                  "\n" <<
                  "\n" << " | "  << wishPlains[0][0] << " | " << wishPlains[3][1] << " | " << wishPlains[3][2] << " | " << wishPlains[3][3] << " | " << wishPlains[3][4] << " | "  <<
                  "\n" <<
                  "\n" << " | "  << wishPlains[0][0] << " | " << wishPlains[4][1] << " | " << wishPlains[4][2] << " | " << wishPlains[4][3] << " | " << wishPlains[4][4] << " | "

                << std::endl;
        
    } // End of player location update.

} // end wishValidate();

// ---------------------------------------------------------------------------------------------------------------------

// Player Interactions.

// ---------------------------------------------------------------------------------------------------------------------

// Check the Tile. -----------------------------------------------------------------------------------------------------

bool blockActivated;

void wishCheck(){

    int buffConfirmation; // declare variable.

    if (wishPlainsTiles[moveWishRow][moveWishCol] == "Loot") // Wish Plains Loot.
        {
        if (blockActivated == true)
            {

                for(;;)
                    {
                        std::cout << "Your companion is ready to stop something from happening.\n";
                        std::cout << "Would you like to skip this event?\n";
                        std::cout << "1 - Yes\n2 - No\n";
                        std::cin.ignore(), '\n';
                        std::cin >> buffConfirmation;
                        if (buffConfirmation == 1)
                            {
                                std::cout << "You have skipped past this tile.\n";
                                wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
                                break;
                            } // End if statement Yes
                        if (buffConfirmation == 2)
                            {
                                    std::cout << "You have chosen not to skip this event.\n";
                                    generateLoot();
                                    lootPickup();
                                    wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
                                    break;
                            } // End if statement No
                    } // End loop validation.
            } // end blockActivated
            if(blockActivated != true)
                {
                    generateLoot();
                    lootPickup();
                    wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
                } // end else.
        } // End Loot.

    if (wishPlainsTiles[moveWishRow][moveWishCol] == "Monster-Lurking") // Wish Plains Monster.
        {
            if (blockActivated == true)
            {
                for(;;)
                {
                    std::cout << "Your companion is ready to stop something from happening.\n";
                    std::cout << "Would you like to skip this event?\n";
                    std::cout << "1 - Yes\n2 - No\n";
                    std::cin.ignore(), '\n';
                    std::cin >> buffConfirmation;
                    if (buffConfirmation == 1)
                    {
                        std::cout << "You have skipped past this tile.\n";
                        wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
                        break;
                    } // End if statement Yes
                    if (buffConfirmation == 2)
                    {
                        std::cout << "You have chosen not to skip this event.\n";
                        generateMonster();
                        combatScreen();
                        wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
                        break;
                    } // End if statement No
                } // End loop validation.
            } // End blockActivated.
            if(blockActivated != true)
            {
                generateMonster();
                combatScreen();
                wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
            } // end else.
        } // End Monster-Lurking
    if (wishPlainsTiles[moveWishRow][moveWishCol] == "Creature-Lurking") // Wish Plains Creature.
        {
            if (blockActivated == true)
            {
                for(;;)
                {
                    std::cout << "Your companion is ready to stop something from happening.\n";
                    std::cout << "Would you like to skip this event?\n";
                    std::cout << "1 - Yes\n2 - No\n";
                    std::cin.ignore(), '\n';
                    std::cin >> buffConfirmation;
                    if (buffConfirmation == 1)
                    {
                        std::cout << "You have skipped past this tile.\n";
                        wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
                        break;
                    } // End if statement Yes
                    if (buffConfirmation == 2)
                    {
                        std::cout << "You have chosen not to skip this event.\n";
                        generateWishCreature();
                        tamingScreen();
                        wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
                        break;
                    } // End if statement No
                } // End loop validation.
            } // End blockActivated.
            if(blockActivated != true)
            {
                generateWishCreature();
                tamingScreen();
                wishPlainsTiles[playerWishRow][playerWishCol] = "Empty";
            } // end else.
        } // End Creature-Lurking.

    // End Condition.

    if (wishPlainsTiles[1][1] == "Empty" && wishPlainsTiles[1][2] == "Empty" && wishPlainsTiles[1][3] == "Empty"
        && wishPlainsTiles[2][1] == "Empty" && wishPlainsTiles[2][2] == "Empty" && wishPlainsTiles[2][3] == "Empty"
        && wishPlainsTiles[3][1] == "Empty" && wishPlainsTiles[3][2] == "Empty" && wishPlainsTiles[3][3] == "Empty") {
        wishActive = 0;
        std::cout << "Nora turns to you.\n ''Congratulations, " << playerName
                  << "! You've learned all I have to teach. \n";
        std::cout
                << "Now, it's time I show you to your test.''\n She begins to lead you toward the forest in the distance. \n";
        forestActive = 1; // Activate the Little Forest.
    }

} // End of wishCheck().
// ---------------------------------------------------------------------------------------------------------------------

void wishLoop () {

    wishMove(); // get move from player
    wishValidate(); // validate move, no blocked tiles
    wishCheck(); // check tile interaction

} // End wishLoop.

// ---------------------------------------------------------------------------------------------------------------------

// Player Menu and Buff addition.

// ---------------------------------------------------------------------------------------------------------------------

void worldBuffs()
{

    for (int tameRows = 0; tameRows < tameCount; tameRows++)
    {
        if (playerTame[tameRows][2] == "Gather")
        {
            // Declare variables.

            srand(time(NULL)); // Random chance generation.
            int mainChance = (rand() % 10); // Random chance generation.

            if (mainChance <= 2) // 20% chance of getting something.
            {
                lootPickup();
            } // End if statement

        } // End Gather.
        if (playerTame[tameRows][2] == "Hutch")
        {
            player.healthBar = player.healthBar + 1;
        } // End Hutch.
        if (playerTame[tameRows][2] == "Listen")
        {

            srand(time(NULL)); // Random chance generation.
            int mainChance = (rand() % 10); // Random chance generation.

            if (mainChance <= 2) // 20% chance of hearing something.
            {
                std::string moveWishChoice;

                for(;;) {

                    std::cout << "Your companion seems to hear something.\n Which direction is it coming from?\n";
                    std::cout << "North (n), South (s), East (e), West(w)\n";
                    std::cin.ignore(), '\n';
                    std::cin >> moveWishChoice;
                    if (moveWishChoice == "n")
                    {
                        std::cout << "Your companion listens carefully to the north.\n";
                        std::cout << "It appears to be a " << wishPlainsTiles[playerWishRow - 1][playerWishCol] << " space.\n";
                        break;
                    }
                    if (moveWishChoice == "s")
                    {
                        std::cout << "Your companion listens carefully to the south.\n";
                        std::cout << "It appears to be a " << wishPlainsTiles[playerWishRow + 1][playerWishCol] << " space.\n";
                        break;
                    }
                    if (moveWishChoice == "e")
                    {
                        std::cout << "Your companion listens carefully to the east.\n";
                        std::cout << "It appears to be a " << wishPlainsTiles[playerWishRow][playerWishCol + 1] << " space.\n";
                        break;
                    }
                    if (moveWishChoice == "w")
                    {
                        std::cout << "Your companion listens carefully to the west.\n";
                        std::cout << "It appears to be a " << wishPlainsTiles[playerWishRow][playerWishCol - 1] << " space.\n";
                        break;
                    }else
                    {
                        std::cout << "Please enter a valid direction!\n";
                        std::cin.clear();
                        std::cin.ignore(), '\n';
                        std::cin >> moveWishChoice;
                    } // End else.
                } // End loop validation.
            } // End if statement
        } // End Listen.
        if (playerTame[tameRows][2] == "Trot")
        {
            srand(time(NULL)); // Random chance generation.
            int mainChance = (rand() % 10); // Random chance generation.
            int subConfirmation;
            std::string moveWishChoice;

            if (mainChance <= 2) // 20% chance of jumping.
            {
                for(;;) {
                    std::cout << "Your companion wants to jump forwards a space.\n Would you like to?\n";
                    std::cout << "1 - Yes\n2 - No\n";
                    std::cin.ignore(), '\n';
                    std::cin >> subConfirmation;
                    if (subConfirmation = 2) // no
                    {
                        std::cout << "You decided not to jump.\n";
                        subConfirmation = 0;
                    } // end no
                    if (subConfirmation = 1) {
                        std::cout << "You decided to jump. Which direction will you choose?\n";
                        std::cout << "North (n), South (s), East (e), West(w)?\n";
                        std::cin.ignore(), '\n';
                        std::cin >> moveWishChoice;
                        if (moveWishChoice == "n") {
                            std::cout << "Your companion takes you forward to the north.\n";

                            moveWishRow = playerWishRow - 1;
                            moveWishCol = playerWishCol;

                            oldWishRow = playerWishRow;
                            oldWishCol = playerWishCol;
                            playerWishRow = moveWishRow;
                            playerWishCol = moveWishCol;

                            wishValidate();

                            wishCheck();

                            break;
                        }
                        if (moveWishChoice == "s") {
                            std::cout << "Your companion takes you forward to the south.\n";

                            moveWishRow = playerWishRow + 1;
                            moveWishCol = playerWishCol;

                            oldWishRow = playerWishRow;
                            oldWishCol = playerWishCol;
                            playerWishRow = moveWishRow;
                            playerWishCol = moveWishCol;

                            wishValidate();

                            wishCheck();

                            break;
                        }
                        if (moveWishChoice == "e") {
                            std::cout << "Your companion takes you forward to the east.\n";

                            moveWishRow = playerWishRow;
                            moveWishCol = playerWishCol + 1;

                            oldWishRow = playerWishRow;
                            oldWishCol = playerWishCol;
                            playerWishRow = moveWishRow;
                            playerWishCol = moveWishCol;

                            wishValidate();

                            wishCheck();

                            break;
                        }
                        if (moveWishChoice == "w") {
                            std::cout << "Your companion takes you forward to the west.\n";
                            moveWishRow = playerWishRow;
                            moveWishCol = playerWishCol - 1;

                            oldWishRow = playerWishRow;
                            oldWishCol = playerWishCol;
                            playerWishRow = moveWishRow;
                            playerWishCol = moveWishCol;

                            wishValidate();

                            wishCheck();

                            break;
                        } else {
                            std::cout << "Please enter a valid direction!\n";
                            std::cin.clear();
                            std::cin.ignore(), '\n';
                            std::cin >> moveWishChoice;
                        } // End else.
                    } // end yes.
                } // End loop validation.
            } // End if statement
        } // End Trot.
        if (playerTame[tameRows][2] == "Growl")
        {
            // Declare variables.

            srand(time(NULL)); // Random chance generation.
            int mainChance = (rand() % 10); // Random chance generation.

            if (mainChance <= 2) // 20% chance of taming.
            {
                tamingScreen();
            } // End if statement taming
            if (mainChance > 2 && mainChance <= 4) // 20% chance of combat.
            {
                combatScreen();
            } // end if statement combat
        } // End Growl.
        if (playerTame[tameRows][2] == "Block")
        {
            // Occurs in tile check.
            blockActivated = true;
        } // End Block.
    }

} // End of worldBuffs()

// ---------------------------------------------------------------------------------------------------------------------

// Player Info Menu.

// ---------------------------------------------------------------------------------------------------------------------

void playerInfoMenu()
{
    for(;;) {
        int subConfirmation;
        std::cout << "Would you like to read about yourself, or your encounters?\n";
        std::cout << "1 -" << playerName << "\n2 - Encounter Journal\n3 - Exit\n";
        std::cin.ignore(), '\n';
        std::cin >> subConfirmation;
        if (subConfirmation == 1) // player
        {

            std::cout << "" << std::endl;
            std::cout << "Name: " << playerName << "\n";
            std::cout << "Occupation: " << player.displayName + " " + player.combatType << "\n";
            std::cout << "Patron Animal: " << playerAnimal << "\n";
            std::cout << "Totem Level: " << player.totemLevel << "\n";
            std::cout << "Ability: " << player.ability << "\n";
            std::cout << "Stats:\n" << "Health: " << player.healthBar << " / " << player.healthMax << "\n" <<
            "Attack: " << player.attack << "Defense: " << player.defense << "\n";
            std::cout << "About: " << player.desc << "\n";
            std::cout << "" << std::endl;

            break;
        } // End playerName, 1
        if (subConfirmation == 2) // encounter journal
        {
            checkJournal();
            break;
        } // end encounter journal, 2
        if (subConfirmation == 3) // exit
        {
            break;
        } // end exit, 3
        else
        {
            std::cout << "Please enter a valid choice!\n";
            std::cin.clear();
            std::cin.ignore(), '\n';
            std::cin >> subConfirmation;
        } // end else
    } // End validation loop.
} // End checkInfoMenu()

// ---------------------------------------------------------------------------------------------------------------------

// Player Menu.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

int turnChoice = 0; // Reset the Menu.

void wishPlayerMenu()
{
    do{
        worldBuffs();
            std::cout << "What would you like to do? \n"; // Ask the player.
            std::cout << "1 - Move \n"; // Move the player.
            std::cout << "2 - " + playerName + " \n"; // Player info.
            std::cout << "3 - Bag \n"; // Bag info.
            std::cout << "4 - Companions \n"; // Tamed Animal info.
            std::cin.ignore(),'\n';
            std::cin >> turnChoice; // User chooses.

        switch(turnChoice){

            case 1: // Move player.
            {
                worldBuffs();
                wishLoop();
                turnChoice = 0;
                break;
            }
            case 2: // Player info.
            {
                playerInfoMenu();
                turnChoice = 0;
                break;
            }
            case 3: // Player bag.
            {
                checkBag();
                turnChoice = 0;
                break;
            }
            case 4: // Player tamed animals.
            {
                checkTame();
                turnChoice = 0;
                break;
            }
            default: // Failed input. Retry.
            {
                    std::cout << "Please enter a valid choice!\n";
                    std::cin.clear();
                    std::cin.ignore(),'\n';
                    std::cin >> turnChoice;
            }
        } // end of turnChoice();
    }while(wishActive = 1); // End of loop.
} // end of PlayerMenu().

// ---------------------------------------------------------------------------------------------------------------------

#endif //exploration

// ---------------------------------------------------------------------------------------------------------------------