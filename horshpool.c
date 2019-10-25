#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 200
int table[max];
void shiftable(char p[])
{
	int m,i,j;
	m=strlen(p);
	for(i=0;i<max;i++)
		table[i]=m;
	for(j=0;j<m-1;j++)
		table[p[j]]=m-1-j;
}
int horspool(char t[],char p[])
{
	int i,n,m,k;
	shiftable(p);
	n=strlen(t);
	m=strlen(p);
	i=m-1;
	while(i<n)
	{
		k=0;
		while(k<m && (p[m-1-k]==t[i-k]))
			k++;
		if(k==m)
			return (i-m+1);
		else
			i=i+table[t[i]];
	}
	return -1;
}
void main()
{
	char t[100],p[100];
	int pos;
	printf("enter the string\n");
	gets(t);
	printf("enter the substring\n");
	gets(p);
	pos=horspool(t,p);
	if(pos>=0)
		printf("string found at position = %d\n",pos);
	else
		printf("string not found");
}
