#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Flags do Flag Register
#define GREATER 0
#define LESSER 1
#define EQUAL 2
#define ZERO 3
#define CARRY 4
#define OVERFLOW 5
#define NEGATIVE 6
#define DIV_BY_ZERO 9

// Condições de salto (bits 9-6 do IR)
#define NO_COND 0
#define COND_EQUAL 1
#define COND_NOT_EQUAL 2
#define COND_ZERO 3
#define COND_NOT_ZERO 4
#define COND_CARRY 5
#define COND_NOT_CARRY 6
#define COND_GREATER 7
#define COND_LESSER 8
#define COND_GREATER_EQUAL 9
#define COND_LESSER_EQUAL 10
#define COND_OVERFLOW 11
#define COND_NOT_OVERFLOW 12
#define COND_DIV_BY_ZERO 13
#define COND_NEGATIVE 14

// Estado do processador
typedef struct {
    int PC;
    int FR[16];
    int IncPC;
    int LoadPC;
    int DATA_OUT;
} ProcessadorState;

// Extrai bits de uma instrução
int pega_pedaco(int ir, int a, int b) {
    int pedaco = ((1 << (a - b + 1)) - 1);
    pedaco = pedaco & (ir >> b);
    return pedaco;
}

// Implementação do JMP
void executar_JMP(int IR, ProcessadorState *processador, int *MEMORY) {
    int COND = pega_pedaco(IR, 9, 6);
    int condicao_satisfeita = 0;
    
    printf("\nIR: 0x%04X | COND: %d\n", IR, COND);
    
    // Verifica cada condição
    if (COND == NO_COND) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_EQUAL && processador->FR[EQUAL] == 1) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_NOT_EQUAL && processador->FR[EQUAL] == 0) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_ZERO && processador->FR[ZERO] == 1) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_NOT_ZERO && processador->FR[ZERO] == 0) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_CARRY && processador->FR[CARRY] == 1) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_NOT_CARRY && processador->FR[CARRY] == 0) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_GREATER && processador->FR[GREATER] == 1) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_LESSER && processador->FR[LESSER] == 1) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_GREATER_EQUAL && 
             (processador->FR[GREATER] == 1 || processador->FR[EQUAL] == 1)) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_LESSER_EQUAL && 
             (processador->FR[LESSER] == 1 || processador->FR[EQUAL] == 1)) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_OVERFLOW && processador->FR[OVERFLOW] == 1) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_NOT_OVERFLOW && processador->FR[OVERFLOW] == 0) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_DIV_BY_ZERO && processador->FR[DIV_BY_ZERO] == 1) {
        condicao_satisfeita = 1;
    }
    else if (COND == COND_NEGATIVE && processador->FR[NEGATIVE] == 1) {
        condicao_satisfeita = 1;
    }
    
    // Define sinais de controle
    if (condicao_satisfeita) {
        processador->LoadPC = 1;
        processador->IncPC = 0;
        printf("SALTA: LoadPC=1, IncPC=0 | PC <- MEMORY[PC]\n");
    } else {
        processador->LoadPC = 0;
        processador->IncPC = 1;
        printf("NAO SALTA: LoadPC=0, IncPC=1 | PC <- PC+1\n");
    }
}

void testar_JMP(void) {
    ProcessadorState proc;
    int MEMORY[100];
    
    proc.PC = 0;
    proc.LoadPC = 0;
    proc.IncPC = 0;
    for (int i = 0; i < 16; i++) {
        proc.FR[i] = 0;
    }
    
    printf("TESTE 1: JMP Incondicional (COND=0)\n");
    int IR1 = 0x0002;
    executar_JMP(IR1, &proc, MEMORY);
    
    printf("\nTESTE 2: JEQ - Verdadeira (COND=1)\n");
    proc.FR[EQUAL] = 1;
    int IR2 = 0x0042;
    executar_JMP(IR2, &proc, MEMORY);
    
    printf("\nTESTE 3: JEQ - Falsa (COND=1)\n");
    proc.FR[EQUAL] = 0;
    proc.FR[GREATER] = 1;
    executar_JMP(IR2, &proc, MEMORY);
    
    printf("\nTESTE 4: JGT - Verdadeira (COND=7)\n");
    proc.FR[EQUAL] = 0;
    proc.FR[GREATER] = 1;
    proc.FR[LESSER] = 0;
    int IR4 = 0x01C2;
    executar_JMP(IR4, &proc, MEMORY);
    
    printf("\nTESTE 5: JZ - Verdadeira (COND=3)\n");
    proc.FR[EQUAL] = 0;
    proc.FR[GREATER] = 0;
    proc.FR[LESSER] = 0;
    proc.FR[ZERO] = 1;
    int IR5 = 0x00C2;
    executar_JMP(IR5, &proc, MEMORY);
    
    printf("\nTESTE 6: JNZ - Falsa (COND=4)\n");
    proc.FR[ZERO] = 1;
    int IR6 = 0x0102;
    executar_JMP(IR6, &proc, MEMORY);
    
    printf("\nTESTE 7: JC - Verdadeira (COND=5)\n");
    proc.FR[CARRY] = 1;
    int IR7 = 0x0142;
    executar_JMP(IR7, &proc, MEMORY);
}

int main(void) {
    testar_JMP();
    return 0;
}
