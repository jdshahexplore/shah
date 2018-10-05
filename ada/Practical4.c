#include<stdio.h>
#include<sys/time.h>

int iterfact(int n)
{
    int ans=1,i;
    for(i=2;i<=n;i++)
        ans*=i;
    return ans;
}

int recurfact(int n)
{
    if(n>1)
        return n*recurfact(n-1);
    else
        return 1;
}

void main()
{
	float timedif;
	struct timeval tpstart;		//start time
	struct timeval tpend;		//end time
	struct timeval now;
	int rc;
	rc=settimeofday(&now, NULL);
	if(rc==0)
		printf("settimeofday() failed.\n");
	else
	{
		printf("\nsettimeofday() Succesful\n");
		printf("\nTime Set sec=%ld Msec=%ld\n",now.tv_sec,now.tv_usec);
	}
	int n;
	printf("Enter n = ");
	scanf("%d",&n);
	int c=1,ans;
	switch(c)
	{
		case 1:
			gettimeofday(&tpstart, NULL);
			if(n>=0)
                ans=iterfact(n);
			gettimeofday(&tpend, NULL);

			break;
		case 2:
			gettimeofday(&tpstart, NULL);
			if(n>=0)
                ans=recurfact(n);
			gettimeofday(&tpend, NULL);
			break;
	}
	printf("ans = %d",ans);

	timedif = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	printf("\nTime difference is : %f\n",timedif);
}
