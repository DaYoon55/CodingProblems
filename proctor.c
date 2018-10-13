//
//  main.c
//  proctor_C
//
//  Created by Daum Yoon on 10/13/18.
//  Copyright © 2018 Daum Yoon. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <time.h>

//using namespace std;

int main(){
    int N, B, C, temp;
    long int sum=0;
    
    scanf("%d",&N);
    int A[N];
    for (int i=0; i<N; ++i){
        scanf("%d",&temp);
        A[i] = temp;
    }
    
    scanf("%d",&B);
    scanf("%d",&C);
    
    for (int i=0; i<N; ++i){
        temp = A[i]-B;
        if (temp >= 0) sum += ceil((double) temp/C);
    }
        
    printf("%ld",sum + N);
}

