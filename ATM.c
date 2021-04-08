#include <stdio.h>
#include <string.h>

int main( void ) {
	
	int input, sel;
	int pinNumber, storedPinNumber = 1234;
	int balAmount = 50000, amount;
	
	HOME:
	printf("\tWelcome to Bank of ANBU\n\n\t   Welcome Anbarasan\n\nEnter your PIN : ");
	scanf("%4d",&pinNumber);
	
	if( pinNumber == storedPinNumber ) {
		printf("\n1.Balance Enquiry\t2.Cash Withdrawl\n3.Cash Deposit\t\t4.Pin Change\n\nSelect your option : ");
		scanf("%1d",&input);
		
		switch(input) {
			
			case 1:
				printf("Your current balance in INR : %d\n\nPress '1' to continue, or anyother key to exit\n",balAmount);
				scanf("%1d",&sel);
				if(sel == 1)
					goto HOME;
				break;
			case 2:
				printf("Please Enter Withdrawl Amount : ");
				scanf("%d",&amount);
				
				if(amount > balAmount)
					printf("You have entered Insuffient Amount\n\n");
				else {
					printf("Collect your cash below\n\nPress '1' to show your current balance, or anyother key to exit\n\n");
					scanf("%1d",&sel);
					balAmount -= amount;
					if(sel == 1)
						printf("Your current balance in INR : %d\n\n",balAmount);
				}
				break;
			case 3:
				printf("Please Enter Deposit Amount, you can deposit below 10000\n\n");
				scanf("%d",&amount);
				if(amount > 10000)
					printf("Deposit limit exceeded\n\n");
				else {
					balAmount += amount;
					printf("You have deposited successfully....\n\nYour Current Balance is %d\n\n",balAmount);
				}
				break;
			case 4:
				printf("Enter your new PIN : ");
				scanf("%4d",&pinNumber);
				if(pinNumber == storedPinNumber) {
					printf("This PIN already used\n\nPlease enter your new PIN : ");
					scanf("%d",&pinNumber);
					if(pinNumber == storedPinNumber) {
						printf("PIN Change limit exceeded\n\n");
						break;
					}
				}
				int rPinNumber;
				printf("Re-enter your new PIN : ");
				scanf("%4d",&rPinNumber);
				if(pinNumber == rPinNumber) {
				    storedPinNumber = pinNumber;
				    printf("You have changed you PIN Number successfully\n\n");
				} else
				    printf("New PIN and Re-entered PIN not matched\nPlease try again later\n\n");
				break;
			default:
				printf("You have selected wrong input\n\n");
				printf("Press '1' to continue, or anyother key to exit\n");
				scanf("%d",&sel);
				if(sel == 1)
					goto HOME;
				break;
		}
		
		printf("Thank you for banking with us\n");
	} else
		printf("You have entered wrong PIN\n");
}