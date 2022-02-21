#include <stdint.h>
#include <memory.h>

void turbopack32(const uint32_t *in, uint32_t number, const uint32_t bit, uint8_t *out) asm("turbopack32");

void turbounpack32(const uint8_t *in, uint32_t number, const uint32_t bit, uint32_t *out) asm("turbounpack32");


static void packblock0(const uint32_t ** pin, uint8_t ** pw) {
    (void)pw;
    *pin += 32; /* we consumed 32 32-bit integers */
}


/* we are going to pack 32 1-bit values, touching 1 64-bit words, using 4 bytes */
static void packblock1(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  1 64-bit word */
    uint64_t w0;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 1;
    w0 |= (uint64_t)  in[2] << 2;
    w0 |= (uint64_t)  in[3] << 3;
    w0 |= (uint64_t)  in[4] << 4;
    w0 |= (uint64_t)  in[5] << 5;
    w0 |= (uint64_t)  in[6] << 6;
    w0 |= (uint64_t)  in[7] << 7;
    w0 |= (uint64_t)  in[8] << 8;
    w0 |= (uint64_t)  in[9] << 9;
    w0 |= (uint64_t)  in[10] << 10;
    w0 |= (uint64_t)  in[11] << 11;
    w0 |= (uint64_t)  in[12] << 12;
    w0 |= (uint64_t)  in[13] << 13;
    w0 |= (uint64_t)  in[14] << 14;
    w0 |= (uint64_t)  in[15] << 15;
    w0 |= (uint64_t)  in[16] << 16;
    w0 |= (uint64_t)  in[17] << 17;
    w0 |= (uint64_t)  in[18] << 18;
    w0 |= (uint64_t)  in[19] << 19;
    w0 |= (uint64_t)  in[20] << 20;
    w0 |= (uint64_t)  in[21] << 21;
    w0 |= (uint64_t)  in[22] << 22;
    w0 |= (uint64_t)  in[23] << 23;
    w0 |= (uint64_t)  in[24] << 24;
    w0 |= (uint64_t)  in[25] << 25;
    w0 |= (uint64_t)  in[26] << 26;
    w0 |= (uint64_t)  in[27] << 27;
    w0 |= (uint64_t)  in[28] << 28;
    w0 |= (uint64_t)  in[29] << 29;
    w0 |= (uint64_t)  in[30] << 30;
    w0 |= (uint64_t)  in[31] << 31;
    pw64[0] = w0;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 4; /* we used up 4 output bytes */
}


/* we are going to pack 32 2-bit values, touching 1 64-bit words, using 8 bytes */
static void packblock2(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  1 64-bit word */
    uint64_t w0;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 2;
    w0 |= (uint64_t)  in[2] << 4;
    w0 |= (uint64_t)  in[3] << 6;
    w0 |= (uint64_t)  in[4] << 8;
    w0 |= (uint64_t)  in[5] << 10;
    w0 |= (uint64_t)  in[6] << 12;
    w0 |= (uint64_t)  in[7] << 14;
    w0 |= (uint64_t)  in[8] << 16;
    w0 |= (uint64_t)  in[9] << 18;
    w0 |= (uint64_t)  in[10] << 20;
    w0 |= (uint64_t)  in[11] << 22;
    w0 |= (uint64_t)  in[12] << 24;
    w0 |= (uint64_t)  in[13] << 26;
    w0 |= (uint64_t)  in[14] << 28;
    w0 |= (uint64_t)  in[15] << 30;
    w0 |= (uint64_t)  in[16] << 32;
    w0 |= (uint64_t)  in[17] << 34;
    w0 |= (uint64_t)  in[18] << 36;
    w0 |= (uint64_t)  in[19] << 38;
    w0 |= (uint64_t)  in[20] << 40;
    w0 |= (uint64_t)  in[21] << 42;
    w0 |= (uint64_t)  in[22] << 44;
    w0 |= (uint64_t)  in[23] << 46;
    w0 |= (uint64_t)  in[24] << 48;
    w0 |= (uint64_t)  in[25] << 50;
    w0 |= (uint64_t)  in[26] << 52;
    w0 |= (uint64_t)  in[27] << 54;
    w0 |= (uint64_t)  in[28] << 56;
    w0 |= (uint64_t)  in[29] << 58;
    w0 |= (uint64_t)  in[30] << 60;
    w0 |= (uint64_t)  in[31] << 62;
    pw64[0] = w0;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 8; /* we used up 8 output bytes */
}


/* we are going to pack 32 3-bit values, touching 2 64-bit words, using 12 bytes */
static void packblock3(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  2 64-bit words */
    uint64_t w0;
    uint64_t w1;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 3;
    w0 |= (uint64_t)  in[2] << 6;
    w0 |= (uint64_t)  in[3] << 9;
    w0 |= (uint64_t)  in[4] << 12;
    w0 |= (uint64_t)  in[5] << 15;
    w0 |= (uint64_t)  in[6] << 18;
    w0 |= (uint64_t)  in[7] << 21;
    w0 |= (uint64_t)  in[8] << 24;
    w0 |= (uint64_t)  in[9] << 27;
    w0 |= (uint64_t)  in[10] << 30;
    w0 |= (uint64_t)  in[11] << 33;
    w0 |= (uint64_t)  in[12] << 36;
    w0 |= (uint64_t)  in[13] << 39;
    w0 |= (uint64_t)  in[14] << 42;
    w0 |= (uint64_t)  in[15] << 45;
    w0 |= (uint64_t)  in[16] << 48;
    w0 |= (uint64_t)  in[17] << 51;
    w0 |= (uint64_t)  in[18] << 54;
    w0 |= (uint64_t)  in[19] << 57;
    w0 |= (uint64_t)  in[20] << 60;
    w0 |= (uint64_t) in[21] << 63;
    w1 = (uint64_t) in[21] >> 1;
    w1 |= (uint64_t)  in[22] << 2;
    w1 |= (uint64_t)  in[23] << 5;
    w1 |= (uint64_t)  in[24] << 8;
    w1 |= (uint64_t)  in[25] << 11;
    w1 |= (uint64_t)  in[26] << 14;
    w1 |= (uint64_t)  in[27] << 17;
    w1 |= (uint64_t)  in[28] << 20;
    w1 |= (uint64_t)  in[29] << 23;
    w1 |= (uint64_t)  in[30] << 26;
    w1 |= (uint64_t)  in[31] << 29;
    pw64[0] = w0;
    pw64[1] = w1;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 12; /* we used up 12 output bytes */
}


/* we are going to pack 32 4-bit values, touching 2 64-bit words, using 16 bytes */
static void packblock4(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  2 64-bit words */
    uint64_t w0;
    uint64_t w1;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 4;
    w0 |= (uint64_t)  in[2] << 8;
    w0 |= (uint64_t)  in[3] << 12;
    w0 |= (uint64_t)  in[4] << 16;
    w0 |= (uint64_t)  in[5] << 20;
    w0 |= (uint64_t)  in[6] << 24;
    w0 |= (uint64_t)  in[7] << 28;
    w0 |= (uint64_t)  in[8] << 32;
    w0 |= (uint64_t)  in[9] << 36;
    w0 |= (uint64_t)  in[10] << 40;
    w0 |= (uint64_t)  in[11] << 44;
    w0 |= (uint64_t)  in[12] << 48;
    w0 |= (uint64_t)  in[13] << 52;
    w0 |= (uint64_t)  in[14] << 56;
    w0 |= (uint64_t)  in[15] << 60;
    w1 = (uint64_t) in[16];
    w1 |= (uint64_t)  in[17] << 4;
    w1 |= (uint64_t)  in[18] << 8;
    w1 |= (uint64_t)  in[19] << 12;
    w1 |= (uint64_t)  in[20] << 16;
    w1 |= (uint64_t)  in[21] << 20;
    w1 |= (uint64_t)  in[22] << 24;
    w1 |= (uint64_t)  in[23] << 28;
    w1 |= (uint64_t)  in[24] << 32;
    w1 |= (uint64_t)  in[25] << 36;
    w1 |= (uint64_t)  in[26] << 40;
    w1 |= (uint64_t)  in[27] << 44;
    w1 |= (uint64_t)  in[28] << 48;
    w1 |= (uint64_t)  in[29] << 52;
    w1 |= (uint64_t)  in[30] << 56;
    w1 |= (uint64_t)  in[31] << 60;
    pw64[0] = w0;
    pw64[1] = w1;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 16; /* we used up 16 output bytes */
}


/* we are going to pack 32 5-bit values, touching 3 64-bit words, using 20 bytes */
static void packblock5(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  3 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 5;
    w0 |= (uint64_t)  in[2] << 10;
    w0 |= (uint64_t)  in[3] << 15;
    w0 |= (uint64_t)  in[4] << 20;
    w0 |= (uint64_t)  in[5] << 25;
    w0 |= (uint64_t)  in[6] << 30;
    w0 |= (uint64_t)  in[7] << 35;
    w0 |= (uint64_t)  in[8] << 40;
    w0 |= (uint64_t)  in[9] << 45;
    w0 |= (uint64_t)  in[10] << 50;
    w0 |= (uint64_t)  in[11] << 55;
    w0 |= (uint64_t) in[12] << 60;
    w1 = (uint64_t) in[12] >> 4;
    w1 |= (uint64_t)  in[13] << 1;
    w1 |= (uint64_t)  in[14] << 6;
    w1 |= (uint64_t)  in[15] << 11;
    w1 |= (uint64_t)  in[16] << 16;
    w1 |= (uint64_t)  in[17] << 21;
    w1 |= (uint64_t)  in[18] << 26;
    w1 |= (uint64_t)  in[19] << 31;
    w1 |= (uint64_t)  in[20] << 36;
    w1 |= (uint64_t)  in[21] << 41;
    w1 |= (uint64_t)  in[22] << 46;
    w1 |= (uint64_t)  in[23] << 51;
    w1 |= (uint64_t)  in[24] << 56;
    w1 |= (uint64_t) in[25] << 61;
    w2 = (uint64_t) in[25] >> 3;
    w2 |= (uint64_t)  in[26] << 2;
    w2 |= (uint64_t)  in[27] << 7;
    w2 |= (uint64_t)  in[28] << 12;
    w2 |= (uint64_t)  in[29] << 17;
    w2 |= (uint64_t)  in[30] << 22;
    w2 |= (uint64_t)  in[31] << 27;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 20; /* we used up 20 output bytes */
}


/* we are going to pack 32 6-bit values, touching 3 64-bit words, using 24 bytes */
static void packblock6(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  3 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 6;
    w0 |= (uint64_t)  in[2] << 12;
    w0 |= (uint64_t)  in[3] << 18;
    w0 |= (uint64_t)  in[4] << 24;
    w0 |= (uint64_t)  in[5] << 30;
    w0 |= (uint64_t)  in[6] << 36;
    w0 |= (uint64_t)  in[7] << 42;
    w0 |= (uint64_t)  in[8] << 48;
    w0 |= (uint64_t)  in[9] << 54;
    w0 |= (uint64_t) in[10] << 60;
    w1 = (uint64_t) in[10] >> 4;
    w1 |= (uint64_t)  in[11] << 2;
    w1 |= (uint64_t)  in[12] << 8;
    w1 |= (uint64_t)  in[13] << 14;
    w1 |= (uint64_t)  in[14] << 20;
    w1 |= (uint64_t)  in[15] << 26;
    w1 |= (uint64_t)  in[16] << 32;
    w1 |= (uint64_t)  in[17] << 38;
    w1 |= (uint64_t)  in[18] << 44;
    w1 |= (uint64_t)  in[19] << 50;
    w1 |= (uint64_t)  in[20] << 56;
    w1 |= (uint64_t) in[21] << 62;
    w2 = (uint64_t) in[21] >> 2;
    w2 |= (uint64_t)  in[22] << 4;
    w2 |= (uint64_t)  in[23] << 10;
    w2 |= (uint64_t)  in[24] << 16;
    w2 |= (uint64_t)  in[25] << 22;
    w2 |= (uint64_t)  in[26] << 28;
    w2 |= (uint64_t)  in[27] << 34;
    w2 |= (uint64_t)  in[28] << 40;
    w2 |= (uint64_t)  in[29] << 46;
    w2 |= (uint64_t)  in[30] << 52;
    w2 |= (uint64_t)  in[31] << 58;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 24; /* we used up 24 output bytes */
}


/* we are going to pack 32 7-bit values, touching 4 64-bit words, using 28 bytes */
static void packblock7(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  4 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 7;
    w0 |= (uint64_t)  in[2] << 14;
    w0 |= (uint64_t)  in[3] << 21;
    w0 |= (uint64_t)  in[4] << 28;
    w0 |= (uint64_t)  in[5] << 35;
    w0 |= (uint64_t)  in[6] << 42;
    w0 |= (uint64_t)  in[7] << 49;
    w0 |= (uint64_t)  in[8] << 56;
    w0 |= (uint64_t) in[9] << 63;
    w1 = (uint64_t) in[9] >> 1;
    w1 |= (uint64_t)  in[10] << 6;
    w1 |= (uint64_t)  in[11] << 13;
    w1 |= (uint64_t)  in[12] << 20;
    w1 |= (uint64_t)  in[13] << 27;
    w1 |= (uint64_t)  in[14] << 34;
    w1 |= (uint64_t)  in[15] << 41;
    w1 |= (uint64_t)  in[16] << 48;
    w1 |= (uint64_t)  in[17] << 55;
    w1 |= (uint64_t) in[18] << 62;
    w2 = (uint64_t) in[18] >> 2;
    w2 |= (uint64_t)  in[19] << 5;
    w2 |= (uint64_t)  in[20] << 12;
    w2 |= (uint64_t)  in[21] << 19;
    w2 |= (uint64_t)  in[22] << 26;
    w2 |= (uint64_t)  in[23] << 33;
    w2 |= (uint64_t)  in[24] << 40;
    w2 |= (uint64_t)  in[25] << 47;
    w2 |= (uint64_t)  in[26] << 54;
    w2 |= (uint64_t) in[27] << 61;
    w3 = (uint64_t) in[27] >> 3;
    w3 |= (uint64_t)  in[28] << 4;
    w3 |= (uint64_t)  in[29] << 11;
    w3 |= (uint64_t)  in[30] << 18;
    w3 |= (uint64_t)  in[31] << 25;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 28; /* we used up 28 output bytes */
}


/* we are going to pack 32 8-bit values, touching 4 64-bit words, using 32 bytes */
static void packblock8(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  4 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 8;
    w0 |= (uint64_t)  in[2] << 16;
    w0 |= (uint64_t)  in[3] << 24;
    w0 |= (uint64_t)  in[4] << 32;
    w0 |= (uint64_t)  in[5] << 40;
    w0 |= (uint64_t)  in[6] << 48;
    w0 |= (uint64_t)  in[7] << 56;
    w1 = (uint64_t) in[8];
    w1 |= (uint64_t)  in[9] << 8;
    w1 |= (uint64_t)  in[10] << 16;
    w1 |= (uint64_t)  in[11] << 24;
    w1 |= (uint64_t)  in[12] << 32;
    w1 |= (uint64_t)  in[13] << 40;
    w1 |= (uint64_t)  in[14] << 48;
    w1 |= (uint64_t)  in[15] << 56;
    w2 = (uint64_t) in[16];
    w2 |= (uint64_t)  in[17] << 8;
    w2 |= (uint64_t)  in[18] << 16;
    w2 |= (uint64_t)  in[19] << 24;
    w2 |= (uint64_t)  in[20] << 32;
    w2 |= (uint64_t)  in[21] << 40;
    w2 |= (uint64_t)  in[22] << 48;
    w2 |= (uint64_t)  in[23] << 56;
    w3 = (uint64_t) in[24];
    w3 |= (uint64_t)  in[25] << 8;
    w3 |= (uint64_t)  in[26] << 16;
    w3 |= (uint64_t)  in[27] << 24;
    w3 |= (uint64_t)  in[28] << 32;
    w3 |= (uint64_t)  in[29] << 40;
    w3 |= (uint64_t)  in[30] << 48;
    w3 |= (uint64_t)  in[31] << 56;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 32; /* we used up 32 output bytes */
}


/* we are going to pack 32 9-bit values, touching 5 64-bit words, using 36 bytes */
static void packblock9(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  5 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 9;
    w0 |= (uint64_t)  in[2] << 18;
    w0 |= (uint64_t)  in[3] << 27;
    w0 |= (uint64_t)  in[4] << 36;
    w0 |= (uint64_t)  in[5] << 45;
    w0 |= (uint64_t)  in[6] << 54;
    w0 |= (uint64_t) in[7] << 63;
    w1 = (uint64_t) in[7] >> 1;
    w1 |= (uint64_t)  in[8] << 8;
    w1 |= (uint64_t)  in[9] << 17;
    w1 |= (uint64_t)  in[10] << 26;
    w1 |= (uint64_t)  in[11] << 35;
    w1 |= (uint64_t)  in[12] << 44;
    w1 |= (uint64_t)  in[13] << 53;
    w1 |= (uint64_t) in[14] << 62;
    w2 = (uint64_t) in[14] >> 2;
    w2 |= (uint64_t)  in[15] << 7;
    w2 |= (uint64_t)  in[16] << 16;
    w2 |= (uint64_t)  in[17] << 25;
    w2 |= (uint64_t)  in[18] << 34;
    w2 |= (uint64_t)  in[19] << 43;
    w2 |= (uint64_t)  in[20] << 52;
    w2 |= (uint64_t) in[21] << 61;
    w3 = (uint64_t) in[21] >> 3;
    w3 |= (uint64_t)  in[22] << 6;
    w3 |= (uint64_t)  in[23] << 15;
    w3 |= (uint64_t)  in[24] << 24;
    w3 |= (uint64_t)  in[25] << 33;
    w3 |= (uint64_t)  in[26] << 42;
    w3 |= (uint64_t)  in[27] << 51;
    w3 |= (uint64_t) in[28] << 60;
    w4 = (uint64_t) in[28] >> 4;
    w4 |= (uint64_t)  in[29] << 5;
    w4 |= (uint64_t)  in[30] << 14;
    w4 |= (uint64_t)  in[31] << 23;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 36; /* we used up 36 output bytes */
}


