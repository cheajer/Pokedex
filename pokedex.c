// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Jeremy Chea (z5259650)
// on 24/04/19
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.

#define TRUE 1
#define FALSE 0

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {

    struct pokenode *head;
    struct pokenode *current_pokemon;

};



// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    struct pokenode *prev;
    struct pokenode *evolution;
    int found;
    Pokemon         pokemon;
};


// Add any other structs you define here.


// Add prototypes for any extra functions you create here.

//int search_string(char *name, char *input);

// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {

    struct pokenode *new_pokemon = malloc(sizeof(struct pokenode));
    struct pokenode *old_node = pokedex -> head;

    if (new_pokemon == NULL) {
        printf("Memory Allocation failed\n");
        exit(1);
    };

    new_pokemon -> next = NULL;
    new_pokemon -> pokemon = pokemon;
    new_pokemon -> found = FALSE;
    new_pokemon -> evolution = NULL;

    if (old_node == NULL) {
        pokedex -> head = new_pokemon;
        new_pokemon->next = NULL;
        new_pokemon -> prev =NULL;;
        pokedex -> current_pokemon = new_pokemon;
        
    } else {

        while (old_node->next != NULL) {

            old_node = old_node->next;

        }
        old_node-> next =new_pokemon;
        new_pokemon-> prev =old_node;
    }

}

void detail_pokemon(Pokedex pokedex) {
    int i = 0;
    struct pokenode *poke_detail = pokedex -> current_pokemon;


    //If pokemon has not been found this if statement is triggered
    if (poke_detail -> found == FALSE) {
        //If the pokemon ID is between 0 and 9 '00'
        if (pokemon_id(poke_detail -> pokemon) >= 0 && pokemon_id(poke_detail -> pokemon) <= 9) {
            printf("Id: 00%d\n", pokemon_id(poke_detail -> pokemon));
        }
        //If the pokemon ID is between 10 and 99 '0'
        else if (pokemon_id(poke_detail -> pokemon) >= 10 && pokemon_id(poke_detail -> pokemon) <= 99) {
            printf("Id: 0%d\n", pokemon_id(poke_detail -> pokemon));
        }
        //If the pokemon ID is between 100 and 999 ''
        else if (pokemon_id(poke_detail -> pokemon) >= 100) {
            printf("Id: %d\n", pokemon_id(poke_detail -> pokemon));
        }

        printf("Name: ");
        //Prints asterisks until null terminator is reached for not found pokemon's name.
        while (pokemon_name(poke_detail -> pokemon)[i] != '\0') {
            printf("*");
            i++;
        }
       
        printf("\n");
        //Prints heigh, weight and type as '--' 
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
        
    }

      
    

    //If pokemon has been found this if statement is triggered
    else if (poke_detail -> found == TRUE) {
        //If the pokemon ID is between 0 and 9 '00'
        if (pokemon_id(poke_detail -> pokemon) >= 0 && pokemon_id(poke_detail -> pokemon) <= 9) {
            printf("Id: 00%d\n", pokemon_id(poke_detail -> pokemon));
        }
        //If the pokemon ID is between 10 and 99 '0'
        else if (pokemon_id(poke_detail -> pokemon) >= 10 && pokemon_id(poke_detail -> pokemon) <= 99) {
            printf("Id: 0%d\n", pokemon_id(poke_detail -> pokemon));
        }
        //If the pokemon ID is between 100 and 999 ''
        else if (pokemon_id(poke_detail -> pokemon) >= 100 && pokemon_id(poke_detail -> pokemon) <= 999) {
            printf("Id: %d\n", pokemon_id(poke_detail -> pokemon));
        }


        //Prints the found pokemon's name, weight and height
        printf("Name: %s\n", pokemon_name(poke_detail -> pokemon));
        printf("Height: %.1lfm\n", pokemon_height(poke_detail -> pokemon));
        printf("Weight: %.1lfkg\n", pokemon_weight(poke_detail -> pokemon));


        //If there is no second type, prints out the pokemon's single type.
        if (pokemon_second_type(poke_detail->pokemon) == 0) {
            printf("Type: %s\n", pokemon_type_to_string(pokemon_first_type(poke_detail -> pokemon)));

        }
        //Otherwise prints out both of the pokemon's types.
        else {
            printf("Type: %s %s\n", pokemon_type_to_string(pokemon_first_type(poke_detail -> pokemon)), 
                              pokemon_type_to_string(pokemon_second_type(poke_detail -> pokemon)));

        }

    }
 

} 


