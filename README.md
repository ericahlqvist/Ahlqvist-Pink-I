# Ahlqvist-Pink-I (Authors: Eric Ahlqvist and Richard Pink)

All files concern the case $p=3$.

1. The folder "1-Checking-powerfulness" contains: 

    - a text file "WhenEGIsPowerful_20260204.txt" with annotated GAP code that decides whether certain subgroups of a Schur $\sigma$-group of Zassenhaus type $(3,3)$ are powerful or not. It should run as is on any GAP installation.

    - "WhenEGIsPowerful_20260204.ipynb"; a Jupyter notebook version of the previous, but including output.   

2. The folder "2-Massey" contains a C program built on PARI which computes cup products (in parallel) and computes certain 3-fold Massey products in the étale cohomology of the ring of integers of a number field $K$. Since for the present purposes the program was used only for imaginary quadratic $K$, where cup products vanish, we have commented out the cup products part. In this case, the program also outputs generating relations for the factor group $G_K/D_4(G_K)$, where $G_K$ is the Galois group of the maximal unramified pro-p-extension of $K$.

3. The folder "3-SmallGroupIds" contains:
       
    - a file "discriminants_3_cyc_[3^m,3^n]"; listing all discriminants $d_K$ of imaginary quadratic fields $K$ with $|d_K| < 10^8$ and whose class group modulo 3 has rank 2 as a vector space over the field $\mathbb{F}_3$ with three elements. This was obtained from the $L$-functions and Modular Forms Database (LMFDB) and filtered using a simple Python script.

   - a Jupyter notebook "massey_relations_p_3.ipynb" with a script which calls the program "massey" from 2. for every discriminant in (a) and prints the generating relations to a GAP file "all_rels".

   - a Jupyter notebook "gap-p-3-cyc-[3^m,3^n].ipynb" computing from "all_rels" the isomorphism classes of $G_K/D_4(G_K)$ and prints it to the file "D-and-small-group-id.json". To each discriminant $d_K$ it associates a pair $[n,i]$ such that $G_K/D_4(G_K)$ is isomorphic to the group obtained by the GAP command "SmallGroup(n,i)".

   - the Jupyter notebook "gap-p-3-cyc-[3^m,3^n].ipynb" also compares the observed frequencies of all small group ids to the conditional probabilities from the generalization of the Cohen-Lenstra heuristic, and prints this as a table in LaTex code.

4. The folder "4-IPADs" contains:
    - a folder "extension-class-groups" containing a C program built on PARI which computes the class groups of all unramified degree p extensions of a number field.

    - a Jupyter notebook "IPADs.ipynb" which applies that program to every discriminant in 3. and produces a json file "IPADs.json".  

5. The folder "5-Data-analysis" contains a Jupyter notebook "explore-data.ipynb" which counts the number of IPADs of each kind and finds that there is for every IPAD $I$ a unique isomorphism class for $G_K/D_4(G_K)$ such that IPAD($G_K$) is $I$. The output is stored in IPADs.txt. The notebook produces a file "IPAD-and-ID-3.json" listing IPAD and small group id of $G_K/D_4(G_K)$ for all discriminants in "discriminants_3_cyc_[3^m,3^n]". 

One may run the script "setup_venv.sh" to create a virtual environment and install the necessary dependencies. 

====================================================================================

<b>Compile and run the C programs:</b>

To run the C programs you must:
    - Download and compile PARI (see https://pari.math.u-bordeaux.fr). 
    - If you want to build using our Makefiles, set the PARI variable. On Unix systems "export PARI={your_pari_location}".
    - Compile the massey program by running the command "make" in your terminal while in the directory "Massey".
    - Once compiled, run it for ex. by running ./build/massey 3 "s^2+4027" in your terminal (in the directory Massey).  


