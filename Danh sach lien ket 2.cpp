#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const maxn = 1e7 + 1;
struct	Node{
	int data;
	Node *pNext;	
};
struct dsHinhtron{
	Node *pHead,*pTail;
};
Node* Makenode(int x){
	Node *newnode = new Node();
	newnode->data = x;
	newnode->pNext = NULL;
	return newnode;
}
int duyet(dsHinhtron a){
	int cnt = 0;
	while(a.pHead != NULL){
		cout << a.pHead->data << " ";
		cnt++;
		a.pHead = a.pHead->pNext;
	}
	cout << endl;
	return cnt;
}
void pushFront(dsHinhtron &a,Node *p){
	if(a.pHead == NULL){
		a.pHead = a.pTail = p;
	}
	else{
		p->pNext = a.pHead;
		a.pHead = p;
	}
}
void pushBack(dsHinhtron &a,Node *p){
	if(a.pHead == NULL){
		a.pHead = a.pTail = p;
	}
	else{
		a.pTail->pNext = p;
		a.pTail = p;
	}
}
void insert(dsHinhtron &a,Node *p,int k){
	int n = duyet(a);
	if(k < 1 || k > n + 1)	return;
	if(k == 1)	pushFront(a,p);
	else if(k == n)	pushBack(a,p);
	else{
		Node *tmp = a.pHead;
		for(int i = 1;i <= k - 2;i++){
			tmp = tmp->pNext;
		}
		p->pNext = tmp->pNext;
		tmp->pNext = p;
	}
}
int main(){
	dsHinhtron a;
	a.pHead = NULL;
	a.pTail = NULL;
	while(1){
		cout << "-------------------------------------------------------\n";
		cout << "1.Them vao dau" << endl;
		cout << "2.Them vao cuoi" << endl;
		cout << "3.Them vao giua" << endl;
		cout << "4.Duyet" << endl;
		cout << "0.Thoat" << endl;
		int lc;cin >> lc;
		if(lc == 1){
			cout << "Nhap x: ";int x;cin >> x;
			pushFront(a,Makenode(x));
		}
		if(lc == 2){
			cout << "Nhap x: ";int x;cin >> x;
			pushBack(a,Makenode(x));
		}
		if(lc == 3){
			cout << "Nhap x: ";int x;cin >> x;
			cout << "Nhap vi tri can chen: ";int k;cin >> k;
			insert(a,Makenode(x),k);
		}
		if(lc == 4){
			duyet(a);
		}
		if(lc == 0){
			break;
		}
	}

}