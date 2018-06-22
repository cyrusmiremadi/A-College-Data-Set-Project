# include <assert.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "dataset.h"


typedef struct student {
    int id;
    int age;
} ST;


typedef struct set{
    ST **students;     //Student data, array of student pointers
    int count;
    int length;
    
} SET;

//Complexity: O(1)
static ST *makeStudent(int id, int age){
    ST *stud = malloc(sizeof(ST));
    assert(stud != NULL);
    stud->age = age; //set pointers to parameters
    stud->id = id;
    
    return stud;
}

//Complexity: O(n)

SET *createSet(int maxElts){
    
    //allocate memory for pointers
    SET *sp = malloc(sizeof(SET));
    assert(sp != NULL);
    
    sp->students = malloc(sizeof(ST*)*maxElts); //number of students equal to 3000
    assert(sp->students != NULL);
    
    sp->count = 0;
    sp->length = maxElts;
    
    return sp;
}


//Complexity: O(n)
 
void destroySet(SET *sp){
    assert(sp != NULL);
    
    for(int i = 0; i < sp->count; i++){
        free(sp->students[i]);
    }
    free(sp->students);
    free(sp);
}

//Complexity: O(log(n))

static int binarySearch(SET *sp, int age, bool *found){
    assert(sp != NULL);
    
    int hi = sp->count - 1;
    int lo = 0;
    int mid = 0;
    *found = false;
    
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(sp->students[mid]->age > age){
            hi = mid - 1;
        } else if(sp->students[mid]->age < age){
            lo = mid + 1;
        } else {
            *found = true;
            return mid;
        }
    }
    
    //if not found, student will be at this position
    return lo;
}

//Complexity: O(n)

static bool searchID(SET *sp, int id){ //search that determines whether or nod ID exists
    assert(sp != NULL);
    for(int i = 0; i < sp->count; i++){
        if(sp->students[i]->id == id){
            return true;
        }
    }
    return false;
}


//Complexity: O(n)

void insertElement(SET *sp, int id, int age){
    assert(sp != NULL);
    
    //check status of student
    if(searchID(sp, id)){
        printf("Insertion failed - student: %d exists already\n", id);
        return;
    }
    bool x;
    //find new index
    int i = binarySearch(sp, age, &x);
    printf("Adding Student with #%d and age: %d\n", id, age);
    
    //shift
    for(int j = sp->count; j > i; j--){
        sp->students[j] = sp->students[j-1];
    }
    
    //Make new student at the index
    sp->students[i] = makeStudent(id, age);
    sp->count ++;
}

//Complexity: O(1)

void maxAgeGap(SET *sp){
    int min = sp->students[0]->age;
    int max = sp->students[sp->count-1]->age;
    int maxGap = max - min;
    
    printf("Max age gap: %d\n", maxGap);
}

//Complexity: O(n)

void searchAge(SET *sp, int a){
    assert(sp != NULL);
    bool found = false;
    //Looks at value in the array until age a and print their id if the age is a
    for(int i = 0; (i < sp->count) && (sp->students[i]->age <= a); i++){
        if(sp->students[i]->age == a){
            printf("Found Student %d\n", sp->students[i]->id);
            found = true;
        }
    }
    if(!found){
        printf("No students with age %d is found\n", a);
    }
}


//Complexity: O(n)
void removeElement(SET *sp, int age){
    assert(sp != NULL);
    bool found = false;
    int i = binarySearch(sp, age, &found);
    printf("Removing students aged %d\n", age);
    if(found){
        int min = i;
        int max = i;
        bool cyrus = true;
        
        //removing students w same age to the right of the index
        for(int j = i; j < sp->count && cyrus ; j++){
            if(sp->students[j]->age != age){
                cyrus = false;
            } else {
                printf("Removed student with ID: %d\t and Age: %d\n", sp->students[j]->id, sp->students[j]->age);
                free(sp->students[j]);
                max++;
            }
        }
        
       //removing students w same age to the left of the index
        cyrus = true;
        for(int j = i-1; j > -1 && cyrus ; j--){
            if(sp->students[j]->age != age){
                cyrus = false;
            } else {
                free(sp->students[j]);
                printf("Removed student with ID: %d Age: %d\n", sp->students[j]->id, sp->students[j]->age);
                min--;
            }
        }
        int gap = max - min;
        int k;
        
        
        for(k = max; k < sp->count && max < sp->count; k++){
            sp->students[min] = sp->students[k];
            min++;
        }
        sp->count -= gap;
    } else {
        printf("No students with age %d are found\n", age);
    }
}


