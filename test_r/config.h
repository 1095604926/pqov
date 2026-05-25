// SPDX-License-Identifier: CC0 OR Apache-2.0
#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef NDEBUG
#define NDEBUG
#endif

/*
 *   This file contains all implementation options that do not affect testvectors
 *   params.h contains other options.
 */


//
// This macro set the max steps for conditional row-swaps in the constant time
// Gaussian Elimination algorithm.
// Default value : OFF
//
//#define _GE_CONST_TIME_CADD_EARLY_STOP_
#define _GE_EARLY_STOP_STEPS_GF16_    16
#define _GE_EARLY_STOP_STEPS_GF256_   8


// GF multiplication with multiplication tables
//#define _MUL_WITH_MULTAB_


//
// choose implementations for SHAKE256, AES128CTR, and randombytes() functions
//
// #if !defined(_UTILS_OPENSSL_)
// #define _UTILS_OPENSSL_
// #endif

//
// Options for randombytes()
//
//
// The following macro will implement randombytes() with utils/nistkat/rng.[hc]
// It uses AEC256CTR and AES256_ECB from openssl.
//
//#define _NIST_KAT_
//
// The following macro will implement randombytes() with C rand()
// Turn on only when there is no proper implementation
//
//#define _DEBUG_RANDOMBYTES_


#endif
