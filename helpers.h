#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printMenu() {
	char input = 0;
	printf("\n\n\n");
printf("**************************************************************************************\n");
printf("*                                                                                    *\n");
printf("  *                   ---------------------------------------                      *  \n");
printf("    *                         WELCOME TO CUAL AIRLINES                           *    \n");                                               
printf("  *                   ---------------------------------------                      *  \n");
printf("*                                                                                    *\n");
printf("**************************************************************************************\n");

	printf("\n\n\n");
	printf("\n1)RESARVATION A TICKET\n2)CHECKING TICKET\n3)CANCELLING RESARVATION\n");
	printf("Please select your choice:");
	while(1) {
		if(scanf("%c",&input) == 1) {
			if(input == '1') {
				BuyTicket();
			} else if(input == '2') {
				checkTicket();
			} else if(input == '3') {
				deleteTicket();
			}
			else if(input != '\n') {
				printf("Unknown command '%c'! Ignoring...\n",input);
			}
		} else {
			printf("Invalid input! Ignoring...\n");
		}
	}
}
void deleteTicket(){
	if (remove("bilet.txt") == 0) 
      printf("YOUR RESERVATION WAS CANCELLED"); 
   else
      printf("Please do a reservation first."); 
      sleep(1);
      system("cls");
      printMenu();
  
}
void checkTicket(){
	    
		FILE *fPointer;
		fPointer=fopen("bilet.txt","r");
		char singleLine[150];
	    
	    if(fPointer == NULL)
   			{
      			printf("You have no reservation now you are going to main menu!!!\n");   
      			sleep(1);
      			system("cls");
	  			printMenu();      
   			}else{
   				while(!feof(fPointer)){
   					fgets(singleLine,150,fPointer);
   					puts(singleLine);
				   }
			}	
			fclose(fPointer);
			printf("\n You are going to main menu in 3 second. \n");
			sleep(3);
			system("cls");
			printMenu();
}

void BuyTicket() {
	char inputA = 0;
	int isRoundTrip = 0;
	printf("\n1)One way\n2)Round trip\n3)Return menu\n");
	printf("Please select your choice:");
	while(1) {
		if(scanf("%c",&inputA) == 1) {
			if(inputA == '1') {
				int passangerNumber =0;
				printf("How many ticket(s) will you buy?\n");
				scanf("%d",&passangerNumber);
				passangerCreator(passangerNumber);	
			} else if(inputA == '2') {
				isRoundTrip = 1;
				int passangerNumber =0;
				printf("How many ticket(s) will you buy?\n");
				scanf("%d",&passangerNumber);
				passangerCreator(passangerNumber,isRoundTrip);
				
			} else if(inputA == '3') {
				printMenu();
			}
			else if(inputA != '\n') {
				printf("Unknown command '%c'! Ignoring...\n",inputA);
			} 
		} else {
			printf("Invalid input! Ignoring...\n");
		}
	}
	
}

