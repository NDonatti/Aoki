// init.c

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"


#define RAND_64 (   (U64)rand() | \
                    (U64)rand() << 15 | \
                    (U64)rand() << 30 | \
                    (U64)rand() << 45 | \
                    ((U64)rand() & 0xf) << 60   )

U64 SetMask[64];
U64 ClearMask[64];

U64 PieceKeys[13][64];
U64 SideKey;
U64 CastleKeys[16];

void InitHashKeys() {

    int index = 0;
    int index2 = 0;
    for(index = 0; index < 13; index++) {
        for(index2 = 0; index2 < 64; index2++) {
                    PieceKeys[index][index2] = RAND_64;
                }
            }
            SideKey = RAND_64;
            for(index = 0; index < 16; index++) {
                CastleKeys[index] = RAND_64;
            }
}

void InitBitMasks() {
    int index = 0;

    for(index = 0; index < 64; index++) {
        SetMask[index] = 0ULL;
        ClearMask[index] = 0ULL;
    }

    for(index = 0; index < 64; index++) {
        SetMask[index] |= (1ULL << index);
        ClearMask[index] = ~SetMask[index];
    }
}

void AllInit() {

    InitBitMasks();
    InitHashKeys();
    
}