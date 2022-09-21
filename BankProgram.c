/*
  Author: Raghd Al Juma
  Date: 13/11/2020
  Compiler: VSC 

  Program description:

  This program is a bank service center. It allowes users to Verify      
  their PIN, change their bank account PIN as well as display the        
  number of failed and succeful attempts to verify their PIN.
  This program will Only read numbers for PIN.
*/

#include <stdio.h>
#include <stdbool.h> 
#define RUN 4

int main(void)
{   
    /*Declared Variabled*/
    char pin[RUN+1] = "1234"; //Set Initial PIN condition
    char verify[RUN+1]; //Used to verify PIN
    char new_pin[RUN+1]; // Variable to store new PIN
    char verify_new_pin[RUN+1]; //Used to verify new PIN
    int failed_attempts = 0;
    int successful_attempts = 0;
    char option;
    int i;
    bool end = false; //Boolean for program termination
    bool valid = true; //Boolean for Input validation
    bool check = true; //Boolean for checking matching PIN

    // Do while loop for the program.
    do
    {
        //Display menu
        printf("\nHello!. Please choose from the menu which service you would like, then enter the number corresponding to it. \n 1. Enter PIN and verify correct \n 2. Change PIN \n 3. Display the number of times the PIN was entered (i) Successfully (ii) Incorrect \n 4. Exit Program\n");
        
        //Scan user's choice
        scanf("%1s", &option);

        //Switch case for the option choosen
        switch (option)
        {
            //Case 1 to verify user's PIN
            case '1':
            {   
                //Ask user to input their PIN
                printf(" You choose option 1 \n Please enter your PIN for verification\n");

                //Do while loop to validate user input. 
                //Loop ends when valid = true.
                do
                {   
                    //Set valid as true 
                    valid = true;
                    printf("\n Enter the 4 digits:\n");

                    //For loop to scan user's input 
                    for (i = 0; i < RUN; i++)
                    {
                        scanf("%1s",&verify[i]);
                    }
                    
                    //For loop to check each digit from user input is not a character
                    for (i = 0; i < RUN; i++)
                    {
                        //If the input contain char it will set valid as false and break for loop
                        if (verify[i] != '0' && verify[i] != '1' && verify[i] != '2' && verify[i] != '3' && verify[i] != '4' && verify[i] != '5' && verify[i] != '6' && verify[i] != '7' && verify[i] != '8' && verify[i] != '9')
                        {
                            printf("you entered an invalid digit\n");

                            //Set valid as false. Do while loop re-run
                            valid = false;

                            //Break for loop
                            break;
                        }; //End if

                    }; //End for loop
                } //End do while loop
                while (valid == false); 

                printf("The pin you enetered is: %s\n", verify);

                //For loop to check if input matches PIN
                for (i = 0; i < RUN; i++)
                {
                    //Set check as true
                    check = true;

                    //If one of the digits does not match, verification fail.
                    if (verify[i] != pin[i])
                    {   
                        printf("\n The two pins do not match, verification failed. \n");

                        //Set check as false
                        check = false;

                        //Increment failed attempts
                        failed_attempts++;

                        //Break the for loop
                        break;
                    } //End if
                }; //End for loop

                // If check is true, verification succeed
                if (check == true)
                {
                    printf("The pin has been verified\n");

                    //Increment succesful attempts
                    successful_attempts++;
                } //End if

                //Break case 1
                break; 
            }//End Case 1

            //Case 2 to Change PIN
            case '2':
            {
                printf("You choose the second option\n Please enter your new PIN\n");

                do
                {   
                    //Set valid as true 
                    valid = true;
                    printf("\n Enter the 4 digits:\n");

                    //For loop to scan user's input 
                    for (i = 0; i < RUN; i++)
                    {
                        scanf("%1s",&new_pin[i]);
                    }
                    
                    //For loop to check each digit from user input is not a character
                    for (i = 0; i < RUN; i++)
                    {
                        //If the input contain char it will set valid as false and break for loop
                        if (new_pin[i] != '0' && new_pin[i] != '1' && new_pin[i] != '2' && new_pin[i] != '3' && new_pin[i] != '4' && new_pin[i] != '5' && new_pin[i] != '6' && new_pin[i] != '7' && new_pin[i] != '8' && new_pin[i] != '9')
                        {
                            printf("you entered an invalid digit\n");

                            //Set valid as false. Do while loop re-run
                            valid = false;

                            //Break for loop
                            break;
                        }; //End if

                    }; //End for loop
                } //End do while loop
                while (valid == false);

                printf("The pin you enetered is:\n");

                // For loop to display user's input
                for (i = 0; i < RUN; i++)
                {
                    printf("%c", new_pin[i]);
                };//End for

                //Ask user to re enter digit
                printf("\n re-Enter you new pin \n");

                do
                {   
                    //Set valid as true 
                    valid = true;
                    printf("\n Enter the 4 digits:\n");

                    //For loop to scan user's input 
                    for (i = 0; i < RUN; i++)
                    {
                        scanf("%1s",&verify_new_pin[i]);
                    }
                    
                    //For loop to check each digit from user input is not a character
                    for (i = 0; i < RUN; i++)
                    {
                        //If the input contain char it will set valid as false and break for loop
                        if (verify_new_pin[i] != '0' && verify_new_pin[i] != '1' && verify_new_pin[i] != '2' && verify_new_pin[i] != '3' && verify_new_pin[i] != '4' && verify_new_pin[i] != '5' && verify_new_pin[i] != '6' && verify_new_pin[i] != '7' && verify_new_pin[i] != '8' && verify_new_pin[i] != '9')
                        {
                            printf("you entered an invalid digit\n");

                            //Set valid as false. Do while loop re-run
                            valid = false;

                            //Break for loop
                            break;
                        }; //End if

                    }; //End for loop
                } //End do while loop
                while (valid == false);

                printf("The pin you enetered is:\n");

                //For loop to display input
                for (i = 0; i < RUN; i++)
                {
                    printf("%c", verify_new_pin[i]);

                }; //End for
                
                //For loop to check two PINS match 
                for (i = 0; i < RUN; i++)
                {
                    //Set check as true
                    check = true;

                    //If one of the digits does not match, verification fail.
                    if (new_pin[i] != verify_new_pin[i])
                    {   
                        printf("\n The two pins do not match. PIN change failed \n");

                        //Set check as false
                        check = false;

                        //Break the for loop
                        break;
                    } //End if
                }; //End for loop

                // If check is true, verification succeed
                if (check == true)
                {
                    printf("\nThe pin has changed!\n");

                    //For loop to update PIN
                    for (i = 0 ; i < RUN ; i++)
                    {
                        pin[i] = new_pin[i];
                    }//End for

                } //End if

                //Break case
                break; 
            }//End case 2

            // Case 3 to display Succefull and failed verification attempts 
            case '3':
            {
                //print to user the failed and successful attempts
                printf("\n The number of \n i) Successful attempts to enter PIN = \t %d \n and the number of failed attempts to enter PIN = \t %d \n", successful_attempts, failed_attempts);
                break;
            } //End case 3

            // Case 4 for program termination 
            case '4':
            {   
                printf("\n You choose to end Program ");
                //Set end as true
                end = true;

                break;
            } //End case 4

            default:
            {
                //Inform user of invalid input
                printf("\n Invalid input, Please choose again");

            }; //End default

        } //End switch

    } while (end == false); //End do while

    printf("\nProgram Termination");

    return 0;
}//End main