
#include <iostream>
#include "DList.h"
using namespace std;

DList::DList():count(0)
{

    P_head = new DList_Node();
    P_head->m_prev = P_head->m_next = P_head;

}
DList::~DList()
{
    DList_Node *p_tmp;
    DList_Node *p_node = P_head->m_next;
    while (p_node!=P_head)
    {
        p_tmp=p_node;
        p_node=p_node->m_next;
        delete p_tmp;
    }
    
    delete P_head;
    P_head = NULL;
}

int DList::DList_size()
{
    return count;
}

int DList::DList_IsEmpty()
{
    return count==0;
}

DList_Node * DList::Get_Node(int index)
{
    if(index<0||index>=0)
    {
        printf("get node failed! the index in out of bound!\r\n");
        return NULL;
    }

    if(index<=count/2)
    {
        int i=0;
        DList_Node *P_Index =P_head->m_next;
        while (i++<index)
        {
            P_Index=P_Index->m_next;
        }
        return P_Index;
    }

    int j=0;
    int R_index =count-index-1;
    DList_Node *P_Rindex =P_head->m_prev;
    while (j++<R_index)
    {
        P_Rindex=P_Rindex->m_prev;
    }
    
    return P_Rindex;
    
}
int DList::DList_GetNode(int index)
{
	return Get_Node(index)->m_value;
}

int DList::DList_Get_Header(void)
{
    return Get_Node(0)->m_value;
}

int DList::DList_Get_End(void)
{
    return Get_Node(count-1)->m_value;
}

int DList::DList_Insert(int index,int value)
{
    if(index==0)
        return DList_Insert_Header(value);
    DList_Node* P_Index=Get_Node(index);
    DList_Node* P_Node = new DList_Node(value,P_Index->m_prev,P_Index);
    P_Index->m_prev->m_next=P_Node;
    P_Index->m_prev=P_Node;
    count++;
    return 0;
}
int DList::DList_Insert_Header(int value)
{
    DList_Node* P_Node=new DList_Node(value,P_head,P_head->m_next);
    P_head->m_next->m_prev=P_Node;
    P_head->m_next=P_Node;
    count++;
    return 0;
}
int DList::DList_Insert_End(int value)
{
    DList_Node* P_Node= new DList_Node(value,P_head->m_prev,P_head);
    P_head->m_prev->m_next=P_Node;
    P_head->m_prev=P_Node;
    count++;
}

int DList::DList_Delte(int index)
{
    DList_Node* P_Index=Get_Node(index);
    P_Index->m_next->m_prev=P_Index->m_prev;
    P_Index->m_prev->m_next=P_Index->m_next;
    delete P_Index;
    count--;
    return 0;
}
int DList::DList_Delte_Header()
{
    DList_Delte(0);
    return 0;
}
int DList:: DList_Delte_End()
{
    DList_Delte(count-1);
    return 0;
}