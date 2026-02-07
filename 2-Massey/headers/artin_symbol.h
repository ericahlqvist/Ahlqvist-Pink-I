// MIT License

// Copyright (c) 2025 [Eric Ahlqvist]

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef ARTIN_SYMBOL_H
#define ARTIN_SYMBOL_H

#include <pari/pari.h>

//-------------------------------------------------------------------------------

/*-------------- The Artin Symbol ---------------
Let L/K be a Galois extension and let p be a prime in O_K which is unramified in L (in our case this holds for all primes in O_K since L/K is unramified). Choose a prime q in O_L lying above p. Then there is a unique element sigma_p in G_q:={sigma in Gal(L/K) : sigma(q)=q} such that sigma = (-)^N(p) when acting on the residue field k(q). 
(1) If p is split in L, then G_q = {1} and k(q) = k(p) which means that (-)^N(p) = (-) = id and hence sigma_p = 1 (so 0 when identified with Z/pZ). 
(2) Otherwise, since we assume L/K to be unramified of prime degree, the only other option is that p is inert in L and hence G_q=Gal(L/K). 
The element sigma_p is independent of the choice of q since we assume L/K to be abelian. 

Since k(q)^x is cyclic, it is enough to check that sigma_p(g) = g^N(p) for a generator g of k(q)^x.
*/

int my_Artin_symbol (GEN Labs, GEN Lrel, GEN K, GEN I_K, int p);

#endif // ARTIN_SYMBOL_H
