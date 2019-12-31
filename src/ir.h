#ifndef IR_H
#define IR_H

#include <stdint.h>

typedef uint32_t MemAddr;

typedef struct IrValue {
    enum {
        VALUE_MEM_ADDR,
        VALUE_INTEGER,
        VALUE_FLOAT,
        VALUE_STRING
    } type;

    union {
        MemAddr mem_addr;
        long long integer;
        long double floating_point;
        char *string;
    };
} IrValue;

typedef struct IrInstr {
    enum {
        IR_INIT,
        IR_COPY,
        IR_JAL,
        IR_RET,
        IR_JNZ,

        // Operations
        IR_OP_ADD,
        IR_OP_SUB,
        IR_OP_MULT,
        IR_OP_DIV
    } type;

    struct IrInstr *next;
    struct IrInstr *branch; // Used in jump instructions

    IrValue p0, p1; // Parameters
} IrInstr;

IrInstr *new_ir_instr(int type, IrValue p0, IrValue p1,
                      IrInstr *next, IrInstr *branch);
#endif