/* we are going to pack 32 10-bit values, touching 5 64-bit words, using 40 bytes */
static void packblock10(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  5 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 10;
    w0 |= (uint64_t)  in[2] << 20;
    w0 |= (uint64_t)  in[3] << 30;
    w0 |= (uint64_t)  in[4] << 40;
    w0 |= (uint64_t)  in[5] << 50;
    w0 |= (uint64_t) in[6] << 60;
    w1 = (uint64_t) in[6] >> 4;
    w1 |= (uint64_t)  in[7] << 6;
    w1 |= (uint64_t)  in[8] << 16;
    w1 |= (uint64_t)  in[9] << 26;
    w1 |= (uint64_t)  in[10] << 36;
    w1 |= (uint64_t)  in[11] << 46;
    w1 |= (uint64_t) in[12] << 56;
    w2 = (uint64_t) in[12] >> 8;
    w2 |= (uint64_t)  in[13] << 2;
    w2 |= (uint64_t)  in[14] << 12;
    w2 |= (uint64_t)  in[15] << 22;
    w2 |= (uint64_t)  in[16] << 32;
    w2 |= (uint64_t)  in[17] << 42;
    w2 |= (uint64_t)  in[18] << 52;
    w2 |= (uint64_t) in[19] << 62;
    w3 = (uint64_t) in[19] >> 2;
    w3 |= (uint64_t)  in[20] << 8;
    w3 |= (uint64_t)  in[21] << 18;
    w3 |= (uint64_t)  in[22] << 28;
    w3 |= (uint64_t)  in[23] << 38;
    w3 |= (uint64_t)  in[24] << 48;
    w3 |= (uint64_t) in[25] << 58;
    w4 = (uint64_t) in[25] >> 6;
    w4 |= (uint64_t)  in[26] << 4;
    w4 |= (uint64_t)  in[27] << 14;
    w4 |= (uint64_t)  in[28] << 24;
    w4 |= (uint64_t)  in[29] << 34;
    w4 |= (uint64_t)  in[30] << 44;
    w4 |= (uint64_t)  in[31] << 54;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 40; /* we used up 40 output bytes */
}


/* we are going to pack 32 11-bit values, touching 6 64-bit words, using 44 bytes */
static void packblock11(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  6 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 11;
    w0 |= (uint64_t)  in[2] << 22;
    w0 |= (uint64_t)  in[3] << 33;
    w0 |= (uint64_t)  in[4] << 44;
    w0 |= (uint64_t) in[5] << 55;
    w1 = (uint64_t) in[5] >> 9;
    w1 |= (uint64_t)  in[6] << 2;
    w1 |= (uint64_t)  in[7] << 13;
    w1 |= (uint64_t)  in[8] << 24;
    w1 |= (uint64_t)  in[9] << 35;
    w1 |= (uint64_t)  in[10] << 46;
    w1 |= (uint64_t) in[11] << 57;
    w2 = (uint64_t) in[11] >> 7;
    w2 |= (uint64_t)  in[12] << 4;
    w2 |= (uint64_t)  in[13] << 15;
    w2 |= (uint64_t)  in[14] << 26;
    w2 |= (uint64_t)  in[15] << 37;
    w2 |= (uint64_t)  in[16] << 48;
    w2 |= (uint64_t) in[17] << 59;
    w3 = (uint64_t) in[17] >> 5;
    w3 |= (uint64_t)  in[18] << 6;
    w3 |= (uint64_t)  in[19] << 17;
    w3 |= (uint64_t)  in[20] << 28;
    w3 |= (uint64_t)  in[21] << 39;
    w3 |= (uint64_t)  in[22] << 50;
    w3 |= (uint64_t) in[23] << 61;
    w4 = (uint64_t) in[23] >> 3;
    w4 |= (uint64_t)  in[24] << 8;
    w4 |= (uint64_t)  in[25] << 19;
    w4 |= (uint64_t)  in[26] << 30;
    w4 |= (uint64_t)  in[27] << 41;
    w4 |= (uint64_t)  in[28] << 52;
    w4 |= (uint64_t) in[29] << 63;
    w5 = (uint64_t) in[29] >> 1;
    w5 |= (uint64_t)  in[30] << 10;
    w5 |= (uint64_t)  in[31] << 21;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 44; /* we used up 44 output bytes */
}


/* we are going to pack 32 12-bit values, touching 6 64-bit words, using 48 bytes */
static void packblock12(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  6 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 12;
    w0 |= (uint64_t)  in[2] << 24;
    w0 |= (uint64_t)  in[3] << 36;
    w0 |= (uint64_t)  in[4] << 48;
    w0 |= (uint64_t) in[5] << 60;
    w1 = (uint64_t) in[5] >> 4;
    w1 |= (uint64_t)  in[6] << 8;
    w1 |= (uint64_t)  in[7] << 20;
    w1 |= (uint64_t)  in[8] << 32;
    w1 |= (uint64_t)  in[9] << 44;
    w1 |= (uint64_t) in[10] << 56;
    w2 = (uint64_t) in[10] >> 8;
    w2 |= (uint64_t)  in[11] << 4;
    w2 |= (uint64_t)  in[12] << 16;
    w2 |= (uint64_t)  in[13] << 28;
    w2 |= (uint64_t)  in[14] << 40;
    w2 |= (uint64_t)  in[15] << 52;
    w3 = (uint64_t) in[16];
    w3 |= (uint64_t)  in[17] << 12;
    w3 |= (uint64_t)  in[18] << 24;
    w3 |= (uint64_t)  in[19] << 36;
    w3 |= (uint64_t)  in[20] << 48;
    w3 |= (uint64_t) in[21] << 60;
    w4 = (uint64_t) in[21] >> 4;
    w4 |= (uint64_t)  in[22] << 8;
    w4 |= (uint64_t)  in[23] << 20;
    w4 |= (uint64_t)  in[24] << 32;
    w4 |= (uint64_t)  in[25] << 44;
    w4 |= (uint64_t) in[26] << 56;
    w5 = (uint64_t) in[26] >> 8;
    w5 |= (uint64_t)  in[27] << 4;
    w5 |= (uint64_t)  in[28] << 16;
    w5 |= (uint64_t)  in[29] << 28;
    w5 |= (uint64_t)  in[30] << 40;
    w5 |= (uint64_t)  in[31] << 52;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 48; /* we used up 48 output bytes */
}


/* we are going to pack 32 13-bit values, touching 7 64-bit words, using 52 bytes */
static void packblock13(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  7 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 13;
    w0 |= (uint64_t)  in[2] << 26;
    w0 |= (uint64_t)  in[3] << 39;
    w0 |= (uint64_t) in[4] << 52;
    w1 = (uint64_t) in[4] >> 12;
    w1 |= (uint64_t)  in[5] << 1;
    w1 |= (uint64_t)  in[6] << 14;
    w1 |= (uint64_t)  in[7] << 27;
    w1 |= (uint64_t)  in[8] << 40;
    w1 |= (uint64_t) in[9] << 53;
    w2 = (uint64_t) in[9] >> 11;
    w2 |= (uint64_t)  in[10] << 2;
    w2 |= (uint64_t)  in[11] << 15;
    w2 |= (uint64_t)  in[12] << 28;
    w2 |= (uint64_t)  in[13] << 41;
    w2 |= (uint64_t) in[14] << 54;
    w3 = (uint64_t) in[14] >> 10;
    w3 |= (uint64_t)  in[15] << 3;
    w3 |= (uint64_t)  in[16] << 16;
    w3 |= (uint64_t)  in[17] << 29;
    w3 |= (uint64_t)  in[18] << 42;
    w3 |= (uint64_t) in[19] << 55;
    w4 = (uint64_t) in[19] >> 9;
    w4 |= (uint64_t)  in[20] << 4;
    w4 |= (uint64_t)  in[21] << 17;
    w4 |= (uint64_t)  in[22] << 30;
    w4 |= (uint64_t)  in[23] << 43;
    w4 |= (uint64_t) in[24] << 56;
    w5 = (uint64_t) in[24] >> 8;
    w5 |= (uint64_t)  in[25] << 5;
    w5 |= (uint64_t)  in[26] << 18;
    w5 |= (uint64_t)  in[27] << 31;
    w5 |= (uint64_t)  in[28] << 44;
    w5 |= (uint64_t) in[29] << 57;
    w6 = (uint64_t) in[29] >> 7;
    w6 |= (uint64_t)  in[30] << 6;
    w6 |= (uint64_t)  in[31] << 19;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 52; /* we used up 52 output bytes */
}


/* we are going to pack 32 14-bit values, touching 7 64-bit words, using 56 bytes */
static void packblock14(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  7 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 14;
    w0 |= (uint64_t)  in[2] << 28;
    w0 |= (uint64_t)  in[3] << 42;
    w0 |= (uint64_t) in[4] << 56;
    w1 = (uint64_t) in[4] >> 8;
    w1 |= (uint64_t)  in[5] << 6;
    w1 |= (uint64_t)  in[6] << 20;
    w1 |= (uint64_t)  in[7] << 34;
    w1 |= (uint64_t)  in[8] << 48;
    w1 |= (uint64_t) in[9] << 62;
    w2 = (uint64_t) in[9] >> 2;
    w2 |= (uint64_t)  in[10] << 12;
    w2 |= (uint64_t)  in[11] << 26;
    w2 |= (uint64_t)  in[12] << 40;
    w2 |= (uint64_t) in[13] << 54;
    w3 = (uint64_t) in[13] >> 10;
    w3 |= (uint64_t)  in[14] << 4;
    w3 |= (uint64_t)  in[15] << 18;
    w3 |= (uint64_t)  in[16] << 32;
    w3 |= (uint64_t)  in[17] << 46;
    w3 |= (uint64_t) in[18] << 60;
    w4 = (uint64_t) in[18] >> 4;
    w4 |= (uint64_t)  in[19] << 10;
    w4 |= (uint64_t)  in[20] << 24;
    w4 |= (uint64_t)  in[21] << 38;
    w4 |= (uint64_t) in[22] << 52;
    w5 = (uint64_t) in[22] >> 12;
    w5 |= (uint64_t)  in[23] << 2;
    w5 |= (uint64_t)  in[24] << 16;
    w5 |= (uint64_t)  in[25] << 30;
    w5 |= (uint64_t)  in[26] << 44;
    w5 |= (uint64_t) in[27] << 58;
    w6 = (uint64_t) in[27] >> 6;
    w6 |= (uint64_t)  in[28] << 8;
    w6 |= (uint64_t)  in[29] << 22;
    w6 |= (uint64_t)  in[30] << 36;
    w6 |= (uint64_t)  in[31] << 50;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 56; /* we used up 56 output bytes */
}


/* we are going to pack 32 15-bit values, touching 8 64-bit words, using 60 bytes */
static void packblock15(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  8 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 15;
    w0 |= (uint64_t)  in[2] << 30;
    w0 |= (uint64_t)  in[3] << 45;
    w0 |= (uint64_t) in[4] << 60;
    w1 = (uint64_t) in[4] >> 4;
    w1 |= (uint64_t)  in[5] << 11;
    w1 |= (uint64_t)  in[6] << 26;
    w1 |= (uint64_t)  in[7] << 41;
    w1 |= (uint64_t) in[8] << 56;
    w2 = (uint64_t) in[8] >> 8;
    w2 |= (uint64_t)  in[9] << 7;
    w2 |= (uint64_t)  in[10] << 22;
    w2 |= (uint64_t)  in[11] << 37;
    w2 |= (uint64_t) in[12] << 52;
    w3 = (uint64_t) in[12] >> 12;
    w3 |= (uint64_t)  in[13] << 3;
    w3 |= (uint64_t)  in[14] << 18;
    w3 |= (uint64_t)  in[15] << 33;
    w3 |= (uint64_t)  in[16] << 48;
    w3 |= (uint64_t) in[17] << 63;
    w4 = (uint64_t) in[17] >> 1;
    w4 |= (uint64_t)  in[18] << 14;
    w4 |= (uint64_t)  in[19] << 29;
    w4 |= (uint64_t)  in[20] << 44;
    w4 |= (uint64_t) in[21] << 59;
    w5 = (uint64_t) in[21] >> 5;
    w5 |= (uint64_t)  in[22] << 10;
    w5 |= (uint64_t)  in[23] << 25;
    w5 |= (uint64_t)  in[24] << 40;
    w5 |= (uint64_t) in[25] << 55;
    w6 = (uint64_t) in[25] >> 9;
    w6 |= (uint64_t)  in[26] << 6;
    w6 |= (uint64_t)  in[27] << 21;
    w6 |= (uint64_t)  in[28] << 36;
    w6 |= (uint64_t) in[29] << 51;
    w7 = (uint64_t) in[29] >> 13;
    w7 |= (uint64_t)  in[30] << 2;
    w7 |= (uint64_t)  in[31] << 17;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 60; /* we used up 60 output bytes */
}


/* we are going to pack 32 16-bit values, touching 8 64-bit words, using 64 bytes */
static void packblock16(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  8 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 16;
    w0 |= (uint64_t)  in[2] << 32;
    w0 |= (uint64_t)  in[3] << 48;
    w1 = (uint64_t) in[4];
    w1 |= (uint64_t)  in[5] << 16;
    w1 |= (uint64_t)  in[6] << 32;
    w1 |= (uint64_t)  in[7] << 48;
    w2 = (uint64_t) in[8];
    w2 |= (uint64_t)  in[9] << 16;
    w2 |= (uint64_t)  in[10] << 32;
    w2 |= (uint64_t)  in[11] << 48;
    w3 = (uint64_t) in[12];
    w3 |= (uint64_t)  in[13] << 16;
    w3 |= (uint64_t)  in[14] << 32;
    w3 |= (uint64_t)  in[15] << 48;
    w4 = (uint64_t) in[16];
    w4 |= (uint64_t)  in[17] << 16;
    w4 |= (uint64_t)  in[18] << 32;
    w4 |= (uint64_t)  in[19] << 48;
    w5 = (uint64_t) in[20];
    w5 |= (uint64_t)  in[21] << 16;
    w5 |= (uint64_t)  in[22] << 32;
    w5 |= (uint64_t)  in[23] << 48;
    w6 = (uint64_t) in[24];
    w6 |= (uint64_t)  in[25] << 16;
    w6 |= (uint64_t)  in[26] << 32;
    w6 |= (uint64_t)  in[27] << 48;
    w7 = (uint64_t) in[28];
    w7 |= (uint64_t)  in[29] << 16;
    w7 |= (uint64_t)  in[30] << 32;
    w7 |= (uint64_t)  in[31] << 48;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 64; /* we used up 64 output bytes */
}


/* we are going to pack 32 17-bit values, touching 9 64-bit words, using 68 bytes */
static void packblock17(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  9 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 17;
    w0 |= (uint64_t)  in[2] << 34;
    w0 |= (uint64_t) in[3] << 51;
    w1 = (uint64_t) in[3] >> 13;
    w1 |= (uint64_t)  in[4] << 4;
    w1 |= (uint64_t)  in[5] << 21;
    w1 |= (uint64_t)  in[6] << 38;
    w1 |= (uint64_t) in[7] << 55;
    w2 = (uint64_t) in[7] >> 9;
    w2 |= (uint64_t)  in[8] << 8;
    w2 |= (uint64_t)  in[9] << 25;
    w2 |= (uint64_t)  in[10] << 42;
    w2 |= (uint64_t) in[11] << 59;
    w3 = (uint64_t) in[11] >> 5;
    w3 |= (uint64_t)  in[12] << 12;
    w3 |= (uint64_t)  in[13] << 29;
    w3 |= (uint64_t)  in[14] << 46;
    w3 |= (uint64_t) in[15] << 63;
    w4 = (uint64_t) in[15] >> 1;
    w4 |= (uint64_t)  in[16] << 16;
    w4 |= (uint64_t)  in[17] << 33;
    w4 |= (uint64_t) in[18] << 50;
    w5 = (uint64_t) in[18] >> 14;
    w5 |= (uint64_t)  in[19] << 3;
    w5 |= (uint64_t)  in[20] << 20;
    w5 |= (uint64_t)  in[21] << 37;
    w5 |= (uint64_t) in[22] << 54;
    w6 = (uint64_t) in[22] >> 10;
    w6 |= (uint64_t)  in[23] << 7;
    w6 |= (uint64_t)  in[24] << 24;
    w6 |= (uint64_t)  in[25] << 41;
    w6 |= (uint64_t) in[26] << 58;
    w7 = (uint64_t) in[26] >> 6;
    w7 |= (uint64_t)  in[27] << 11;
    w7 |= (uint64_t)  in[28] << 28;
    w7 |= (uint64_t)  in[29] << 45;
    w7 |= (uint64_t) in[30] << 62;
    w8 = (uint64_t) in[30] >> 2;
    w8 |= (uint64_t)  in[31] << 15;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 68; /* we used up 68 output bytes */
}


