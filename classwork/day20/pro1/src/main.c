#include "defect.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <defect details>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DefectList list;
    initDefectList(&list);

    for (int i = 1; i < argc; i++) {
        char *token = strtok(argv[i], ":");
        if (token == NULL || token[0] != 'D') {
            printf("Parse error in %s\n", argv[i]);
            continue;
        }
        char id[MAX_LENGTH];
        strcpy(id, token);

        token = strtok(NULL, ":");
        if (token == NULL) {
            printf("Parse error in %s\n", argv[i]);
            continue;
        }
        char state[MAX_LENGTH];
        strcpy(state, token);

        updateDefect(&list, id, state);
    }

    printf("Displayed Output:\n-------------------\n");
    displayDefects(&list);

    freeDefectList(&list);
    return EXIT_SUCCESS;
}

