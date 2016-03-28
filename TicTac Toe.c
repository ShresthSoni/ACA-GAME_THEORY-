
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//2=X
//1=O
char board[9];
int check()
{
    int j,k,t1,t2;
    for(j=0;j<3;j++)
    {
        t1=0;
        t2=0;
        for(k=0;k<3;k++)
        {
            if(board[j+3*k]=='1')
                t1++;
            if(board[j+3*k]=='2')
                t2++;
        }
        if(t1==3)
            return 1;
        if(t2==3)
            return -1;
    }


    t1=t2=0;
    for(j=0;j<9;j++)
    {
        if(board[j]=='1')
            t1++;
        if(board[j]=='2')
            t2++;
        if((j+1)%3==0)
        {
            if(t1==3)
                return 1;
            if(t2==3)
                return -1;
            t1=t2=0;
        }
    }
    if(board[0]=='1'&&board[4]=='1'&&board[8]=='1')
        return 1;
    if(board[0]=='2'&&board[4]=='2'&&board[8]=='2')
        return -1;
    if(board[2]=='1'&&board[4]=='1'&&board[6]=='1')
        return 1;
    if(board[2]=='2'&&board[4]=='2'&&board[6]=='2')
        return -1;

    k=0;
    for(j=0;j<9;j++)
    {
        if(board[j]=='0')
            k++;
    }
    if(k==0)
        return 0;

    return 100;
}

int mina(int i1,int pos1)
{
    int j;
    if(check()!=100)
        return check();
    int s1[9];
    for(j=0;j<9;j++)
    {
        s1[j]=1000;
    }
    for(j=0;j<9;j++)
    {
        if(board[j]=='0')
        {
            board[j]='2';
            s1[j]=maxa(i1-1,pos1);
            board[j]='0';
        }
    }
    int mini=999;
    for(j=0;j<9;j++)
    {
        if(s1[j]<mini)
        {
            mini=s1[j];
        }
    }
    return mini;
}

int maxa(int i,int pos)
{
    int j;
    if(check()!=100)
    {
        return check();
    }
    int s[9];
    for(j=0;j<9;j++)
    {
        s[j]=-1000;
    }
    for(j=0;j<9;j++)
    {
        if(board[j]=='0')
        {
            board[j]='1';
            s[j]=mina(i-1,pos);
            board[j]='0';
        }
    }
    int k=0;
    int maxi=-999;
    for(j=0;j<9;j++)
    {
        if(s[j]>maxi)
        {
            maxi=s[j];
            k=j;
        }
    }
    if(i==pos)
    {
        board[k]='1';
    }
    return maxi;

}

int main()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        board[i]='0';
    }
    i=0;
    while(1)
    {
         int n;
        scanf("%d",&n);
        board[n]='2';
        maxa(100,100);
        for(j=0;j<9;j++)
        {
            printf("%c",board[j]);
            if((j+1)%3==0)
                printf("\n");

        }

        if(check()==1)
        {
            printf("You Loose");
            break;
        }
        if(check()==-1)
        {
            printf("I Win");
            break;
        }
        if(check()==0)
            break;

    }
    return 0;
}
