#include "defect.h"

void initDefectList(DefectList *list) {
    list->size = 0;
    list->capacity = 10;
    list->defects = (Defect *)malloc(list->capacity * sizeof(Defect));
}

void addDefect(DefectList *list, const char *id, const char *state) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->defects = (Defect *)realloc(list->defects, list->capacity * sizeof(Defect));
    }
    strcpy(list->defects[list->size].id, id);
    strcpy(list->defects[list->size].state, state);
    list->defects[list->size].transition[0] = '\0';
    list->size++;
}

void updateDefect(DefectList *list, const char *id, const char *state) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->defects[i].id, id) == 0) {
            char expectedState[MAX_LENGTH];
            if (validateStateTransition(list->defects[i].state, state, expectedState)) {
                sprintf(list->defects[i].transition, "%s->%s", list->defects[i].state, state);
                strcpy(list->defects[i].state, state);
            } else {
                printf("Defect:%s, Invalid State:%s, Expected:%s\n", id, state, expectedState);
            }
            return;
        }
    }
    addDefect(list, id, state);
}

void displayDefects(const DefectList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("Defect:%s, State:%s", list->defects[i].id, list->defects[i].state);
        if (list->defects[i].transition[0] != '\0') {
            printf(", Transition:%s", list->defects[i].transition);
        }
        printf("\n");
    }
}

void freeDefectList(DefectList *list) {
    free(list->defects);
}

int validateStateTransition(const char *oldState, const char *newState, char *expectedState) {
    const char *states[] = {"New", "Assigned", "InProgress", "Fixed", "Verified", "Closed"};
    int oldIndex = -1, newIndex = -1;
    for (int i = 0; i < 6; i++) {
        if (strcmp(oldState, states[i]) == 0) oldIndex = i;
        if (strcmp(newState, states[i]) == 0) newIndex = i;
    }
    if (oldIndex == -1 || newIndex == -1 || newIndex != oldIndex + 1) {
        if (oldIndex != -1 && oldIndex < 5) {
            strcpy(expectedState, states[oldIndex + 1]);
        } else {
            expectedState[0] = '\0';
        }
        return 0;
    }
    return 1;
}

