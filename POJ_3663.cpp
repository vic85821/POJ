#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int num,len,Count = 0;
    scanf("%d %d",&num,&len);
    int cow[num];
    for(int i=0;i<num;++i)
    {
        scanf("%d",&cow[i]);
    }
    sort(cow,cow+num);
    for(int i=0;i<num;++i)
    {
        for(int j=num-1;j>i;--j)
        {
            if(cow[i]+cow[j] <= len)
            {
                    Count+=(j-i);
                    break;
            }
        }

    }
    printf("%d\n",Count);

    return 0;
}
