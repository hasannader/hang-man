#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 100

int var=0;  /*variable for storing the last order entered by user,
              which we use in case the user replayed the game
              to be sure that he/she won't enter the same order
              for two consecutive games*/

void showHangman(int ,char* ,int );
int main()
{
    char *hangmanWord, tempWord[100];       //hangmanWord[] array for the original word and tempWord[] array to get the alphabet from user and compare it with original word*/
    char hangmanOutput[100],wrongword[100];                    /*This array will show the remaining blanks and correct inputs*/
    int wrongTry , matchFound , length , i , order ;
    int counter , position , winner,  l , x = 1 , y ,z ;
    char alphabetFromUser;
    char HardCoded[10][N]={"equip","wizard","jumbo","zipper",   /*HardCoded[][] is an array of strings containing 10 hard-coded words to be guessed*/
                           "scratch","pixel","luxury","stretch",
                           "ivory","matrix"};

    //printf("\n Previous order = %d\n",var);

  loop:
  while(x)  //the program runs when x=1 and ends when x=0
  {

    wrongTry = 10 , matchFound = 0 ;
    counter = 0 , position = 0, l = 0 , y = 0 , z = 0 ;

    printf("\n\t\t\t\t!!!!!!! Welcome to the HANGMAN game !!!!!!!");   /*Brief description of the game*/
    printf("\n\t\t\t\t        We hope you enjoy our game (^-^)\n\n\n");

    printf("\n\n You will get 10 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");

    printf("\n\n Enter order of hard-coded word to be guessed : ");
    scanf("%d",&order);

    if(order>10 || order<1)   /*to check that the entered order is in the restricted range*/
    {
         system("cls");
         printf("\n <Invalid order>\n\n");
         //main();
         goto loop ;
    }

    if(var!=0)               /*to check that new order is not equal to old order*/
    {
        if(var==order)
        {
            system("cls");
            printf("\n   <This order was used before!!>");
            printf("\n <You have to enter a new order!!!>\n");
            //main();
            goto loop ;
        }
    }

    system("cls");

    printf("\n\t||===== ");                 /*show the HANGMAN*/
    	printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

   hangmanWord=HardCoded[order-1];         //the unknown word which will be guessed by the user
   length = strlen(HardCoded[order-1]);    //length of the unknown word
   printf("\n\n The required word has %d alphabets : \n\n",length);  /*tell the user how many alphabets the word has*/

   for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '.';

        hangmanOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);        /*Show the Word With n(length of the original word) number of underscores (_)*/

    }

    printf("\n\n\t\t\t\t You have 10 tries :) ");

    while(wrongTry != 0)                        /*while loop for exiting the program when no try left*/
    {
        matchFound = 0;
        printf("\n\n Enter any alphabet letter from a to z!!");
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);
        scanf("%c",&alphabetFromUser);            /*get alphabet from user*/

        alphabetFromUser=tolower(alphabetFromUser); /*The tolower() function takes an uppercase alphabet and convert it to a lowercase character*/

    if(alphabetFromUser < 'a' || alphabetFromUser > 'z') /*In case player gives input other than 'a' to 'z' the console will ask again*/
    {
        system("cls");
        printf("\n\n\t Wrong input TRY AGAIN ");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)    /*for loop to check whether player input alphabet exists or not in the word*/
	    {
          if (hangmanWord[counter]!=' '){
		    if(hangmanWord[counter]==alphabetFromUser)
		     {
		       matchFound = 1;
                     }//end of if()

	            }//end of 1st if
            }//end of for()
            y=0;
        for(i=0;i<length;i++){
            if(hangmanWord[i]==alphabetFromUser){
                    break;
            }
            else{
                y++;
            }
        }

         if(y==length){
                wrongword[z]=alphabetFromUser;
                z++;
                }

	   if(matchFound == 0)                      /*in case of wrong guess*/
	    {
     	      printf("\n\t\t\t\t Wrong input character :( ");
     	      printf("\n\n\t\t\t\t You have now %d tries left!!! ",--wrongTry);
     	      printf("\n\n\t\t\t\t <Press Enter to continue...> ");
	          getchar();
              showHangman(wrongTry+1,wrongword,z);
              //getchar();
	    }//end of if()

	   else
	   {
	     for(counter = 0; counter < length; counter++)
             {
     	         matchFound = 0;

                 if(alphabetFromUser == hangmanWord[counter])
	          {
     		     position = counter ;
     		     matchFound = 1;
	          }//end of if
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          hangmanOutput[i] = alphabetFromUser; /*Put the alphabet at right position*/
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z') /** If the position already occupied
                                                                                  by same alphabet then no need to
                                                                                  fill again EASY!! and continue */
                      {
                          continue;
                  	  }

                      else
                      {
                            if (hangmanWord[i]!=' ')
                                 hangmanOutput[i] = '.';
                            else
                                 hangmanOutput[i]=' ';
                                 hangmanOutput[length] = '\0';            /* Put a blank at not guessed alphabet position */
                      }
                }
                for (i = 0 ; i < length ; i++){
                    if (hangmanWord[i]!=' ')
                        continue;
                    else
                        tempWord[i]=hangmanWord[i];
                }
                tempWord[position] = alphabetFromUser;      /*put the alphabet in another char array to check with the original word*/
                tempWord[length] = '\0';                    /*put the NULL character at the end of the temp string*/
                winner = strcmp(tempWord,hangmanWord);      /*upon True comparison it will return 0*/

                if(winner == 0)                             /*if the player guessed the whole word right then he/she is the WINNER*/
                {
                    printf("\n\n\t \t YAHOOOO!!!!! You are the WINNER!!!!!");
                    printf("\n\n\n\t The word was %s ",hangmanWord);
                    printf("\n\n\n\t\t EASY HUH ???!");
                    printf("\n\n\t\t <Press Enter to continue...> ");
                    getchar();

                    printf("\n\n\n If you want to replay press 1 or press 0 to end game: ");
                    scanf("%d",&x);

                    if(x==0)
                    {
                        printf("\n\n\n\t\t\t\t!!!!!!! Game Over !!!!!!!\n\n\n");  //endgame if 0 is entered
                        //return 0;
                    }
                    else if(x==1)
                    {
                        system("cls"); /*clear the command then re-execute
                                        the main() if 1 is entered */
                        getchar();
                        var=order;
                        //main();
                    }

                    goto loop ;

                }//end of inner if
	       }//end of outer if
	    }//end of for loop
      }//end of else
     }// end of if(matchFound != 2) condition

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanOutput[i]);                /*Show the original Word With blanks and right Input alphabet*/
      }

    //getchar();
    }//end of while loop

      if(wrongTry == 0)                                 /*if the player can not guess the whole word in 10 chaces*/
      {
          printf("\n\n\t The Word was %s ",hangmanWord);
          printf("\n\n\t The man is dead!!!");
	      printf("\n\n\t Better luck next time!!!");

	      printf("\n\n If you want to replay press 1 or press 0 to end game: ");
          scanf("%d",&x);

          if(x==0)printf("\n\n\n\t\t\t\t!!!!!!! Game Over !!!!!!!\n\n\n");  //endgame if 0 is entered
          else if(x==1)
          {
              system("cls");   //clear the command then initialize "var" to "order"
              var=order;
          }

      }

      getchar();
  }

    return 0;
}
void showHangman(int choice,char *wrongword,int length)                            //This function show the hangman after each wrong try*/
 {
     int i=0;

     switch(choice)
     {

     case 1:
           system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||  %c | /",'\\');
	printf("\n\t||   %c0/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");
   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;

     case 2:
          system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||  %c | /",'\\');
	printf("\n\t||   %c0/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||    | ");
	printf("\n\t||   / ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");
   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||  %c | /",'\\');
	printf("\n\t||   %c0/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");
   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
     case 4:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||  %c | /",'\\');
	printf("\n\t||   %c0/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");

   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
     case 5:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||  %c | /",'\\');
	printf("\n\t||   %c0/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");

   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
     case 6:
        system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||  %c | ",'\\');
	printf("\n\t||   %c0/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");

   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
     case 7:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    | ");
	printf("\n\t||   %c0/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");

   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
	case 8:
	  system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    | ");
	printf("\n\t||   %c0",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");

   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
     case 9:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    | ");
	printf("\n\t||    0 ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");

   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
	case 10 :
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\n The list of wrong letters : ");

   for (i=0;i<length;i++){
    printf("%c",wrongword[i]);
   }

	break;
      }//end of switch-case
     return;
 }