Pokemon get_current_pokemon(Pokedex pokedex) {
    struct pokenode *current_poke = pokedex -> current_pokemon;


        //If no pokemon have been found, exits.
    if (pokedex -> head == NULL) {
        printf("No pokemon have yet been found. Pokedex will now shut down.");
        exit(1);
    }


    else{
        return current_poke->pokemon;
       
    }
    
}

void find_current_pokemon(Pokedex pokedex) {
        //Sets the found value for currently selected pokemon to '1'
    pokedex -> current_pokemon -> found = TRUE;

}

void print_pokemon(Pokedex pokedex) {
    int i = 0 ;
    
    struct pokenode *current_pointer = pokedex -> current_pokemon;
    struct pokenode *printing_pokemon = pokedex->head;


        //Loops through pokedex
    while (printing_pokemon != NULL) {
        i=0;
            //Pointer to the currently selected pokemon.
        if (printing_pokemon == current_pointer) {
            printf("--> ");
        }
            //Spaces for all non-currently selected pokemon.
        else {
            printf("    ");
        }

            //If the pokemon ID is between 1 and 9 '00'
        if (pokemon_id(printing_pokemon -> pokemon) >= 0 && pokemon_id(printing_pokemon -> pokemon) <= 9) {
            printf("#00%d: ", pokemon_id(printing_pokemon -> pokemon));
        }
            //If the pokemon ID is between 10 and 99 '0'
        else if (pokemon_id(printing_pokemon -> pokemon) >= 10 && pokemon_id(printing_pokemon -> pokemon) <= 99) {
            printf("#0%d: ", pokemon_id(printing_pokemon -> pokemon));
        }
            //If the pokemon ID is between 100 and 999 ''
        else if (pokemon_id(printing_pokemon -> pokemon) >= 100) {
            printf("#%d: ", pokemon_id(printing_pokemon -> pokemon));
        }	


            //If the pokemon has been found print out its full name.
        if (printing_pokemon -> found == TRUE) {
            printf("%s", pokemon_name(printing_pokemon -> pokemon));

        }
            //If the pokemon has not been found print out asterisks.
        else {
            while (pokemon_name(printing_pokemon -> pokemon)[i] != '\0') {
                printf("*");
                i++;
            } 
        }
        printing_pokemon=printing_pokemon->next;
        printf("\n");
    }



    
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    struct pokenode *poke_next = pokedex->current_pokemon;
        //If the current pokemon is NULL returns
    if(pokedex -> head== NULL) {
        return;
    }
    


        //If the next pokemon is NULL returns
    else if (poke_next -> next == NULL) {
        return;
    }

        //Otherwise, sets the current pokemon to the next pokemon.
    else {
        pokedex-> current_pokemon = poke_next -> next;
    }


}
void prev_pokemon(Pokedex pokedex) {
    struct pokenode *poke_prev = pokedex-> current_pokemon;   

        //If the current pokemon is NULL returns.
    if (pokedex->head == NULL ) {
        return;
    }
 
        //If the previous pokenmon is NULL returns.
    else if (poke_prev -> prev == NULL) {
    
        return;
    }
        //Otherwise, sets the current pokemon to the previous pokemon.
    else {
        pokedex-> current_pokemon = poke_prev -> prev;  
    }

}

void change_current_pokemon(Pokedex pokedex, int id) {

    struct pokenode *change_poke = pokedex -> head;

        //Loops through the pokedex until the pokemon id = to the given id and then sets that pokemon to the current.
    while (change_poke != NULL) {
        if (pokemon_id(change_poke -> pokemon) == id) {
            pokedex -> current_pokemon = change_poke;
            break;
        }
        change_poke =  change_poke -> next;
    }
}

