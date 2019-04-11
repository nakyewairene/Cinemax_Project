
/*
GROUP MEMEBERS 

SENYANGE RICHARD	16/U/1102
NAKYEWA IRENE     	16/U/851
NINSIIMA SHEILLA	16/U/964
ARIHO IGNATIUS	        16/U/1811 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

//Variables
int selection,op,row,column,row1,column1;
	char seat[16][20];
	char category[8],action[8];
	char row_c,sel,seat_status,row_c1;

int a,b,i,j;
 int rseat=0;
 int tickets=0;
	int seat_num;


	int seat_num_per_cat=0;
    enum rows { A = 1,B, C,D, E,F,G, H,I,J,K,L,M,N,O,P };
   /* A = 1, C= 3, etc. */
   //returns number of seats available per category
   int seat_avail_per_categry(category){
       int twin_no=0;
   if(strcmp(category,"twin")==0){
    for(row=1;row<=2;row++){
        for(column=5;column<=15;column++){
            if(seat[row][column]=='*'){
                twin_no+=1;
            }
        }
    }
    return twin_no;
   }
   else if(strcmp(category,"vip")==0){
        int vvip_no=0;
    for(row=7;row<=12;row++){
        for(column=1;column<=20;column++){
            if(seat[row][column]=='*'){
                vvip_no+=1;
            }
        }
    }
    return vvip_no;
   }
   else if(strcmp(category,"economy")==0){
       int econ_no=0;
        for(row=13;row<=16;row++){
        for(column=1;column<=20;column++){
            if(seat[row][column]=='*'){
                econ_no+=1;
            }
        }

    }
    return econ_no;

   }else{
      for(row=1;row<=6;row++){

        for(column=1;column<=20;column++){
            if(!twin(row,column)){
               if(seat[row][column]=='*'){
                seat_num_per_cat+=1;
            }
            }

        }
    }
    return seat_num_per_cat;

   }
   }


    void reserve_seat(row,column){

        if(seat[row][column]=='*'){
        seat[row][column]='O';
}else {
SetColor(12);
    printf("\n ticket not available\n");
    ClearColor();
}


    }
//This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
     WORD wColor;
     //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearColor(){
    SetColor(15);
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     //Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     //This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     //A return value... indicating how many chars were written
     //   not used but we need to capture this since it will be
     //   written anyway (passing NULL causes an access violation).
     DWORD count;

     //This is a structure containing all of the console info
     // it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          //This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

//prints seats available basing on category and number
void category_seats(category){
if(strcmp(category,"economy")==0){
    for(row_c='M',row=M;row_c<='P',row<=P;row_c++,row++){
         //printf("%c",row_c);
        for(column=1;column<=20;column++){
            if(seat[row][column]=='*'){

                printf("\t%c %d  ,%d  \n",row_c,column,ticket_price(category));

            }

        }

    }
}
else if(strcmp(category,"twin")==0){

 for(row_c='A',row=A;row_c<='B',row<=B;row_c++,row++){
         //printf("%c",row_c);
        for(column=5;column<=15;column++){
            if(seat[row][column]=='*'){

                printf("\t%c %d  ,%d  \n",row_c,column,ticket_price(category));

            }

        }

    }

}
else if(strcmp(category,"vip")==0){
     for(row_c='G',row=G;row_c<='L',row<=L;row_c++,row++){
         //printf("%c",row_c);
        for(column=1;column<=20;column++){
            if(seat[row][column]=='*'){

                printf("\t%c %d  ,%d  \n",row_c,column,ticket_price(category));

            }

        }

    }
}else if(strcmp(category,"vvip")==0){

 for(row_c='A',row=A;row_c<='F',row<=F;row_c++,row++){
         //excluding twin  columns and rows

               for(column=1;column<=20;column++){
            if(seat[row][column]=='*'){
                   if(!twin(row,column)){
                printf("\t%c %d  ,%d  \n",row_c,column,ticket_price(category));
                   }
            }

        }



    }
}else{
printf("None\nPlease Try Again....");

}



}

    //default theater state
   void chart_seat_store(){
for( i=1,row_c='A';row_c<='P',i<=16;row_c,i++){

    for( j=1;j<=20;j++){
       seat[i][j]='*';
    }
}
}
//updated chart
void seat_arrangement(){
    int i,j;
    printf("       ");
    SetColor(12);
printf("1   2    3    4    5    6    7    8    9   10    11   12  13   14   15   16    17  18   19   20 ");


printf("\n______________________________________________________________________________________________________\n");
ClearColor();
for(i=A,row_c='A';row_c<='P',i<=P;i++,row_c++){
        SetColor(12);
 printf(" %c  ",row_c);
        ClearColor();
    for(j=1;j<=20;j++){
            SetColor(15);
       printf("  %c  ",seat[i][j]);
//sales+=total_sales(i,j);
ClearColor();
    }
   printf("\n______________________________________________________________________________________________________\n");

}
SetColor(12);
printf("Total seats remaining=%d\n\n",seats_remaining());
ClearColor();
}

    //sales
    int total_sales(){
int sales=0;
    //storing default state of seats in theater
	for( row=1;row<=16;row++){

		for(column=1;column<=20;column++){

		if(twin(row,column)==1&&seat[row][column]=='#'){
                int twin_sales=0;
           twin_sales+=(ticket_price(row,column)*2);
            sales+=twin_sales;

		}
		if(!twin(row,column)&&seat[row][column]=='#'){
		    int other_sales=0;
		other_sales+=(ticket_price(row,column)*1);
		sales+=other_sales;

		}


		}
	}
   return sales;

    }
           //price per row
