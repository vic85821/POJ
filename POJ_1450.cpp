#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int num,Count=1;
    while(scanf("%d",&num)==1)
    {
        while(num--){
            int a,b;
            scanf("%d %d",&a,&b);
            if(a%2&&b%2)
                printf("Scenario #%d:\n%.2f\n\n",Count++,(float)(a*b+0.41));
            else
                printf("Scenario #%d:\n%.2f\n\n",Count++,(float)(a*b));
        }
        //�Ya,b�Ҭ��_�ơA�h�[�ڸ�2
        Count=1;
    }

    return 0;
}
