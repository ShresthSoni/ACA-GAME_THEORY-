#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[6][7];

int legit(int j)
{
    int i;
    for(i=5;i>=-1;i--)
    {
        if(board[i][j]==0)
            break;
    }
    return i;
}
int check()
{
    int i,j,k,t1,t2;  //points
    for(i=5;i>=1;i--)
    {
        for(j=0;j<4;j++)
        {
            t1=0;
            t2=0;
            if(board[i][j]!=0)
            {
            for(k=0;k<4;k++)
            {
                if(board[i][j+k]==1)
                    t1++;
                if(board[i][j+k]==2)
                    t2++;
            }
            if(t1==4)
            {
              //  printf("p1\n");
                return 1;
            }
            if(t2==4)
            {
              //  printf("p2\n");
                return -1;
            }
            t2=0;
            t1=0;
            for(k=0;k<4;k++)
            {
                if(board[i-k][j+k]==1)
                    t1++;
                if(board[i-k][j+k]==2)
                    t2++;
            }
            if(t1==4)
            {
              //  printf("p3\n");
                return 1;
            }
            if(t2==4)
            {
              //  printf("p4\n");
                return -1;
            }
            }
        }
        for(j=3;j<7;j++)
        {
            t1=0;
            t2=0;
            if(board[i][j]!=0)
            for(k=0;k<4;k++)
            {
                if(board[i-k][j-k]==1)
                    t1++;
                if(board[i-k][j-k]==2)
                    t2++;
            }
            if(t1==4)
            {
               // printf("p5");
                return 1;
            }
            if(t2==4)
            {
               // printf("p6\n");
                return -1;
            }
            t1=t2=0;
        }
        for(j=0;j<7;j++)
        {
            t1=0;
            t2=0;
            if(board[i][j]!=0)
            for(k=0;k<4;k++)
            {
                if(board[i-k][j]==1)
                    t1++;
                if(board[i-k][j]==2)
                    t2++;
            }
            if(t1==4)
            {
               // printf("p7");
                return 1;
            }
            if(t2==4)
            {
              //  printf("p8\n");
                return -1;
            }
        }
    }
return 0;
}
int eval()
{
    int i,j,t1,t2,l,a,b,c,d,k;
        a=0;
        b=0;
        c=0;
        d=0;
        for(j=0;j<7;j++)
        {
            t1=0;
            t2=0;
            l=legit(j);
            if(l>=0)
                i=l;
            else
                continue;
            for(i=i;i>=0;i--)
            {
            if(board[i][j-1]==1&&j<=3)
                for(k=1;k<4;k++)
                {
                    if(board[i][j-k]==1)
                        t1++;
                    if(board[i][j-k-1]==1)
                        continue;
                    else
                        break;
                }
            if(board[i][j+1]==1&&j<=3)
               for(k=1;k<4;k++)
                {
                    if(board[i][j+k]==1)
                        t2++;
                    if(board[i][j+k+1]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                 a++;
            if((t1+t2)>=2)
                 b++;
            t1=0;
            t2=0;

            if(board[i][j-1]==2&&j<=3)
                for(k=1;k<4;k++)
                {
                    if(board[i][j-k]==2)
                        t1++;
                    if(board[i][j-k-1]==2)
                        continue;
                    else
                        break;
                }
            if(board[i][j+1]==2&&j<=3)
               for(k=1;k<4;k++)
                {
                    if(board[i][j+k]==2)
                        t2++;
                    if(board[i][j+k+1]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                c++;
            if((t1+t2)>=2)
                d++;
            t1=0;
            t2=0;

             if(board[i+1][j-1]==1)
                for(k=1;k<4;k++)
                {
                    if(board[i+k][j-k]==1)
                        t1++;
                    if(board[i+k+1][j-k-1]==1)
                        continue;
                    else
                        break;
                }
            if(board[i-1][j+1]==1)
               for(k=1;k<4;k++)
                {
                    if(board[i-k][j+k]==1)
                        t2++;
                    if(board[i-k-1][j+k+1]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                 a++;
            if((t1+t2)>=2)
                b++;
            t1=0;
            t2=0;

            if(board[i+1][j-1]==2)
                for(k=1;k<4;k++)
                {
                    if(board[i+k][j-k]==2)
                        t1++;
                    if(board[i+k+1][j-k-1]==2)
                        continue;
                    else
                        break;
                }
            if(board[i-1][j+1]==2)
               for(k=1;k<4;k++)
                {
                    if(board[i-k][j+k]==2)
                        t2++;
                    if(board[i-k-1][j+k+1]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                 c++;
            if((t1+t2)>=2)
                 d++;

            t1=0;
            t2=0;

             if(board[i+1][j]==1)
                for(k=1;k<4;k++)
                {
                    if(board[i+k][j]==1)
                        t1++;
                    if(board[i+k+1][j]==1)
                        continue;
                    else
                        break;
                }
            if(board[i-1][j]==1)
               for(k=1;k<4;k++)
                {
                    if(board[i-k][j]==1)
                        t2++;
                    if(board[i-k-1][j]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                a++;
            if((t1+t2)>=2)
                b++;
            t1=0;
            t2=0;

            if(board[i+1][j]==2)
                for(k=1;k<4;k++)
                {
                    if(board[i+k][j]==2)
                        t1++;
                    if(board[i+k+1][j]==2)
                        continue;
                    else
                        break;
                }
            if(board[i-1][j+1]==2)
               for(k=1;k<4;k++)
                {
                    if(board[i-k][j]==2)
                        t2++;
                    if(board[i-k-1][j]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                c++;
            if((t1+t2)>=2)
                d++;

            t1=0;
            t2=0;

             if(board[i+1][j+1]==1)
                for(k=1;k<4;k++)
                {
                    if(board[i+k][j+k]==1)
                        t1++;
                    if(board[i+k+1][j+k+1]==1)
                        continue;
                    else
                        break;
                }
            if(board[i-1][j-1]==1)
               for(k=1;k<4;k++)
                {
                    if(board[i-k][j-k]==1)
                        t2++;
                    if(board[i-k-1][j-k-1]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                a++;
            if((t1+t2)>=2)
                b++;
            t1=0;
            t2=0;

            if(board[i+1][j+1]==2)
                for(k=1;k<4;k++)
                {
                    if(board[i+k][j+k]==2)
                        t1++;
                    if(board[i+k+1][j+k+1]==2)
                        continue;
                    else
                        break;
                }
            if(board[i-1][j+1]==2)
               for(k=1;k<4;k++)
                {
                    if(board[i-k][j-k]==2)
                        t2++;
                    if(board[i-k-1][j-k-1]==1)
                        continue;
                    else
                        break;
                }
            if((t1+t2)>=3)
                 c++;
            if((t1+t2)>=2)
                 d++;
            t1=0;
            t2=0;
            }

        }

        int sc=100000*a-100000*c+1000*b-1000*d ;
    return sc;
}
int min(int k,int p,int alpha,int beta)
{
    int ev,l;
    ev=check();
    if(ev==1)
        return 10000000;
    if(ev==-1)
        return -10000000;
    if(k==1)
        return eval();

    int i,j,s[7],e[7],e1[7];
    for(j=0;j<7;j++)
    {
        s[j]=1000000;
        l=legit(j);
        if(l>=0)
        i=l;
        else
            continue;
        if(beta>alpha)
        {
        board[i][j]=2;
        s[j]=max(k-1,p,alpha,beta);
        board[i][j]=0;
        }
        if(s[j]<beta)
            beta=s[j];
    }
    return beta;
}
int max(int k,int p,int alpha,int beta)
{
    int i,j,s[7],l,q,r,e[7],e1[7];
    r=0;
    int ev;
    ev=check();
    if(ev==1)
        return 10000000;
    if(ev==-1)
        return -10000000;

    if(k==1)
    {
        return eval();
    }
    for(j=0;j<7;j++)
    {
        s[j]=-1000000;
        l=legit(j);
        if(l>=0)
        i=l;
        else
            continue;

        if(alpha<beta)
        {
        board[i][j]=1;
        s[j]=min(k-1,p,alpha,beta);
        board[i][j]=0;
        }
        if(s[j]>alpha)
        {
        alpha=s[j];
        q=j;
        r=l;
        }
    }

        if(k==p)
        {
//          i=legit(q);
            board[r][q]=1;

            /*for(j=0;j<7;j++)
            {
                printf("%d\n",s[j]);
            }*/
            return q;
        }

        return alpha;
}
int main()
{
    int i,j,t,q;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            board[i][j]=0;
        }
    }
  /*  for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
    //printf("%d",check());
    q= max(7,7);
    for(i=0;i<6;i++)
        {
            for(j=0;j<7;j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }*/
    while(1)
    {


        clock_t start, end;
        start= clock();

        q=max(11,11,-1000000,1000000);

        for(i=0;i<6;i++)
        {
            for(j=0;j<7;j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
        end=clock();
        double ctu;
        ctu= ((double)(end-start))/CLOCKS_PER_SEC ;
        printf("%f\n",ctu);
         int n;
        scanf("%d",&n);
        i=legit(n);
        board[i][n]=2;





        t=check();
        if(t==1)
        {
            printf("you loose %d",t);
            break;
        }
        if(t==-1)
        {
            printf("you win");
            break;
        }
    }
    return 0;
}
