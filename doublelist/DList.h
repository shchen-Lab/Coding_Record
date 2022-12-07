#ifndef D_LIST_H
#define D_LIST_H

struct DList_Node
{
public:
    int m_value;
    DList_Node* m_prev;
    DList_Node* m_next;
public:
    DList_Node(){}
    DList_Node(int value, DList_Node*prev, DList_Node* next)
    {
        this->m_value=value;
        this->m_next=next;
        this->m_prev=prev;
    }
};

class DList
{
private:
    int count;
    DList_Node* P_head;
private:
    DList_Node* Get_Node(int index);
public:
    DList();
    ~DList();
    int DList_size();
    int DList_IsEmpty();

    int DList_GetNode(int index);
    int DList_Get_Header(void);
    int DList_Get_End(void);

    int DList_Insert(int index,int value);
    int DList_Insert_Header(int value);
    int DList_Insert_End(int value);

    int DList_Delte(int index);
    int DList_Delte_Header();
    int DList_Delte_End();
};
