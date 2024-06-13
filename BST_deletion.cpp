#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	
	int info;
	Node* left;
	Node* right;
	
	Node(){
		left = NULL;
		right = NULL;
	}
		
};

class tree{
	public:
		Node* root;
		Node* temp;
		Node* temp1;
		
		int number;
		
	
	tree(){
		root = NULL;
		temp = NULL;
		temp1 = NULL;
	}
	
	void insertion(Node* head){
		if(head == root && root == NULL){
			root = new Node;
			root->info = number;
			return;
		}
		
		
		if(number < head->info && head->left != NULL){
			insertion(head->left);
		}
		else if(number == head->info){
			cout<<"Cannot Add A Duplicate"<<endl<<endl;
		}
		else if(number > head->info && head->right != NULL){
			insertion(head->right);
		}
		else{
			if(number < head->info){
				head->left = new Node;
				head->left->info = number;
			}
			else{
				head->right = new Node;
				head->right->info = number;
			}
		}
		
	}
	
	void in_order_triversal(Node* head){
		if(head == root && root == NULL){
			cout<<"Nothing To Triverse In The Tree"<<endl<<endl;
			return;
		}
		
		if(head->left != NULL){
			in_order_triversal(head->left);
		}
		
		cout<<head->info<<" ";
		
		if(head->right != NULL){
			in_order_triversal(head->right);
		}
	}
	
	Node* findSuccessor(Node* temp){
		if(temp->left == NULL){
            return temp;
        }
        else{
            return findSuccessor(temp->left);
        }
        // while(temp->left != NULL){
        //     temp = temp->left;

        // }

        // return temp;
	}
	
	Node* deletion(Node* head){
		
        if(head == NULL && head == root){
            cout<<"There is Nothing in the Tree"<<endl<<endl;
            return NULL;
        }

        if(number < head->info){
            head->left = deletion(head->left);
        }
        else if(number > head->info){
            head->right = deletion(head->right);
        }
        else{
            if(head->left == NULL && head->right == NULL){
                delete head;
                head = NULL;
            }
            else if(head->left == NULL){
                temp = head;
                head = head->right;
                delete temp;
                temp = NULL;
            }
            else if(head->right == NULL){
                temp = head;
                head = head->left;
                delete temp;
                temp = NULL;
            }
            else{
                temp1 = findSuccessor(head->right);
                head->info = temp1->info;

                number = temp1->info;

                head->right = deletion(head->right);
            }
        }

        return head;
		
		
	}
	
};


int main(){
	tree T;
	
	int option;
	
	do{
		cout<<"1. Insertion"<<endl;
		cout<<"2. Triverse In Order"<<endl;
		cout<<"3. Deletion"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter The Number To Add : ";
			cin>>T.number;
			T.insertion(T.root);
		}
		else if(option == 2){
			T.in_order_triversal(T.root);
			cout<<endl<<endl;
		}
		else if(option == 3){
			cout<<"Enter The Number That You Want To Delete : ";
			cin>>T.number;
			
			T.root = T.deletion(T.root);
		}
		else if(option == 4){
			break;
		}
		
	}
	while(option != 4);
	
	
}