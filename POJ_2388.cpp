#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int num;
    scanf("%d",&num);

    int cow[num];
    for(int i=0;i<num;++i)
    {
        scanf("%d",&cow[i]);
    }

    sort(cow,cow+num);
    printf("%d\n",cow[num/2]);


    return 0;
}