/* we are going to pack 32 18-bit values, touching 9 64-bit words, using 72 bytes */
static void packblock18(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  9 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 18;
    w0 |= (uint64_t)  in[2] << 36;
    w0 |= (uint64_t) in[3] << 54;
    w1 = (uint64_t) in[3] >> 10;
    w1 |= (uint64_t)  in[4] << 8;
    w1 |= (uint64_t)  in[5] << 26;
    w1 |= (uint64_t)  in[6] << 44;
    w1 |= (uint64_t) in[7] << 62;
    w2 = (uint64_t) in[7] >> 2;
    w2 |= (uint64_t)  in[8] << 16;
    w2 |= (uint64_t)  in[9] << 34;
    w2 |= (uint64_t) in[10] << 52;
    w3 = (uint64_t) in[10] >> 12;
    w3 |= (uint64_t)  in[11] << 6;
    w3 |= (uint64_t)  in[12] << 24;
    w3 |= (uint64_t)  in[13] << 42;
    w3 |= (uint64_t) in[14] << 60;
    w4 = (uint64_t) in[14] >> 4;
    w4 |= (uint64_t)  in[15] << 14;
    w4 |= (uint64_t)  in[16] << 32;
    w4 |= (uint64_t) in[17] << 50;
    w5 = (uint64_t) in[17] >> 14;
    w5 |= (uint64_t)  in[18] << 4;
    w5 |= (uint64_t)  in[19] << 22;
    w5 |= (uint64_t)  in[20] << 40;
    w5 |= (uint64_t) in[21] << 58;
    w6 = (uint64_t) in[21] >> 6;
    w6 |= (uint64_t)  in[22] << 12;
    w6 |= (uint64_t)  in[23] << 30;
    w6 |= (uint64_t) in[24] << 48;
    w7 = (uint64_t) in[24] >> 16;
    w7 |= (uint64_t)  in[25] << 2;
    w7 |= (uint64_t)  in[26] << 20;
    w7 |= (uint64_t)  in[27] << 38;
    w7 |= (uint64_t) in[28] << 56;
    w8 = (uint64_t) in[28] >> 8;
    w8 |= (uint64_t)  in[29] << 10;
    w8 |= (uint64_t)  in[30] << 28;
    w8 |= (uint64_t)  in[31] << 46;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 72; /* we used up 72 output bytes */
}


/* we are going to pack 32 19-bit values, touching 10 64-bit words, using 76 bytes */
static void packblock19(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  10 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 19;
    w0 |= (uint64_t)  in[2] << 38;
    w0 |= (uint64_t) in[3] << 57;
    w1 = (uint64_t) in[3] >> 7;
    w1 |= (uint64_t)  in[4] << 12;
    w1 |= (uint64_t)  in[5] << 31;
    w1 |= (uint64_t) in[6] << 50;
    w2 = (uint64_t) in[6] >> 14;
    w2 |= (uint64_t)  in[7] << 5;
    w2 |= (uint64_t)  in[8] << 24;
    w2 |= (uint64_t)  in[9] << 43;
    w2 |= (uint64_t) in[10] << 62;
    w3 = (uint64_t) in[10] >> 2;
    w3 |= (uint64_t)  in[11] << 17;
    w3 |= (uint64_t)  in[12] << 36;
    w3 |= (uint64_t) in[13] << 55;
    w4 = (uint64_t) in[13] >> 9;
    w4 |= (uint64_t)  in[14] << 10;
    w4 |= (uint64_t)  in[15] << 29;
    w4 |= (uint64_t) in[16] << 48;
    w5 = (uint64_t) in[16] >> 16;
    w5 |= (uint64_t)  in[17] << 3;
    w5 |= (uint64_t)  in[18] << 22;
    w5 |= (uint64_t)  in[19] << 41;
    w5 |= (uint64_t) in[20] << 60;
    w6 = (uint64_t) in[20] >> 4;
    w6 |= (uint64_t)  in[21] << 15;
    w6 |= (uint64_t)  in[22] << 34;
    w6 |= (uint64_t) in[23] << 53;
    w7 = (uint64_t) in[23] >> 11;
    w7 |= (uint64_t)  in[24] << 8;
    w7 |= (uint64_t)  in[25] << 27;
    w7 |= (uint64_t) in[26] << 46;
    w8 = (uint64_t) in[26] >> 18;
    w8 |= (uint64_t)  in[27] << 1;
    w8 |= (uint64_t)  in[28] << 20;
    w8 |= (uint64_t)  in[29] << 39;
    w8 |= (uint64_t) in[30] << 58;
    w9 = (uint64_t) in[30] >> 6;
    w9 |= (uint64_t)  in[31] << 13;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 76; /* we used up 76 output bytes */
}


/* we are going to pack 32 20-bit values, touching 10 64-bit words, using 80 bytes */
static void packblock20(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  10 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 20;
    w0 |= (uint64_t)  in[2] << 40;
    w0 |= (uint64_t) in[3] << 60;
    w1 = (uint64_t) in[3] >> 4;
    w1 |= (uint64_t)  in[4] << 16;
    w1 |= (uint64_t)  in[5] << 36;
    w1 |= (uint64_t) in[6] << 56;
    w2 = (uint64_t) in[6] >> 8;
    w2 |= (uint64_t)  in[7] << 12;
    w2 |= (uint64_t)  in[8] << 32;
    w2 |= (uint64_t) in[9] << 52;
    w3 = (uint64_t) in[9] >> 12;
    w3 |= (uint64_t)  in[10] << 8;
    w3 |= (uint64_t)  in[11] << 28;
    w3 |= (uint64_t) in[12] << 48;
    w4 = (uint64_t) in[12] >> 16;
    w4 |= (uint64_t)  in[13] << 4;
    w4 |= (uint64_t)  in[14] << 24;
    w4 |= (uint64_t)  in[15] << 44;
    w5 = (uint64_t) in[16];
    w5 |= (uint64_t)  in[17] << 20;
    w5 |= (uint64_t)  in[18] << 40;
    w5 |= (uint64_t) in[19] << 60;
    w6 = (uint64_t) in[19] >> 4;
    w6 |= (uint64_t)  in[20] << 16;
    w6 |= (uint64_t)  in[21] << 36;
    w6 |= (uint64_t) in[22] << 56;
    w7 = (uint64_t) in[22] >> 8;
    w7 |= (uint64_t)  in[23] << 12;
    w7 |= (uint64_t)  in[24] << 32;
    w7 |= (uint64_t) in[25] << 52;
    w8 = (uint64_t) in[25] >> 12;
    w8 |= (uint64_t)  in[26] << 8;
    w8 |= (uint64_t)  in[27] << 28;
    w8 |= (uint64_t) in[28] << 48;
    w9 = (uint64_t) in[28] >> 16;
    w9 |= (uint64_t)  in[29] << 4;
    w9 |= (uint64_t)  in[30] << 24;
    w9 |= (uint64_t)  in[31] << 44;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 80; /* we used up 80 output bytes */
}


/* we are going to pack 32 21-bit values, touching 11 64-bit words, using 84 bytes */
static void packblock21(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  11 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 21;
    w0 |= (uint64_t)  in[2] << 42;
    w0 |= (uint64_t) in[3] << 63;
    w1 = (uint64_t) in[3] >> 1;
    w1 |= (uint64_t)  in[4] << 20;
    w1 |= (uint64_t)  in[5] << 41;
    w1 |= (uint64_t) in[6] << 62;
    w2 = (uint64_t) in[6] >> 2;
    w2 |= (uint64_t)  in[7] << 19;
    w2 |= (uint64_t)  in[8] << 40;
    w2 |= (uint64_t) in[9] << 61;
    w3 = (uint64_t) in[9] >> 3;
    w3 |= (uint64_t)  in[10] << 18;
    w3 |= (uint64_t)  in[11] << 39;
    w3 |= (uint64_t) in[12] << 60;
    w4 = (uint64_t) in[12] >> 4;
    w4 |= (uint64_t)  in[13] << 17;
    w4 |= (uint64_t)  in[14] << 38;
    w4 |= (uint64_t) in[15] << 59;
    w5 = (uint64_t) in[15] >> 5;
    w5 |= (uint64_t)  in[16] << 16;
    w5 |= (uint64_t)  in[17] << 37;
    w5 |= (uint64_t) in[18] << 58;
    w6 = (uint64_t) in[18] >> 6;
    w6 |= (uint64_t)  in[19] << 15;
    w6 |= (uint64_t)  in[20] << 36;
    w6 |= (uint64_t) in[21] << 57;
    w7 = (uint64_t) in[21] >> 7;
    w7 |= (uint64_t)  in[22] << 14;
    w7 |= (uint64_t)  in[23] << 35;
    w7 |= (uint64_t) in[24] << 56;
    w8 = (uint64_t) in[24] >> 8;
    w8 |= (uint64_t)  in[25] << 13;
    w8 |= (uint64_t)  in[26] << 34;
    w8 |= (uint64_t) in[27] << 55;
    w9 = (uint64_t) in[27] >> 9;
    w9 |= (uint64_t)  in[28] << 12;
    w9 |= (uint64_t)  in[29] << 33;
    w9 |= (uint64_t) in[30] << 54;
    w10 = (uint64_t) in[30] >> 10;
    w10 |= (uint64_t)  in[31] << 11;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 84; /* we used up 84 output bytes */
}


/* we are going to pack 32 22-bit values, touching 11 64-bit words, using 88 bytes */
static void packblock22(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  11 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 22;
    w0 |= (uint64_t) in[2] << 44;
    w1 = (uint64_t) in[2] >> 20;
    w1 |= (uint64_t)  in[3] << 2;
    w1 |= (uint64_t)  in[4] << 24;
    w1 |= (uint64_t) in[5] << 46;
    w2 = (uint64_t) in[5] >> 18;
    w2 |= (uint64_t)  in[6] << 4;
    w2 |= (uint64_t)  in[7] << 26;
    w2 |= (uint64_t) in[8] << 48;
    w3 = (uint64_t) in[8] >> 16;
    w3 |= (uint64_t)  in[9] << 6;
    w3 |= (uint64_t)  in[10] << 28;
    w3 |= (uint64_t) in[11] << 50;
    w4 = (uint64_t) in[11] >> 14;
    w4 |= (uint64_t)  in[12] << 8;
    w4 |= (uint64_t)  in[13] << 30;
    w4 |= (uint64_t) in[14] << 52;
    w5 = (uint64_t) in[14] >> 12;
    w5 |= (uint64_t)  in[15] << 10;
    w5 |= (uint64_t)  in[16] << 32;
    w5 |= (uint64_t) in[17] << 54;
    w6 = (uint64_t) in[17] >> 10;
    w6 |= (uint64_t)  in[18] << 12;
    w6 |= (uint64_t)  in[19] << 34;
    w6 |= (uint64_t) in[20] << 56;
    w7 = (uint64_t) in[20] >> 8;
    w7 |= (uint64_t)  in[21] << 14;
    w7 |= (uint64_t)  in[22] << 36;
    w7 |= (uint64_t) in[23] << 58;
    w8 = (uint64_t) in[23] >> 6;
    w8 |= (uint64_t)  in[24] << 16;
    w8 |= (uint64_t)  in[25] << 38;
    w8 |= (uint64_t) in[26] << 60;
    w9 = (uint64_t) in[26] >> 4;
    w9 |= (uint64_t)  in[27] << 18;
    w9 |= (uint64_t)  in[28] << 40;
    w9 |= (uint64_t) in[29] << 62;
    w10 = (uint64_t) in[29] >> 2;
    w10 |= (uint64_t)  in[30] << 20;
    w10 |= (uint64_t)  in[31] << 42;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 88; /* we used up 88 output bytes */
}


/* we are going to pack 32 23-bit values, touching 12 64-bit words, using 92 bytes */
static void packblock23(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  12 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 23;
    w0 |= (uint64_t) in[2] << 46;
    w1 = (uint64_t) in[2] >> 18;
    w1 |= (uint64_t)  in[3] << 5;
    w1 |= (uint64_t)  in[4] << 28;
    w1 |= (uint64_t) in[5] << 51;
    w2 = (uint64_t) in[5] >> 13;
    w2 |= (uint64_t)  in[6] << 10;
    w2 |= (uint64_t)  in[7] << 33;
    w2 |= (uint64_t) in[8] << 56;
    w3 = (uint64_t) in[8] >> 8;
    w3 |= (uint64_t)  in[9] << 15;
    w3 |= (uint64_t)  in[10] << 38;
    w3 |= (uint64_t) in[11] << 61;
    w4 = (uint64_t) in[11] >> 3;
    w4 |= (uint64_t)  in[12] << 20;
    w4 |= (uint64_t) in[13] << 43;
    w5 = (uint64_t) in[13] >> 21;
    w5 |= (uint64_t)  in[14] << 2;
    w5 |= (uint64_t)  in[15] << 25;
    w5 |= (uint64_t) in[16] << 48;
    w6 = (uint64_t) in[16] >> 16;
    w6 |= (uint64_t)  in[17] << 7;
    w6 |= (uint64_t)  in[18] << 30;
    w6 |= (uint64_t) in[19] << 53;
    w7 = (uint64_t) in[19] >> 11;
    w7 |= (uint64_t)  in[20] << 12;
    w7 |= (uint64_t)  in[21] << 35;
    w7 |= (uint64_t) in[22] << 58;
    w8 = (uint64_t) in[22] >> 6;
    w8 |= (uint64_t)  in[23] << 17;
    w8 |= (uint64_t)  in[24] << 40;
    w8 |= (uint64_t) in[25] << 63;
    w9 = (uint64_t) in[25] >> 1;
    w9 |= (uint64_t)  in[26] << 22;
    w9 |= (uint64_t) in[27] << 45;
    w10 = (uint64_t) in[27] >> 19;
    w10 |= (uint64_t)  in[28] << 4;
    w10 |= (uint64_t)  in[29] << 27;
    w10 |= (uint64_t) in[30] << 50;
    w11 = (uint64_t) in[30] >> 14;
    w11 |= (uint64_t)  in[31] << 9;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 92; /* we used up 92 output bytes */
}


/* we are going to pack 32 24-bit values, touching 12 64-bit words, using 96 bytes */
static void packblock24(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  12 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 24;
    w0 |= (uint64_t) in[2] << 48;
    w1 = (uint64_t) in[2] >> 16;
    w1 |= (uint64_t)  in[3] << 8;
    w1 |= (uint64_t)  in[4] << 32;
    w1 |= (uint64_t) in[5] << 56;
    w2 = (uint64_t) in[5] >> 8;
    w2 |= (uint64_t)  in[6] << 16;
    w2 |= (uint64_t)  in[7] << 40;
    w3 = (uint64_t) in[8];
    w3 |= (uint64_t)  in[9] << 24;
    w3 |= (uint64_t) in[10] << 48;
    w4 = (uint64_t) in[10] >> 16;
    w4 |= (uint64_t)  in[11] << 8;
    w4 |= (uint64_t)  in[12] << 32;
    w4 |= (uint64_t) in[13] << 56;
    w5 = (uint64_t) in[13] >> 8;
    w5 |= (uint64_t)  in[14] << 16;
    w5 |= (uint64_t)  in[15] << 40;
    w6 = (uint64_t) in[16];
    w6 |= (uint64_t)  in[17] << 24;
    w6 |= (uint64_t) in[18] << 48;
    w7 = (uint64_t) in[18] >> 16;
    w7 |= (uint64_t)  in[19] << 8;
    w7 |= (uint64_t)  in[20] << 32;
    w7 |= (uint64_t) in[21] << 56;
    w8 = (uint64_t) in[21] >> 8;
    w8 |= (uint64_t)  in[22] << 16;
    w8 |= (uint64_t)  in[23] << 40;
    w9 = (uint64_t) in[24];
    w9 |= (uint64_t)  in[25] << 24;
    w9 |= (uint64_t) in[26] << 48;
    w10 = (uint64_t) in[26] >> 16;
    w10 |= (uint64_t)  in[27] << 8;
    w10 |= (uint64_t)  in[28] << 32;
    w10 |= (uint64_t) in[29] << 56;
    w11 = (uint64_t) in[29] >> 8;
    w11 |= (uint64_t)  in[30] << 16;
    w11 |= (uint64_t)  in[31] << 40;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 96; /* we used up 96 output bytes */
}


/* we are going to pack 32 25-bit values, touching 13 64-bit words, using 100 bytes */
static void packblock25(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  13 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 25;
    w0 |= (uint64_t) in[2] << 50;
    w1 = (uint64_t) in[2] >> 14;
    w1 |= (uint64_t)  in[3] << 11;
    w1 |= (uint64_t)  in[4] << 36;
    w1 |= (uint64_t) in[5] << 61;
    w2 = (uint64_t) in[5] >> 3;
    w2 |= (uint64_t)  in[6] << 22;
    w2 |= (uint64_t) in[7] << 47;
    w3 = (uint64_t) in[7] >> 17;
    w3 |= (uint64_t)  in[8] << 8;
    w3 |= (uint64_t)  in[9] << 33;
    w3 |= (uint64_t) in[10] << 58;
    w4 = (uint64_t) in[10] >> 6;
    w4 |= (uint64_t)  in[11] << 19;
    w4 |= (uint64_t) in[12] << 44;
    w5 = (uint64_t) in[12] >> 20;
    w5 |= (uint64_t)  in[13] << 5;
    w5 |= (uint64_t)  in[14] << 30;
    w5 |= (uint64_t) in[15] << 55;
    w6 = (uint64_t) in[15] >> 9;
    w6 |= (uint64_t)  in[16] << 16;
    w6 |= (uint64_t) in[17] << 41;
    w7 = (uint64_t) in[17] >> 23;
    w7 |= (uint64_t)  in[18] << 2;
    w7 |= (uint64_t)  in[19] << 27;
    w7 |= (uint64_t) in[20] << 52;
    w8 = (uint64_t) in[20] >> 12;
    w8 |= (uint64_t)  in[21] << 13;
    w8 |= (uint64_t)  in[22] << 38;
    w8 |= (uint64_t) in[23] << 63;
    w9 = (uint64_t) in[23] >> 1;
    w9 |= (uint64_t)  in[24] << 24;
    w9 |= (uint64_t) in[25] << 49;
    w10 = (uint64_t) in[25] >> 15;
    w10 |= (uint64_t)  in[26] << 10;
    w10 |= (uint64_t)  in[27] << 35;
    w10 |= (uint64_t) in[28] << 60;
    w11 = (uint64_t) in[28] >> 4;
    w11 |= (uint64_t)  in[29] << 21;
    w11 |= (uint64_t) in[30] << 46;
    w12 = (uint64_t) in[30] >> 18;
    w12 |= (uint64_t)  in[31] << 7;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 100; /* we used up 100 output bytes */
}


