#include<iostream>
#include<cstring>
using namespace std;
const int MAX=100;
struct Tnode
{
    char* word;
	int count;
	Tnode *left,*right;
};
bool lesser(char* a,char* b)
{
    int i=0;
    while(1)
    {
        if(a[i]<b[i])return 1;
        if(a[i]>b[i])return 0;
        i++;
    }
}
void addin(Tnode& root,char* str)
{
	if(lesser(str,root.word))
	{
		if(!root.left)
		{
            char* temp=new char[MAX];
            strcpy(temp,str);
			root.left=new Tnode;
			root.left->word=temp;
			root.left->count=NULL;
			root.left->left=NULL;
			root.left->right=NULL;
		}
		else addin(*(root.left),str);
	}
	else
	{
		if(!root.right)
		{
            char* temp=new char[MAX];
            strcpy(temp,str);
			root.right=new Tnode;
			root.right->word=temp;
			root.right->count=NULL;
			root.right->left=NULL;
			root.right->right=NULL;
		}
		else addin(*(root.right),str);
	}
}
void print(const Tnode& root)
{
	if(root.left)print(*(root.left));
	cout<<root.word<<" ";
	if(root.right)print(*(root.right));
}
int main(int argc,char* argv[])
{
    char* temp=new char[MAX];
    strcpy(temp,"str");
	Tnode root={temp,0,NULL,NULL};
	cout<<root.word<<endl;
    char* str=new char[MAX];
	while(cin>>str)
	{
		addin(root,str);
		print(root);
        cout<<endl;
        delete str;
        char* str=new char[MAX];
	}
    delete str;
	return 0;
}
