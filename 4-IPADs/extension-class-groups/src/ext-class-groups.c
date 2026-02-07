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


#include <pthread.h>
#include <pari/pari.h>
#include <stdio.h>
#include <time.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Debug level
#define MY_DEBUGLEVEL 0

// Debug printing function
#define DEBUG_PRINT(level, ...) \
    do { if (MY_DEBUGLEVEL >= (level)) pari_printf(__VA_ARGS__); } while (0)

#include "../headers/misc_functions.h"
#include "../headers/ext_and_aut.h"

int
main (int argc, char *argv[])	  
{
    printf(ANSI_COLOR_YELLOW "\n---------------------------------------------------------------------------------------------------------\nStarting program: Massey products\n---------------------------------------------------------------------------------------------------------\n\n" ANSI_COLOR_RESET);

    // Start timer (actual time)
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    // Start timer (CPU time)
    clock_t start = clock();

    int min, sec, msec;
    
    //--------------------------------------------------
    // Initialize PARI/GP
    //--------------------------------------------------
    pari_init(1L<<30,1048576);
    // entree ep = {"_worker",0,(void*)compute_my_relations,20,"LG",""};
    // pari_init_opts(1L<<30,1048576, INIT_JMPm|INIT_SIGm|INIT_DFTm|INIT_noIMTm);
    // pari_add_function(&ep); /* add Cworker function to gp */
    // pari_mt_init(); /* ... THEN initialize parallelism */
    paristack_setsize(1L<<30, 1L<<33);
    //sd_threadsizemax("2147483648", 0);
    setalldebug(0);
    //--------------------------------------------------
    
    int p_int;
    GEN p, K, f, Kcyc, D, D_prime_vect;

    // Read the prime number p from arguments
    p = gp_read_str(argv[1]);
    p_int = atoi(argv[1]);
    
    // Read the defining polynomial for K
    f = gp_read_str(argv[2]);
    pari_printf("K pol: %Ps\n\n", f);
    
    //--------------------------------------------------
    // Define base field K
    K = Buchall(f, nf_FORCE, DEFAULTPREC);
    //K = Buchall_param(f, 1.5, 1.5, 4, nf_FORCE, DEFAULTPREC);
    //--------------------------------------------------
    // Discriminant
    D = nf_get_disc(bnf_get_nf(K));
    pari_printf("Discriminant: %Ps\n\n", D);
    pari_printf("Root discriminant: %Ps\n\n", gsqrtn(gabs(D, DEFAULTPREC), stoi(nf_get_degree(bnf_get_nf(K))), NULL, DEFAULTPREC));
    
    //--------------------------------------------------
    // Check Galois
    if (MY_DEBUGLEVEL >= 1){ my_check_galois(K); }
    
    //--------------------------------------------------        

    // Factor discriminant
    D_prime_vect = gel(factor(D), 1);
    
    //--------------------------------------------------
    // Class group of K (cycle type)
    Kcyc = bnf_get_cyc(K);
    pari_printf("K cyc: %Ps\n\n", Kcyc);
    // pari_printf("r_2(K): %ld\n\n", nf_get_r2(bnf_get_nf(K)));
    //--------------------------------------------------
    // Test if p divides the class number. If not, then H^1(X, Z/pZ) = 0 and there is nothing to compute. 
    my_test_p_rank(K, p_int);
    
    //--------------------------------------------------
    // Find data of unramified extensions
    my_unramified_p_extensions(K, p, D_prime_vect);
    
    
    //--------------------------------------------------

    DEBUG_PRINT(0, ANSI_COLOR_GREEN "Done! \n \n" ANSI_COLOR_YELLOW);
   
    pari_close();






    //--------------------------------------------------
    // Compute the CPU time
    clock_t duration = (clock()-start) / 1000; // Compute CPU duration in microseconds

    // Compute the actual time
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    
    // Compute actual duration in milliseconds
    long duration_ns = (end_time.tv_sec - start_time.tv_sec) * 1e9 + (end_time.tv_nsec - start_time.tv_nsec);
    long duration_ms = duration_ns / 1e6; // Convert to milliseconds

    // Convert to minutes, seconds, and milliseconds
    msec = duration_ms % 1000;
    sec = (duration_ms / 1000) % 60;
    min = duration_ms / 60000;

    // Print actual elapsed time
    printf(ANSI_COLOR_YELLOW "Actual time: %d min, %d sec, %d msec\n\n" ANSI_COLOR_RESET, min, sec, msec);
    
    // Compute the CPU time
    msec = duration%1000000;
    sec = (duration/1000)%60;
    min = duration/60000;

    printf (ANSI_COLOR_YELLOW "CPU time: %d min, %d,%d sec\n" ANSI_COLOR_RESET, min, sec, msec);
    //--------------------------------------------------
    printf("\n---------------------------------------------------------------------------------------------------------\nEnd program\n---------------------------------------------------------------------------------------------------------\n\n");
    return 0;
}

