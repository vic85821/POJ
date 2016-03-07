#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int num;
    scanf("%d",&num);
    getchar();
    int cow[num];
    for(int i=0;i<num;++i)
        scanf("%d",&cow[i]);

    sort(cow,cow+num);
    long long int sum=0;
    for(int i=1;i<num;++i)
        sum+=(long long int)(cow[i]-cow[i-1])*(num-i)*i;

    printf("%lld\n",2*sum);

    return 0;
}