/* we are going to pack 32 26-bit values, touching 13 64-bit words, using 104 bytes */
static void packblock26(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  13 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 26;
    w0 |= (uint64_t) in[2] << 52;
    w1 = (uint64_t) in[2] >> 12;
    w1 |= (uint64_t)  in[3] << 14;
    w1 |= (uint64_t) in[4] << 40;
    w2 = (uint64_t) in[4] >> 24;
    w2 |= (uint64_t)  in[5] << 2;
    w2 |= (uint64_t)  in[6] << 28;
    w2 |= (uint64_t) in[7] << 54;
    w3 = (uint64_t) in[7] >> 10;
    w3 |= (uint64_t)  in[8] << 16;
    w3 |= (uint64_t) in[9] << 42;
    w4 = (uint64_t) in[9] >> 22;
    w4 |= (uint64_t)  in[10] << 4;
    w4 |= (uint64_t)  in[11] << 30;
    w4 |= (uint64_t) in[12] << 56;
    w5 = (uint64_t) in[12] >> 8;
    w5 |= (uint64_t)  in[13] << 18;
    w5 |= (uint64_t) in[14] << 44;
    w6 = (uint64_t) in[14] >> 20;
    w6 |= (uint64_t)  in[15] << 6;
    w6 |= (uint64_t)  in[16] << 32;
    w6 |= (uint64_t) in[17] << 58;
    w7 = (uint64_t) in[17] >> 6;
    w7 |= (uint64_t)  in[18] << 20;
    w7 |= (uint64_t) in[19] << 46;
    w8 = (uint64_t) in[19] >> 18;
    w8 |= (uint64_t)  in[20] << 8;
    w8 |= (uint64_t)  in[21] << 34;
    w8 |= (uint64_t) in[22] << 60;
    w9 = (uint64_t) in[22] >> 4;
    w9 |= (uint64_t)  in[23] << 22;
    w9 |= (uint64_t) in[24] << 48;
    w10 = (uint64_t) in[24] >> 16;
    w10 |= (uint64_t)  in[25] << 10;
    w10 |= (uint64_t)  in[26] << 36;
    w10 |= (uint64_t) in[27] << 62;
    w11 = (uint64_t) in[27] >> 2;
    w11 |= (uint64_t)  in[28] << 24;
    w11 |= (uint64_t) in[29] << 50;
    w12 = (uint64_t) in[29] >> 14;
    w12 |= (uint64_t)  in[30] << 12;
    w12 |= (uint64_t)  in[31] << 38;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 104; /* we used up 104 output bytes */
}


/* we are going to pack 32 27-bit values, touching 14 64-bit words, using 108 bytes */
static void packblock27(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  14 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    uint64_t w13;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 27;
    w0 |= (uint64_t) in[2] << 54;
    w1 = (uint64_t) in[2] >> 10;
    w1 |= (uint64_t)  in[3] << 17;
    w1 |= (uint64_t) in[4] << 44;
    w2 = (uint64_t) in[4] >> 20;
    w2 |= (uint64_t)  in[5] << 7;
    w2 |= (uint64_t)  in[6] << 34;
    w2 |= (uint64_t) in[7] << 61;
    w3 = (uint64_t) in[7] >> 3;
    w3 |= (uint64_t)  in[8] << 24;
    w3 |= (uint64_t) in[9] << 51;
    w4 = (uint64_t) in[9] >> 13;
    w4 |= (uint64_t)  in[10] << 14;
    w4 |= (uint64_t) in[11] << 41;
    w5 = (uint64_t) in[11] >> 23;
    w5 |= (uint64_t)  in[12] << 4;
    w5 |= (uint64_t)  in[13] << 31;
    w5 |= (uint64_t) in[14] << 58;
    w6 = (uint64_t) in[14] >> 6;
    w6 |= (uint64_t)  in[15] << 21;
    w6 |= (uint64_t) in[16] << 48;
    w7 = (uint64_t) in[16] >> 16;
    w7 |= (uint64_t)  in[17] << 11;
    w7 |= (uint64_t) in[18] << 38;
    w8 = (uint64_t) in[18] >> 26;
    w8 |= (uint64_t)  in[19] << 1;
    w8 |= (uint64_t)  in[20] << 28;
    w8 |= (uint64_t) in[21] << 55;
    w9 = (uint64_t) in[21] >> 9;
    w9 |= (uint64_t)  in[22] << 18;
    w9 |= (uint64_t) in[23] << 45;
    w10 = (uint64_t) in[23] >> 19;
    w10 |= (uint64_t)  in[24] << 8;
    w10 |= (uint64_t)  in[25] << 35;
    w10 |= (uint64_t) in[26] << 62;
    w11 = (uint64_t) in[26] >> 2;
    w11 |= (uint64_t)  in[27] << 25;
    w11 |= (uint64_t) in[28] << 52;
    w12 = (uint64_t) in[28] >> 12;
    w12 |= (uint64_t)  in[29] << 15;
    w12 |= (uint64_t) in[30] << 42;
    w13 = (uint64_t) in[30] >> 22;
    w13 |= (uint64_t)  in[31] << 5;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    pw64[13] = w13;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 108; /* we used up 108 output bytes */
}


/* we are going to pack 32 28-bit values, touching 14 64-bit words, using 112 bytes */
static void packblock28(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  14 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    uint64_t w13;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 28;
    w0 |= (uint64_t) in[2] << 56;
    w1 = (uint64_t) in[2] >> 8;
    w1 |= (uint64_t)  in[3] << 20;
    w1 |= (uint64_t) in[4] << 48;
    w2 = (uint64_t) in[4] >> 16;
    w2 |= (uint64_t)  in[5] << 12;
    w2 |= (uint64_t) in[6] << 40;
    w3 = (uint64_t) in[6] >> 24;
    w3 |= (uint64_t)  in[7] << 4;
    w3 |= (uint64_t)  in[8] << 32;
    w3 |= (uint64_t) in[9] << 60;
    w4 = (uint64_t) in[9] >> 4;
    w4 |= (uint64_t)  in[10] << 24;
    w4 |= (uint64_t) in[11] << 52;
    w5 = (uint64_t) in[11] >> 12;
    w5 |= (uint64_t)  in[12] << 16;
    w5 |= (uint64_t) in[13] << 44;
    w6 = (uint64_t) in[13] >> 20;
    w6 |= (uint64_t)  in[14] << 8;
    w6 |= (uint64_t)  in[15] << 36;
    w7 = (uint64_t) in[16];
    w7 |= (uint64_t)  in[17] << 28;
    w7 |= (uint64_t) in[18] << 56;
    w8 = (uint64_t) in[18] >> 8;
    w8 |= (uint64_t)  in[19] << 20;
    w8 |= (uint64_t) in[20] << 48;
    w9 = (uint64_t) in[20] >> 16;
    w9 |= (uint64_t)  in[21] << 12;
    w9 |= (uint64_t) in[22] << 40;
    w10 = (uint64_t) in[22] >> 24;
    w10 |= (uint64_t)  in[23] << 4;
    w10 |= (uint64_t)  in[24] << 32;
    w10 |= (uint64_t) in[25] << 60;
    w11 = (uint64_t) in[25] >> 4;
    w11 |= (uint64_t)  in[26] << 24;
    w11 |= (uint64_t) in[27] << 52;
    w12 = (uint64_t) in[27] >> 12;
    w12 |= (uint64_t)  in[28] << 16;
    w12 |= (uint64_t) in[29] << 44;
    w13 = (uint64_t) in[29] >> 20;
    w13 |= (uint64_t)  in[30] << 8;
    w13 |= (uint64_t)  in[31] << 36;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    pw64[13] = w13;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 112; /* we used up 112 output bytes */
}


/* we are going to pack 32 29-bit values, touching 15 64-bit words, using 116 bytes */
static void packblock29(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  15 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    uint64_t w13;
    uint64_t w14;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 29;
    w0 |= (uint64_t) in[2] << 58;
    w1 = (uint64_t) in[2] >> 6;
    w1 |= (uint64_t)  in[3] << 23;
    w1 |= (uint64_t) in[4] << 52;
    w2 = (uint64_t) in[4] >> 12;
    w2 |= (uint64_t)  in[5] << 17;
    w2 |= (uint64_t) in[6] << 46;
    w3 = (uint64_t) in[6] >> 18;
    w3 |= (uint64_t)  in[7] << 11;
    w3 |= (uint64_t) in[8] << 40;
    w4 = (uint64_t) in[8] >> 24;
    w4 |= (uint64_t)  in[9] << 5;
    w4 |= (uint64_t)  in[10] << 34;
    w4 |= (uint64_t) in[11] << 63;
    w5 = (uint64_t) in[11] >> 1;
    w5 |= (uint64_t)  in[12] << 28;
    w5 |= (uint64_t) in[13] << 57;
    w6 = (uint64_t) in[13] >> 7;
    w6 |= (uint64_t)  in[14] << 22;
    w6 |= (uint64_t) in[15] << 51;
    w7 = (uint64_t) in[15] >> 13;
    w7 |= (uint64_t)  in[16] << 16;
    w7 |= (uint64_t) in[17] << 45;
    w8 = (uint64_t) in[17] >> 19;
    w8 |= (uint64_t)  in[18] << 10;
    w8 |= (uint64_t) in[19] << 39;
    w9 = (uint64_t) in[19] >> 25;
    w9 |= (uint64_t)  in[20] << 4;
    w9 |= (uint64_t)  in[21] << 33;
    w9 |= (uint64_t) in[22] << 62;
    w10 = (uint64_t) in[22] >> 2;
    w10 |= (uint64_t)  in[23] << 27;
    w10 |= (uint64_t) in[24] << 56;
    w11 = (uint64_t) in[24] >> 8;
    w11 |= (uint64_t)  in[25] << 21;
    w11 |= (uint64_t) in[26] << 50;
    w12 = (uint64_t) in[26] >> 14;
    w12 |= (uint64_t)  in[27] << 15;
    w12 |= (uint64_t) in[28] << 44;
    w13 = (uint64_t) in[28] >> 20;
    w13 |= (uint64_t)  in[29] << 9;
    w13 |= (uint64_t) in[30] << 38;
    w14 = (uint64_t) in[30] >> 26;
    w14 |= (uint64_t)  in[31] << 3;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    pw64[13] = w13;
    pw64[14] = w14;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 116; /* we used up 116 output bytes */
}


/* we are going to pack 32 30-bit values, touching 15 64-bit words, using 120 bytes */
static void packblock30(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  15 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    uint64_t w13;
    uint64_t w14;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 30;
    w0 |= (uint64_t) in[2] << 60;
    w1 = (uint64_t) in[2] >> 4;
    w1 |= (uint64_t)  in[3] << 26;
    w1 |= (uint64_t) in[4] << 56;
    w2 = (uint64_t) in[4] >> 8;
    w2 |= (uint64_t)  in[5] << 22;
    w2 |= (uint64_t) in[6] << 52;
    w3 = (uint64_t) in[6] >> 12;
    w3 |= (uint64_t)  in[7] << 18;
    w3 |= (uint64_t) in[8] << 48;
    w4 = (uint64_t) in[8] >> 16;
    w4 |= (uint64_t)  in[9] << 14;
    w4 |= (uint64_t) in[10] << 44;
    w5 = (uint64_t) in[10] >> 20;
    w5 |= (uint64_t)  in[11] << 10;
    w5 |= (uint64_t) in[12] << 40;
    w6 = (uint64_t) in[12] >> 24;
    w6 |= (uint64_t)  in[13] << 6;
    w6 |= (uint64_t) in[14] << 36;
    w7 = (uint64_t) in[14] >> 28;
    w7 |= (uint64_t)  in[15] << 2;
    w7 |= (uint64_t)  in[16] << 32;
    w7 |= (uint64_t) in[17] << 62;
    w8 = (uint64_t) in[17] >> 2;
    w8 |= (uint64_t)  in[18] << 28;
    w8 |= (uint64_t) in[19] << 58;
    w9 = (uint64_t) in[19] >> 6;
    w9 |= (uint64_t)  in[20] << 24;
    w9 |= (uint64_t) in[21] << 54;
    w10 = (uint64_t) in[21] >> 10;
    w10 |= (uint64_t)  in[22] << 20;
    w10 |= (uint64_t) in[23] << 50;
    w11 = (uint64_t) in[23] >> 14;
    w11 |= (uint64_t)  in[24] << 16;
    w11 |= (uint64_t) in[25] << 46;
    w12 = (uint64_t) in[25] >> 18;
    w12 |= (uint64_t)  in[26] << 12;
    w12 |= (uint64_t) in[27] << 42;
    w13 = (uint64_t) in[27] >> 22;
    w13 |= (uint64_t)  in[28] << 8;
    w13 |= (uint64_t) in[29] << 38;
    w14 = (uint64_t) in[29] >> 26;
    w14 |= (uint64_t)  in[30] << 4;
    w14 |= (uint64_t)  in[31] << 34;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    pw64[13] = w13;
    pw64[14] = w14;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 120; /* we used up 120 output bytes */
}


/* we are going to pack 32 31-bit values, touching 16 64-bit words, using 124 bytes */
static void packblock31(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  16 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    uint64_t w13;
    uint64_t w14;
    uint64_t w15;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 31;
    w0 |= (uint64_t) in[2] << 62;
    w1 = (uint64_t) in[2] >> 2;
    w1 |= (uint64_t)  in[3] << 29;
    w1 |= (uint64_t) in[4] << 60;
    w2 = (uint64_t) in[4] >> 4;
    w2 |= (uint64_t)  in[5] << 27;
    w2 |= (uint64_t) in[6] << 58;
    w3 = (uint64_t) in[6] >> 6;
    w3 |= (uint64_t)  in[7] << 25;
    w3 |= (uint64_t) in[8] << 56;
    w4 = (uint64_t) in[8] >> 8;
    w4 |= (uint64_t)  in[9] << 23;
    w4 |= (uint64_t) in[10] << 54;
    w5 = (uint64_t) in[10] >> 10;
    w5 |= (uint64_t)  in[11] << 21;
    w5 |= (uint64_t) in[12] << 52;
    w6 = (uint64_t) in[12] >> 12;
    w6 |= (uint64_t)  in[13] << 19;
    w6 |= (uint64_t) in[14] << 50;
    w7 = (uint64_t) in[14] >> 14;
    w7 |= (uint64_t)  in[15] << 17;
    w7 |= (uint64_t) in[16] << 48;
    w8 = (uint64_t) in[16] >> 16;
    w8 |= (uint64_t)  in[17] << 15;
    w8 |= (uint64_t) in[18] << 46;
    w9 = (uint64_t) in[18] >> 18;
    w9 |= (uint64_t)  in[19] << 13;
    w9 |= (uint64_t) in[20] << 44;
    w10 = (uint64_t) in[20] >> 20;
    w10 |= (uint64_t)  in[21] << 11;
    w10 |= (uint64_t) in[22] << 42;
    w11 = (uint64_t) in[22] >> 22;
    w11 |= (uint64_t)  in[23] << 9;
    w11 |= (uint64_t) in[24] << 40;
    w12 = (uint64_t) in[24] >> 24;
    w12 |= (uint64_t)  in[25] << 7;
    w12 |= (uint64_t) in[26] << 38;
    w13 = (uint64_t) in[26] >> 26;
    w13 |= (uint64_t)  in[27] << 5;
    w13 |= (uint64_t) in[28] << 36;
    w14 = (uint64_t) in[28] >> 28;
    w14 |= (uint64_t)  in[29] << 3;
    w14 |= (uint64_t) in[30] << 34;
    w15 = (uint64_t) in[30] >> 30;
    w15 |= (uint64_t)  in[31] << 1;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    pw64[13] = w13;
    pw64[14] = w14;
    pw64[15] = w15;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 124; /* we used up 124 output bytes */
}


/* we are going to pack 32 32-bit values, touching 16 64-bit words, using 128 bytes */
static void packblock32(const uint32_t ** pin, uint8_t ** pw) {
    uint64_t * pw64 = *(uint64_t **) pw;
    const uint32_t * in = *pin;
    /* we are going to touch  16 64-bit words */
    uint64_t w0;
    uint64_t w1;
    uint64_t w2;
    uint64_t w3;
    uint64_t w4;
    uint64_t w5;
    uint64_t w6;
    uint64_t w7;
    uint64_t w8;
    uint64_t w9;
    uint64_t w10;
    uint64_t w11;
    uint64_t w12;
    uint64_t w13;
    uint64_t w14;
    uint64_t w15;
    w0 = (uint64_t) in[0];
    w0 |= (uint64_t)  in[1] << 32;
    w1 = (uint64_t) in[2];
    w1 |= (uint64_t)  in[3] << 32;
    w2 = (uint64_t) in[4];
    w2 |= (uint64_t)  in[5] << 32;
    w3 = (uint64_t) in[6];
    w3 |= (uint64_t)  in[7] << 32;
    w4 = (uint64_t) in[8];
    w4 |= (uint64_t)  in[9] << 32;
    w5 = (uint64_t) in[10];
    w5 |= (uint64_t)  in[11] << 32;
    w6 = (uint64_t) in[12];
    w6 |= (uint64_t)  in[13] << 32;
    w7 = (uint64_t) in[14];
    w7 |= (uint64_t)  in[15] << 32;
    w8 = (uint64_t) in[16];
    w8 |= (uint64_t)  in[17] << 32;
    w9 = (uint64_t) in[18];
    w9 |= (uint64_t)  in[19] << 32;
    w10 = (uint64_t) in[20];
    w10 |= (uint64_t)  in[21] << 32;
    w11 = (uint64_t) in[22];
    w11 |= (uint64_t)  in[23] << 32;
    w12 = (uint64_t) in[24];
    w12 |= (uint64_t)  in[25] << 32;
    w13 = (uint64_t) in[26];
    w13 |= (uint64_t)  in[27] << 32;
    w14 = (uint64_t) in[28];
    w14 |= (uint64_t)  in[29] << 32;
    w15 = (uint64_t) in[30];
    w15 |= (uint64_t)  in[31] << 32;
    pw64[0] = w0;
    pw64[1] = w1;
    pw64[2] = w2;
    pw64[3] = w3;
    pw64[4] = w4;
    pw64[5] = w5;
    pw64[6] = w6;
    pw64[7] = w7;
    pw64[8] = w8;
    pw64[9] = w9;
    pw64[10] = w10;
    pw64[11] = w11;
    pw64[12] = w12;
    pw64[13] = w13;
    pw64[14] = w14;
    pw64[15] = w15;
    *pin += 32; /* we consumed 32 32-bit integers */
    *pw += 128; /* we used up 128 output bytes */
}

