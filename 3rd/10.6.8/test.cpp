#include<iostream>
#include<string>
using namespace std;
struct node
{
    string str;
    node *lch,*rch;
};
class Tnode
{
    public:
        Tnode()
        {
            root=NULL;
        }
        void insert(const string& str)
        {
            if(root!=NULL)
            {
                node *np=root;
                while(np!=NULL)
                {
                    if(str==np->str)return;
                    if(str<np->str)
                    {
                        if(np->lch!=NULL) np=np->lch;
                        else
                        {
                            np->lch=new node{str,NULL,NULL};
                            return;
                        }
                    }
                    else
                    {
                        if(np->rch!=NULL) np=np->rch;
                        else
                        {
                            np->rch=new node{str,NULL,NULL};
                            return;
                        }
                    }
                }
            }
            root=new node{str,NULL,NULL};
        }
        /*~Tnode()
        {
            destory(root);
        }*/
        void print()
        {
            if(root==NULL) throw 0;
            else print(root);
            cout<<endl;
        }
    private:
        void destory(node* root)
        {
            if(root->lch!=NULL)destory(root->lch);
            if(root->rch!=NULL)destory(root->rch);
            delete root;
        }
        void print(node* root)
        {
            if(root->lch!=NULL)print(root->lch);
            cout<<root->str<<" ";
            if(root->rch!=NULL)print(root->rch);
        }
        node* root;
};

void testfun()
{
    Tnode test;
    test.insert("12345111111111111111111111111111111111111111111111111111111111111");
    test.insert("1345111111111111111111111111111111111111111111111111111111111111");
    test.insert("12335111111111111111111111111111111111111111111111111111111111111");
    test.insert("1235111111111111111111111111111111111111111111111111111111111111");
    test.insert("134111111111111111111111111111111111111111111111111111111111111");
}
int main()
{
    Tnode tree;
    string str;
    /*try
    {
        while(cin>>str)
        {
            tree.insert(str);
            tree.print();
        }
    }
    catch(int e)
    {
        cerr<<"error code :"<<e<<endl;
        exit(0);
    }*/
    for(int i=0;i<200000;i++)
    {
        testfun();
    }
    cin>>str;
    return 0;
}
