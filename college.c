# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <time.h>
# include "dataset.h"

# define MAX_STUDENTS 3000

int ran(int min, int max){ //adapted random function that either returns a one or a two
    return ((rand() % (max - min + 1)) + min);
}

int main(void){
    srand(time(NULL));
    SET *sp = createSet(MAX_STUDENTS); //create set that's the size 3000
    int id = ran(1, 2);
    for(int i = 0; i < 1000; i++){
        int age = ran(18, 30);
        insertElement(sp, id, age);
        id += ran(1,2); //loop
        // maxAgeGap(sp);
    }
    // printAll(sp);
    searchAge(sp, ran(18,30));
    int r = ran(18, 30); //set parameter for functions
    removeElement(sp, r);
    searchAge(sp, r);
    // printAll(sp);
    maxAgeGap(sp);
    destroySet(sp);
    return 0;
}
