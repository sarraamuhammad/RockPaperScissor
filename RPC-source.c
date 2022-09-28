#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
void win_func(int robo,int hum)
{
    if(robo>hum) //Lose case
    {
        printf("\nTotal Points:\nRobot %d\nYou %d\n______________Sorry, You lost!______________",robo,hum);
    }
    else if(hum>robo) //Win case
    {
        printf("\nTotal Points:\nYou %d\nRobot %d\n______________Congatulations! You won!______________",hum,robo);
    }
    else if(hum==robo) //Draw case
    {
        printf("\nTotal Points:\nYou %d\nRobot %d\n______________Match Draw!______________",hum,robo);
    }
}
int main()
{
    int robot,num,i,tp_human,tp_robot,repeat;
    char human;
    printf("\n\n______________________________Welcome to the Rock-Paper-Scissor Game!______________________________\n\n");
    start:
    tp_human=0;
    tp_robot=0;
    printf("Please enter the number of games you would like to play:");
    scanf("%d",&num);
    fflush(stdin);
    printf("\n______________________________Lets start!______________________________\n");
    printf("\nPlease note that in case of invalid inputs, a Penalty will be implemented \n\n");

    for(i=0; i<num; i++)
    {
        fflush(stdin);
        printf("\nChoose your option-\nr. Rock\np. Paper\ns. Scissor\n\n");
        scanf("%c",&human);
        srand(time(NULL));
        robot=((rand()%3)+1);
        if(robot==1)
        {
            printf("Robot chose Rock\n");
        }
        else if(robot==2)
        {
            printf("Robot chose Paper\n");
        }
        else if(robot==3)
        {
            printf("Robot chose Scissor\n");
        }

        if((human=='r'&&robot==1)||(human=='p'&&robot==2)||(human=='s'&&robot==3))
        {
            printf("\nDraw!!!");
        }
            else if(human=='r'&&robot==2)
            {
                printf("\nRobot Got 1 point");
                tp_robot=tp_robot+1;
            }
            else if(human=='r'&&robot==3)
            {
                printf("\nYou Got 1 point");
                tp_human=tp_human+1;
            }
            else if(human=='p'&&robot==1)
            {
                printf("\nYou Got 1 point");
                tp_human=tp_human+1;
            }
            else if(human=='p'&&robot==3)
            {
                printf("\nRobot Got 1 point");
                tp_robot=tp_robot+1;
            }
            else if(human=='s'&&robot==1)
            {
                printf("\nRobot Got 1 point");
                tp_robot=tp_robot+1;
            }
            else if(human=='s'&&robot==2)
            {
                printf("\nYou Got 1 point");
                tp_human=tp_human+1;
            }
            else
            {
            printf("\nInvalid Input!, Penalty will be a draw in this turn");
            }

        printf("\n____________________________________________");
        printf("\n____________________________________________\n");
        sleep(1);
    }

    win_func(tp_robot,tp_human);
    printf("\n\n____________________________________________\n\n");
    sleep(1);
    printf("Would you like to play again?\n1.Yes\nEnter any other key to exit\n");
    scanf("%d",&repeat);

    if(repeat==1)
    {
        goto start;
    }
    else
    {
         printf("Thank You!");
         return 0;
    }
}
