/*
     Desc: to test the eligibility for deployment post training. Need to f    ulfill all the 4 conditions. Read the score inputs from user at runtime.     (Use if else and switch together).

 i. Test1 Score >= 75%

 ii. Test2 Score >= 75%

 iii. Test3 Score >= 70%

 iv. Project Score >=75%
 */
 #include<stdio.h>
 int main()
 {
     int t1Scr,t2Scr,t3Scr,prjtScr;
     printf("Enter test1 Score:");
     scanf("%d",&t1Scr);
     printf("Enter test2 Score:");
     scanf("%d",&t2Scr);
     printf("Enter test3 Score:");
     scanf("%d",&t3Scr);
     printf("Enter project Score:");
     scanf("%d",&prjtScr);
     if((t1Scr>=75) && (t2Scr>=75) && (t3Scr>=70) && (prjtScr>=75))
     {
         printf("Eligible for deployment to Post training\n");
     }
     else
     {
         printf("Not Eligible for deployment to post training\n");
     }
     return 0;
 }

