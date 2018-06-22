# ifndef DATASET_H
# define DATASET_H

typedef struct set SET;

extern SET *createSet(int maxElts);

extern void destroySet(SET *sp);

extern void searchAge(SET *sp, int a);   

extern void insertElement(SET *sp, int id, int age);

extern void removeElement(SET *sp, int age);

extern void maxAgeGap(SET *sp);

# endif /* DATASET_H */
