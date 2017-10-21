//------------------------------------------------------------------
// File: test.c
//   
// Description: This program uses the srandom and random functions and 
//      tests how random the random number generator really is.  The 
//      random function returns a number between 0 and RAND_MAX.  To 
//      test the distribution, this range will be divided into 10 equal
//      ranges.  The program will call random 1,000,000 times and 
//      calculate the number of times that a random number is seen 
//      within those 10 ranges. The results will be output in three
//      columns as shown below, including the percentage (to two 
//      decimal points) for each range.  It will also print the largest
//      and smallest random number and the number of odds and evens 
//      returned. The program will also print the first number seen
//      and how many times that number is returned by the random number
//      generator.  It will also print out a Jackpot indicator if the 
//      Jackpot number (837729) is generated.  
//        
//       
// Syntax: The program will be called from the command line.
//      Sample columns are shown below.
//       
//       Sample Output:
//              
//       Random Number Test on 1,000,000 Attempts
//       
//       Group  Observed  Percentage
//       -----  --------  ----------
//           1    100057       10.01
//           2     99496        9.95
//           3    100140       10.01
//           4     99922        9.99
//           5     99807        9.98
//           6    100022       10.00
//           7    100491       10.05
//           8     99818        9.98
//           9    100206       10.02
//          10    100041       10.00
//
//       Smallest observed number = 174119
//       Largest observed number  = 2147303399
//       Number of odd numbers    = 500587
//       Number of even numbers   = 499413
//       First number seen        = 1257834
//       The first number was seen 1 time(s)
//
//-------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM_CALLS 1000000
#define PERCENT 100
#define JACKPOT 837729
#define statement(p)\
        printf("%d", __LINE__)

//------------------------------
// Main
//------------------------------

int main(int argc, char * argv[])
{
        // Creation of local variables
	
	int random_number;
	int smallest = RAND_MAX;
        int largest = 0;
        int evens = 0;
        int odds = 0;
        int x = 0;
        int first_number;
        
        int group1count = 0;
        int group2count = 0;
        int group3count = 0;
        int group4count = 0;
        int group5count = 0;
        int group6count = 0;
        int group7count = 0;
        int group8count = 0;
        int group9count = 0;
        int group10count = 0;
        int first_number_count = 0;
        
        float group1percent = 0;
        float group2percent = 0;
        float group3percent = 0;
        float group4percent = 0;
        float group5percent = 0;
        float group6percent = 0;
        float group7percent = 0;
        float group8percent = 0;
        float group9percent = 0;
        float group10percent = 0;

        int GROUP1_MAX = RAND_MAX/10;
        int GROUP2_MAX = 2*GROUP1_MAX;
        int GROUP3_MAX = 3*GROUP1_MAX;
        int GROUP4_MAX = 4*GROUP1_MAX;
        int GROUP5_MAX = 5*GROUP1_MAX;
        int GROUP6_MAX = 6*GROUP1_MAX;
        int GROUP7_MAX = 7*GROUP1_MAX;
        int GROUP8_MAX = 8*GROUP1_MAX;
        int GROUP9_MAX = 9*GROUP1_MAX;
        int GROUP10_MAX = 10*GROUP1_MAX;                                                      

        // Seed the random number generator 

        srandom(time(NULL));

        // Call the random number generator 1,000,000 times

        while (x < MAX_RANDOM_CALLS) {

                random_number = random();
                
                // Set the first number called
                if (x == 0){
                        first_number = random_number;
                }
                
                // Increment odds or evens
                if (random_number % 2 == 0){
                        evens += 1;
                } else {
                        odds += 1;
                }
                
                // Increment first number count
                if (random_number == first_number){
                        first_number_count += 1;
                }
                
                // Increment group counts
                if (random_number < GROUP1_MAX){
                        group1count += 1;
                } else if (random_number > GROUP1_MAX && 
                           random_number < GROUP2_MAX){
                        group2count += 1;
                } else if (random_number > GROUP2_MAX && 
                           random_number < GROUP3_MAX){
                        group3count += 1;
                } else if (random_number > GROUP3_MAX && 
                           random_number < GROUP4_MAX){
                        group4count += 1;
                } else if (random_number > GROUP4_MAX && 
                           random_number < GROUP5_MAX){
                        group5count += 1;
                } else if (random_number > GROUP5_MAX && 
                           random_number < GROUP6_MAX){
                        group6count += 1;
                } else if (random_number > GROUP6_MAX && 
                           random_number < GROUP7_MAX){
                        group7count += 1;
                } else if (random_number > GROUP7_MAX && 
                           random_number < GROUP8_MAX){
                        group8count += 1;
                } else if (random_number > GROUP8_MAX && 
                           random_number < GROUP9_MAX){
                        group9count += 1;
                } else if (random_number > GROUP9_MAX && 
                           random_number < GROUP10_MAX){
                        group10count += 1;
                }
                
                // Keep track of the largest number
                if (random_number > largest){
                        largest = random_number;
                }
                
                // Keep track of the smallest number
                if (random_number < smallest){
                        smallest = random_number;
                }

                // Print statement if JACKPOT number seen
                if (random_number == JACKPOT){
                        printf("\n"); 
                        printf(" Jackpot found on line number ");
                        statement(p);
                        printf("\n"); 
                }
                x += 1;
        }
        
        // Calculate the percents for each group

        group1percent = (float) group1count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group2percent = (float) group2count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group3percent = (float) group3count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group4percent = (float) group4count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group5percent = (float) group5count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group6percent = (float) group6count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group7percent = (float) group7count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group8percent = (float) group8count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group9percent = (float) group9count/MAX_RANDOM_CALLS 
                                * PERCENT;
        group10percent = (float) group10count/MAX_RANDOM_CALLS 
                                * PERCENT;                       

        // Print out the output

        printf("\n");
        printf(" Random Number Test on 1,000,000 Attempts\n");
        printf("\n");
        printf(" Group  Observed  Percentage\n");
        printf(" -----  --------  ----------\n");
        printf("     1  %8i       %5.2f\n", group1count, 
                                            group1percent);
        printf("     2  %8i       %5.2f\n", group2count, 
                                            group2percent);
        printf("     3  %8i       %5.2f\n", group3count, 
                                            group3percent);
        printf("     4  %8i       %5.2f\n", group4count, 
                                            group4percent);
        printf("     5  %8i       %5.2f\n", group5count, 
                                            group5percent);
        printf("     6  %8i       %5.2f\n", group6count, 
                                            group6percent);
        printf("     7  %8i       %5.2f\n", group7count, 
                                            group7percent);
        printf("     8  %8i       %5.2f\n", group8count, 
                                            group8percent);
        printf("     9  %8i       %5.2f\n", group9count, 
                                            group9percent);
        printf("    10  %8i       %5.2f\n", group10count, 
                                            group10percent);
        printf("\n");
        printf(" Smallest observed number = %i\n", smallest);
        printf(" Largest observed number  = %i\n", largest);       
        printf(" Number of odd numbers    = %i\n", odds);        
        printf(" Number of even numbers   = %i\n", evens);
        printf(" First number seen        = %i\n", first_number);
        printf(" The first number was seen %i time(s)\n", first_number_count);
        printf("\n");

        return 0;
}



