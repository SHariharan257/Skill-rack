#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    scanf("%s", str);
    int l=strlen(str);
    for(int ct=1;ct<(1<<l);ct++){
        char comb[100];
        int pos=0;
        for(int j=0;j<l;j++){

            if((ct&(1<<j))>0){

                comb[pos++]=str[j];
            }
  }
        comb[pos]='\0';
        printf("%s",comb);
        printf("\n");
    }
    return 0;
}
