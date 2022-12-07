
#include <iostream>
#include "DList.h"
using namespace std;
 
int main(void)
{	
	DList* P_DList = new DList();
 
	P_DList->DList_Insert(0, 20);        // 将 20 插入到第一个位置
	P_DList->DList_Insert_End(10);    // 将 10 追加到链表末尾
	P_DList->DList_Insert_Header(30);    // 将 30 插入到第一个位置
 
    printf("P_DList IsEmpty()=%d\r\n",P_DList->DList_IsEmpty());
	printf("P_DList Size =%d\r\n",P_DList->DList_size());
 
	int DList_Num = P_DList->DList_size();
	for (int i=0; i<DList_Num; i++)
    {
        printf("P_DList Value =%d\r\n",P_DList->DList_GetNode());
    }

    delete P_DList;
    P_DList=NULL;
}