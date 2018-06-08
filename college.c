//
//  college.c
//  app1
//
//  Created by Cyrus Miremadi on 6/3/18.
//  Copyright © 2018 Cyrus Miremadi. All rights reserved.
//

#include "dataset.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define MAX_STUDENTS 3000

int main(void){
    bool found = false;
    SET *number = createSet(MAX_STUDENTS);
    //printf("Set created\n");
    //int seed = time(NULL);
    //srand(seed);
    int id = rand() % 2 + 1;
    
    for(int i = 0; i < 1000; i++){
        int age = rand() % 13 + 18;
        insertElement(number, age, id);
        id += rand() % 2 + 1;
        printf("The following age: %d and id: %d were added for your search or deletion option.\n", age, id);
    }
    int age = rand() % 13 + 18;
    searchAge(number, age, &found); {
        if(found)
            printf("The student aged %d has been found. \n", age);
        else if(!found)
            printf("The student was not found. \n");
    }
    
    
    //int age = rand() % 13 + 18; MIGHT NEED TO DECLARE AGAIN
    removeElement(number, age);
    //if (searchAge(number,age,&found)==true)
        //printf("The student %d, %d has been removed \n", findElement(number), findElement(number(age));
    printf("The following element was removed successfully: %d\n", age);


    maxAgeGap(number);
    printf("The maximum age gap is: %d \n", maxAgeGap(number));
    destroySet(number);
    return 0;

}


