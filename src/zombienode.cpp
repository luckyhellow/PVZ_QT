//#include "zombienode.h"

////ZombieList init()
////{
////}

//bool insert_intail(ZombieList& head,Zombie_0*zombie)
//{
//    if(head == NULL)
//    {
//        head = new Node;
//        head->zombie = zombie;
//        head->next = NULL;
//        return 1;
//    }
//    else
//    {
//        Node *p;
//        for(p=head;p!=NULL;p=p->next)
//        {
//        }
//        p->next = new Node;
//        p->next->next = NULL;
//        p->next->zombie = zombie;
//        return 1;
//    }
//    return 0;
//}

//bool delete_node(ZombieList& head,Zombie_0*zombie)
//{
//    Node* p = head;
//    Node *q = head;
//    if(head ==NULL)
//        return 0;
//    else
//    {
//        for(;p!=NULL;p=p->next)
//        {
//            if(p->zombie==zombie)
//            {
//                q->next = p->next;
//                delete p;
//            }
//            else
//            {
//                q=p;
//            }
//        }
//    }
//    return 0;
//}


//void clear(ZombieList& head)
//{
//    if(head==NULL) return;
//    Node* p = head;
//    Node* q = NULL;
//    while(p!=NULL)
//    {
//        q = p;
//        p = p->next;
//        delete q;
//    }
//    head = NULL;
//}
