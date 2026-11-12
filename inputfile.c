#include<stdio.h>
#include"student.h"

//simple macro definitions
#define PI 3.14
#define PASS_MARK 40
#define BONUS 5

//macro with arguments
#define SQUARE(x) ((x)*(x))
#define ADD(a,b) ((a)+(b))

/*Main function starts here*/
void inputfile()
{
	struct student s;

	//taking student details
	printf("ENTER ROLL NUMBER:");
	scanf("%d",&s.rollno);

	printf("ENTER NAME:");
	scanf("%s",s.name);

	printf("ENTER MARKS:");
	scanf("%f",&s.marks);

	/*calculate bonus marks*/
	s.marks=s.marks+BONUS;

	if(s.marks>=PASS_MARK)
	{
		printf("RESULT: PASS\n");
	}
	else
	{
		printf("RESULT: FAIL\n");
	}

	//macro calculations
	printf("square:%d\n",SQUARE(5));
	printf("addition:%d\n",ADD(10,20));
	printf("PI VALUE:%f\n",PI);
}
/*End of program*/