void remove_pokemon(Pokedex pokedex) {
        
    struct pokenode *remove_current = pokedex -> current_pokemon;
    struct pokenode *old_node = pokedex -> current_pokemon;

        //If there is only a single pokemon in the pokedex
    if (remove_current == pokedex -> head && remove_current -> next == NULL) {
        pokedex -> head = NULL;
        pokedex -> current_pokemon = NULL;
        destroy_pokemon(old_node->pokemon);
        free(old_node);		
    }
    //If the currently selected is equal to the head and there are more than one entries next.
    else if (pokedex -> current_pokemon == pokedex -> head && pokedex -> head -> next != NULL) {
        pokedex -> current_pokemon = pokedex -> current_pokemon -> next;
        pokedex -> head = pokedex -> head -> next;
        pokedex -> current_pokemon = pokedex -> head;
        pokedex -> head -> prev = NULL;
        destroy_pokemon(old_node->pokemon);
        free(old_node);	

    }
    //If the currently selected is the final pokemon in the list.
    else if (pokedex->current_pokemon->next ==NULL && pokedex -> current_pokemon -> prev!=NULL) {
        pokedex -> current_pokemon = pokedex -> current_pokemon -> prev;
        pokedex -> current_pokemon -> next = NULL;
        destroy_pokemon(old_node->pokemon);
        free(old_node);	

    }

    else if (pokedex -> current_pokemon -> next != NULL && pokedex -> current_pokemon -> prev !=NULL) {
            //If the previous pokemon to the selected is the head.
        if (pokedex -> current_pokemon -> prev == pokedex -> head) {
            pokedex -> current_pokemon = pokedex -> current_pokemon -> next;
            pokedex -> head -> next = pokedex -> current_pokemon;
            pokedex -> current_pokemon -> prev = pokedex -> head;
            destroy_pokemon(old_node -> pokemon);
            free(old_node);
        }
            //If the previous pokemon to the selected is not the head.
        else if (pokedex->current_pokemon->prev!=pokedex->head) {
            old_node -> prev -> next = old_node -> next;
            old_node ->next -> prev = old_node -> prev;
            pokedex -> current_pokemon = old_node -> next;
            destroy_pokemon(old_node -> pokemon);
            free(old_node);

        }

    }

}

void destroy_pokedex(Pokedex pokedex) {
        //One pointer will destroy nodes whilst the other will act as a flag so that the destroying node can follow it.
        
    struct pokenode *destroy_node = pokedex -> head;
    struct pokenode *temp_node;
    
    while(destroy_node != NULL) {
        temp_node = destroy_node;
        destroy_node = destroy_node -> next;
        destroy_pokemon(temp_node -> pokemon);
        free(temp_node);
        
    }
    free(pokedex);
  
  /*  struct pokenode *pointer1 = pokedex -> head;
    
        //If there is no head exits program.
    if (pointer1 == NULL) {
        free(pokedex);
        exit(1);

    }
        //If there is only one pokemon, frees and then exits program.
    else if (pointer1 -> next == NULL) {
        destroy_pokemon(pointer1->pokemon);
        free(pointer1);	
        free(pokedex);
        exit(1);	
    
    }
        //Otherwise, loops through the pokedex, with pointer2 one in front of pointer1. Pointer1 destroying and following pointer2.
    else {
        while (pointer1!= NULL) {
            struct pokenode *pointer2 = pokedex -> head -> next;
            destroy_pokemon(pointer1 -> pokemon);

            pointer1 = pointer2;
            pointer2 = pointer2 -> next;
            
            free(pointer1);
            free(pointer2);
            
        }
  
            
        free(pokedex);

    }*/

}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    srand((unsigned) seed);
    
    
        //Loops through and sets the int check_id to true for all pokemon ids returned by the srand.
        //Then if check_id is true sets the found value for the pokemon to found.
    int encounter_count = 0;
    while (encounter_count < how_many) {
        int check_id = FALSE;
        if (pokedex -> head != NULL) {
            struct pokenode *explore_node = pokedex -> head;

            while (explore_node != NULL) {
                if (pokemon_id (explore_node -> pokemon) >= seed &&     pokemon_id (explore_node -> pokemon) <= factor-1 ){
                    check_id = TRUE;
                }

                explore_node = explore_node -> next;
            }

            if (check_id == TRUE) {
                int id = rand() % factor;
                struct pokenode *pokedex_loop = pokedex -> head;
                while (pokedex_loop != NULL) {
                    if (id == pokemon_id (pokedex_loop -> pokemon)) {
                        pokedex_loop -> found = TRUE;
                        
                    }
                    pokedex_loop = pokedex_loop -> next;
                }
            } 
                //If the range is invalid then prints error message and exits program.
            else {
                printf("No ID values for this given range. Program will not exit.\n");
                exit(1);

            }
        }
        encounter_count++;
    }
}
int count_found_pokemon(Pokedex pokedex) {
    struct pokenode *count_node = pokedex -> head;
    int found_count=0;

        //Cycles through the pokedex incrementing found_count whenever a found pokemon is passed.
    while(count_node != NULL) {
        if (count_node -> found ==TRUE) {
            found_count++;
        }
        count_node=count_node->next;
    }
    return found_count;
}

