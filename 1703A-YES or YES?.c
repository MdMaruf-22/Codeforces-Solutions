#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char name[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%s",name);
        //if(a=='yes' || a=='Yes' || a=='YEs' || a=='YES' || a=='yEs' || a=='yeS' || a=='yES' || a=='YeS') printf("YES\n");
        if(strcmp(name,"yes")==0) printf("YES\n");
        else if(strcmp(name,"Yes")==0) printf("YES\n");
        else if(strcmp(name,"YEs")==0) printf("YES\n");
        else if(strcmp(name,"YES")==0) printf("YES\n");
        else if(strcmp(name,"yEs")==0) printf("YES\n");
        else if(strcmp(name,"yeS")==0) printf("YES\n");
        else if(strcmp(name,"yES")==0) printf("YES\n");
        else if(strcmp(name,"YeS")==0) printf("YES\n");
 
        else printf("NO\n");
 
    }
 
}
