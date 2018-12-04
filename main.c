#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <locale.h>

//  Created by Yusuf Erman ERGÖZ on November 2015.
//  All rights reserved.

struct snakes
{
    int x,y;
};

int len=4;
int score=0;
int col=20,row=10;
char map[20][40];

int done_or_continue(struct snakes snake[])
{
    int i,k1=0,k2=0;
    if(snake[0].x==0||snake[0].x==19||snake[0].y==0||snake[0].y==39)
    {
        k1=1;
    }
    for(i=1; i<len; i++)
    {
        if(snake[0].x==snake[i].x&&snake[0].y==snake[i].y)
        {
            k2=1;
            break;
        }
    }
    if(k1==1||k2==1) return 1;
    else return 0;
}

void feeding()
{
    srand(time(NULL));
    row=rand()%18+1;
    col=rand()%38+1;
}
void food(char dizi[20][40],struct snakes snake[])
{
    if(snake[len-1].x==row&&snake[len-1].y==col)
    {
        snake[len].x=row;
        snake[len].y=col;
        len++;
        score=score+10;
        feeding();
        printf("\a");
    }
}
void wall(char dizi[20][40])
{
    int i,j;
    for(i=0; i<20; i++)
    {
        if(i==0||i==19)
        {
            for(j=0; j<40; j++)
            {
                dizi[i][j]='=';
            }
        }
        else
        {
            dizi[i][0]='|';
            for(j=1; j<39; j++)
            {
                dizi[i][j]=' ';
            }
            dizi[i][39]='|';
        }
    }
    map[row][col]='x';
}
void draw(char dizi[20][40])
{
    system("CLS");
    printf("Score: %d\n",score);

    int i,j;
    for(i=0; i<20; i++)
    {
        for(j=0; j<40; j++)
        {
            printf("%c",dizi[i][j]);
        }
        printf("\n");
    }
}
void start(struct snakes age[])
{
    age[0].x=1;
    age[0].y=4;
    age[1].x=1;
    age[1].y=3;
    age[2].x=1;
    age[2].y=2;
    age[3].x=1;
    age[3].y=1;
}
void snakes (char dizi[20][40],struct snakes age[])
{
    food(map,age);
    int i;

    for(i=0; i<len; i++)
    {
        dizi[age[i].x][age[i].y]='*';
    }
}
void rightt(struct snakes snake[],int lenght)
{
    int i;
    for(i=lenght-1; i>0; i--)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }
    snake[0].y++;
}
void leftt(struct snakes snake[],int lenght)
{
    int i;
    for(i=lenght-1; i>0; i--)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }
    snake[0].y--;
}
void upp(struct snakes snake[],int lenght)
{
    int i;
    for(i=lenght-1; i>0; i--)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }
    snake[0].x--;
}
void downn(struct snakes snake[],int lenght)
{
    int i;
    for(i=lenght-1; i>0; i--)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }
    snake[0].x++;
}

int main()
{
    printf("\n\n\t\t\t  WELCOME TO SNAKE GAME!\n");
    printf("\n\n\n\n\n\n");
    printf("\t\tUse w,a,s,d keys for direction of the snake");
    printf("\n\n\n\n\n\n");

    //setlocale(LC_ALL,"Turkish");
    //printf(" Yusuf Erman ERGÖZ\n\n");

    system("pause");
    system("cls");

    char right='d';
    char left='a';
    char up='w';
    char down='s';
    char direction;
    long i;
    int kontrol=0;
    struct snakes snake[100];

    wall(map);
    start(snake);
    snakes(map,snake);
    draw(map);
    
    while(1)
    {
        direction=getch();
        i=0;

        if(direction==right)
        {
            while(i<100000)
            {
                if(i%2000==0)
                {
                    if(done_or_continue(snake))
                    {
                        draw(map);
                        kontrol=1;
                        break;
                    }
                    rightt(snake,len);
                    wall(map);
                    snakes(map,snake);
                    draw(map);
                }
                i++;
                if(kbhit()) break;
            }
        }
        else if(direction==left)
        {
            while(i<100000)
            {
                if(i%2000==0)
                {
                    if(done_or_continue(snake))
                    {
                        draw(map);
                        kontrol=1;
                        break;
                    }
                    leftt(snake,len);
                    wall(map);
                    snakes(map,snake);
                    draw(map);
                }
                i++;
                if(kbhit()) break;
            }
        }
        else if(direction==up)
        {
            while(i<100000)
            {
                if(i%2000==0)
                {
                    if(done_or_continue(snake))
                    {
                        draw(map);
                        kontrol=1;
                        break;
                    }
                    upp(snake,len);
                    wall(map);
                    snakes(map,snake);
                    draw(map);
                }
                i++;
                
                if(kbhit()) break;
            }
        }
        else if(direction==down)
        {
            while(i<100000)
            {
                if(i%2000==0)
                {
                    if(done_or_continue(snake))
                    {
                        kontrol=1;
                        draw(map);
                        kontrol=1;
                        break;
                    }
                    downn(snake,len);
                    wall(map);
                    snakes(map,snake);
                    draw(map);
                }
                i++;

                if(kbhit()) break;
            }
        }
        if(kontrol==1) 
            break;
    }
}
