// SPDX-License-Identifier: CC0 OR Apache-2.0
//// @file blas_matrix.c
/// @brief The standard implementations for blas_matrix.h
///

//#include "blas_comm.h"
#include "blas_matrix.h"
//#include "blas.h"
#include "params.h"  // for macro _USE_GF16


#include "config.h"

#include "blas_matrix_ref.h"

#define gf16mat_prod_impl             gf16mat_prod_ref
#define gf256mat_prod_impl            gf256mat_prod_ref

#define gf256mat_gaussian_elim_impl   gf256mat_gaussian_elim_ref
#define gf256mat_back_substitute_impl gf256mat_back_substitute_ref
#define gf16mat_gaussian_elim_impl   gf16mat_gaussian_elim_ref
#define gf16mat_back_substitute_impl gf16mat_back_substitute_ref

#ifdef _USE_GF16

void gf16mat_prod(uint8_t *c, const uint8_t *matA, unsigned n_A_vec_byte, unsigned n_A_width, const uint8_t *b) {
    gf16mat_prod_impl( c, matA, n_A_vec_byte, n_A_width, b);
}

#if defined(_MUL_WITH_MULTAB_)
void gf16mat_prod_multab(uint8_t *c, const uint8_t *matA, unsigned n_A_vec_byte, unsigned n_A_width, const uint8_t *b) {
    gf16mat_prod_multab_impl( c, matA, n_A_vec_byte, n_A_width, b);
}
#endif

unsigned gf16mat_gaussian_elim(uint8_t *sqmat_a, uint8_t *constant, unsigned len) {
    return gf16mat_gaussian_elim_impl(sqmat_a, constant, len );
}

void gf16mat_back_substitute( uint8_t *constant, const uint8_t *sqmat_a, unsigned len) {
    gf16mat_back_substitute_impl( constant, sqmat_a, len );
}

#else  // #ifdef _USE_GF16

void gf256mat_prod(uint8_t *c, const uint8_t *matA, unsigned n_A_vec_byte, unsigned n_A_width, const uint8_t *b) {
    gf256mat_prod_impl( c, matA, n_A_vec_byte, n_A_width, b);
}

#if defined(_MUL_WITH_MULTAB_)
void gf256mat_prod_multab(uint8_t *c, const uint8_t *matA, unsigned n_A_vec_byte, unsigned n_A_width, const uint8_t *b) {
    gf256mat_prod_multab_impl( c, matA, n_A_vec_byte, n_A_width, b);
}
#endif

unsigned gf256mat_gaussian_elim(uint8_t *sqmat_a, uint8_t *constant, unsigned len) {
    return gf256mat_gaussian_elim_impl(sqmat_a, constant, len );
}

void gf256mat_back_substitute( uint8_t *constant, const uint8_t *sqmat_a, unsigned len) {
    gf256mat_back_substitute_impl( constant, sqmat_a, len );
}

#endif  // #ifdef _USE_GF16
