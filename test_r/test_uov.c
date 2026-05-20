// SPDX-License-Identifier: CC0 OR Apache-2.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api.h"
#include "utils_randombytes.h"

int main(void) {
    printf("%s\n", OV_ALGNAME );
    printf("sk size: %d\n", CRYPTO_SECRETKEYBYTES );
    printf("pk size: %d\n", CRYPTO_PUBLICKEYBYTES );
    printf("signature overhead: %d\n\n", CRYPTO_BYTES );

    unsigned char sm[256 + CRYPTO_BYTES];
    unsigned char m[256];
    for (unsigned i = 0; i < 256; i++) {
        m[i] = i;
    }
    unsigned long long mlen = 256;
    unsigned long long smlen;

    unsigned char *pk = (unsigned char *)malloc( CRYPTO_PUBLICKEYBYTES );
    unsigned char *sk = (unsigned char *)malloc( CRYPTO_SECRETKEYBYTES );

    unsigned char seed[48] = { 0 };
    randombytes_init(seed, NULL, 256);

    int ret = 0;

    int r0 = crypto_sign_keypair( pk, sk);
    if ( 0 != r0 ) {
        printf("generating key return %d.\n", r0);
        printf("test failed!\n");
        ret = -1;
        goto clean_exit;
    }
    printf("pk: ");
    for (size_t i = 0; i < CRYPTO_PUBLICKEYBYTES;  ++i) {
        printf("%02X", pk[i]);
    }
    printf("\n");
    printf("sk: ");
    for (size_t i = 0; i < CRYPTO_SECRETKEYBYTES;  ++i) {
        printf("%02X", sk[i]);
    }
    printf("\n");
    

    int r1 = crypto_sign( sm, &smlen, m, mlen, sk );
    if ( 0 != r1 ) {
        printf("crypto_sign() return %d.\n", r1);
        printf("test failed!\n");
        ret = -1;
        goto clean_exit;
    }
    printf("sm: ");
    for (size_t i = 0; i < smlen;  ++i) {
        printf("%02X", sm[i]);
    }
    printf("\n");

    int r2 = crypto_sign_open( m, &mlen, sm, smlen, pk );
    if ( 0 != r2 ) {
        printf("crypto_sign_open() return %d.\n", r2);
        printf("test failed!\n");
        ret = -1;
        goto clean_exit;
    }

    printf("verify success!\n");

    sm[0] = ~sm[0];
    int r3 = crypto_sign_open( m, &mlen, sm, smlen, pk );
    if ( -1 != r3 ) {
        printf("wrong signature still verified!\n");
        printf("test failed!\n");
        ret = -1;
        goto clean_exit;
    }


clean_exit:
    free( pk );
    free( sk );
    return ret;
}

