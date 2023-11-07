#include <stdio.h>
#include <string.h>

void assembleToC(char *assembly) {
    if (strcmp(assembly, "MOV R0, 5") == 0) {
        int R0 = 5;
        printf("R0 = %d;\n", R0);
    } else if (strcmp(assembly, "ADD R1, R2, R3") == 0) {
        int R1, R2, R3;
        R1 = R2 + R3;
        printf("R1 = R2 + R3;\n");
    } else if (strcmp(assembly, "SUB R1, R2, R3") == 0) {
        int R1, R2, R3;
        R1 = R2 - R3;
        printf("R1 = R2 - R3;\n");
    } else {
        printf("Unsupported instruction: %s\n", assembly);
    }
}

int main() {
    char assembly1[] = "MOV R0, 5";
    char assembly2[] = "ADD R1, R2, R3";
    char assembly3[] = "SUB R1, R2, R3";
    
    assembleToC(assembly1);
    assembleToC(assembly2);
    assembleToC(assembly3);

    return 0;
}
