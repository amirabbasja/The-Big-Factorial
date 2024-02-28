#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long * subMultiply(long ptr1, long ptr2){

    static long outPut[]={99,99}, multiply;

    int a1 = ptr1 , a2 = ptr2;

    multiply =a1 * a2;

    outPut[1] = (long) multiply / 100000;

    outPut[0] =multiply - 100000 * outPut[1];

    return outPut;
}
long getNumberLen(long number){

    long num = number;

    for(int i = 0; 1; i++){

        num /= 10;

        if(num == 0) return i + 1;

    }

}
long ptrLen(long *ptr, long identifier){

    long initLen = 0;

    for(int i = 0; 1; i++){

        if(ptr[i] == identifier) {initLen = i + 1 ;break;}

    }

    return initLen;
}
void getPtrMap(long *start, long identifier){

       for(int i = 0;1; i++){

           printf("  %d\n", start[i]);

           if(start[i] == identifier) break;

       }

}
long * mainMultiply(long *ptr1, long *ptr2){

    long initLen = ptrLen(ptr1, 999999);

    static long *ptrOut;

    ptrOut = (long*) calloc(initLen, sizeof(long));

    long temp[2], reminder;

    for(int i = 0; 1; i++){
        temp[0] = subMultiply(ptr1[i], ptr2)[0];

        temp[1] = subMultiply(ptr1[i], ptr2)[1];

        reminder = temp[1];

        if(ptr1[i] == 999999) break;

        ptrOut[i] += temp[0];// += because of not making another temp check if the new allocated ptr is zero

        if(reminder != 0){

            if(i+2 == initLen  &&  reminder != 0){

                ptrOut =  (long*) realloc(ptrOut, (initLen + 1)* sizeof(long));

                ptrOut[initLen] = 999999;

                ptrOut[initLen - 1] += reminder;

            }else{

                ptrOut[i+1] += reminder;

            }
        }else if(reminder == 0 && i+2 == initLen){

            ptrOut[initLen-1] = 999999;

        }

    }

    return ptrOut;
}

void numbePrint(long *ptr, long identifier, long chopperLen){

    int start = ptrLen(ptr, identifier), len;

    int k = 0;

    for(int i = start - 1; 0 <= i; i--){

        len = getNumberLen(ptr[i]);

        if(len == chopperLen){

            printf("%d", ptr[i]);

        }else if (chopperLen < len && ptr[i] != identifier) {

            printf("%d", ptr[i]);

        }else if (len < chopperLen) {
            if(i == start - 1)
            for(int j = 0; j < chopperLen - len; j++){printf("0");}

            printf("%d",ptr[i]);

        }
//printf("%d\n",k);
        k++;

    }
    printf("\n");
}
int main()
{
    while(1){

        printf("Please enter the number:(enter 0 to exit)\n");

        long *ptr1 = (long*) calloc(2, sizeof(long));

        ptr1[0] = 1;

        ptr1[1] = 999999;

        int last;

        scanf("%d",&last);

        if(last == 0 )break;

        for(long i = 1; i <= last; i++){

            ptr1 = mainMultiply(ptr1,i);

        }
        numbePrint(ptr1,999999,5);

        printf("Programmed by A.jafarpour\n");

    }

    return 0;
}
