#include<stdio.h>

int a[10][7];
int n;
float cawt=0,ctat=0;

void calculate_tat();
void calculate_wt();

int main()
{
    int tq,time=0,completed=0;
    int i;
    printf("\nEnter Number of Process: ");
    scanf("%d",&n);
    printf("\nEnter Time Quantum : ");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Process id,burst time,arrival time : ");
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
        a[i][6] = a[i][1];
    }
    int done;
    do{
        done = 1;
        for(i=0;i<n;i++)
        {
            if(a[i][6]>0 && a[i][2] <= time)
            {
                done=0;
                if(a[i][6]>tq)
                {
                    time+=tq;
                    a[i][6]-=tq;
                }
                else
                {
                    time+=a[i][6];
                    a[i][6]=0;
                    a[i][5]=time;
                    completed++;
                }
            }
        }
    }while(completed<n);
    calculate_tat();
    calculate_wt();
    printf("\nPID\tBT\tAT\tWT\tTAT\tCT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
    }

    printf("\n Average Waiting Time : %.2f",cawt/n);
    printf("\n Average Turn Around Time : %.2f",ctat/n);
    return 0;
}

void calculate_tat()
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i][4] = a[i][5]-a[i][2];
        ctat+=a[i][4];
    }
}

void calculate_wt()
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i][3] = a[i][4]-a[i][1];
        cawt+=a[i][3];
    }
}