int ticket_price(int row,int column){
       FILE *myFile;

myFile = fopen("prices.txt", "r");

//read file into array

int price[4];
int i,price_cat;

if (myFile == NULL)

{
    SetColor(12);
printf("Error Reading File\n");
ClearColor();
exit (0);

}

for (i = 1; i <= 4; i++)

{

fscanf(myFile, "%d,", &price[i] );

}//economy
 if( row==13|row==14|row==15|row==16){
            price_cat=price[4];
    //return price_cat;
        }
        // VIP
    else if(row==7|row==8|row==9|row==10|row==11|row==12){
        price_cat=price[3];
   // return price_cat;
}
// vvip
else if(row==3|row==4|row==5|row==6){
    price_cat=price[2];
    //return price_cat;
}
else if(twin(row,column)==1){
    price_cat=price[1];
}
    else{
        price_cat=price[2];
    }
    //printf("%d",price_cat);
return price_cat;
fclose(myFile);

       }
    //check if twin
    int twin(int row,int column){
   if((row<=2)&&(column>4&&column<=15)){
    return 1;
   }else{
   return 0;
   }

    }
//sell seat
void seat_sell(int row,int col){
if(twin(row,column)&&seat[row][column]=='O'|seat[row][column]=='*'){
    seat[row][column]='#';
    seat[row][column+1]='#';
}else if(twin(row,column)&&seat[row][column]=='#'|seat[row][column+1]=='#'){
    seat[row][column+1]='#';
    seat[row][column+2]='#';
}
else if(seat[row][column]=='O'|seat[row][column]=='*'){
seat[row][column]='#';

}else{
    SetColor(12);
printf("\n ticket not available\n");
    ClearColor();
}
}


//seats remaining
    int seats_remaining(){
          int seat_no=0;
    //storing default state of seats in theater
	for( row=1;row<=16;row++){

		for( i=1;i<=20;i++){

		if(seat[row][i]=='*'){
            seat_no+=1;
		}

		}
	}
    return seat_no;

    }

int mapper(char x){
int i;
switch(x){
case 'A':
    i=1;
    return i;
    break;
case 'B':
    i=2;
    return i;
    break;
case 'C':
    i=3;
    return i;
    break;
case 'D':
    i=4;
    return i;
    break;
case 'E':
    i=5;
    return i;
    break;
case 'F':
    i=6;
    return i;
    break;
case 'G':
    i=7;
    return i;
    break;
case 'H':
    i=8;
    return i;
    break;
case 'I':
    i=9;
    return i;
    break;
case 'J':
    i=10;
    return i;
    break;
case 'K':
    i=11;
    return i;
    break;
case 'L':
    i=12;
    return i;
    break;
case 'M':
    i=13;
    return i;
    break;
case 'N':
    i=14;
    return i;
    break;
case 'O':
    i=15;
    return i;
    break;
case 'P':
    i=16;
    return i;
    break;
default:
printf("\ninvalid row...\n");

}


}
int row_reserved(int row,int column){
    for(row; ;){
        for(column;column<=20;column++){
                if(seat[row][column]=='O'){
                   return 1;
                }else{
                return 0;
                }


        }
    }
}

        //exit function
