# Ahlqvist-Pink-I (Authors: Eric Ahlqvist and Richard Pink)

1. The folder "Checking-powerfulness" contains a text file with GAP code that checks whether certain subgroups of a Schur ![equation](https://latex.codecogs.com/svg.image?\color{white}{\sigma})-group of Zassenhaus type (3,3) is powerful or not. 

2. The folder "Massey" contains a C program built on PARI which computes cup products (in parallell) and computes certain 3-fold Massey products in the étale cohomology of the ring of integers of a number field ![equation](https://latex.codecogs.com/svg.image?\color{white}{K}). Since the program was mainly used in the case ![equation](https://latex.codecogs.com/svg.image?\color{white}{K}) is imaginary quadratic (i.e., cup products vanish), we have commented out the cup products part. In this case, the program also outputs generating relations for the group ![G_K/D_4(G_K](docs/equations/G_D4.svg?sanitize=true) where ![equation](https://latex.codecogs.com/svg.image?\color{white}{G_K}) is the Galois group of the maximal unramified pro-![equation](https://latex.codecogs.com/svg.image?\color{white}{p})-extension of ![equation](https://latex.codecogs.com/svg.image?\color{white}{K}). 

3. The folder "SmallGroupIds" contains:
    - "discriminants_3_cyc_[3^m,3^n]"; a file listing a discriminants ![equation](https://latex.codecogs.com/svg.image?\color{white}{0>d>-10^8}) whose class group modulo 3 has rank 2 as a vector space over the field with three elements. This was obtained from LMFDB and filtered using a simple Python script.
    - "massey_relations_p_3.ipynb"; a Jupyter notebook with a script which calls the program "massey" of point 2 for every discriminant in "discriminants_3_cyc_[3^m,3^n]" and prints the generating relations (as described in point 2) to a GAP file "all_rels".
    - "all_rels_20260106a"; a GAP file as described in the the previous step and that we obtained 2026-01-06. 
    - "gap-p-3-cyc-[3^m,3^n].ipynb"; a notebook taking "all_rels_20260106a" as input to compute the small group ids of the groups ![equation](https://latex.codecogs.com/svg.image?\color{white}{G_K/D_4(G_K)}) and compare the frequencies to the Pink–Rubio heuristics. 

4. The folder "IPADs" contains:
    - The folder "extension-class-groups" containing a C program built on PARI which computes class groups of all unramified degree p extensions of a number field. 
    - "IPADs.ipynb"; a Jupyter notebook which calls the C program "extension-class-groups" for every discriminant in "discriminants_3_cyc_[3^m,3^n]" and produces a json file "IPADs.json"

5. The folder "Data-analysis" contains a notebook where we analyze the SmallGroupId data obtained from Massey products and compare it to the IPAD data. One may run the script "setup_venv.sh" to create a virtual environment and install the necessary dependencies. The notebook produces a file "IPAD-and-ID-3.json" listing IPAD and small group id of ![equation](https://latex.codecogs.com/svg.image?\color{white}{G_K/D_4(G_K)}) for all discriminants in "discriminants_3_cyc_[3^m,3^n]". The notebook shows that for this list of discriminants, two discriminants with distinct small group ids never have equal IPADs, i.e. the IPAD determines the small group id. It then lists the number of IPADs of each type along with their associated small group id. We include a textfile with the output that we obtained from this count. The IPAD count matches the one in the <a href="https://link.springer.com/article/10.1007/s00208-016-1449-3">paper</a> of Boston–Bush–Hajir, where they counted these IPADs but without the small groups ids. 

====================================================================================

<b>Compile and run the C programs:</b>

To run the C programs you must:
    - Download and compile PARI (see https://pari.math.u-bordeaux.fr). 
    - If you want to build using our Makefiles, set the PARI variable. On Unix systems "export PARI={your_pari_location}".
    - Compile the massey program by running the command "make" in your terminal while in the directory "Massey".
    - Once compiled, run it for ex. by running ./build/massey 3 "s^2+4027" in your terminal (in the directory Massey).  


