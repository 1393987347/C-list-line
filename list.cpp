#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct listnode 
{
    char name[50];
    listnode  *next;
};


class list
{
    private:

    public:
        //创建链表
        listnode createlist(listnode *Head, char content, int num)
        {
            Head = new listnode;
            if(content == NULL)
            {
                Head -> name[num] = '\0';
            }
            else 
            {
                Head -> name[num] = content;
            }
        }

        //添加节点
        void add(listnode *Head , char content, int num)
        {
            Head = new listnode;
            listnode *newnode = new listnode; 
            int i = 0;
            while(Head ->next != NULL)
            {
                Head = Head -> next;
                num = i++;
            }
            *newnode = createlist(Head, content, num);
            Head -> next = newnode;
        }

        //删除最后的节点
        void deletnode(listnode *Head)
        {
            Head = new listnode;
            listnode *last = new listnode;
            while(Head -> next != NULL)
            {
                last = Head;
                Head = Head -> next;
            }
            last -> next = Head -> next;
            delete Head;
        }

        //遍历链表
        void travel(listnode *Head)
        {
            Head = new listnode;
            while(Head != NULL)
            {
                cout << Head -> next << endl;
                Head = Head -> next;
            }
        }
        

};

class queue
{
    public:
    list a;  

    //入对
    void inqueue(listnode *Head , char content, int num)
    {
        a.add(Head , content , num);
    }
    //出对
    void outqueue(listnode *Head)
    {
        a.deletnode(Head);
    }
    //显示对列
    void travel(listnode *Head)
    {
        a.travel(Head);
    }
};

int main()
{
    list a;
    queue q;
    listnode *Head = new listnode;

    a.add(Head, '3', 0);
    a.add(Head, 'r', 1);
    a.add(Head, 'd', 2);
    a.add(Head, 'h', 3);
    a.travel(Head);

    q.inqueue(Head, '9', 4); 
    q.outqueue(Head);
    q.travel(Head);

}