#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const maxn = 1e7 + 1;
ll a[maxn];
struct node{
	int data;
	node *next;
};
node* Makenode(int x){
	node* newnode = new node();
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
int count(node *head){
	int dem = 0;
	while(head != NULL){
		dem++;
		head = head->next;
	}
	cout << endl;
	return dem;
}
void duyet(node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void pushFront(node **head,int x){
	node *newnode = Makenode(x);
	newnode->next = (*head);
	(*head) = newnode;
}
void pushBack(node **head,int x){
	node *newnode = Makenode(x);
	if(*head == NULL){
		*head = newnode;	
	}
	else{
		node *tmp = *head;
		while(tmp-> next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
}
void insert(node **head,int k,int x){
	int n = count(*head);
	if(k < 1 || k > n + 1){
		return;
	}
	if(k == 1)	pushFront(&(*head),x);
	else if(k == n)	pushBack(&(*head),x);
	else{
		node *newnode = Makenode(x);
		node *tmp = *head;
		for(int i = 1;i <= k - 2;i++){
			tmp = tmp->next;
		}
		newnode->next = tmp->next;
		tmp->next = newnode;
	}
}
void popFront(node **head){
	if(*head == NULL) return;
	node *tmp = *head;
	(*head) = (*head)->next;
	delete tmp;
}
void popBack(node **head){
	if(*head == NULL)	return;
	node *tmp = *head;
	if(tmp->next == NULL){
		*head = NULL;
		delete tmp;
		return;
	}
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	node *last = tmp->next;
	tmp->next = NULL;
	delete last;
}
void popMid(node **head,int k){
	int n = count(*head);
	if(k < 1 || k > n)	return;
	if(k == 1)	popFront(&(*head));
	else if(k == n)	popBack(&(*head));
	else{
		node *tmp = *head;
		for(int i = 1;i <= k - 2;i++){
			tmp = tmp->next;
		}
		node *tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
	}
	
}
int main(){
	node *head = NULL;
	while(1){
		cout << "-------------------------------------------------------\n";
		cout << "1.Them vao dau" << endl;
		cout << "2.Them vao cuoi" << endl;
		cout << "3.Them vao giua" << endl;
		cout << "4.Xoa node dau" << endl;
		cout << "5.Xoa node cuoi" << endl;
		cout << "6.Xoa node giua" << endl;
		cout << "7.Duyet" << endl;
		cout << "0.Thoat" << endl;
		int lc;cin >> lc;
		if(lc == 1){
			cout << "Nhap x: ";int x;cin >> x;
			pushFront(&head,x);
		}
		if(lc == 2){
			cout << "Nhap x: ";int x;cin >> x;
			pushBack(&head,x);
		}
		if(lc == 3){
			cout << "Nhap x: ";int x;cin >> x;
			cout << "Nhap vi tri can chen: ";int k;cin >> k;
			insert(&head,k,x);
		}
		if(lc == 4){
			popFront(&head);
		}
		if(lc == 5){
			popBack(&head);
		}
		if(lc == 6){
			cout << "Nhap vi tri can xoa: ";int k;cin >> k;
			popMid(&head,k);
		}
		if(lc == 7){
			duyet(head);
		}
		if(lc == 0){
			break;
		}
	}
}