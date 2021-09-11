
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse_add(int l1[],int l2[],int a_e1,int a_e2) //Function to reverse the input arrays elements,l1 and l2, turn them into numbers,
{                                                     //add them, reverse the sum, and turn it into elements of output array.
    int v1=10,v2=10,n1=0,n2=0,t1=0,t2=0,tt=0,div=0,div_2=0,mod=0,i=0,j=0,k=0;
    int save_1[100]={},save_2[100]={};
    int out[100]={};

//Reversing the inputed arrays, l1 and l2. The l1[last] goes to l1[0], l1[0] goes to l1[last], and so on.
//The save_1 and save_2 arrays are used to store the the l1 and l2 elements and then transfer them to their new reversed positions
//in l1 and l2.
    for(i=0;i<a_e1;i++)
    {
        save_1[i]=l1[i];
    }
    for(i=0;i<a_e1;i++)
    {
        l1[a_e1-(i+1)]=save_1[i];
    }

    for(i=0;i<a_e2;i++)
    {
        save_2[i]=l2[i];
    }
    for(i=0;i<a_e2;i++)
    {
        l2[a_e2-(i+1)]=save_2[i];
    }


//Turning the reversed arrays into numbers.
//Technique: suppose, A=[7,4,6,8],array_elements=4. To turn A into number, suppose t1, t1=7*10^(4-1)+4*10^(4-2)+6*10^(4-3)+8*10^(4-4)
    for(i=1;i<=a_e1;i++)
    {
        for(j=1;j<a_e1-i;j++) //Loop to calculate powers of 10. If 10^3, the loop should run 2 times since 10^3=10*10*10
        {
            v1=v1*10;
        }
        if(a_e1-i==0)//This conditional statement is passed because when array_elements-i=0, 10^(4-4), the loop won't run since
        {            //for(j=1;j<0;j++) is not logical and v1 will be equal to 0.
            v1=1;
        }

        n1=l1[i-1]*v1; //The n1 is the value to be added and t1 is the total adding up.
        t1=t1+n1;      //The i-1 in l1[] is because the for loop starts with i=1.
        v1=10;
    }
    for(i=1;i<=a_e2;i++)
    {
        for(j=1;j<a_e2-i;j++)
        {
            v2=v2*10;
        }
        if(a_e2-i==0)
        {
            v2=1;
        }

        n2=l2[i-1]*v2;
        t2=t2+n2;
        v2=10;
    }

    //Adding both the reversed numbers of arrays l1 and l2.
    tt=t1+t2;

    //Turning the total into reversed elements of the output array.
    //Technique: Suppose, tt=7468: 7468%10=8(out[0]) 7468/10=746.8=746(since int variable type) 746%10=6(out[1]) 746/10=74.6=74
    //74%10=4(out[2]) 74/10=7.4=7 7%10=7(out[3]) 7/10=0.7=0
    out[0]=tt%10;
    div=tt;
    for(k=1;;k++)
    {
        div_2=div;  //The div_2 is used because when last digit reached, div-0, 7/10=0.
        div=div/10; //So the before div becomes 0 the last digit is saved in div_2.
        if(div==0)
        {
           mod=div_2%10; //This is done to evaluate the last digit.
           out[k]=mod;
           break;
        }
        else
        {
            mod=div%10;
            out[k]=mod;
        }
    }

//This prints the output array.
    printf("Output: [");
    for(i=0;i<k;i++)
    {
           printf("%d",out[i]);
            if(i!=k-1)
            {
                printf(",");
            }
    }
    printf("]\n");

//This prints the explanation statement.
    printf("Explanation: %d + %d = ",t1,t2);
    for(i=0;i<k;i++)
    {
        printf("%d",out[k-(i+1)]);
    }
    printf(" (number reversed in output array)\n");
}


int main(int argc, char**argv)
{
    int a_e1=0,a_e2=0,i=0,j=0,x=0,y=0;

    //This inputs the number of elements and the elements for arrays l1 and l2.
    //It also prints the arrays of l1 and l2 after input.
    printf("Enter Number of Array Elements for l1: ");
    for(i=0;;i++)
    {
        scanf("%d",&y);
        if(y<0||y>100)
        {
            printf("Number of Elements must be between 0 and 100 inclusive! Please enter again: ");
        }
        else
        {
            a_e1=y;
            break;
        }
    }
    int l1[100]={};
    printf("Input Elements for l2:\n");
    for(i=0;i<a_e1;i++)
    {
        scanf("%d",&x);
        for(j=0;;j++)
        {
            CHECK1: if(x<0||x>9)
            {
                printf("Array Element must be single positive digit. Enter again!\n");
                scanf("%d",&x);
                goto CHECK1;
            }
            else
            {
                l1[i]=x;
                break;
            }
        }
    }
    printf("l1 = [");
    for(i=0;i<a_e1;i++)
    {
        printf("%d",l1[i]);
        if(i!=(a_e1-1))
        {
            printf(",");
        }
    }
    printf("]\n");
    //------------------------------------
    printf("Enter Number of Array Elements for l2: ");
    for(i=0;;i++)
    {
        scanf("%d",&y);
        if(y<0||y>100)
        {
            printf("Number of Elements must be between 0 and 100 inclusive! Please enter again: ");
        }
        else
        {
            a_e2=y;
            break;
        }
    }
    int l2[100]={};
    printf("Input Elements for l2:\n");
    for(i=0;i<a_e2;i++)
    {
        scanf("%d",&x);
        for(j=0;;j++)
        {
            CHECK2: if(x<0||x>9)
            {
                printf("Array Element must be single positive digit. Enter again!\n");
                scanf("%d",&x);
                goto CHECK2;
            }
            else
            {
                l2[i]=x;
                break;
            }
        }
    }
    printf("l2 = [");
    for(i=0;i<a_e2;i++)
    {
        printf("%d",l2[i]);
        if(i!=(a_e2-1))
        {
            printf(",");
        }
    }
    printf("]\n");

    //Declaration of the function above.
    reverse_add(l1,l2,a_e1,a_e2);
}
