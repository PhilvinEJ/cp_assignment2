#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CONTINUE 1
#define WON 2
#define LOST 3

int main()
{

    int myPoint;
    int gameStatus;
    int sum, dice1, dice2;
    int bankBalance = 1000;
    int betAmount, cont;
    do
    {
        do
        {
          printf("Please Enter Your Bet:\n'Note Bet Should Be Less Than %d\n",bankBalance);
          scanf("%d",&betAmount);   
        }while(betAmount < bankBalance);
        srand(time(NULL));
        dice1 = 1 + rand() % 6;
        dice2 = 1 + rand() % 6;
        sum = dice1 + dice2;
        printf("Player rolled %d + %d = %d\n", dice1, dice2, sum);
        switch(sum)
        {
            case 7:
            case 11:
            gameStatus = WON;
            break;
            case 2:
            case 3:
            case 12:
            gameStatus = LOST;
            break;
            default:
            gameStatus = CONTINUE;
            myPoint = sum;
            printf("Point is %d\n", myPoint);
            break;
        }
        while(CONTINUE == gameStatus)
        {
            dice1 = 1 + rand() % 6;
            dice2 = 1 + rand() % 6;
            sum = dice1 + dice2;
            printf("Player rolled %d + %d = %d\n", dice1, dice2, sum);
            if(sum == myPoint)
            {
                gameStatus = WON;
            }
            else
            {
                if(7 == sum)
                {
                    gameStatus = LOST;
                }
            }
        }
        if(WON == gameStatus)
        {
            bankBalance = bankBalance + betAmount;
            printf("Player wins.\nThe Balance Amount Is :%d\n",bankBalance);
        }
        else
        {
            bankBalance = bankBalance - betAmount;
            printf("Player losses.\nThe Balance Amount Is :%d\n",bankBalance);
        }
        if(bankBalance = 0)
        {
            printf("Sorry.You Are Busted!\n");
        }
        if(bankBalance < 100)
        {
            printf("Oh, you're going for broke, huh?\n");
        }
        if(betAmount < 100)
        {
            printf("Aw cmon, take a chance!\n");
        }
        if(bankBalance > 1500)
        {
            printf("You're up big.\n");
        }
        if(bankBalance > 2000)
        {
            printf("Now's the time to cash in your chips!\n");
        }
        printf("Do You Want To Continue.\n1.Yes\t2.No.\n");
        scanf("%d",&cont);
    }while(cont == 1 && bankBalance >= 0);
    return 0;
}