void passangerCreator (int passangerNumber,int isRoundTrip){
	int yesRoundTrip = isRoundTrip;
	int x = 0;
	FILE *fptr;
	typedef struct{
        			char* firstName;
        			char* lastName;
        			char   genderCode;
        			int day;
        			int month;
        			int year;	
    			}PASSANGER;
    			fptr = fopen("bilet.txt","w");
    			PASSANGER* passangers =malloc(passangerNumber * sizeof *passangers);
    			for(x=0;x<passangerNumber;x++){
    				printf("%d . passangers name :",x);
    				passangers[x].firstName=(char *)malloc(sizeof(char));
        			scanf("%s",&passangers[x].firstName);
        			printf("%d . passangers lastname :",x);
        			passangers[x].lastName=(char *)malloc(sizeof(char*));
        			scanf("%s",&passangers[x].lastName);
        			printf("%d . passangers gendercode :",x);
        			scanf("%s",&passangers[x].genderCode);
        			printf("%d . passangers day :",x);
        			scanf("%d",&passangers[x].day);
        			printf("%d . passangers mount :",x);
        			scanf("%d",&passangers[x].month);
        			printf("%d . passangers year :",x);
        			scanf("%d",&passangers[x].year);
        			fprintf(fptr, "\nName = %s\n Last Name =%s \n Gender Code = %s \n Tarih = %d-%d-%d \n",&passangers[x].firstName,&passangers[x].lastName,&passangers[x].genderCode,passangers[x].day,
					passangers[x].month,passangers[x].year);
				}
				    fclose(fptr);
				for (x = 0; x < passangerNumber; x++){
					printf("first name: %s, surname: %s, day: %d, month: %d, year: %d\n,gendercode: %s\n"
					,&passangers[x].firstName,&passangers[x].lastName,passangers[x].day,passangers[x].month,passangers[x].year,&passangers[x].genderCode);
				
				}
				Rota(passangerNumber , yesRoundTrip);			
}
void Rota(int passangerNumber,int isRoundTrip)
{
	FILE *fptr;
	int toBursa =16;
	int fromBursa = 10;
	int toIzmir =24;
	int fromIzmir = 36;
	char a  = 0;  
	int b = 0;
	int y;   
	int c = 0;
	int arr[100];
	srand(time(NULL));
	printf("Select your flight will you buy or press 5 return to main menu.");-
	printf("\nFlight                    Price   Seating Capacity    Available Seats\n");
    printf("1. Ýstanbul to  Bursa       160 TL        120                    %d\n",toBursa);
    printf("2. Ýstanbul to  Ankara      287 TL        190                    0\n");
    printf("3. Ýstanbul To  Ýzmir       200 TL        150                    %d\n",toIzmir);
    sleep(1);
	while(1) {
		scanf("%c",&a);
			if(a == '1' && isRoundTrip == 1) {
				toBursa = toBursa-passangerNumber;
				printf("You reserved %d ticket for Bursa. Remaining ticket for Bursa = %d\Price = %d TL ",passangerNumber,toBursa,(160*passangerNumber));
				fptr = fopen("bilet.txt", "a");
				fputs("\n from Istanbul to = Bursa", fptr);
				for(y=0;y<passangerNumber;y++){
					arr[y]=rand()%100+1;
					fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				sleep(1);
				printf("Select your  returning flight will you buy:");
				printf("\nFlight                    Price   Seating Capacity    Available Seats\n");
    			printf("1. Bursa to  Ýstanbul       180 TL        120                    %d\n",fromBursa);
    			printf("2. Bursa to  Ankara     	287 TL        190                    0\n");
    			printf("3. Bursa To  Ýzmir       	200 TL        150                    %d\n",toIzmir);
    			scanf("%d",&b);
    			sleep(1);
    			switch (b){
    				case 1:
    					printf("You reserved %d ticket for Istanbul.Remaining ticket for Istanbul = %d\Ücret = %d TL\n\n",passangerNumber,fromBursa,(160*passangerNumber));
    					fputs("\n from Bursa to Ýstanbul", fptr);
						for(y=0;y<passangerNumber;y++){
				             	arr[y]=rand()%100+1;
				     	fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				
						fclose(fptr);
						printf("CONGRATULATIONS!! You have your reservation successfully.\n");
						sleep(3);
						system("cls");
						printMenu();
    					break;
    				case 2:
    					printf("Sorry there is no seat to place.You are going to main menu in a second.\n");
    					sleep(1);
    					system("cls");
    					printMenu();
    					break;
    				case 3:
    					printf("You reserved &d ticket for Izmir.Remaining ticket for Izmir = %d\\Price = %d TL",passangerNumber,fromBursa,(160*passangerNumber));
    					fputs("\n from Bursa to Ýzmir", fptr);
						for(y=0;y<passangerNumber;y++){
					             arr[y]=rand()%100+1;
				    	fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				
						fclose(fptr);
						printf("CONGRATULATIONS!! You have your reservation successfully.\n");
						sleep(3);
						system("cls");
						printMenu();
    					break;
				}

					
			}else if(a == '1' && isRoundTrip != 1){
				toBursa = toBursa-passangerNumber;
				printf("You reserved %d ticket for Bursa. Remaining ticket for Bursa = %d\\Price = %d TL ",passangerNumber,toBursa,(160*passangerNumber));
				fptr = fopen("bilet.txt", "a");
				fputs("\n from Istanbul to = Bursaya", fptr);
				for(y=0;y<passangerNumber;y++){
					arr[y]=rand()%100+1;
				fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				fclose(fptr);
				printf("CONGRATULATIONS!! You have your reservation successfully.\n");
				sleep(3);
				system("cls");
				printMenu();
			}
			else if(a == '2') {
				printf("There is no seat to place You are going to flight table in a sec...");
				sleep(3);
				system("cls");
				Rota(passangerNumber,isRoundTrip);
			}
			else if(a == '3' && isRoundTrip!=1) {
		      toIzmir = toIzmir-passangerNumber;      
			printf("You reserved %d ticket for Izmýr. there are %d tickets remaining. Price=%d TL\n",passangerNumber,toIzmir,(200*passangerNumber));	
					fptr = fopen("bilet.txt", "a");
				fputs("\n from Ýstanbul to = Izmir", fptr);
				for(y=0;y<passangerNumber;y++){
					arr[y]=rand()%100+1;
				fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				fclose(fptr);
				printf("CONGRATULATIONS!! You have your reservation successfully.\n");
				printf("You are going to main menu in 3 second...\n");
				sleep(3);
				printMenu();
			}
			else if(a == '3' && isRoundTrip == 1){
			toIzmir = toIzmir-passangerNumber;
			printf("You reserved %d ticket for Izmir. Remaining ticket for Izmir = %d\\Price = %d TL ",passangerNumber,toBursa,(160*passangerNumber));
				fptr = fopen("bilet.txt", "a");
				fputs("\n from Istanbul to = Bursa", fptr);
				for(y=0;y<passangerNumber;y++){
					arr[y]=rand()%100+1;
				fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				
				
				sleep(1);
				
				printf("Select your  returning flight will you buy.");
				printf("\nFlight                    Price   Seating Capacity    Available Seats\n");
    			printf("1. Izmir to  Ýstanbul       180 TL        120                    %d\n",fromBursa);
    			printf("2. Izmir to  Ankara     	287 TL        190                    0\n");
    			printf("3. Izmir To  Bursa       	200 TL        150                    %d\n",toIzmir);
    			scanf("%d",&c);
    			sleep(1);
    			
    			switch (c){
    				case 1:
    					printf("You reserved %d ticket for Istanbul.Remaining ticket for Istanbul = %d\\Price = %d TL\n\n",passangerNumber,fromIzmir,(180*passangerNumber));
    					fputs("\n from Izmir to Ýstanbul", fptr);
						for(y=0;y<passangerNumber;y++){
					         arr[y]=rand()%100+1;
					    fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				     	fclose(fptr);
						printf("CONGRATULATIONS!! You have your reservation successfully.\n");
						sleep(3);
						system("cls");
						printMenu();
    					break;
    				case 2:
    					printf("Sorry there is no seat to place.You are going to main menu in a second.\n");
    					sleep(1);
    					system("cls");
    					printMenu();
    					break;
    				case 3:
    					printf("You reserved %d ticket for 	Bursa.Remaining ticket for Bursa = %d\\Price = %d TL",passangerNumber,fromIzmir,(200*passangerNumber));
    					fputs("\n from Izmir to Bursa", fptr);
                       	for(y=0;y<passangerNumber;y++){
					        arr[y]=rand()%100+1;
					    fprintf(fptr,"\n Your seat number is:%d",arr[y]);
				}
				     	fclose(fptr);
						printf("CONGRATULATIONS!! You have your reservation successfully.\n");
						sleep(3);
						system("cls");
						printMenu();
    					break;
				
		}
	}
			
			else if(a == '5') {
				printf("You are going to main menu in 3 second...\n");
				sleep(3);
				system("cls");
				printMenu();
			}
			else if(a != '\n') {
				printf("Unknown command '%c'! Please use proper commands!!\n",&a);
			}
}
}