static void unpackblock0(const uint8_t ** pw, uint32_t ** pout) {
    (void) pw;
    memset(*pout,0,32);
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 1-bit values, touching 1 64-bit words, using 4 bytes */
static void unpackblock1(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(1);
    /* we are going to access  1 64-bit word */
    uint64_t w0 = pw64[0];
    *pw += 4; /* we used up 4 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 1 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 2 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 3 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 4 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 5 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 6 )  & mask  );
    out[7] = (uint32_t)  ( ( w0 >> 7 )  & mask  );
    out[8] = (uint32_t)  ( ( w0 >> 8 )  & mask  );
    out[9] = (uint32_t)  ( ( w0 >> 9 )  & mask  );
    out[10] = (uint32_t)  ( ( w0 >> 10 )  & mask  );
    out[11] = (uint32_t)  ( ( w0 >> 11 )  & mask  );
    out[12] = (uint32_t)  ( ( w0 >> 12 )  & mask  );
    out[13] = (uint32_t)  ( ( w0 >> 13 )  & mask  );
    out[14] = (uint32_t)  ( ( w0 >> 14 )  & mask  );
    out[15] = (uint32_t)  ( ( w0 >> 15 )  & mask  );
    out[16] = (uint32_t)  ( ( w0 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( w0 >> 17 )  & mask  );
    out[18] = (uint32_t)  ( ( w0 >> 18 )  & mask  );
    out[19] = (uint32_t)  ( ( w0 >> 19 )  & mask  );
    out[20] = (uint32_t)  ( ( w0 >> 20 )  & mask  );
    out[21] = (uint32_t)  ( ( w0 >> 21 )  & mask  );
    out[22] = (uint32_t)  ( ( w0 >> 22 )  & mask  );
    out[23] = (uint32_t)  ( ( w0 >> 23 )  & mask  );
    out[24] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[25] = (uint32_t)  ( ( w0 >> 25 )  & mask  );
    out[26] = (uint32_t)  ( ( w0 >> 26 )  & mask  );
    out[27] = (uint32_t)  ( ( w0 >> 27 )  & mask  );
    out[28] = (uint32_t)  ( ( w0 >> 28 )  & mask  );
    out[29] = (uint32_t)  ( ( w0 >> 29 )  & mask  );
    out[30] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[31] = (uint32_t)  ( ( w0 >> 31 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 2-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackblock2(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(3);
    /* we are going to access  1 64-bit word */
    uint64_t w0 = pw64[0];
    *pw += 8; /* we used up 8 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 2 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 4 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 6 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 8 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 10 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 12 )  & mask  );
    out[7] = (uint32_t)  ( ( w0 >> 14 )  & mask  );
    out[8] = (uint32_t)  ( ( w0 >> 16 )  & mask  );
    out[9] = (uint32_t)  ( ( w0 >> 18 )  & mask  );
    out[10] = (uint32_t)  ( ( w0 >> 20 )  & mask  );
    out[11] = (uint32_t)  ( ( w0 >> 22 )  & mask  );
    out[12] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[13] = (uint32_t)  ( ( w0 >> 26 )  & mask  );
    out[14] = (uint32_t)  ( ( w0 >> 28 )  & mask  );
    out[15] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[16] = (uint32_t)  ( ( w0 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( w0 >> 34 )  & mask  );
    out[18] = (uint32_t)  ( ( w0 >> 36 )  & mask  );
    out[19] = (uint32_t)  ( ( w0 >> 38 )  & mask  );
    out[20] = (uint32_t)  ( ( w0 >> 40 )  & mask  );
    out[21] = (uint32_t)  ( ( w0 >> 42 )  & mask  );
    out[22] = (uint32_t)  ( ( w0 >> 44 )  & mask  );
    out[23] = (uint32_t)  ( ( w0 >> 46 )  & mask  );
    out[24] = (uint32_t)  ( ( w0 >> 48 )  & mask  );
    out[25] = (uint32_t)  ( ( w0 >> 50 )  & mask  );
    out[26] = (uint32_t)  ( ( w0 >> 52 )  & mask  );
    out[27] = (uint32_t)  ( ( w0 >> 54 )  & mask  );
    out[28] = (uint32_t)  ( ( w0 >> 56 )  & mask  );
    out[29] = (uint32_t)  ( ( w0 >> 58 )  & mask  );
    out[30] = (uint32_t)  ( ( w0 >> 60 )  & mask  );
    out[31] = (uint32_t) ( w0  >> 62  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 3-bit values, touching 2 64-bit words, using 12 bytes */
static void unpackblock3(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(7);
    /* we are going to access  2 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    *pw += 12; /* we used up 12 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 3 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 6 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 9 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 12 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 15 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 18 )  & mask  );
    out[7] = (uint32_t)  ( ( w0 >> 21 )  & mask  );
    out[8] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[9] = (uint32_t)  ( ( w0 >> 27 )  & mask  );
    out[10] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[11] = (uint32_t)  ( ( w0 >> 33 )  & mask  );
    out[12] = (uint32_t)  ( ( w0 >> 36 )  & mask  );
    out[13] = (uint32_t)  ( ( w0 >> 39 )  & mask  );
    out[14] = (uint32_t)  ( ( w0 >> 42 )  & mask  );
    out[15] = (uint32_t)  ( ( w0 >> 45 )  & mask  );
    out[16] = (uint32_t)  ( ( w0 >> 48 )  & mask  );
    out[17] = (uint32_t)  ( ( w0 >> 51 )  & mask  );
    out[18] = (uint32_t)  ( ( w0 >> 54 )  & mask  );
    out[19] = (uint32_t)  ( ( w0 >> 57 )  & mask  );
    out[20] = (uint32_t)  ( ( w0 >> 60 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w1 >> 2 )  & mask  );
    out[23] = (uint32_t)  ( ( w1 >> 5 )  & mask  );
    out[24] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[25] = (uint32_t)  ( ( w1 >> 11 )  & mask  );
    out[26] = (uint32_t)  ( ( w1 >> 14 )  & mask  );
    out[27] = (uint32_t)  ( ( w1 >> 17 )  & mask  );
    out[28] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[29] = (uint32_t)  ( ( w1 >> 23 )  & mask  );
    out[30] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[31] = (uint32_t)  ( ( w1 >> 29 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 4-bit values, touching 2 64-bit words, using 16 bytes */
static void unpackblock4(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(15);
    /* we are going to access  2 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    *pw += 16; /* we used up 16 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 4 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 8 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 12 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 16 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 20 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[7] = (uint32_t)  ( ( w0 >> 28 )  & mask  );
    out[8] = (uint32_t)  ( ( w0 >> 32 )  & mask  );
    out[9] = (uint32_t)  ( ( w0 >> 36 )  & mask  );
    out[10] = (uint32_t)  ( ( w0 >> 40 )  & mask  );
    out[11] = (uint32_t)  ( ( w0 >> 44 )  & mask  );
    out[12] = (uint32_t)  ( ( w0 >> 48 )  & mask  );
    out[13] = (uint32_t)  ( ( w0 >> 52 )  & mask  );
    out[14] = (uint32_t)  ( ( w0 >> 56 )  & mask  );
    out[15] = (uint32_t) ( w0  >> 60  );
    out[16] = (uint32_t)  ( ( w1 )  & mask  );
    out[17] = (uint32_t)  ( ( w1 >> 4 )  & mask  );
    out[18] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[19] = (uint32_t)  ( ( w1 >> 12 )  & mask  );
    out[20] = (uint32_t)  ( ( w1 >> 16 )  & mask  );
    out[21] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[22] = (uint32_t)  ( ( w1 >> 24 )  & mask  );
    out[23] = (uint32_t)  ( ( w1 >> 28 )  & mask  );
    out[24] = (uint32_t)  ( ( w1 >> 32 )  & mask  );
    out[25] = (uint32_t)  ( ( w1 >> 36 )  & mask  );
    out[26] = (uint32_t)  ( ( w1 >> 40 )  & mask  );
    out[27] = (uint32_t)  ( ( w1 >> 44 )  & mask  );
    out[28] = (uint32_t)  ( ( w1 >> 48 )  & mask  );
    out[29] = (uint32_t)  ( ( w1 >> 52 )  & mask  );
    out[30] = (uint32_t)  ( ( w1 >> 56 )  & mask  );
    out[31] = (uint32_t) ( w1  >> 60  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 5-bit values, touching 3 64-bit words, using 20 bytes */
static void unpackblock5(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(31);
    /* we are going to access  3 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    *pw += 20; /* we used up 20 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 5 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 10 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 15 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 20 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 25 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[7] = (uint32_t)  ( ( w0 >> 35 )  & mask  );
    out[8] = (uint32_t)  ( ( w0 >> 40 )  & mask  );
    out[9] = (uint32_t)  ( ( w0 >> 45 )  & mask  );
    out[10] = (uint32_t)  ( ( w0 >> 50 )  & mask  );
    out[11] = (uint32_t)  ( ( w0 >> 55 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w1 >> 1 )  & mask  );
    out[14] = (uint32_t)  ( ( w1 >> 6 )  & mask  );
    out[15] = (uint32_t)  ( ( w1 >> 11 )  & mask  );
    out[16] = (uint32_t)  ( ( w1 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( w1 >> 21 )  & mask  );
    out[18] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[19] = (uint32_t)  ( ( w1 >> 31 )  & mask  );
    out[20] = (uint32_t)  ( ( w1 >> 36 )  & mask  );
    out[21] = (uint32_t)  ( ( w1 >> 41 )  & mask  );
    out[22] = (uint32_t)  ( ( w1 >> 46 )  & mask  );
    out[23] = (uint32_t)  ( ( w1 >> 51 )  & mask  );
    out[24] = (uint32_t)  ( ( w1 >> 56 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w1 >> 61  ) | ( w2 << 3 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w2 >> 2 )  & mask  );
    out[27] = (uint32_t)  ( ( w2 >> 7 )  & mask  );
    out[28] = (uint32_t)  ( ( w2 >> 12 )  & mask  );
    out[29] = (uint32_t)  ( ( w2 >> 17 )  & mask  );
    out[30] = (uint32_t)  ( ( w2 >> 22 )  & mask  );
    out[31] = (uint32_t)  ( ( w2 >> 27 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 6-bit values, touching 3 64-bit words, using 24 bytes */
static void unpackblock6(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(63);
    /* we are going to access  3 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    *pw += 24; /* we used up 24 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 6 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 12 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 18 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 36 )  & mask  );
    out[7] = (uint32_t)  ( ( w0 >> 42 )  & mask  );
    out[8] = (uint32_t)  ( ( w0 >> 48 )  & mask  );
    out[9] = (uint32_t)  ( ( w0 >> 54 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w1 >> 2 )  & mask  );
    out[12] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[13] = (uint32_t)  ( ( w1 >> 14 )  & mask  );
    out[14] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[15] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[16] = (uint32_t)  ( ( w1 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( w1 >> 38 )  & mask  );
    out[18] = (uint32_t)  ( ( w1 >> 44 )  & mask  );
    out[19] = (uint32_t)  ( ( w1 >> 50 )  & mask  );
    out[20] = (uint32_t)  ( ( w1 >> 56 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w2 >> 4 )  & mask  );
    out[23] = (uint32_t)  ( ( w2 >> 10 )  & mask  );
    out[24] = (uint32_t)  ( ( w2 >> 16 )  & mask  );
    out[25] = (uint32_t)  ( ( w2 >> 22 )  & mask  );
    out[26] = (uint32_t)  ( ( w2 >> 28 )  & mask  );
    out[27] = (uint32_t)  ( ( w2 >> 34 )  & mask  );
    out[28] = (uint32_t)  ( ( w2 >> 40 )  & mask  );
    out[29] = (uint32_t)  ( ( w2 >> 46 )  & mask  );
    out[30] = (uint32_t)  ( ( w2 >> 52 )  & mask  );
    out[31] = (uint32_t) ( w2  >> 58  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 7-bit values, touching 4 64-bit words, using 28 bytes */
static void unpackblock7(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(127);
    /* we are going to access  4 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    *pw += 28; /* we used up 28 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 7 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 14 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 21 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 28 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 35 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 42 )  & mask  );
    out[7] = (uint32_t)  ( ( w0 >> 49 )  & mask  );
    out[8] = (uint32_t)  ( ( w0 >> 56 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w1 >> 6 )  & mask  );
    out[11] = (uint32_t)  ( ( w1 >> 13 )  & mask  );
    out[12] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[13] = (uint32_t)  ( ( w1 >> 27 )  & mask  );
    out[14] = (uint32_t)  ( ( w1 >> 34 )  & mask  );
    out[15] = (uint32_t)  ( ( w1 >> 41 )  & mask  );
    out[16] = (uint32_t)  ( ( w1 >> 48 )  & mask  );
    out[17] = (uint32_t)  ( ( w1 >> 55 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w2 >> 5 )  & mask  );
    out[20] = (uint32_t)  ( ( w2 >> 12 )  & mask  );
    out[21] = (uint32_t)  ( ( w2 >> 19 )  & mask  );
    out[22] = (uint32_t)  ( ( w2 >> 26 )  & mask  );
    out[23] = (uint32_t)  ( ( w2 >> 33 )  & mask  );
    out[24] = (uint32_t)  ( ( w2 >> 40 )  & mask  );
    out[25] = (uint32_t)  ( ( w2 >> 47 )  & mask  );
    out[26] = (uint32_t)  ( ( w2 >> 54 )  & mask  );
    out[27] = (uint32_t)  ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
    out[28] = (uint32_t)  ( ( w3 >> 4 )  & mask  );
    out[29] = (uint32_t)  ( ( w3 >> 11 )  & mask  );
    out[30] = (uint32_t)  ( ( w3 >> 18 )  & mask  );
    out[31] = (uint32_t)  ( ( w3 >> 25 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 8-bit values, touching 4 64-bit words, using 32 bytes */
static void unpackblock8(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(255);
    /* we are going to access  4 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    *pw += 32; /* we used up 32 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 8 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 16 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 32 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 40 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 48 )  & mask  );
    out[7] = (uint32_t) ( w0  >> 56  );
    out[8] = (uint32_t)  ( ( w1 )  & mask  );
    out[9] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[10] = (uint32_t)  ( ( w1 >> 16 )  & mask  );
    out[11] = (uint32_t)  ( ( w1 >> 24 )  & mask  );
    out[12] = (uint32_t)  ( ( w1 >> 32 )  & mask  );
    out[13] = (uint32_t)  ( ( w1 >> 40 )  & mask  );
    out[14] = (uint32_t)  ( ( w1 >> 48 )  & mask  );
    out[15] = (uint32_t) ( w1  >> 56  );
    out[16] = (uint32_t)  ( ( w2 )  & mask  );
    out[17] = (uint32_t)  ( ( w2 >> 8 )  & mask  );
    out[18] = (uint32_t)  ( ( w2 >> 16 )  & mask  );
    out[19] = (uint32_t)  ( ( w2 >> 24 )  & mask  );
    out[20] = (uint32_t)  ( ( w2 >> 32 )  & mask  );
    out[21] = (uint32_t)  ( ( w2 >> 40 )  & mask  );
    out[22] = (uint32_t)  ( ( w2 >> 48 )  & mask  );
    out[23] = (uint32_t) ( w2  >> 56  );
    out[24] = (uint32_t)  ( ( w3 )  & mask  );
    out[25] = (uint32_t)  ( ( w3 >> 8 )  & mask  );
    out[26] = (uint32_t)  ( ( w3 >> 16 )  & mask  );
    out[27] = (uint32_t)  ( ( w3 >> 24 )  & mask  );
    out[28] = (uint32_t)  ( ( w3 >> 32 )  & mask  );
    out[29] = (uint32_t)  ( ( w3 >> 40 )  & mask  );
    out[30] = (uint32_t)  ( ( w3 >> 48 )  & mask  );
    out[31] = (uint32_t) ( w3  >> 56  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 9-bit values, touching 5 64-bit words, using 36 bytes */
static void unpackblock9(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(511);
    /* we are going to access  5 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    *pw += 36; /* we used up 36 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 9 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 18 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 27 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 36 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 45 )  & mask  );
    out[6] = (uint32_t)  ( ( w0 >> 54 )  & mask  );
    out[7] = (uint32_t)  ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
    out[8] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[9] = (uint32_t)  ( ( w1 >> 17 )  & mask  );
    out[10] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[11] = (uint32_t)  ( ( w1 >> 35 )  & mask  );
    out[12] = (uint32_t)  ( ( w1 >> 44 )  & mask  );
    out[13] = (uint32_t)  ( ( w1 >> 53 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w2 >> 7 )  & mask  );
    out[16] = (uint32_t)  ( ( w2 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( w2 >> 25 )  & mask  );
    out[18] = (uint32_t)  ( ( w2 >> 34 )  & mask  );
    out[19] = (uint32_t)  ( ( w2 >> 43 )  & mask  );
    out[20] = (uint32_t)  ( ( w2 >> 52 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w3 >> 6 )  & mask  );
    out[23] = (uint32_t)  ( ( w3 >> 15 )  & mask  );
    out[24] = (uint32_t)  ( ( w3 >> 24 )  & mask  );
    out[25] = (uint32_t)  ( ( w3 >> 33 )  & mask  );
    out[26] = (uint32_t)  ( ( w3 >> 42 )  & mask  );
    out[27] = (uint32_t)  ( ( w3 >> 51 )  & mask  );
    out[28] = (uint32_t)  ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
    out[29] = (uint32_t)  ( ( w4 >> 5 )  & mask  );
    out[30] = (uint32_t)  ( ( w4 >> 14 )  & mask  );
    out[31] = (uint32_t)  ( ( w4 >> 23 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 10-bit values, touching 5 64-bit words, using 40 bytes */
static void unpackblock10(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(1023);
    /* we are going to access  5 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    *pw += 40; /* we used up 40 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 10 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 20 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 40 )  & mask  );
    out[5] = (uint32_t)  ( ( w0 >> 50 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w1 >> 6 )  & mask  );
    out[8] = (uint32_t)  ( ( w1 >> 16 )  & mask  );
    out[9] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[10] = (uint32_t)  ( ( w1 >> 36 )  & mask  );
    out[11] = (uint32_t)  ( ( w1 >> 46 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w2 >> 2 )  & mask  );
    out[14] = (uint32_t)  ( ( w2 >> 12 )  & mask  );
    out[15] = (uint32_t)  ( ( w2 >> 22 )  & mask  );
    out[16] = (uint32_t)  ( ( w2 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( w2 >> 42 )  & mask  );
    out[18] = (uint32_t)  ( ( w2 >> 52 )  & mask  );
    out[19] = (uint32_t)  ( ( ( w2 >> 62  ) | ( w3 << 2 ) )  & mask  );
    out[20] = (uint32_t)  ( ( w3 >> 8 )  & mask  );
    out[21] = (uint32_t)  ( ( w3 >> 18 )  & mask  );
    out[22] = (uint32_t)  ( ( w3 >> 28 )  & mask  );
    out[23] = (uint32_t)  ( ( w3 >> 38 )  & mask  );
    out[24] = (uint32_t)  ( ( w3 >> 48 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w3 >> 58  ) | ( w4 << 6 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w4 >> 4 )  & mask  );
    out[27] = (uint32_t)  ( ( w4 >> 14 )  & mask  );
    out[28] = (uint32_t)  ( ( w4 >> 24 )  & mask  );
    out[29] = (uint32_t)  ( ( w4 >> 34 )  & mask  );
    out[30] = (uint32_t)  ( ( w4 >> 44 )  & mask  );
    out[31] = (uint32_t) ( w4  >> 54  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 11-bit values, touching 6 64-bit words, using 44 bytes */
static void unpackblock11(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(2047);
    /* we are going to access  6 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    *pw += 44; /* we used up 44 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 11 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 22 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 33 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 44 )  & mask  );
    out[5] = (uint32_t)  ( ( ( w0 >> 55  ) | ( w1 << 9 ) )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 2 )  & mask  );
    out[7] = (uint32_t)  ( ( w1 >> 13 )  & mask  );
    out[8] = (uint32_t)  ( ( w1 >> 24 )  & mask  );
    out[9] = (uint32_t)  ( ( w1 >> 35 )  & mask  );
    out[10] = (uint32_t)  ( ( w1 >> 46 )  & mask  );
    out[11] = (uint32_t)  ( ( ( w1 >> 57  ) | ( w2 << 7 ) )  & mask  );
    out[12] = (uint32_t)  ( ( w2 >> 4 )  & mask  );
    out[13] = (uint32_t)  ( ( w2 >> 15 )  & mask  );
    out[14] = (uint32_t)  ( ( w2 >> 26 )  & mask  );
    out[15] = (uint32_t)  ( ( w2 >> 37 )  & mask  );
    out[16] = (uint32_t)  ( ( w2 >> 48 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w2 >> 59  ) | ( w3 << 5 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w3 >> 6 )  & mask  );
    out[19] = (uint32_t)  ( ( w3 >> 17 )  & mask  );
    out[20] = (uint32_t)  ( ( w3 >> 28 )  & mask  );
    out[21] = (uint32_t)  ( ( w3 >> 39 )  & mask  );
    out[22] = (uint32_t)  ( ( w3 >> 50 )  & mask  );
    out[23] = (uint32_t)  ( ( ( w3 >> 61  ) | ( w4 << 3 ) )  & mask  );
    out[24] = (uint32_t)  ( ( w4 >> 8 )  & mask  );
    out[25] = (uint32_t)  ( ( w4 >> 19 )  & mask  );
    out[26] = (uint32_t)  ( ( w4 >> 30 )  & mask  );
    out[27] = (uint32_t)  ( ( w4 >> 41 )  & mask  );
    out[28] = (uint32_t)  ( ( w4 >> 52 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w4 >> 63  ) | ( w5 << 1 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w5 >> 10 )  & mask  );
    out[31] = (uint32_t)  ( ( w5 >> 21 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 12-bit values, touching 6 64-bit words, using 48 bytes */
static void unpackblock12(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(4095);
    /* we are going to access  6 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    *pw += 48; /* we used up 48 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 12 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 36 )  & mask  );
    out[4] = (uint32_t)  ( ( w0 >> 48 )  & mask  );
    out[5] = (uint32_t)  ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[7] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[8] = (uint32_t)  ( ( w1 >> 32 )  & mask  );
    out[9] = (uint32_t)  ( ( w1 >> 44 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w2 >> 4 )  & mask  );
    out[12] = (uint32_t)  ( ( w2 >> 16 )  & mask  );
    out[13] = (uint32_t)  ( ( w2 >> 28 )  & mask  );
    out[14] = (uint32_t)  ( ( w2 >> 40 )  & mask  );
    out[15] = (uint32_t) ( w2  >> 52  );
    out[16] = (uint32_t)  ( ( w3 )  & mask  );
    out[17] = (uint32_t)  ( ( w3 >> 12 )  & mask  );
    out[18] = (uint32_t)  ( ( w3 >> 24 )  & mask  );
    out[19] = (uint32_t)  ( ( w3 >> 36 )  & mask  );
    out[20] = (uint32_t)  ( ( w3 >> 48 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w4 >> 8 )  & mask  );
    out[23] = (uint32_t)  ( ( w4 >> 20 )  & mask  );
    out[24] = (uint32_t)  ( ( w4 >> 32 )  & mask  );
    out[25] = (uint32_t)  ( ( w4 >> 44 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w5 >> 4 )  & mask  );
    out[28] = (uint32_t)  ( ( w5 >> 16 )  & mask  );
    out[29] = (uint32_t)  ( ( w5 >> 28 )  & mask  );
    out[30] = (uint32_t)  ( ( w5 >> 40 )  & mask  );
    out[31] = (uint32_t) ( w5  >> 52  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 13-bit values, touching 7 64-bit words, using 52 bytes */
static void unpackblock13(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(8191);
    /* we are going to access  7 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    *pw += 52; /* we used up 52 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 13 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 26 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 39 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w0 >> 52  ) | ( w1 << 12 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 1 )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 14 )  & mask  );
    out[7] = (uint32_t)  ( ( w1 >> 27 )  & mask  );
    out[8] = (uint32_t)  ( ( w1 >> 40 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w1 >> 53  ) | ( w2 << 11 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w2 >> 2 )  & mask  );
    out[11] = (uint32_t)  ( ( w2 >> 15 )  & mask  );
    out[12] = (uint32_t)  ( ( w2 >> 28 )  & mask  );
    out[13] = (uint32_t)  ( ( w2 >> 41 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w2 >> 54  ) | ( w3 << 10 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w3 >> 3 )  & mask  );
    out[16] = (uint32_t)  ( ( w3 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( w3 >> 29 )  & mask  );
    out[18] = (uint32_t)  ( ( w3 >> 42 )  & mask  );
    out[19] = (uint32_t)  ( ( ( w3 >> 55  ) | ( w4 << 9 ) )  & mask  );
    out[20] = (uint32_t)  ( ( w4 >> 4 )  & mask  );
    out[21] = (uint32_t)  ( ( w4 >> 17 )  & mask  );
    out[22] = (uint32_t)  ( ( w4 >> 30 )  & mask  );
    out[23] = (uint32_t)  ( ( w4 >> 43 )  & mask  );
    out[24] = (uint32_t)  ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
    out[25] = (uint32_t)  ( ( w5 >> 5 )  & mask  );
    out[26] = (uint32_t)  ( ( w5 >> 18 )  & mask  );
    out[27] = (uint32_t)  ( ( w5 >> 31 )  & mask  );
    out[28] = (uint32_t)  ( ( w5 >> 44 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w5 >> 57  ) | ( w6 << 7 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w6 >> 6 )  & mask  );
    out[31] = (uint32_t)  ( ( w6 >> 19 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 14-bit values, touching 7 64-bit words, using 56 bytes */
static void unpackblock14(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(16383);
    /* we are going to access  7 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    *pw += 56; /* we used up 56 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 14 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 28 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 42 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w0 >> 56  ) | ( w1 << 8 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 6 )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[7] = (uint32_t)  ( ( w1 >> 34 )  & mask  );
    out[8] = (uint32_t)  ( ( w1 >> 48 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w2 >> 12 )  & mask  );
    out[11] = (uint32_t)  ( ( w2 >> 26 )  & mask  );
    out[12] = (uint32_t)  ( ( w2 >> 40 )  & mask  );
    out[13] = (uint32_t)  ( ( ( w2 >> 54  ) | ( w3 << 10 ) )  & mask  );
    out[14] = (uint32_t)  ( ( w3 >> 4 )  & mask  );
    out[15] = (uint32_t)  ( ( w3 >> 18 )  & mask  );
    out[16] = (uint32_t)  ( ( w3 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( w3 >> 46 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w4 >> 10 )  & mask  );
    out[20] = (uint32_t)  ( ( w4 >> 24 )  & mask  );
    out[21] = (uint32_t)  ( ( w4 >> 38 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w4 >> 52  ) | ( w5 << 12 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w5 >> 2 )  & mask  );
    out[24] = (uint32_t)  ( ( w5 >> 16 )  & mask  );
    out[25] = (uint32_t)  ( ( w5 >> 30 )  & mask  );
    out[26] = (uint32_t)  ( ( w5 >> 44 )  & mask  );
    out[27] = (uint32_t)  ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
    out[28] = (uint32_t)  ( ( w6 >> 8 )  & mask  );
    out[29] = (uint32_t)  ( ( w6 >> 22 )  & mask  );
    out[30] = (uint32_t)  ( ( w6 >> 36 )  & mask  );
    out[31] = (uint32_t) ( w6  >> 50  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 15-bit values, touching 8 64-bit words, using 60 bytes */
static void unpackblock15(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(32767);
    /* we are going to access  8 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    *pw += 60; /* we used up 60 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 15 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[3] = (uint32_t)  ( ( w0 >> 45 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 11 )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[7] = (uint32_t)  ( ( w1 >> 41 )  & mask  );
    out[8] = (uint32_t)  ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
    out[9] = (uint32_t)  ( ( w2 >> 7 )  & mask  );
    out[10] = (uint32_t)  ( ( w2 >> 22 )  & mask  );
    out[11] = (uint32_t)  ( ( w2 >> 37 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w3 >> 3 )  & mask  );
    out[14] = (uint32_t)  ( ( w3 >> 18 )  & mask  );
    out[15] = (uint32_t)  ( ( w3 >> 33 )  & mask  );
    out[16] = (uint32_t)  ( ( w3 >> 48 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w3 >> 63  ) | ( w4 << 1 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w4 >> 14 )  & mask  );
    out[19] = (uint32_t)  ( ( w4 >> 29 )  & mask  );
    out[20] = (uint32_t)  ( ( w4 >> 44 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w4 >> 59  ) | ( w5 << 5 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w5 >> 10 )  & mask  );
    out[23] = (uint32_t)  ( ( w5 >> 25 )  & mask  );
    out[24] = (uint32_t)  ( ( w5 >> 40 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w5 >> 55  ) | ( w6 << 9 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w6 >> 6 )  & mask  );
    out[27] = (uint32_t)  ( ( w6 >> 21 )  & mask  );
    out[28] = (uint32_t)  ( ( w6 >> 36 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w6 >> 51  ) | ( w7 << 13 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w7 >> 2 )  & mask  );
    out[31] = (uint32_t)  ( ( w7 >> 17 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 16-bit values, touching 8 64-bit words, using 64 bytes */
static void unpackblock16(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(65535);
    /* we are going to access  8 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    *pw += 64; /* we used up 64 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 16 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 32 )  & mask  );
    out[3] = (uint32_t) ( w0  >> 48  );
    out[4] = (uint32_t)  ( ( w1 )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 16 )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 32 )  & mask  );
    out[7] = (uint32_t) ( w1  >> 48  );
    out[8] = (uint32_t)  ( ( w2 )  & mask  );
    out[9] = (uint32_t)  ( ( w2 >> 16 )  & mask  );
    out[10] = (uint32_t)  ( ( w2 >> 32 )  & mask  );
    out[11] = (uint32_t) ( w2  >> 48  );
    out[12] = (uint32_t)  ( ( w3 )  & mask  );
    out[13] = (uint32_t)  ( ( w3 >> 16 )  & mask  );
    out[14] = (uint32_t)  ( ( w3 >> 32 )  & mask  );
    out[15] = (uint32_t) ( w3  >> 48  );
    out[16] = (uint32_t)  ( ( w4 )  & mask  );
    out[17] = (uint32_t)  ( ( w4 >> 16 )  & mask  );
    out[18] = (uint32_t)  ( ( w4 >> 32 )  & mask  );
    out[19] = (uint32_t) ( w4  >> 48  );
    out[20] = (uint32_t)  ( ( w5 )  & mask  );
    out[21] = (uint32_t)  ( ( w5 >> 16 )  & mask  );
    out[22] = (uint32_t)  ( ( w5 >> 32 )  & mask  );
    out[23] = (uint32_t) ( w5  >> 48  );
    out[24] = (uint32_t)  ( ( w6 )  & mask  );
    out[25] = (uint32_t)  ( ( w6 >> 16 )  & mask  );
    out[26] = (uint32_t)  ( ( w6 >> 32 )  & mask  );
    out[27] = (uint32_t) ( w6  >> 48  );
    out[28] = (uint32_t)  ( ( w7 )  & mask  );
    out[29] = (uint32_t)  ( ( w7 >> 16 )  & mask  );
    out[30] = (uint32_t)  ( ( w7 >> 32 )  & mask  );
    out[31] = (uint32_t) ( w7  >> 48  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 17-bit values, touching 9 64-bit words, using 68 bytes */
static void unpackblock17(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(131071);
    /* we are going to access  9 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    *pw += 68; /* we used up 68 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 17 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 34 )  & mask  );
    out[3] = (uint32_t)  ( ( ( w0 >> 51  ) | ( w1 << 13 ) )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 4 )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 21 )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 38 )  & mask  );
    out[7] = (uint32_t)  ( ( ( w1 >> 55  ) | ( w2 << 9 ) )  & mask  );
    out[8] = (uint32_t)  ( ( w2 >> 8 )  & mask  );
    out[9] = (uint32_t)  ( ( w2 >> 25 )  & mask  );
    out[10] = (uint32_t)  ( ( w2 >> 42 )  & mask  );
    out[11] = (uint32_t)  ( ( ( w2 >> 59  ) | ( w3 << 5 ) )  & mask  );
    out[12] = (uint32_t)  ( ( w3 >> 12 )  & mask  );
    out[13] = (uint32_t)  ( ( w3 >> 29 )  & mask  );
    out[14] = (uint32_t)  ( ( w3 >> 46 )  & mask  );
    out[15] = (uint32_t)  ( ( ( w3 >> 63  ) | ( w4 << 1 ) )  & mask  );
    out[16] = (uint32_t)  ( ( w4 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( w4 >> 33 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w4 >> 50  ) | ( w5 << 14 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w5 >> 3 )  & mask  );
    out[20] = (uint32_t)  ( ( w5 >> 20 )  & mask  );
    out[21] = (uint32_t)  ( ( w5 >> 37 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w5 >> 54  ) | ( w6 << 10 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w6 >> 7 )  & mask  );
    out[24] = (uint32_t)  ( ( w6 >> 24 )  & mask  );
    out[25] = (uint32_t)  ( ( w6 >> 41 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w6 >> 58  ) | ( w7 << 6 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w7 >> 11 )  & mask  );
    out[28] = (uint32_t)  ( ( w7 >> 28 )  & mask  );
    out[29] = (uint32_t)  ( ( w7 >> 45 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w7 >> 62  ) | ( w8 << 2 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w8 >> 15 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 18-bit values, touching 9 64-bit words, using 72 bytes */
static void unpackblock18(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(262143);
    /* we are going to access  9 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    *pw += 72; /* we used up 72 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 18 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 36 )  & mask  );
    out[3] = (uint32_t)  ( ( ( w0 >> 54  ) | ( w1 << 10 ) )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[6] = (uint32_t)  ( ( w1 >> 44 )  & mask  );
    out[7] = (uint32_t)  ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
    out[8] = (uint32_t)  ( ( w2 >> 16 )  & mask  );
    out[9] = (uint32_t)  ( ( w2 >> 34 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w3 >> 6 )  & mask  );
    out[12] = (uint32_t)  ( ( w3 >> 24 )  & mask  );
    out[13] = (uint32_t)  ( ( w3 >> 42 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w4 >> 14 )  & mask  );
    out[16] = (uint32_t)  ( ( w4 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w4 >> 50  ) | ( w5 << 14 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w5 >> 4 )  & mask  );
    out[19] = (uint32_t)  ( ( w5 >> 22 )  & mask  );
    out[20] = (uint32_t)  ( ( w5 >> 40 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w6 >> 12 )  & mask  );
    out[23] = (uint32_t)  ( ( w6 >> 30 )  & mask  );
    out[24] = (uint32_t)  ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
    out[25] = (uint32_t)  ( ( w7 >> 2 )  & mask  );
    out[26] = (uint32_t)  ( ( w7 >> 20 )  & mask  );
    out[27] = (uint32_t)  ( ( w7 >> 38 )  & mask  );
    out[28] = (uint32_t)  ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
    out[29] = (uint32_t)  ( ( w8 >> 10 )  & mask  );
    out[30] = (uint32_t)  ( ( w8 >> 28 )  & mask  );
    out[31] = (uint32_t) ( w8  >> 46  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 19-bit values, touching 10 64-bit words, using 76 bytes */
static void unpackblock19(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(524287);
    /* we are going to access  10 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    *pw += 76; /* we used up 76 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 19 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 38 )  & mask  );
    out[3] = (uint32_t)  ( ( ( w0 >> 57  ) | ( w1 << 7 ) )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 12 )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 31 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w1 >> 50  ) | ( w2 << 14 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w2 >> 5 )  & mask  );
    out[8] = (uint32_t)  ( ( w2 >> 24 )  & mask  );
    out[9] = (uint32_t)  ( ( w2 >> 43 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w2 >> 62  ) | ( w3 << 2 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w3 >> 17 )  & mask  );
    out[12] = (uint32_t)  ( ( w3 >> 36 )  & mask  );
    out[13] = (uint32_t)  ( ( ( w3 >> 55  ) | ( w4 << 9 ) )  & mask  );
    out[14] = (uint32_t)  ( ( w4 >> 10 )  & mask  );
    out[15] = (uint32_t)  ( ( w4 >> 29 )  & mask  );
    out[16] = (uint32_t)  ( ( ( w4 >> 48  ) | ( w5 << 16 ) )  & mask  );
    out[17] = (uint32_t)  ( ( w5 >> 3 )  & mask  );
    out[18] = (uint32_t)  ( ( w5 >> 22 )  & mask  );
    out[19] = (uint32_t)  ( ( w5 >> 41 )  & mask  );
    out[20] = (uint32_t)  ( ( ( w5 >> 60  ) | ( w6 << 4 ) )  & mask  );
    out[21] = (uint32_t)  ( ( w6 >> 15 )  & mask  );
    out[22] = (uint32_t)  ( ( w6 >> 34 )  & mask  );
    out[23] = (uint32_t)  ( ( ( w6 >> 53  ) | ( w7 << 11 ) )  & mask  );
    out[24] = (uint32_t)  ( ( w7 >> 8 )  & mask  );
    out[25] = (uint32_t)  ( ( w7 >> 27 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w7 >> 46  ) | ( w8 << 18 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w8 >> 1 )  & mask  );
    out[28] = (uint32_t)  ( ( w8 >> 20 )  & mask  );
    out[29] = (uint32_t)  ( ( w8 >> 39 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w8 >> 58  ) | ( w9 << 6 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w9 >> 13 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 20-bit values, touching 10 64-bit words, using 80 bytes */
static void unpackblock20(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(1048575);
    /* we are going to access  10 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    *pw += 80; /* we used up 80 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 20 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 40 )  & mask  );
    out[3] = (uint32_t)  ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 16 )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 36 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w2 >> 12 )  & mask  );
    out[8] = (uint32_t)  ( ( w2 >> 32 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w3 >> 8 )  & mask  );
    out[11] = (uint32_t)  ( ( w3 >> 28 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w4 >> 4 )  & mask  );
    out[14] = (uint32_t)  ( ( w4 >> 24 )  & mask  );
    out[15] = (uint32_t) ( w4  >> 44  );
    out[16] = (uint32_t)  ( ( w5 )  & mask  );
    out[17] = (uint32_t)  ( ( w5 >> 20 )  & mask  );
    out[18] = (uint32_t)  ( ( w5 >> 40 )  & mask  );
    out[19] = (uint32_t)  ( ( ( w5 >> 60  ) | ( w6 << 4 ) )  & mask  );
    out[20] = (uint32_t)  ( ( w6 >> 16 )  & mask  );
    out[21] = (uint32_t)  ( ( w6 >> 36 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w6 >> 56  ) | ( w7 << 8 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w7 >> 12 )  & mask  );
    out[24] = (uint32_t)  ( ( w7 >> 32 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w7 >> 52  ) | ( w8 << 12 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w8 >> 8 )  & mask  );
    out[27] = (uint32_t)  ( ( w8 >> 28 )  & mask  );
    out[28] = (uint32_t)  ( ( ( w8 >> 48  ) | ( w9 << 16 ) )  & mask  );
    out[29] = (uint32_t)  ( ( w9 >> 4 )  & mask  );
    out[30] = (uint32_t)  ( ( w9 >> 24 )  & mask  );
    out[31] = (uint32_t) ( w9  >> 44  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 21-bit values, touching 11 64-bit words, using 84 bytes */
static void unpackblock21(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(2097151);
    /* we are going to access  11 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    *pw += 84; /* we used up 84 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 21 )  & mask  );
    out[2] = (uint32_t)  ( ( w0 >> 42 )  & mask  );
    out[3] = (uint32_t)  ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[5] = (uint32_t)  ( ( w1 >> 41 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w2 >> 19 )  & mask  );
    out[8] = (uint32_t)  ( ( w2 >> 40 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w3 >> 18 )  & mask  );
    out[11] = (uint32_t)  ( ( w3 >> 39 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w4 >> 17 )  & mask  );
    out[14] = (uint32_t)  ( ( w4 >> 38 )  & mask  );
    out[15] = (uint32_t)  ( ( ( w4 >> 59  ) | ( w5 << 5 ) )  & mask  );
    out[16] = (uint32_t)  ( ( w5 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( w5 >> 37 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w6 >> 15 )  & mask  );
    out[20] = (uint32_t)  ( ( w6 >> 36 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w6 >> 57  ) | ( w7 << 7 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w7 >> 14 )  & mask  );
    out[23] = (uint32_t)  ( ( w7 >> 35 )  & mask  );
    out[24] = (uint32_t)  ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
    out[25] = (uint32_t)  ( ( w8 >> 13 )  & mask  );
    out[26] = (uint32_t)  ( ( w8 >> 34 )  & mask  );
    out[27] = (uint32_t)  ( ( ( w8 >> 55  ) | ( w9 << 9 ) )  & mask  );
    out[28] = (uint32_t)  ( ( w9 >> 12 )  & mask  );
    out[29] = (uint32_t)  ( ( w9 >> 33 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w10 >> 11 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 22-bit values, touching 11 64-bit words, using 88 bytes */
static void unpackblock22(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(4194303);
    /* we are going to access  11 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    *pw += 88; /* we used up 88 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 22 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 44  ) | ( w1 << 20 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 2 )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 24 )  & mask  );
    out[5] = (uint32_t)  ( ( ( w1 >> 46  ) | ( w2 << 18 ) )  & mask  );
    out[6] = (uint32_t)  ( ( w2 >> 4 )  & mask  );
    out[7] = (uint32_t)  ( ( w2 >> 26 )  & mask  );
    out[8] = (uint32_t)  ( ( ( w2 >> 48  ) | ( w3 << 16 ) )  & mask  );
    out[9] = (uint32_t)  ( ( w3 >> 6 )  & mask  );
    out[10] = (uint32_t)  ( ( w3 >> 28 )  & mask  );
    out[11] = (uint32_t)  ( ( ( w3 >> 50  ) | ( w4 << 14 ) )  & mask  );
    out[12] = (uint32_t)  ( ( w4 >> 8 )  & mask  );
    out[13] = (uint32_t)  ( ( w4 >> 30 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w4 >> 52  ) | ( w5 << 12 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w5 >> 10 )  & mask  );
    out[16] = (uint32_t)  ( ( w5 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w5 >> 54  ) | ( w6 << 10 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w6 >> 12 )  & mask  );
    out[19] = (uint32_t)  ( ( w6 >> 34 )  & mask  );
    out[20] = (uint32_t)  ( ( ( w6 >> 56  ) | ( w7 << 8 ) )  & mask  );
    out[21] = (uint32_t)  ( ( w7 >> 14 )  & mask  );
    out[22] = (uint32_t)  ( ( w7 >> 36 )  & mask  );
    out[23] = (uint32_t)  ( ( ( w7 >> 58  ) | ( w8 << 6 ) )  & mask  );
    out[24] = (uint32_t)  ( ( w8 >> 16 )  & mask  );
    out[25] = (uint32_t)  ( ( w8 >> 38 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w8 >> 60  ) | ( w9 << 4 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w9 >> 18 )  & mask  );
    out[28] = (uint32_t)  ( ( w9 >> 40 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w9 >> 62  ) | ( w10 << 2 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w10 >> 20 )  & mask  );
    out[31] = (uint32_t) ( w10  >> 42  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 23-bit values, touching 12 64-bit words, using 92 bytes */
static void unpackblock23(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(8388607);
    /* we are going to access  12 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    *pw += 92; /* we used up 92 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 23 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 46  ) | ( w1 << 18 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 5 )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 28 )  & mask  );
    out[5] = (uint32_t)  ( ( ( w1 >> 51  ) | ( w2 << 13 ) )  & mask  );
    out[6] = (uint32_t)  ( ( w2 >> 10 )  & mask  );
    out[7] = (uint32_t)  ( ( w2 >> 33 )  & mask  );
    out[8] = (uint32_t)  ( ( ( w2 >> 56  ) | ( w3 << 8 ) )  & mask  );
    out[9] = (uint32_t)  ( ( w3 >> 15 )  & mask  );
    out[10] = (uint32_t)  ( ( w3 >> 38 )  & mask  );
    out[11] = (uint32_t)  ( ( ( w3 >> 61  ) | ( w4 << 3 ) )  & mask  );
    out[12] = (uint32_t)  ( ( w4 >> 20 )  & mask  );
    out[13] = (uint32_t)  ( ( ( w4 >> 43  ) | ( w5 << 21 ) )  & mask  );
    out[14] = (uint32_t)  ( ( w5 >> 2 )  & mask  );
    out[15] = (uint32_t)  ( ( w5 >> 25 )  & mask  );
    out[16] = (uint32_t)  ( ( ( w5 >> 48  ) | ( w6 << 16 ) )  & mask  );
    out[17] = (uint32_t)  ( ( w6 >> 7 )  & mask  );
    out[18] = (uint32_t)  ( ( w6 >> 30 )  & mask  );
    out[19] = (uint32_t)  ( ( ( w6 >> 53  ) | ( w7 << 11 ) )  & mask  );
    out[20] = (uint32_t)  ( ( w7 >> 12 )  & mask  );
    out[21] = (uint32_t)  ( ( w7 >> 35 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w7 >> 58  ) | ( w8 << 6 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w8 >> 17 )  & mask  );
    out[24] = (uint32_t)  ( ( w8 >> 40 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w8 >> 63  ) | ( w9 << 1 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w9 >> 22 )  & mask  );
    out[27] = (uint32_t)  ( ( ( w9 >> 45  ) | ( w10 << 19 ) )  & mask  );
    out[28] = (uint32_t)  ( ( w10 >> 4 )  & mask  );
    out[29] = (uint32_t)  ( ( w10 >> 27 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w10 >> 50  ) | ( w11 << 14 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w11 >> 9 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 24-bit values, touching 12 64-bit words, using 96 bytes */
static void unpackblock24(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(16777215);
    /* we are going to access  12 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    *pw += 96; /* we used up 96 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 24 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 48  ) | ( w1 << 16 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 8 )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 32 )  & mask  );
    out[5] = (uint32_t)  ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
    out[6] = (uint32_t)  ( ( w2 >> 16 )  & mask  );
    out[7] = (uint32_t) ( w2  >> 40  );
    out[8] = (uint32_t)  ( ( w3 )  & mask  );
    out[9] = (uint32_t)  ( ( w3 >> 24 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w4 >> 8 )  & mask  );
    out[12] = (uint32_t)  ( ( w4 >> 32 )  & mask  );
    out[13] = (uint32_t)  ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
    out[14] = (uint32_t)  ( ( w5 >> 16 )  & mask  );
    out[15] = (uint32_t) ( w5  >> 40  );
    out[16] = (uint32_t)  ( ( w6 )  & mask  );
    out[17] = (uint32_t)  ( ( w6 >> 24 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w7 >> 8 )  & mask  );
    out[20] = (uint32_t)  ( ( w7 >> 32 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w8 >> 16 )  & mask  );
    out[23] = (uint32_t) ( w8  >> 40  );
    out[24] = (uint32_t)  ( ( w9 )  & mask  );
    out[25] = (uint32_t)  ( ( w9 >> 24 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w9 >> 48  ) | ( w10 << 16 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w10 >> 8 )  & mask  );
    out[28] = (uint32_t)  ( ( w10 >> 32 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w10 >> 56  ) | ( w11 << 8 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w11 >> 16 )  & mask  );
    out[31] = (uint32_t) ( w11  >> 40  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 25-bit values, touching 13 64-bit words, using 100 bytes */
static void unpackblock25(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(33554431);
    /* we are going to access  13 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    *pw += 100; /* we used up 100 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 25 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 50  ) | ( w1 << 14 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 11 )  & mask  );
    out[4] = (uint32_t)  ( ( w1 >> 36 )  & mask  );
    out[5] = (uint32_t)  ( ( ( w1 >> 61  ) | ( w2 << 3 ) )  & mask  );
    out[6] = (uint32_t)  ( ( w2 >> 22 )  & mask  );
    out[7] = (uint32_t)  ( ( ( w2 >> 47  ) | ( w3 << 17 ) )  & mask  );
    out[8] = (uint32_t)  ( ( w3 >> 8 )  & mask  );
    out[9] = (uint32_t)  ( ( w3 >> 33 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w3 >> 58  ) | ( w4 << 6 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w4 >> 19 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w4 >> 44  ) | ( w5 << 20 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w5 >> 5 )  & mask  );
    out[14] = (uint32_t)  ( ( w5 >> 30 )  & mask  );
    out[15] = (uint32_t)  ( ( ( w5 >> 55  ) | ( w6 << 9 ) )  & mask  );
    out[16] = (uint32_t)  ( ( w6 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w6 >> 41  ) | ( w7 << 23 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w7 >> 2 )  & mask  );
    out[19] = (uint32_t)  ( ( w7 >> 27 )  & mask  );
    out[20] = (uint32_t)  ( ( ( w7 >> 52  ) | ( w8 << 12 ) )  & mask  );
    out[21] = (uint32_t)  ( ( w8 >> 13 )  & mask  );
    out[22] = (uint32_t)  ( ( w8 >> 38 )  & mask  );
    out[23] = (uint32_t)  ( ( ( w8 >> 63  ) | ( w9 << 1 ) )  & mask  );
    out[24] = (uint32_t)  ( ( w9 >> 24 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w9 >> 49  ) | ( w10 << 15 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w10 >> 10 )  & mask  );
    out[27] = (uint32_t)  ( ( w10 >> 35 )  & mask  );
    out[28] = (uint32_t)  ( ( ( w10 >> 60  ) | ( w11 << 4 ) )  & mask  );
    out[29] = (uint32_t)  ( ( w11 >> 21 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w11 >> 46  ) | ( w12 << 18 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w12 >> 7 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 26-bit values, touching 13 64-bit words, using 104 bytes */
static void unpackblock26(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(67108863);
    /* we are going to access  13 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    *pw += 104; /* we used up 104 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 26 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 52  ) | ( w1 << 12 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 14 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w1 >> 40  ) | ( w2 << 24 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w2 >> 2 )  & mask  );
    out[6] = (uint32_t)  ( ( w2 >> 28 )  & mask  );
    out[7] = (uint32_t)  ( ( ( w2 >> 54  ) | ( w3 << 10 ) )  & mask  );
    out[8] = (uint32_t)  ( ( w3 >> 16 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w3 >> 42  ) | ( w4 << 22 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w4 >> 4 )  & mask  );
    out[11] = (uint32_t)  ( ( w4 >> 30 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w5 >> 18 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w5 >> 44  ) | ( w6 << 20 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w6 >> 6 )  & mask  );
    out[16] = (uint32_t)  ( ( w6 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w6 >> 58  ) | ( w7 << 6 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w7 >> 20 )  & mask  );
    out[19] = (uint32_t)  ( ( ( w7 >> 46  ) | ( w8 << 18 ) )  & mask  );
    out[20] = (uint32_t)  ( ( w8 >> 8 )  & mask  );
    out[21] = (uint32_t)  ( ( w8 >> 34 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w8 >> 60  ) | ( w9 << 4 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w9 >> 22 )  & mask  );
    out[24] = (uint32_t)  ( ( ( w9 >> 48  ) | ( w10 << 16 ) )  & mask  );
    out[25] = (uint32_t)  ( ( w10 >> 10 )  & mask  );
    out[26] = (uint32_t)  ( ( w10 >> 36 )  & mask  );
    out[27] = (uint32_t)  ( ( ( w10 >> 62  ) | ( w11 << 2 ) )  & mask  );
    out[28] = (uint32_t)  ( ( w11 >> 24 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w11 >> 50  ) | ( w12 << 14 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w12 >> 12 )  & mask  );
    out[31] = (uint32_t) ( w12  >> 38  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 27-bit values, touching 14 64-bit words, using 108 bytes */
static void unpackblock27(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(134217727);
    /* we are going to access  14 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    uint64_t w13 = pw64[13];
    *pw += 108; /* we used up 108 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 27 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 54  ) | ( w1 << 10 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 17 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w1 >> 44  ) | ( w2 << 20 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w2 >> 7 )  & mask  );
    out[6] = (uint32_t)  ( ( w2 >> 34 )  & mask  );
    out[7] = (uint32_t)  ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
    out[8] = (uint32_t)  ( ( w3 >> 24 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w3 >> 51  ) | ( w4 << 13 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w4 >> 14 )  & mask  );
    out[11] = (uint32_t)  ( ( ( w4 >> 41  ) | ( w5 << 23 ) )  & mask  );
    out[12] = (uint32_t)  ( ( w5 >> 4 )  & mask  );
    out[13] = (uint32_t)  ( ( w5 >> 31 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w6 >> 21 )  & mask  );
    out[16] = (uint32_t)  ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
    out[17] = (uint32_t)  ( ( w7 >> 11 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w7 >> 38  ) | ( w8 << 26 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w8 >> 1 )  & mask  );
    out[20] = (uint32_t)  ( ( w8 >> 28 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w8 >> 55  ) | ( w9 << 9 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w9 >> 18 )  & mask  );
    out[23] = (uint32_t)  ( ( ( w9 >> 45  ) | ( w10 << 19 ) )  & mask  );
    out[24] = (uint32_t)  ( ( w10 >> 8 )  & mask  );
    out[25] = (uint32_t)  ( ( w10 >> 35 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w10 >> 62  ) | ( w11 << 2 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w11 >> 25 )  & mask  );
    out[28] = (uint32_t)  ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
    out[29] = (uint32_t)  ( ( w12 >> 15 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w12 >> 42  ) | ( w13 << 22 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w13 >> 5 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 28-bit values, touching 14 64-bit words, using 112 bytes */
static void unpackblock28(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(268435455);
    /* we are going to access  14 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    uint64_t w13 = pw64[13];
    *pw += 112; /* we used up 112 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 28 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 56  ) | ( w1 << 8 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 20 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w1 >> 48  ) | ( w2 << 16 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w2 >> 12 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w2 >> 40  ) | ( w3 << 24 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w3 >> 4 )  & mask  );
    out[8] = (uint32_t)  ( ( w3 >> 32 )  & mask  );
    out[9] = (uint32_t)  ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
    out[10] = (uint32_t)  ( ( w4 >> 24 )  & mask  );
    out[11] = (uint32_t)  ( ( ( w4 >> 52  ) | ( w5 << 12 ) )  & mask  );
    out[12] = (uint32_t)  ( ( w5 >> 16 )  & mask  );
    out[13] = (uint32_t)  ( ( ( w5 >> 44  ) | ( w6 << 20 ) )  & mask  );
    out[14] = (uint32_t)  ( ( w6 >> 8 )  & mask  );
    out[15] = (uint32_t) ( w6  >> 36  );
    out[16] = (uint32_t)  ( ( w7 )  & mask  );
    out[17] = (uint32_t)  ( ( w7 >> 28 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w8 >> 20 )  & mask  );
    out[20] = (uint32_t)  ( ( ( w8 >> 48  ) | ( w9 << 16 ) )  & mask  );
    out[21] = (uint32_t)  ( ( w9 >> 12 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w9 >> 40  ) | ( w10 << 24 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w10 >> 4 )  & mask  );
    out[24] = (uint32_t)  ( ( w10 >> 32 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w10 >> 60  ) | ( w11 << 4 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w11 >> 24 )  & mask  );
    out[27] = (uint32_t)  ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
    out[28] = (uint32_t)  ( ( w12 >> 16 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w12 >> 44  ) | ( w13 << 20 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w13 >> 8 )  & mask  );
    out[31] = (uint32_t) ( w13  >> 36  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 29-bit values, touching 15 64-bit words, using 116 bytes */
static void unpackblock29(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(536870911);
    /* we are going to access  15 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    uint64_t w13 = pw64[13];
    uint64_t w14 = pw64[14];
    *pw += 116; /* we used up 116 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 29 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 58  ) | ( w1 << 6 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 23 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w1 >> 52  ) | ( w2 << 12 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w2 >> 17 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w2 >> 46  ) | ( w3 << 18 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w3 >> 11 )  & mask  );
    out[8] = (uint32_t)  ( ( ( w3 >> 40  ) | ( w4 << 24 ) )  & mask  );
    out[9] = (uint32_t)  ( ( w4 >> 5 )  & mask  );
    out[10] = (uint32_t)  ( ( w4 >> 34 )  & mask  );
    out[11] = (uint32_t)  ( ( ( w4 >> 63  ) | ( w5 << 1 ) )  & mask  );
    out[12] = (uint32_t)  ( ( w5 >> 28 )  & mask  );
    out[13] = (uint32_t)  ( ( ( w5 >> 57  ) | ( w6 << 7 ) )  & mask  );
    out[14] = (uint32_t)  ( ( w6 >> 22 )  & mask  );
    out[15] = (uint32_t)  ( ( ( w6 >> 51  ) | ( w7 << 13 ) )  & mask  );
    out[16] = (uint32_t)  ( ( w7 >> 16 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w7 >> 45  ) | ( w8 << 19 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w8 >> 10 )  & mask  );
    out[19] = (uint32_t)  ( ( ( w8 >> 39  ) | ( w9 << 25 ) )  & mask  );
    out[20] = (uint32_t)  ( ( w9 >> 4 )  & mask  );
    out[21] = (uint32_t)  ( ( w9 >> 33 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w9 >> 62  ) | ( w10 << 2 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w10 >> 27 )  & mask  );
    out[24] = (uint32_t)  ( ( ( w10 >> 56  ) | ( w11 << 8 ) )  & mask  );
    out[25] = (uint32_t)  ( ( w11 >> 21 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w11 >> 50  ) | ( w12 << 14 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w12 >> 15 )  & mask  );
    out[28] = (uint32_t)  ( ( ( w12 >> 44  ) | ( w13 << 20 ) )  & mask  );
    out[29] = (uint32_t)  ( ( w13 >> 9 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w13 >> 38  ) | ( w14 << 26 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w14 >> 3 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 30-bit values, touching 15 64-bit words, using 120 bytes */
static void unpackblock30(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(1073741823);
    /* we are going to access  15 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    uint64_t w13 = pw64[13];
    uint64_t w14 = pw64[14];
    *pw += 120; /* we used up 120 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 30 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 26 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w2 >> 22 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w3 >> 18 )  & mask  );
    out[8] = (uint32_t)  ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
    out[9] = (uint32_t)  ( ( w4 >> 14 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w4 >> 44  ) | ( w5 << 20 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w5 >> 10 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w5 >> 40  ) | ( w6 << 24 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w6 >> 6 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w6 >> 36  ) | ( w7 << 28 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w7 >> 2 )  & mask  );
    out[16] = (uint32_t)  ( ( w7 >> 32 )  & mask  );
    out[17] = (uint32_t)  ( ( ( w7 >> 62  ) | ( w8 << 2 ) )  & mask  );
    out[18] = (uint32_t)  ( ( w8 >> 28 )  & mask  );
    out[19] = (uint32_t)  ( ( ( w8 >> 58  ) | ( w9 << 6 ) )  & mask  );
    out[20] = (uint32_t)  ( ( w9 >> 24 )  & mask  );
    out[21] = (uint32_t)  ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
    out[22] = (uint32_t)  ( ( w10 >> 20 )  & mask  );
    out[23] = (uint32_t)  ( ( ( w10 >> 50  ) | ( w11 << 14 ) )  & mask  );
    out[24] = (uint32_t)  ( ( w11 >> 16 )  & mask  );
    out[25] = (uint32_t)  ( ( ( w11 >> 46  ) | ( w12 << 18 ) )  & mask  );
    out[26] = (uint32_t)  ( ( w12 >> 12 )  & mask  );
    out[27] = (uint32_t)  ( ( ( w12 >> 42  ) | ( w13 << 22 ) )  & mask  );
    out[28] = (uint32_t)  ( ( w13 >> 8 )  & mask  );
    out[29] = (uint32_t)  ( ( ( w13 >> 38  ) | ( w14 << 26 ) )  & mask  );
    out[30] = (uint32_t)  ( ( w14 >> 4 )  & mask  );
    out[31] = (uint32_t) ( w14  >> 34  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 31-bit values, touching 16 64-bit words, using 124 bytes */
static void unpackblock31(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    const uint64_t mask = UINT64_C(2147483647);
    /* we are going to access  16 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    uint64_t w13 = pw64[13];
    uint64_t w14 = pw64[14];
    uint64_t w15 = pw64[15];
    *pw += 124; /* we used up 124 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  & mask  );
    out[1] = (uint32_t)  ( ( w0 >> 31 )  & mask  );
    out[2] = (uint32_t)  ( ( ( w0 >> 62  ) | ( w1 << 2 ) )  & mask  );
    out[3] = (uint32_t)  ( ( w1 >> 29 )  & mask  );
    out[4] = (uint32_t)  ( ( ( w1 >> 60  ) | ( w2 << 4 ) )  & mask  );
    out[5] = (uint32_t)  ( ( w2 >> 27 )  & mask  );
    out[6] = (uint32_t)  ( ( ( w2 >> 58  ) | ( w3 << 6 ) )  & mask  );
    out[7] = (uint32_t)  ( ( w3 >> 25 )  & mask  );
    out[8] = (uint32_t)  ( ( ( w3 >> 56  ) | ( w4 << 8 ) )  & mask  );
    out[9] = (uint32_t)  ( ( w4 >> 23 )  & mask  );
    out[10] = (uint32_t)  ( ( ( w4 >> 54  ) | ( w5 << 10 ) )  & mask  );
    out[11] = (uint32_t)  ( ( w5 >> 21 )  & mask  );
    out[12] = (uint32_t)  ( ( ( w5 >> 52  ) | ( w6 << 12 ) )  & mask  );
    out[13] = (uint32_t)  ( ( w6 >> 19 )  & mask  );
    out[14] = (uint32_t)  ( ( ( w6 >> 50  ) | ( w7 << 14 ) )  & mask  );
    out[15] = (uint32_t)  ( ( w7 >> 17 )  & mask  );
    out[16] = (uint32_t)  ( ( ( w7 >> 48  ) | ( w8 << 16 ) )  & mask  );
    out[17] = (uint32_t)  ( ( w8 >> 15 )  & mask  );
    out[18] = (uint32_t)  ( ( ( w8 >> 46  ) | ( w9 << 18 ) )  & mask  );
    out[19] = (uint32_t)  ( ( w9 >> 13 )  & mask  );
    out[20] = (uint32_t)  ( ( ( w9 >> 44  ) | ( w10 << 20 ) )  & mask  );
    out[21] = (uint32_t)  ( ( w10 >> 11 )  & mask  );
    out[22] = (uint32_t)  ( ( ( w10 >> 42  ) | ( w11 << 22 ) )  & mask  );
    out[23] = (uint32_t)  ( ( w11 >> 9 )  & mask  );
    out[24] = (uint32_t)  ( ( ( w11 >> 40  ) | ( w12 << 24 ) )  & mask  );
    out[25] = (uint32_t)  ( ( w12 >> 7 )  & mask  );
    out[26] = (uint32_t)  ( ( ( w12 >> 38  ) | ( w13 << 26 ) )  & mask  );
    out[27] = (uint32_t)  ( ( w13 >> 5 )  & mask  );
    out[28] = (uint32_t)  ( ( ( w13 >> 36  ) | ( w14 << 28 ) )  & mask  );
    out[29] = (uint32_t)  ( ( w14 >> 3 )  & mask  );
    out[30] = (uint32_t)  ( ( ( w14 >> 34  ) | ( w15 << 30 ) )  & mask  );
    out[31] = (uint32_t)  ( ( w15 >> 1 )  & mask  );
    *pout += 32; /* we wrote 32 32-bit integers */
}


/* we packed 32 32-bit values, touching 16 64-bit words, using 128 bytes */
static void unpackblock32(const uint8_t ** pw, uint32_t ** pout) {
    const uint64_t * pw64 = *(const uint64_t **) pw;
    uint32_t * out = *pout;
    /* we are going to access  16 64-bit words */
    uint64_t w0 = pw64[0];
    uint64_t w1 = pw64[1];
    uint64_t w2 = pw64[2];
    uint64_t w3 = pw64[3];
    uint64_t w4 = pw64[4];
    uint64_t w5 = pw64[5];
    uint64_t w6 = pw64[6];
    uint64_t w7 = pw64[7];
    uint64_t w8 = pw64[8];
    uint64_t w9 = pw64[9];
    uint64_t w10 = pw64[10];
    uint64_t w11 = pw64[11];
    uint64_t w12 = pw64[12];
    uint64_t w13 = pw64[13];
    uint64_t w14 = pw64[14];
    uint64_t w15 = pw64[15];
    *pw += 128; /* we used up 128 input bytes */
    out[0] = (uint32_t)  ( ( w0 )  );
    out[1] = (uint32_t) ( w0  >> 32  );
    out[2] = (uint32_t)  ( ( w1 )  );
    out[3] = (uint32_t) ( w1  >> 32  );
    out[4] = (uint32_t)  ( ( w2 )  );
    out[5] = (uint32_t) ( w2  >> 32  );
    out[6] = (uint32_t)  ( ( w3 )  );
    out[7] = (uint32_t) ( w3  >> 32  );
    out[8] = (uint32_t)  ( ( w4 )  );
    out[9] = (uint32_t) ( w4  >> 32  );
    out[10] = (uint32_t)  ( ( w5 )  );
    out[11] = (uint32_t) ( w5  >> 32  );
    out[12] = (uint32_t)  ( ( w6 )  );
    out[13] = (uint32_t) ( w6  >> 32  );
    out[14] = (uint32_t)  ( ( w7 )  );
    out[15] = (uint32_t) ( w7  >> 32  );
    out[16] = (uint32_t)  ( ( w8 )  );
    out[17] = (uint32_t) ( w8  >> 32  );
    out[18] = (uint32_t)  ( ( w9 )  );
    out[19] = (uint32_t) ( w9  >> 32  );
    out[20] = (uint32_t)  ( ( w10 )  );
    out[21] = (uint32_t) ( w10  >> 32  );
    out[22] = (uint32_t)  ( ( w11 )  );
    out[23] = (uint32_t) ( w11  >> 32  );
    out[24] = (uint32_t)  ( ( w12 )  );
    out[25] = (uint32_t) ( w12  >> 32  );
    out[26] = (uint32_t)  ( ( w13 )  );
    out[27] = (uint32_t) ( w13  >> 32  );
    out[28] = (uint32_t)  ( ( w14 )  );
    out[29] = (uint32_t) ( w14  >> 32  );
    out[30] = (uint32_t)  ( ( w15 )  );
    out[31] = (uint32_t) ( w15  >> 32  );
    *pout += 32; /* we wrote 32 32-bit integers */
}



/* write number 32-bit values from in bit bits per value to out. */
__attribute__((flatten))
void turbopack32(const uint32_t *  in,  uint32_t number, const uint32_t bit, uint8_t *  out) {
    for(uint32_t pos = 0; pos < number; pos += 32) {
        switch (bit) {
            case 0:
                packblock0(&in, &out);
                break;
            case 1:
                packblock1(&in, &out);
                break;
            case 2:
                packblock2(&in, &out);
                break;
            case 3:
                packblock3(&in, &out);
                break;
            case 4:
                packblock4(&in, &out);
                break;
            case 5:
                packblock5(&in, &out);
                break;
            case 6:
                packblock6(&in, &out);
                break;
            case 7:
                packblock7(&in, &out);
                break;
            case 8:
                packblock8(&in, &out);
                break;
            case 9:
                packblock9(&in, &out);
                break;
            case 10:
                packblock10(&in, &out);
                break;
            case 11:
                packblock11(&in, &out);
                break;
            case 12:
                packblock12(&in, &out);
                break;
            case 13:
                packblock13(&in, &out);
                break;
            case 14:
                packblock14(&in, &out);
                break;
            case 15:
                packblock15(&in, &out);
                break;
            case 16:
                packblock16(&in, &out);
                break;
            case 17:
                packblock17(&in, &out);
                break;
            case 18:
                packblock18(&in, &out);
                break;
            case 19:
                packblock19(&in, &out);
                break;
            case 20:
                packblock20(&in, &out);
                break;
            case 21:
                packblock21(&in, &out);
                break;
            case 22:
                packblock22(&in, &out);
                break;
            case 23:
                packblock23(&in, &out);
                break;
            case 24:
                packblock24(&in, &out);
                break;
            case 25:
                packblock25(&in, &out);
                break;
            case 26:
                packblock26(&in, &out);
                break;
            case 27:
                packblock27(&in, &out);
                break;
            case 28:
                packblock28(&in, &out);
                break;
            case 29:
                packblock29(&in, &out);
                break;
            case 30:
                packblock30(&in, &out);
                break;
            case 31:
                packblock31(&in, &out);
                break;
            case 32:
                packblock32(&in, &out);
                break;
        }
    }
}

/* reads  number 32-bit values from "in" as packed bit bits values, and write to "out" */
__attribute__((flatten))
void turbounpack32(const uint8_t * in, uint32_t number, const uint32_t bit, uint32_t *  out) {
    for(uint32_t pos = 0; pos < number; pos += 32) {
        switch (bit) {
            case 0:
                unpackblock0(&in, &out);
                break;
            case 1:
                unpackblock1(&in, &out);
                break;
            case 2:
                unpackblock2(&in, &out);
                break;
            case 3:
                unpackblock3(&in, &out);
                break;
            case 4:
                unpackblock4(&in, &out);
                break;
            case 5:
                unpackblock5(&in, &out);
                break;
            case 6:
                unpackblock6(&in, &out);
                break;
            case 7:
                unpackblock7(&in, &out);
                break;
            case 8:
                unpackblock8(&in, &out);
                break;
            case 9:
                unpackblock9(&in, &out);
                break;
            case 10:
                unpackblock10(&in, &out);
                break;
            case 11:
                unpackblock11(&in, &out);
                break;
            case 12:
                unpackblock12(&in, &out);
                break;
            case 13:
                unpackblock13(&in, &out);
                break;
            case 14:
                unpackblock14(&in, &out);
                break;
            case 15:
                unpackblock15(&in, &out);
                break;
            case 16:
                unpackblock16(&in, &out);
                break;
            case 17:
                unpackblock17(&in, &out);
                break;
            case 18:
                unpackblock18(&in, &out);
                break;
            case 19:
                unpackblock19(&in, &out);
                break;
            case 20:
                unpackblock20(&in, &out);
                break;
            case 21:
                unpackblock21(&in, &out);
                break;
            case 22:
                unpackblock22(&in, &out);
                break;
            case 23:
                unpackblock23(&in, &out);
                break;
            case 24:
                unpackblock24(&in, &out);
                break;
            case 25:
                unpackblock25(&in, &out);
                break;
            case 26:
                unpackblock26(&in, &out);
                break;
            case 27:
                unpackblock27(&in, &out);
                break;
            case 28:
                unpackblock28(&in, &out);
                break;
            case 29:
                unpackblock29(&in, &out);
                break;
            case 30:
                unpackblock30(&in, &out);
                break;
            case 31:
                unpackblock31(&in, &out);
                break;
            case 32:
                unpackblock32(&in, &out);
                break;
        }
    }
}


