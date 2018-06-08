//
//  dataset.h
//  app1
//
//  Created by Cyrus Miremadi on 6/3/18.
//  Copyright © 2018 Cyrus Miremadi. All rights reserved.
//

#ifndef dataset_h
#define dataset_h

# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <time.h>
# include "dataset.h"
# include <stdbool.h>


typedef struct set SET;
typedef struct student ST;

SET *createSet(int maxElts);

void destroySet(SET *sp);

int numElements(SET *sp);

int searchAge(SET *sp, int age, bool *found); 

//int searchID(SET *sp, int id);

void insertElement(SET *sp, int age, int );

void removeElement(SET *sp, int age);

//void removeAge(SET *num, int age);

void *findElement(SET *sp, int age);

int maxAgeGap(SET *number);

void getAges(SET *number);

#endif /* dataset_h */
