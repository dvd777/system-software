#include<stdio.h>

void main()
{
	struct he
	{
	int t;
	char ar[2];
	}ar[50];
	int temp,g,ext[5],arrt[5],cpy[5],i,j,sum=0,sum3,sum4,s[5]={0},e[5]={0},k,or[5],pos[5],ps[5]={0},pe[5]={0},ex;
	float n,att,awt,sum1=0,sum2=0;
	printf("Enter the number of process");
	scanf("%f",&n);
	printf("Enter the execution times of process %d\n",n);
	for(i=0;i<n;i++)
	{
		pos[i]=i;
		printf("Enter the execution time for process %d:",i+1 );
		scanf("%d",&ext[i]);
		cpy[i]=ext[i];
	}
	printf("Enter the QUANTOM TIME:");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		sum=sum+ext[i];
	}
	printf("sum=%d\n",sum);
	printf("\n Pno\text time\tremaining time\twaiting time\t turnaround time\n");
	sum1=0;
	sum2=0;
	g=0;
	for(j=0;j<sum;)
	{
		i=0;
		while(i<n)
		{
			if(ext[i]!=0)
			{
				ps[i]=j;
				ext[i]=ext[i]-k;
				if(ext[i]<0)
				{
				ex=ext[i]+k;
				
				j=j+ex;
				ext[i]=0;
				pe[i]=ps[i]+ex;
				}
				else
				{
				j=j+k;
				ex=k;
				pe[i]=ps[i]+k;
				}		
			printf(" %d\t     %d\t         %d\t        %d\t        %d\n",pos[i]+1,ex,ext[i],ps[i],pe[i]);
			sum1=sum1+ps[i];
			sum2=sum2+pe[i];
			s[i]=ps[i];
			e[i]=pe[i];
			}
		i++;
		
		}
	}
	printf("Avg wating time is =%f\n",sum1/n);
	printf("Avg trunaround time is =%f\n",sum2/n);
	printf("\n\n\n");
	printf("-----GANTT CHART-----");
	printf("\n");
	for(j=0;j<sum;)
	{
		i=0;
		while(i<n)
		{
			if(cpy[i]!=0)
			{
				ps[i]=j;
				cpy[i]=cpy[i]-k;
				if(cpy[i]<0)
				{
				ex=cpy[i]+k;
				j=j+ex;
				cpy[i]=0;
				pe[i]=ps[i]+ex;
				}
				else
				{
				j=j+k;
				ex=k;
				pe[i]=ps[i]+k;
				}		
			sum1=sum1+ps[i];
			sum2=sum2+pe[i];
			s[i]=ps[i];
			e[i]=pe[i];
			printf("%d P%d %d\t",ps[i],i+1,pe[i]);			
			
			}
		i++;
		}
	}
printf("\n");
}
