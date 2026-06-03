#include <stdio.h>
int main() {
    char str[100001];
    int flag1=0;
    scanf("%s",str);
    for(int i=0;str[i];i++){
        flag1=flag1|(1<<(str[i]-'a'));
    }
    if(flag1==(1<<26)-1 ){
        printf("Yes");
    }
    else{
        printf("NO");
    }

    return 0;
}