int count_total_pokemon(Pokedex pokedex) {
    struct pokenode *count_node = pokedex -> head;
    int poke_count=0;

        //Loops through pokedex incrementing poke_count every entry.
    while(count_node != NULL) {
        poke_count++;
        count_node=count_node->next;
    }
    return poke_count;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    struct pokenode *from_pointer = pokedex -> head;
    struct pokenode *to_pointer = pokedex -> head;
            //Loops through the pokedex until the pokemon id of the pokemon at from_point is equal to from_id, then breaks
            //leaving the pointer at that pokemon.
    while (from_pointer != NULL) {


        if (pokemon_id(from_pointer->pokemon) == from_id) {
            break;
        }
        from_pointer = from_pointer -> next;
    }

            //Loops through pokedex until the pokemon id of the pokemon at to_point is equal to to_id, then breaks
            //leaving the pointer at that pokemon
    while (to_pointer != NULL) {
        if (pokemon_id(to_pointer->pokemon) == to_id) {
            break;
        }
        to_pointer = to_pointer -> next;
    }
            //Sets the 'evolution' of the pokemon at from_pointer to the pokemon at to_pointer.
    from_pointer -> evolution = to_pointer;

}

void show_evolutions(Pokedex pokedex) {
    struct pokenode *evo_pointer = pokedex -> current_pokemon;
    int evo_counter = 0 ;
    while(evo_pointer != NULL) {
        if (evo_counter >0){
            printf(" --> ");
        }
            //if the pokemon ID is between 1 and 9 '00'
        if (pokemon_id(evo_pointer -> pokemon) >= 0 && pokemon_id(evo_pointer -> pokemon) <= 9) {
            printf("#00%d ", pokemon_id(evo_pointer -> pokemon));
        }
            //If the pokemon ID is between 10 and 99 '0'
        else if (pokemon_id(evo_pointer -> pokemon) >= 10 && pokemon_id(evo_pointer -> pokemon) <= 99) {
            printf("#0%d ", pokemon_id(evo_pointer -> pokemon));
        }
            //If the pokemon ID is between 100 and 999 ''
        else if (pokemon_id(evo_pointer -> pokemon) >= 100) {
            printf("#%d ", pokemon_id(evo_pointer -> pokemon));
        }
            //If the pokemon has been found before prints out its name in full as well as type
        if (evo_pointer->found==TRUE) {
            if(pokemon_second_type(evo_pointer->pokemon) == 0){
                printf("%s [%s] ", pokemon_name(evo_pointer->pokemon), pokemon_type_to_string(pokemon_first_type(evo_pointer -> pokemon)));
            }
            else {
                printf("%s [%s, %s] ", pokemon_name(evo_pointer->pokemon), pokemon_type_to_string(pokemon_first_type(evo_pointer -> pokemon)), 
                                                                         pokemon_type_to_string(pokemon_second_type(evo_pointer -> pokemon)));
            }	    
            //If the pokemon has not been found prints out '????' for name and type.
        }
        else {
            printf("???? [????]");
        }
        evo_counter++;
        evo_pointer = evo_pointer -> evolution;
    }
    printf("\n");


}
int get_next_evolution(Pokedex pokedex) {
        //If the pokemon does not evolve returns 'DOES_NOT_EVOLVE'
    if (pokedex->current_pokemon->evolution == NULL) {
        return DOES_NOT_EVOLVE;
    }
        //If there are no pokemon in pokedex exits.
    else if (pokedex->head == NULL) {
        printf("Pokedex is empty. Pokedex will now exit.");
        exit(1);
    }
        //Returns id of evolution of current pokemon.a
    else  {
        return pokemon_id(pokedex->current_pokemon->evolution->pokemon);
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    Pokedex type_pokedex = new_pokedex();
    struct pokenode *pointer_old = pokedex -> head;
        //Loops through the old pokedex. Everytime there is a pokemon of desired type clones to the new pokedex.
    while(pointer_old != NULL) {
        if ((pokemon_first_type(pointer_old -> pokemon) == type || pokemon_second_type(pointer_old-> pokemon) == type)&& pointer_old -> found ==TRUE) {
            struct pokenode *pointer_new = malloc(sizeof(struct pokenode)); //Creates a pointer for new pokedex entry
            struct pokenode *pointer_new1 = type_pokedex -> head; //Creates a pointer at the head of new pokedex
                //When this is the first pokemon in the new pokedex this if is triggered, making the new pokemon the head.
            if (pointer_new1 == NULL) { 
                type_pokedex -> head = pointer_new;
                pointer_new->next = NULL;
                pointer_new -> prev = NULL;
                type_pokedex -> current_pokemon = pointer_new;
            }
            
                //Otherwise, the next pokemon is added to the string.
            else {
                
                while (pointer_new1->next != NULL) {
                    pointer_new1 = pointer_new1->next;

                }
                pointer_new1-> next =pointer_new;
                pointer_new-> prev =pointer_new1;

            }
            pointer_new -> pokemon = clone_pokemon(pointer_old -> pokemon);
            pointer_new -> next = NULL;
            pointer_new -> found = TRUE;



        }

        pointer_old = pointer_old -> next;
    }

    return type_pokedex;
}



Pokedex get_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the get_found_pokemon function in pokedex.c\n");
    exit(1);
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {    
    fprintf(stderr, "exiting because you have not implemented the get_found_pokemon function in pokedex.c\n");
    exit(1);
}
/*    struct pokenode *pointer_old = pokedex -> head;	Pokedex search_pokedex = new_pokedex();

        //Loops through the old pokedex. Everytime there is a pokemon with desired string in name, clones to the new pokedex.
    while(pointer_old != NULL) {
        if (search_string(pokemon_name(pointer_old->pokemon, text) == TRUE && pointer_old -> found == TRUE) {
            struct pokenode *pointer_new = malloc(sizeof(struct pokenode));
            struct pokenode *pointer_new1 = search_pokedex -> head;

            if (pointer_new1 == NULL) {
                search -> head = pointer_new;
                pointer_new->next = NULL;
                pointer_new -> prev = NULL;
                search -> current_pokemon = pointer_new;
            }
            

            else {
                
                while (pointer_new1->next != NULL) {
                    pointer_new1 = pointer_new1->next;

                }
                pointer_new1-> next =pointer_new;
                pointer_new-> prev =pointer_new1;

            }
            pointer_new -> pokemon = clone_pokemon(pointer_old -> pokemon);
            pointer_new -> next = NULL;
            pointer_new -> found = FALSE;
            pointer_new -> evolution = NULL;


        }

        pointer_old = pointer_old -> next;
    }

    return search_pokedex;
}
*/

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.x`

/*int search_string(char *name, char *input)
{
    //A function that searchs within strings for smaller strings. Outputs TRUE or FALSE.
    char input[40], name[40];
    int i = 0, j = 0;
    while ((name[j] != '\0')||(input[i] != '\0')) {
        if (input[i] != name[j]) {
            j++;
            i = 0;
        }
        else {
            i++;
            j++;
        }
    }
    if (input[i] == '\0')
        return TRUE;
    else
        return FALSE;
}*/

