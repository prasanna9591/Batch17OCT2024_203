#ifndef DEFECT_H
#define DEFECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct 
{
    char id[MAX_LENGTH];
    char state[MAX_LENGTH];
    char transition[MAX_LENGTH];
} Defect;

typedef struct
{
    Defect *defects;
    int size;
    int capacity;
} DefectList;

void initDefectList(DefectList *list);
void addDefect(DefectList *list, const char *id, const char *state);
void updateDefect(DefectList *list, const char *id, const char *state);
void displayDefects(const DefectList *list);
void freeDefectList(DefectList *list);
int validateStateTransition(const char *oldState, const char *newState, char *expectedState);

#endif

