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

#ifndef __SW_SHARP_CPU_MODULEH__
#define __SW_SHARP_CPU_MODULEH__

#include "alignment.h"
#include "chain.h"
#include "scorer.h"

#ifdef __cplusplus 
extern "C" {
#endif

extern void alignPairCpu(Alignment** alignment, int type, Chain* query, 
    Chain* target, Scorer* scorer);
    
extern void nwReconstructCpu(char** path, int* pathLen, int* outScore, 
    Chain* query, int queryFrontGap, int queryBackGap, Chain* target, 
    int targetFrontGap, int targetBackGap, Scorer* scorer, int score);
    
extern int scorePairCpu(int type, Chain* query, Chain* target, Scorer* scorer);
    
extern void swFindStartCpu(int* queryStart, int* targetStart, Chain* query, 
    Chain* target, Scorer* scorer, int score);
    
#ifdef __cplusplus 
}
#endif
#endif // __SW_SHARP_CPU_MODULEH__
