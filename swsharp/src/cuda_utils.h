/*
swsharp - CUDA parallelized Smith Waterman with applying Hirschberg's and 
Ukkonen's algorithm and dynamic cell pruning.
Copyright (C) 2013 Matija Korpar, contributor Mile Šikić

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Contact the author by mkorpar@gmail.com.
*/
/**
@file

@brief CUDA utility header.
*/

#ifndef __SW_SHARP_CUDA_UTILSH__
#define __SW_SHARP_CUDA_UTILSH__

#ifdef __cplusplus 
extern "C" {
#endif

#define CUDA_SAFE_CALL(call) \
    do { \
        cudaError err = call; \
        if (cudaSuccess != err) { \
            fprintf(stderr, "Cuda error in file '%s' in line %i : %s.\n", \
                    __FILE__, __LINE__, cudaGetErrorString(err)); \
            exit(EXIT_FAILURE); \
        } \
    } while(0)
    
#define TO_GPU cudaMemcpyHostToDevice
#define FROM_GPU cudaMemcpyDeviceToHost

#define MAX3(x, y, w) max(x, max(y, w))
#define MAX4(x, y, w, z) max(max(x, y), max(w, z))

#define VEC2_ASSIGN(X, Y) \
    do { \
        (X).x = (Y).x; \
        (X).y = (Y).y; \
    } while(0)

#define VEC3_ASSIGN(X, Y) \
    do { \
        (X).x = (Y).x; \
        (X).y = (Y).y; \
        (X).z = (Y).z; \
    } while(0)

#define VEC4_ASSIGN(X, Y) \
    do { \
        (X).x = (Y).x; \
        (X).y = (Y).y; \
        (X).z = (Y).z; \
        (X).w = (Y).w; \
    } while(0)

/*!
@brief Gets CUDA card index list.

@param cards output CUDA cards index array
@param cardsLen output CUDA cards index array length
*/
extern void cudaGetCards(int** cards, int* cardsLen);

/*!
@brief Checks CUDA card index list.

@param cards CUDA cards index array
@param cardsLen CUDA cards index array length

@return 1 if all input card indices are available, 0 otherwise
*/
extern int cudaCheckCards(int* cards, int cardsLen);

#ifdef __cplusplus 
}
#endif
#endif // __SW_SHARP_CUDA_UTILSH__
