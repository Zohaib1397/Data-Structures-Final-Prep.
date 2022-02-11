#include<iostream>
#include<queue>
struct Node {
    int data;
    Node* right;
    Node* left;
};
class Tree {
    Node* BSTR;
    Node* BTR;
public:
    Tree() :BSTR(NULL), BTR(NULL) {};
    void setBTRoot(Node* root) {
        BTR = root;
    }
    void setBSTRoot(Node* root) {
        BSTR = root;
    }
    Node* getBTRoot() {
        return BTR;
    }
    Node* getBSTRoot() {
        return BSTR;
    }
    Node* newNode(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->right = temp->left = NULL;
        return temp;
    }
    Node* insertBST(Node* root, int data) {
        if (root == NULL) return newNode(data);
        else if (root->data > data) root->right = insertBST(root->right, data);
        else if (root->data < data) root->left = insertBST(root->left, data);
        return root;
    }
    Node* deletion(struct Node* root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == key)
                return NULL;
            else
                return root;
        }
        Node* key_node = NULL;
        Node* temp = NULL;
        Node* last = NULL;
        std::queue<Node*> q;
        q.push(root);
        // Do level order traversal to find deepest
        // node(temp), node to be deleted (key_node)
          // and parent of deepest node(last)
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->data == key)
                key_node = temp;
            if (temp->left)
            {
                last = temp;//storing the parent node
                q.push(temp->left);
            }
            if (temp->right)
            {
                last = temp;// storing the parent node
                q.push(temp->right);
            }


        }
        if (key_node != NULL)
        {
            key_node->data = temp->data;//replacing key_node's data to deepest node's data
            if (last->right == temp)
                last->right = NULL;
            else
                last->left = NULL;
            delete(temp);
        }
        return root;
    }
    Node* insertBinaryTree() {
        int data;
        Node* temp = new Node();
        printf("Enter Data or Press -1 to Stop: ");
        std::cin >> data;
        std::cin.ignore();
        if (data == -1)return 0;
        temp->data = data;
        printf("Enter Left of Node (%d)\n ", temp->data);
        temp->left = insertBinaryTree();
        printf("Enter Right of Node (%d)\n ", temp->data);
        temp->right = insertBinaryTree();
        return temp;
    }
    void inOrder(Node* root) {
        if (root != NULL) {
            inOrder(root->left);
            printf("%d ", root->data);
            inOrder(root->right);
        }
    }
};
void InsertFunction();
void RemoveFunction();
void DisplayFunction();
int main() {
    Tree obj;
    bool isRunning = true;
    do {
        bool user_choice;
        do {
            user_choice = true;
            printf("\033[1m\033[31mMain Menu\033[0m\n");
            printf("Press [I] to Insert\n");
            printf("Press [R] to Delete\n");
            printf("Press [D] to Display\n");
            printf("Choose your Option: ");
            char choice;
            std::cin >> choice;
            switch (tolower(choice)) {
            case 'i':InsertFunction();
                break;
            case 'r':RemoveFunction();
                break;
            case 'd':DisplayFunction();
                break;
            case 'x':isRunning = false;
                break;
            default:printf("Invalid Choice Try Again\n");
                user_choice = false;
            }
        } while (user_choice == false);
    } while (isRunning);
}
void InsertFunction() {
    bool isRunning = true;
    do {
        bool user_choice;
        do {
            user_choice = true;
            printf("\033[1m\033[31mInsert Menu\033[0m\n");
            printf("Press [I] to Insert\n");
            printf("Press [R] to Delete\n");
            printf("Press [D] to Display\n");
            printf("Choose your Option: ");
            char choice;
            std::cin >> choice;
            switch (tolower(choice)) {
            case 'i':InsertFunction();
                break;
            case 'r':RemoveFunction();
                break;
            case 'd':DisplayFunction();
                break;
            case 'x':isRunning = false;
                break;
            default:printf("Invalid Choice Try Again\n");
                user_choice = false;
            }
        } while (user_choice == false);
    } while (isRunning);
}