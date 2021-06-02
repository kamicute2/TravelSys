#ifndef LIST_H
#define LIST_H
#include <QString>

template <class T> class List
{
    struct Element
    {
        T data;
        Element *next;
    };

    Element *pHead;
    Element *pPrev;
    int countElem;

  public :
    List()
    {
        pHead = NULL;
        pPrev = NULL;
        countElem = 0;
    }

    ~List()
    {
        delAllList();
    }

    T operator[] (int index)
    {
        T res = T();
        int c = 0;
        Element *cur = pHead;

        while (cur != NULL)
        {
            if (c == index)
            {
                res = cur->data;
                break;
            }
            cur = cur->next;
            c++;
        }
        return res;
    }

    void  add_front(T data)
    {
        Element *temp = new Element;
        temp->next = pHead;
        pHead = temp;
        if(pPrev == NULL)
            pPrev = pHead;
        pHead->data = data;
        ++countElem;
    }

    void add_back(T data)
    {
        Element *temp = new Element;

        if(pHead == NULL)
            pHead = temp;
        else
            pPrev->next = temp;

        temp->data = data;
        temp->next = NULL;
        pPrev = temp;
        countElem++;
    }

    int Count(){return countElem;}

    void DEL(int i){
        if(countElem == 1){
            delete pHead;
            pHead = pPrev = nullptr;
        }
        else{
            if(i == 0){
                Element* nextnode = pHead->next;
                delete pHead;
                pHead = nextnode;
            }
            else if(i+1 == countElem){
                Element* nextnode = pHead;
                for(int j = 0; j<i-1; j++)
                    nextnode=nextnode->next;

                pPrev = nextnode;
            }
            else{
                Element* nextnode = pHead;
                for(int j = 0; j<i-1; j++)
                    nextnode=nextnode->next;
                Element* tmpnode = nextnode;
                nextnode=nextnode->next;
                tmpnode->next=nextnode->next;
                delete nextnode;
            }
        }
        countElem--;
    }

    void EDIT(int num, T item)
    {
        Element* nextnode = pHead;
        for(int j = 0; j < num; j++)
            nextnode=nextnode->next;
        nextnode->data = item;
    }

    void delAllList()
    {
        while(pHead != NULL)
        {
            Element *pTemp = pHead;
            pHead = pHead->next;
            delete pTemp;
        }
        pHead = pPrev = NULL;
        countElem = 0;
    }

    bool IsEmpty()
    {
        if(countElem == 0)
            return true;
        else
            return false;
    }

    int length()
    {
        return countElem;
    }
};


#endif // LIST_H
