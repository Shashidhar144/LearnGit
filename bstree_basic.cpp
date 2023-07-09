#include<iostream>
using namespace std;
struct bstnode{
	bstnode* lc;
	int data;
	bstnode* rc;
};

typedef bstnode* bstptr;

void insert(bstptr &p, int x){
	if(p==NULL){
		p = new(bstnode);
		p->data = x;
		p->lc = NULL;
		p->rc = NULL;
	}
	else{
		if(x>p->data)insert(p->rc,x);
		else insert(p->lc,x);
	}
}

void construct(btptr &t, int ch){
	cin>>ch;
	if(ch==0)return;
	else{
		t = new(btptr);
		t->data = ch;
		t->left = NULL;
		t->right = NULL;
	}
	construct(t->l,ch);
	construct(t->r,ch);
}

void inorder(bstptr p){
	if(p!=NULL){
		inorder(p->lc);
		cout<<(p->data)<<" ";
		inorder(p->rc);
	}
}

void preorder(bstptr p){
	if(p!=NULL){
		cout<<p->data<<" ";
		preorder(p->lc);
		preorder(p->rc);
	}
}

void postorder(bstptr p){
	if(p!=NULL){
		postorder(p->lc);
		postorder(p->rc);
		cout<<p->data<<" ";
	}
}

int find(bstptr t, int k){
	if(t!=NULL){
		if(t->data==k)return 1;
		else{
			if(t->data<k)return find(t->rc,k);
			else find(t->lc,k);
		}
	}
}

int findmax(bstptr t){
	while(t->rc!=NULL){
		t=t->rc;
	}
	return t->data;
}

int findmin(bstptr t){
	while(t->lc!=NULL){
		t=t->lc;
	}
	return t->data;
}

int main(){
	bstptr p;
	p=NULL;
	
	int n;
	cin>>n;
	while(n!=-1){
		insert(p,n);
		cin>>n;
	}
	preorder(p);cout<<endl;
	inorder(p);cout<<endl;
	postorder(p);cout<<endl;
	cout<<findmin(p)<<endl;
	cout<<findmax(p)<<endl;
	cout<<find(p,1);
	
}
/*
input
5 8 3 4 1 9 6 7 2 -1
7
15 

Your Output
5 3 1 2 4 8 6 7 9 
1 2 3 4 5 6 7 8 9 
2 1 4 3 7 6 9 8 5 
9
1
1
0
*/
