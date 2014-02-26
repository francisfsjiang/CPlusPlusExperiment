#include<iostream>
using namespace std;
struct Tnode
{
	string word;
	int count;
	Tnode *left,*right;
};
void addin(Tnode& root,const string& str)
{
	if(str<root.word)
	{
		if(!root.left)
		{
			root.left=new Tnode{str,0,0,0};
			root.left->word=str;
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
			root.right=new Tnode;
			root.right->word=str;
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
	Tnode root={string("str"),0,NULL,NULL};
	cout<<root.word<<endl;
	string str;
	while(cin>>str)
	{
		addin(root,str);
		print(root);
        cout<<endl;
	}
	return 0;
}
