//
//  dataset.c
//  app1
//
//  Created by Cyrus Miremadi on 6/3/18.
//  Copyright © 2018 Cyrus Miremadi. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include "dataset.h"


# define MAX_STUDENTS 3000


typedef struct student {
    int age;
    int ID;
} ST ;

struct set {
    int count;
    int length;
    ST ** students;
};

// complexity: O(1)
SET *createSet (int maxElts) //create set of elements/objects

{ SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp->length = maxElts;
    sp->count = 0;
    sp->students = malloc(sizeof(ST*)*maxElts);
    assert(sp->students != NULL);
    return sp;
}

// complexity: O(n)
void destroySet(SET *sp)

{
    assert(sp!=NULL);
    int i;
    for(i=0;i < sp->count; i++){
        //free(sp->students[i]);
    }
    free(sp->students);
    free(sp);
}

//REMOVE SEMICOLONS FROM END OF EACH FUNCTION


// complexity: O(n)
int numElements(SET *sp)

{
    assert(sp!=NULL);
    return(sp->count);
}


//complexity: O(log(n))
int searchAge(SET *sp, int age, bool *found)

{
    //printf("Entering search\n");
    assert(sp != NULL); //complexity: O(log(n))
    //printf("Search age\n");
    int lo = 0; //setting levels
    int mid = 0;
    int hi = sp->count -1; //value of "highest" word set to total count represented
    ///printf("Lo is %d , mid is %d, hi is %d \n", lo, mid, hi);
    while (lo <= hi) { //stopping condition is when lo becomes greater than hi
        //printf("Lo is %d , mid is %d, hi is %d \n", lo, mid, hi);
        mid = (hi+lo)/2;
        //printf("Ages are %d and %d\n", age, sp->students[mid]->age);
        if (age<sp->students[mid]->age) //if elt is less than mid
            hi = mid -1;
        if ( age>sp->students[mid]->age) //if elt is greater than mid
            lo = mid + 1;
        else if (age==sp->students[mid]->age){
            //printf("hey\n");
            *found = true;
            return mid; }; //if neither, return mid
    };
    //printf("Exiting search\n");
    //*found = false;
    //printf("The following age: %d was found in the search\n", sp->students[lo]->age);
    //printf("Lo: %d \n",lo);
    return lo; //return position
    
    
}


//complexity: O(n)

void insertElement(SET *sp, int age, int id)

{
    //printf("Entering insertElement\n");
    assert(sp!=NULL);
    bool found = false;
    int i;
    int j;
    int idx=searchAge(sp, age, &found); //age is similar to elt
    //printf("Result is %d\n", idx);
    if (!found) {
        for(i=sp->count;i>idx;i--)
            sp->students[i] = sp->students[i-1];
        //printf("Allocating new student at %d \n", idx);
        
        ST *temp = malloc(sizeof(ST));
       
        temp->age = age;
        sp->students[idx] = temp;
        
        sp->count++;
    }
    else {
        
        for(i=sp->count-1;i>idx;i--)
            sp->students[i+1] = sp->students[i];
       
        
        ST *temp = malloc(sizeof(ST));
        
        temp->age = age;
        sp->students[idx] = temp;
        
        sp->count++;
    }

    return;
}


//complexity: O(n)
void removeElement(SET *sp, int age)

{
    assert(sp!=NULL);
    bool found;
    int i;
    int idx=searchAge(sp, age, &found);
    if (found) {
        free(sp->students[idx]);
        for(i=idx+1;i<sp->count;i++)
            sp->students[i-1]=sp->students[i];
        sp->count--;
    }
    
}


//Complexity: O(n)

/*
void removeAge(SET *num, int age)

{
    assert(num!=NULL);
}

*/


// Complexity: O(log(n))

void *findElement(SET *sp, int age)

{
    assert(sp!=NULL);
    bool found;
    int idx = searchAge(sp,age,&found);
    
    if (!found)
        return NULL;
    else
        return sp->students[idx];
}

// Complexity: O(1)

int maxAgeGap(SET *number)

{
    assert(number!= NULL && number->count > 0 );
    return number->students[number->count-1]->age-number->students[0]->age;
    
}

void getAges(SET *number)

{
    int i;
    //int x;
    assert(number!=NULL&&number->count>0); //checks to see if the set is not NULL and the count is not 0
    for (i=0;i<number->count;i++)
    {
        printf("%d\t",number->students[i]->age); //prints the ages in the array
    }
}




































