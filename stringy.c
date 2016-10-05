#include <stdio.h>
#include <string.h>

int str_len(char *s) {
    int n=0;
    while (*s) {
        ++n;
        ++s;
    }
    return n;
}

char *str_cpy(char *dst,char *src) {
    char *dst0=dst;
    while (*src) *dst++=*src++;
    *dst='\0';
    return dst0;
}

char *strn_cpy(char *dst,char *src,int n) {
    int i;
    char *dst0=dst;
    for (i=1;i<=n;++i) *dst++=*src++;
    *dst='\0';
    return dst0;
}

char *str_cat(char *dst,char *src){
    char *dst0=dst; 
    while (*dst++);
    --dst;
    while (*src) *dst++=*src++;
    *dst='\0';  
    return dst0;
}

char *str_cat1(char *dst,char *src) {
    char *dst0=dst; 
    while (*dst++);
    --dst;
    str_cpy(dst,src);
    return dst0;
}

char *strn_cat(char *dst,char *src,int n) {
    int i;
    char *dst0=dst;     
    while (*dst++);
    --dst;
    for (i=1;i<=n;++i) *dst++=*src++;   
    *dst='\0';  
    return dst0;
}

int str_cmp(char *s1,char *s2) {
    unsigned char c1,c2;
    for (;;) {
        c1=*s1;
        c2=*s2;
        if (c1==0) return c2?0:-1;
        if (c2==0) return 1;
        if (c1<c2) 
            return -1;
        else if (c1>c2)
            return 1;
        ++s1;
        ++s2;
    }
}
    
char *str_chr(char *s,char c) {
    while (*s!=c)
        if (!*s++) return NULL;
    return s;
}

int main()  
{
    char *s="abcd",*src="abcd",dst[8],c,*p1,*s1="abcd",*s2="aBcde";
    
    
    printf("---- testing str_len\n");
    printf("s=%s\n",s);
    printf("str_len(s)=%d\n",str_len(s));
    
    printf("---- testing str_cpy\n");
    printf("src=\"%s\"\n",src); 
    dst[0]='\0';
    printf("dst=\"%s\"\n",dst);
    printf("about to call str_cpy(dst,src) ...\n");
    str_cpy(dst,src);
    printf("src=\"%s\"\n",src); 
    printf("dst=\"%s\"\n",dst);
    
    printf("---- testing strn_cpy\n");
    printf("src=\"%s\"\n",src); 
    dst[0]='\0';
    printf("dst=\"%s\"\n",dst);
    printf("about to call strn_cpy(dst,src,3) ...\n");
    strn_cpy(dst,src,3);
    printf("src=\"%s\"\n",src); 
    printf("dst=\"%s\"\n",dst); 

    printf("---- testing str_cat\n");
    printf("src=\"%s\"\n",src); 
    str_cpy(dst,"xyz");
    printf("dst=\"%s\"\n",dst);
    printf("about to call str_cat(dst,src) ...\n");
    str_cat(dst,src);
    printf("src=\"%s\"\n",src); 
    printf("dst=\"%s\"\n",dst);
    
    printf("---- testing strn_cat\n");
    printf("src=\"%s\"\n",src); 
    str_cpy(dst,"xyz");
    printf("dst=\"%s\"\n",dst);
    printf("about to call strn_cat(dst,src,3) ...\n");
    strn_cat(dst,src,3);
    printf("src=\"%s\"\n",src); 
    printf("dst=\"%s\"\n",dst);
    
    printf("---- testing str_chr for existing char\n");
    printf("s=\"%s\"\n",s);
    c='b';
    printf("c=\'%c\'\n",c);
    printf("about to compute p1=str_chr(s,c) ...\n");
    p1=str_chr(s,c);
    printf("s=\"%s\"\n",s); 
    printf("c=\'%c\'\n",c);
    printf("p1=\"%s\"\n",p1);
    
    printf("---- testing str_chr for non-existent char\n");
    printf("s=\"%s\"\n",s);
    c='z';
    printf("c=\'%c\'\n",c);
    printf("about to compute p1=str_chr(s,c) ...\n");
    p1=str_chr(s,c);
    if (p1) {
        printf("error -- p1 expected to be NULL\n");
        printf("p1=%x\n",(unsigned int)p1);
        printf("----\n");
        return 1;}
    else {
        printf("s=\"%s\"\n",s); 
        printf("c=\'%c\'\n",c);
        printf("p1=%x, i.e., p1=NULL (as a pointer)\n",(unsigned int)p1);   
    }
    
    printf("---- testing str_cmp\n");
    printf("s1=\"%s\"\n",s1);   
    printf("s2=\"%s\"\n",s2);   
    printf("str_cmp(s1,s2)=%d\n",str_cmp(s1,s2));
    
    printf("----\n");
    
    return 0;
}
