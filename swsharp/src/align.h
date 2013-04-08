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

@brief
*/

#ifndef __SW_SHARP_ALIGNH__
#define __SW_SHARP_ALIGNH__

#include "alignment.h"
#include "chain.h"
#include "constants.h"
#include "scorer.h"
#include "thread.h"

#ifdef __cplusplus 
extern "C" {
#endif

extern void alignPair(Alignment** alignment, Chain* query, Chain* target, 
    Scorer* scorer, int type, int* cards, int cardsLen, Thread* thread);

extern void alignBest(Alignment** alignment, Chain** queries, int queriesLen, 
    Chain* target, Scorer* scorer, int type, int* cards, int cardsLen, 
    Thread* thread);

#ifdef __cplusplus 
}
#endif
#endif // __SW_SHARP_ALIGNH__