void exit_(){
        printf("\n\n\tCINEMAX THEATER EXITED........\n\n");
        exit(1);
        return;
        }


 int main(void){
     SetConsoleTitle("CINEMAX THEATER");
     //ClearConsoleToColors(15, 1);
     chart_seat_store();
        menu:  printf("\n");
       SetColor(12);
        printf("\t CINEMAX THEATER\n"
                  "\t=======================\n"
                  "\t  MENU\n"
                  "\t=======================\n"
                  "\t1.ASSIGN SEAT\n"
                  "\t2.PAYMENT (for reserved seat)\n"
                  "\t3.RESET\n"
                  "\t4.EXIT\n\n");
                  ClearColor();
                  SetColor(15);

        printf("\tEnter your selection : ");
        scanf("%d",&selection);
        printf("\n");
        ClearColor();
        switch(selection){

    case 1:
       //chart_seat_store();
       seat_arrangement();
       printf("Total Sales=%d\n",total_sales());
       SetColor(15);
       printf("Number of seats Required: ");
       scanf("%d",&seat_num);

       printf("Desired Seat Category (twin, vvip, vip or economy):  ");
       scanf("%s",&category);
       ClearColor();
       SetColor(12);
       //if seats are available per category
       printf("Available seats:");
       ClearColor();
       if(seat_num<=seat_avail_per_categry(category)){
            //display seats
                category_seats(category);

                printf("\n");
another_seat:    printf("Choose Seat: \n");
 rscan:          printf("Row : ");
       scanf(" %c",&row_c);
       printf("Column number: ");
       scanf("%d",&column);
       //validating rows and columns
       if((strcmp(category,"twin")==0)){
       	if(mapper(row_c)>0&&mapper(row_c)<=2&&column>4&&column<16){
       		  goto ctn;
       	}else{
       		printf("\nselect row between A- B....\n");
       		goto rscan;
       	}

           }
		   else if((strcmp(category,"vip")==0)){
		   	if(mapper(row_c)>6&&mapper(row_c)<13){
		   		 goto ctn;
		   	}else{
		   		printf("\nselect row between G- L...\n");
		   		goto rscan;
		   	}

           }else if((strcmp(category,"vvip")==0)){
           	if(!twin(mapper(row_c),column)&&mapper(row_c)>0&&mapper(row_c)<7){
           		 goto ctn;
           	}else{
           		printf("\nselect row between A- F...\n");
           		goto rscan;
           	}

           }else if((strcmp(category,"economy")==0)){
           	if(mapper(row_c)>12&&mapper(row_c)<17){
           		 goto ctn;
           	}else{
           		printf("\nselect row between M- P...\n");
           		goto rscan;
           	}

           }else{
           printf("\nwrong Selection.....\n");
           goto rscan;
           }
     ctn:  printf("\nAction(Reserve(x) and Cancle(q): ");
       scanf(" %c",&sel);
       //check if all required seats are reserved
       if(sel=='x'){

                //check if seat is twin during reservation
                if(strcmp(category,"twin")==0){
                              if(seat[mapper(row_c)][column]=='*'&&seat[mapper(row_c)][column+1]=='*'){
                                reserve_seat(mapper(row_c),column);
                                reserve_seat(mapper(row_c),(column+1));
                              }else if(row_reserved(mapper(row_c),column)){
                                reserve_seat((mapper(row_c)+1),column);
                                reserve_seat((mapper(row_c)+1),(column+1));
                              }

                              else{

                                    reserve_seat(mapper(row_c),(column+1));
                                reserve_seat((mapper(row_c)),(column+2));
                              }


                }else{

                reserve_seat(mapper(row_c),column);
                }

        rseat++;
        if(rseat<seat_num){
              goto another_seat;
        }


       }else{
       goto chart;
       }
       system("cls");
       //print new arrangement after reserving seats
      chart: seat_arrangement();
       printf("Total Sales=%d\n",total_sales(mapper(row_c),column));
       printf("\ncontinue to menu.........\n");
       system("PAUSE");
       printf("\nContinuing to menu.................\n");
       system("cls");
       goto menu;

       }else{

       printf("none\n Please Try again.");
       }
        break;
    case 2:

        seat_arrangement();
        SetColor(15);
        printf("Total Sales=%d\n",total_sales());
      R:   printf("Enter seat number paid:\n");
         //sell seat
        printf("Row : ");
        scanf(" %c",&row_c);
        printf("Column number: ");
        scanf("%d",&column);
       seat_sell(mapper(row_c),column);
       tickets+=1;
       ClearColor();
        system("cls");
    seat_arrangement();
       SetColor(15);
    printf("\nwould you like to sell another ticket?(y/n): ");
    ClearColor();
    scanf(" %c",&sel);
        while(sel!='n'){
            goto R;
        }
       SetColor(12);
        printf("\nTotal tickets sold=%d \n",tickets);
        ClearColor();
        system("PAUSE");
        system("cls");
    seat_arrangement();
    SetColor(12);
        printf("Total Sales=%d\n",total_sales());
        ClearColor();
        system("PAUSE");
        system("cls");
        goto menu;

        break;

    case 3:
        system("cls");
 printf("\nResetting Options(any key to return to menu):\n1.seat status\n2.seating plan\n");
        scanf(" %d",&selection);
        switch(selection){

    case 1:
        seat_arrangement();
       printf("Total Sales=%d\n",total_sales());
        printf("\nTotal tickets sold=%d \n",tickets);
        printf("Enter seat details: \nRow : ");
        scanf(" %c",&row_c);
        printf("Column number: ");
        scanf("%d",&column);
      if(seat[mapper(row_c)][column]=='O'){
            //changing status to default
        seat[mapper(row_c)][column]='*';

        system("PAUSE");
         system("cls");

          seat_arrangement();
       printf("Total Sales=%d\n",total_sales());
        printf("\nTotal tickets sold=%d \n",tickets);

        printf("\nOperation successfully done......\n");
      }else if(seat[mapper(row_c)][column]=='#'){
      printf("\nSeat Already sold.....\n");
      }else{
      printf("\nseat not reserved......\n");
      }
system("PAUSE");
system("cls");
        goto menu;
        break;
    case 2:
           //display updates
            system("cls");
            seat_arrangement();
           printf("Total Sales=%d\n",total_sales());
            printf("\nTotal tickets sold=%d \n",tickets);
        //change of seats by customer
        printf("\nReset seating plan(Client position).......\n");
        printf("\ncustomer Initial seat details: \n");
        printf("Row : ");
        scanf(" %c",&row_c);
        printf("Column number: ");
        scanf("%d",&column);
        printf("\nNew Desired seat details: \n");
        printf("Row : ");
        scanf(" %c",&row_c1);
        printf("Column number: ");
        scanf("%d",&column1);
        if(!twin(mapper(row_c),column)&&(mapper(row_c)==mapper(row_c1))&&(seat[mapper(row_c)][column]=='#'))
        {
            seat[mapper(row_c)][column1]='#';
            //shift position to next column in the same category or same row and set initial position to available
            seat[mapper(row_c)][column]='*';
            SetColor(12);
               printf("\nOperation successfully done.......\n");
               ClearColor();
               system("PAUSE");
            //display updates
            system("cls");
            seat_arrangement();
           SetColor(12);
           printf("Total Sales=%d\n",total_sales());
            printf("\nTotal tickets sold=%d \n",tickets);
            ClearColor();

        }else if(twin(mapper(row_c),column)&&(mapper(row_c)<=mapper(row_c1))&&seat[mapper(row_c)][column]=='#'){

        seat[mapper(row_c1)][column1]='#';
        seat[mapper(row_c1)][column1+1]='#';
        //make initial available
        seat[mapper(row_c)][column]='*';
         seat[mapper(row_c)][column+1]='*';
         SetColor(12);
         printf("\nOperation successfully done.......\n");
         ClearColor();
            //display updates
            system("PAUSE");
            system("cls");
            seat_arrangement();
            SetColor(12);
           printf("Total Sales=%d\n",total_sales());
            printf("\nTotal tickets sold=%d \n",tickets);
            ClearColor();
            goto menu;

        }

        break;
    default :
        goto menu;
        break;

        }
        break;
    case 4:
        exit_();
        break;
    default:
        break;
        }

system("PAUSE");
        return 0;
}






