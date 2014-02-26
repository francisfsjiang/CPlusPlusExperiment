#include<iostream>
#include<string>
using namespace std;
class Table
{
    public:
        Table()
        {
            root=NULL;
        }
        double& operator [](const string& str)
        {
            if(root!=NULL)
            {
                node *np=root;
                while(np!=NULL)
                {
                    if(str==np->str)return np->data;
                    if(str>np->str)
                    {
                        if(np->lch!=NULL) np=np->lch;
                        else
                        {
                            np->lch=new node{str,0,NULL,NULL};
                            return np->lch->data;
                        }
                    }
                    else
                    {
                        if(np->rch!=NULL) np=np->rch;
                        else
                        {
                            np->rch=new node{str,0,NULL,NULL};
                            return np->rch->data;
                        }
                    }
                }
            }
            root=new node{str,0,NULL,NULL};
            return root->data;
        }
    private:
        struct node
        {
            string str;
            double data;
            node *lch,*rch;
        }*root;

};
