#include"LinkList.h"
char array1[]= {'1','2','3','2','1'};
char array2[]= {'1','1'};
bool isPalindrome(LinkList * list, int length);
int main()
{
	LinkList * list;
    LinkList * list2;

	int length = sizeof(array1)/sizeof(array1[0]);
	InitList(list);
    InitList(list2);
	CreateListHead(list,array1,length);
    CreateListHead(list2,array2,2);
    ShowList(list);
    ShowList(list2);
	if(isPalindrome(list, length))
		printf("isPalindrome\n");
	else
		printf("isNotPalindrome\n");
	return 0;
}
bool isPalindrome(LinkList * list, int length)
{
	int i;
	char buff1[length],buff2[length];
	ElemType e;
	for(i=1; i<=length; i++) 
	{
		GetListElem(list,i,e);
		buff1[i-1]=e;
		buff2[length-i]=e;
	}
	i=0;
	while(i<length) {
		if(buff1[i]==buff2[i])
		{
			i++; 
		} 
		else 
		{
            return false;
		}
	}
	return true;
}
