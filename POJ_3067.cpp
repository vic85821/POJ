#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct{
    int east,west;
}way;



long long int Count_cross;
way temp[1000000];


void combine(int head,int tail,way bar[])
{
    int middle = (head + tail)/2,k = head;

    for(int i=head ,j=middle+1;i<=middle || j<=tail;)
    {
        if(i>middle)
        {
            temp[k++] = bar[j++];
        }
        else if(j>tail)
        {
            temp[k++] = bar[i++];
        }
        else
        {
            if(bar[i].west > bar[j].west)
            {
                Count_cross += j-k;
                temp[k++] = bar[j++];
            }
            else
                temp[k++] = bar[i++];
        }
    }
    k=head;
    for(int i=head;i<=tail;++i)
    {
        bar[i] = temp[i];
    }
}
void mergesort(int head,int tail,way bar[])
{
    if(head<tail)
    {
        int middle = (head + tail)/2;

        mergesort(head,middle,bar);
        mergesort(middle+1,tail,bar);

        combine(head,tail,bar);

    }
}
bool cmp(way a,way b)
{
    if(a.east != b.east)
        return a.east < b.east;
    else
        return a.west < b.west;
}

int main()
{
    int num,number=1;
    scanf("%d",&num);

    while(num--)
    {
        Count_cross=0;
        int num_way,east,west,useless;
        scanf("%d %d %d",&east,&west,&num_way);
        way bar[num_way];

        for(int i=0;i<num_way;++i)
        {
            scanf("%d %d",&bar[i].east,&bar[i].west);
        }

        sort(bar,bar+num_way,cmp);

        mergesort(0,num_way-1,bar);

        printf("Test case %d: %lld\n",number++,Count_cross);
    }

    return 0;
}
