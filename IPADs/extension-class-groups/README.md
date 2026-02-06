# Massey-pari

This folder contains a program which computes class groups of degree p unramified extensions of a number field. The program is written in C using the library [PARI](http://pari.math.u-bordeaux.fr/) which makes it very fast for number fields of low degree. 

To run the main program: ./ext-class-groups p "pol(s)" where you replace pol(s) by a defining polynomial of the number field K in the variable s, and replace p by a prime number dividing the class number.