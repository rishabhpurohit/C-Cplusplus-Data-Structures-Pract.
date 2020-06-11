#include<stdio.h>
#include<math.h>

int main()
{

	float n;
	int p,w;
	w=floor(n);
	printf("Enter a real number : ");
	scanf("%f",&n);
	printf("\n Enter the precision number: ");
	scanf("%d",&p);
	printf("%*.*f\n",w,p,n);
	
	
	return 0;
}
