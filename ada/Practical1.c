#include<stdio.h>
#include<math.h>
#include<sys/time.h>

void main()
{
	int c=3,i,j;
	float timedif;
	struct timeval tpstart;		//start time
	struct timeval tpend;		//end time
	struct timeval now;
	int rc;

	now.tv_sec;
	now.tv_usec;

	rc=settimeofday(&now, NULL);

	if(rc==0)
	{
		printf("settimeofday() failed.\n");
	}
	else
	{
		printf("\nsettimeofday() Succesful\n");
		printf("\nTime Set sec=%ld Msec=%ld\n",now.tv_sec,now.tv_usec);
	}

	/*printf("1. Bubble Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Insertion Sort\n");

	printf("Enter choice = ");
	scanf("%d",&c);*/

	int n=10000,temp;
	/*printf("Enter n = ");
	scanf("%d",&n);*/
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand()%n;

	switch(c)
	{
		case 1:
			gettimeofday(&tpstart, NULL);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n-1;j++)
				{
					if(a[j]>a[j+1])
					{
						temp=a[j];
						a[j]=a[j+1];
						a[j+1]=temp;
					}

				}
			}
			gettimeofday(&tpend, NULL);

			break;
		case 2:
			gettimeofday(&tpstart, NULL);
			for(i=0;i<n;i++)
			{
			    for(j=i+1;j<n;j++)
			    {
			        if(a[i]>a[j])
			        {
			            temp=a[i];
						a[i]=a[j];
						a[j]=temp;
			        }
			    }
			}
			gettimeofday(&tpend, NULL);
			break;
		case 3:
			gettimeofday(&tpstart, NULL);
			for(i=1;i<n;i++)
			{
                for(j=0;j<i;j++)
                {
                    if(a[j]>a[i])
                    {
                        temp=a[i];
						a[i]=a[j];
						a[j]=temp;
                    }
                }
			}
            gettimeofday(&tpend, NULL);
            break;
		case 4:
			break;
	}

	/*timedif = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	printf("\nTime difference is : %f\n",timedif);*/
}


