// Assignment 2 19T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Jeremy Chea (z5259650)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Added pointer check for the provided tests.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"

// Add your own #defines here.


// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE

#define VENUSAUR_ID 3
#define VENUSAUR_NAME "Venusaur"
#define VENUSAUR_HEIGHT 2.0
#define VENUSAUR_WEIGHT 100.0
#define VENUSAUR_FIRST_TYPE GRASS_TYPE
#define VENUSAUR_SECOND_TYPE POISON_TYPE

#define CHARMANDER_ID 4
#define CHARMANDER_NAME "Charmander"
#define CHARMANDER_HEIGHT 0.6
#define CHARMANDER_WEIGHT 8.5
#define CHARMANDER_FIRST_TYPE FIRE_TYPE
#define CHARMANDER_SECOND_TYPE NONE_TYPE

#define CHARMELEON_ID 5
#define CHARMELEON_NAME "Charmeleon"
#define CHARMELEON_HEIGHT 1.1
#define CHARMELEON_WEIGHT 19.0
#define CHARMELEON_FIRST_TYPE FIRE_TYPE
#define CHARMELEON_SECOND_TYPE NONE_TYPE

#define CHARIZARD_ID 6
#define CHARIZARD_NAME "Charizard"
#define CHARIZARD_HEIGHT 1.7
#define CHARIZARD_WEIGHT 90.5
#define CHARIZARD_FIRST_TYPE FIRE_TYPE
#define CHARIZARD_SECOND_TYPE NONE_TYPE

#define SQUIRTLE_ID 7
#define SQUIRTLE_NAME "Squirtle"
#define SQUIRTLE_HEIGHT 0.5
#define SQUIRTLE_WEIGHT 9.0
#define SQUIRTLE_FIRST_TYPE WATER_TYPE
#define SQUIRTLE_SECOND_TYPE NONE_TYPE

#define WARTORTLE_ID 8
#define WARTORTLE_NAME "Wartortle"
#define WARTORTLE_HEIGHT 1.0
#define WARTORTLE_WEIGHT 22.5
#define WARTORTLE_FIRST_TYPE WATER_TYPE
#define WARTORTLE_SECOND_TYPE NONE_TYPE

#define BLASTOISE_ID 9
#define BLASTOISE_NAME "Blastoise"
#define BLASTOISE_HEIGHT 1.6
#define BLASTOISE_WEIGHT 85.5
#define BLASTOISE_FIRST_TYPE WATER_TYPE
#define BLASTOISE_SECOND_TYPE NONE_TYPE


// Add your own prototypes here.

static void test_change_current_pokemon(void);
static void test_remove_pokemon(void);
static void test_count_found_pokemon(void);
static void test_count_total_pokemon(void);
static void test_get_pokemon_of_type(void);

// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_next_pokemon(void);

// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_venusaur(void);
static Pokemon create_charmander(void);
static Pokemon create_charmeleon(void);
static Pokemon create_charizard(void);
static Pokemon create_squirtle(void);
static Pokemon create_wartortle(void);
static Pokemon create_blastoise(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_change_current_pokemon();
    test_remove_pokemon();
    test_count_found_pokemon();
    test_count_total_pokemon();
    test_get_pokemon_of_type();
    
    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating all generation 1 starters and their evolutions\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();

    printf("    ... Adding all generation 1 starters and their evolutions\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);

    printf("    ... Counting number of pokemon in pokedex\n");
    assert(count_total_pokemon(pokedex)==8);
    add_pokemon(pokedex, blastoise);
    printf("    ... Now adding one and recounting\n");
    
    assert(count_total_pokemon(pokedex)==9);
    

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//

static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Testing when there is no pokemon\n");
    next_pokemon(pokedex);
    

    printf("    ... Creating all generation 1 starters and evolutions\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    
    printf("    ... Adding all generation 1 starters and evolutions\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
   

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
   

    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
   

    printf("       --> Checking that the current Pokemon is Charmander\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charmander));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
   

    printf("       --> Checking that the current Pokemon is Charmeleon\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charmeleon));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
   

    printf("       --> Checking that the current Pokemon is Charizard\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charizard));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
    
    
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!


// Write your own Pokedex tests here!


static void test_change_current_pokemon(void) {
    printf("\n>> Testing change_current_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating all generation 1 starters and evolutions\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    


    printf("    ... Adding all generation 1 starters and evolutions\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("    ... Changing current pokemon to blastoise\n");
    change_current_pokemon(pokedex, 9);
    
    printf("    ... Asserting that the currently selected pokemon is blastoise\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), blastoise));
    
    
    printf("    ... Destroying Pokedex\n");
    destroy_pokedex(pokedex);
    
    printf(">> Passed change_current_pokemon tests!\n");  
}    
static void test_remove_pokemon(void) {
    printf("\n>> Testing remove_pokemon\n");  
      
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating all generation 1 starters and evolutions\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    


    printf("    ... Adding all generation 1 starters and evolutions\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
   
    
    printf("    ... Removing bulbasaur\n");
    remove_pokemon(pokedex);
    
    printf("    ... Asserting that the new head of pokedex is ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));    

    printf("   ... Goes to next pokemon and tests again if the remove pokemon funciton works for when the current is one from the head\n");
    next_pokemon(pokedex);
    remove_pokemon(pokedex);
    assert(is_same_pokemon(get_current_pokemon(pokedex), charmander));
    
    printf("   ... Goes next by two in the list and tests once again\n");
    next_pokemon(pokedex);
    next_pokemon(pokedex);
    remove_pokemon(pokedex);
    assert(is_same_pokemon(get_current_pokemon(pokedex), squirtle));

    printf("    ... Destroying pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_found_pokemon tests!\n");  
}
static void test_count_found_pokemon(void) {
    printf("\n>> Testing get_pokemon_of_type\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating all generation 1 starters and evolutions\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    


    printf("    ... Adding all generation 1 starters and evolutions\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, blastoise);
    
    printf("    ... Finding bulbasaur\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Asserts that found count is correct\n");
    assert(count_found_pokemon(pokedex)==1);
    
    printf("    ... Finding blastoise\n");
    change_current_pokemon(pokedex, 9);
    find_current_pokemon(pokedex);
    
    printf("    ... Asserts that the new found count is correct\n");
    assert(count_found_pokemon(pokedex)==2);

    printf("    ... Destroying pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_found_pokemon tests!\n");  
}
static void test_count_total_pokemon(void) {
    printf("\n>> Testing count_total_pokemon\n");
    
        printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    
    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    
    printf("    ... Asserts count is correct");
    
    assert(count_total_pokemon(pokedex)==1);
 
    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);   
    
    printf("    ... Asserts count is correct after change");
    
    assert(count_total_pokemon(pokedex)==2);
 
    printf("    ... Destroying pokedex\n");
    destroy_pokedex(pokedex);
 
    printf(">> Passed count_total_pokemon tests!\n");   
    
}

static void test_get_pokemon_of_type(void) {
    printf("\n>> Testing get_pokemon_of_type\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating all generation 1 starters\n");
    Pokemon bulbasaur = create_bulbasaur();

    Pokemon charmander = create_charmander();

    Pokemon squirtle = create_squirtle();

    


    printf("    ... Adding all generation 1 starters\n");
    add_pokemon(pokedex, bulbasaur);

    add_pokemon(pokedex, charmander);

    add_pokemon(pokedex, squirtle);


    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Setting charmander to be found\n");
    change_current_pokemon(pokedex, 4);
    find_current_pokemon(pokedex);

    
    printf("    ... Searching new pokedex for fire types only\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, FIRE_TYPE);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(type_pokedex) == 1);
    assert(count_found_pokemon(type_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(type_pokedex), charmander));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_pokemon_of_type tests!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}
//Helper function to create Venusaur for testing purposes.
static Pokemon create_venusaur(void) {
    Pokemon pokemon = new_pokemon(
            VENUSAUR_ID, VENUSAUR_NAME,
            VENUSAUR_HEIGHT, VENUSAUR_WEIGHT,
            VENUSAUR_FIRST_TYPE,
            VENUSAUR_SECOND_TYPE
    );
    return pokemon;
}
//Helper function to create Charmander for testing purposes.
static Pokemon create_charmander(void) {
    Pokemon pokemon = new_pokemon(
            CHARMANDER_ID, CHARMANDER_NAME,
            CHARMANDER_HEIGHT, CHARMANDER_WEIGHT,
            CHARMANDER_FIRST_TYPE,
            CHARMANDER_SECOND_TYPE
    );
    return pokemon;
}
//Helper function to create Charmeleon for testing purposes.
static Pokemon create_charmeleon(void) {
    Pokemon pokemon = new_pokemon(
            CHARMELEON_ID, CHARMELEON_NAME,
            CHARMELEON_HEIGHT, CHARMELEON_WEIGHT,
            CHARMELEON_FIRST_TYPE,
            CHARMELEON_SECOND_TYPE
    );
    return pokemon;
}
//Helper function to create Charizard for testing purposes.
static Pokemon create_charizard(void) {
    Pokemon pokemon = new_pokemon(
            CHARIZARD_ID, CHARIZARD_NAME,
            CHARIZARD_HEIGHT, CHARIZARD_WEIGHT,
            CHARIZARD_FIRST_TYPE,
            CHARIZARD_SECOND_TYPE
    );
    return pokemon;
}
//Helper function to create Squirtle for testing purposes.
static Pokemon create_squirtle(void) {
    Pokemon pokemon = new_pokemon(
            SQUIRTLE_ID, SQUIRTLE_NAME,
            SQUIRTLE_HEIGHT, SQUIRTLE_WEIGHT,
            SQUIRTLE_FIRST_TYPE,
            SQUIRTLE_SECOND_TYPE
    );
    return pokemon;
}//Helper function to create Wartortle for testing purposes.
static Pokemon create_wartortle(void) {
    Pokemon pokemon = new_pokemon(
            WARTORTLE_ID, WARTORTLE_NAME,
            WARTORTLE_HEIGHT, WARTORTLE_WEIGHT,
            WARTORTLE_FIRST_TYPE,
            WARTORTLE_SECOND_TYPE
    );
    return pokemon;
}//Helper function to create Blastoise for testing purposes.
static Pokemon create_blastoise(void) {
    Pokemon pokemon = new_pokemon(
            BLASTOISE_ID, BLASTOISE_NAME,
            BLASTOISE_HEIGHT, BLASTOISE_WEIGHT,
            BLASTOISE_FIRST_TYPE,
            BLASTOISE_SECOND_TYPE
    );
    return pokemon;
}


// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!

