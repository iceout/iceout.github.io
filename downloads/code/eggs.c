/*
 * =====================================================================================
 *
 *       Filename:  eggs.c
 *
 *    Description:  N层楼,K个鸡蛋,在某一层之下扔鸡蛋不会碎,问至少测试多少次才能测试出来这个层数
 *
 *        Version:  1.0
 *        Created:  08/25/2012 02:29:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  iceout (), ice.404.out@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int result[300][50];

void eggs(int n, int k)
{
    int i, j, r;
    int max, temp;

    for (i = 0; i <= k; i++) {
        result[0][i] = 0;
    }
    for (i = 0; i <= n; i++) {
        result[i][1] = i;
        result[i][0] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            temp = n;
            for (r = 1; r <= i; r++) {
                max = result[r-1][j-1] > result[i-r][j] ? result[r-1][j-1] : result[i-r][j];
                max++;
                if (max < temp) {
                    temp = max;
                }
            }
            result[i][j] = temp;
        }
    }
    printf("%d\n", result[n][k]);
}

int main(int argc, char * const argv[])
{
    eggs(100, 2);
    return 0;
}
