#include <stdio.h>
int main() {
    char str[100001];
    int flag1=0;
    int flag2=0;
    scanf("%s", str);
    for(int i=0;str[i];i++){
        if(str[i]>='a' && str[i]<='z'){
            flag1=flag1|(1<<(str[i]-'a'));
        }
        else{
            flag2=flag2|(1<<(str[i]-'A'));
        }
    }
    if((flag1==(1<<26)-1) && (flag2==(1<<26)-1) ){
        printf("Yes");
    }
    else{ printf("NO");
    }
    printf("%d",flag2);
    return 0;
}
