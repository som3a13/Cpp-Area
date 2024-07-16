#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>

/*can be struct*/
class Node
{
public:
    int data;

    Node * left,*right=nullptr ;

    Node(int data1,Node*left1,Node*right1):data(data1),left(left1),right(right1){}


};

class BST
{
    public:
        Node *root=nullptr;

        BST(){
            root = nullptr;
        }


        
        /*Data insertion*/
        void insert(int item)
        {
            root=insert(root,item);
        }

        /*Data Display*/
        void PreOrder(Node*node)/*root > left > right*/
        {   
            if(node==nullptr)
            {
                return;
            }
            else
            {
                std::cout << node->data << '\t';
                PreOrder(node->left);
                PreOrder(node->right);

            }
        }
    
        void inOrder(Node*node)
        {
            if(node==nullptr)
            {
                return;
            }
            else
            {
                inOrder(node->left);
                std::cout << node->data << '\t';
                inOrder(node->right);

            }
        }
        void postOrder(Node*node) /*left > right >root*/
        {
            if(node==nullptr)
            {
                return;
            }
            else
            {
                postOrder(node->left);
                postOrder(node->right);
                std::cout << node->data << '\t';


            }
        }

        /*Data Search*/

        Node* search(Node*node,int item)
        {
            if(node==nullptr)
            {
                return nullptr;
            }
            else if(node->data==item)
            {
                return node;

            }else if( item < node->data )
            {   
                node = search(node->left, item);
            }
            else if( item > node->data )
            {   
                node = search(node->right, item);
            }
            else
            {
                /*not found*/
                return nullptr;
            }

            return node;
        }
        /*Find Max element*/
        Node*findMax(Node*node)
        {
            if(node==nullptr)
            {
                return nullptr;

            }
            else if( node->right==nullptr)
            {
                return node;
            }
            else
            {
                return findMax(node->right);
            }

        }
        Node* Findmin(Node* node)
	    {
            if (node == NULL)
            {
                return NULL;
            }    
            else if (node->left == NULL)
            {
                return node;

            }

            else{
                    return Findmin(node->left);

            }


	    }



        /*Data erase*/
        Node* erase(Node*node,int item)
        {   
            if(node==nullptr)
            {

                return nullptr;
            }
            if(item < node->data )
     
            {
                node->left=erase(node->left, item);
            }
            else if(item > node->data)
            {
                node->right =erase(node->right, item);
            }
            else 
            {   
                if(node->left == nullptr && node->right==nullptr)
                {
                    node=nullptr;
                }else if (node->left != nullptr && node ->right==nullptr)
                {
                    node->data = node->left->data;
                    delete node->left;
                    node->left=nullptr;
                }
                else if (node->left == nullptr && node ->right!=nullptr)
                {
                    node->data = node->right->data;
                    delete node->right;
                    node->right=nullptr;
                }
                else
                {
                    Node*max=findMax(node->left);
                    node->data = max->data;
                    node->left=erase(node->left, max->data);
                }

            }
            return node;
        }









    ~BST()
    {
        delete root;
    }



    private: 

    Node * insert(Node*node,int item)
        {   
            if(node==nullptr)
            {
                node=new Node(item,nullptr,nullptr);
            }
            else if(node->data > item )
            {   
                node->left =insert(node->left, item);
            }   
            else
            {
                node->right=insert(node->right, item);
            }

            

         return node;
        }








        


};



/*For sorted array*/

int binarySearch(int arr[],int n,int target,int left , int right)
{   
    int mid{};

    while(left<=right)
    {   
         mid=left+((right-left)/2);

        if(arr[mid]==target)
        {
            return mid;
        }

        if(target<arr[mid])
        {
            
            right=mid-1;

        }
        else
        {
            left=mid+1;
        }   

    }




    return -1;
}





int main()
{

    BST t1;

    t1.insert(45);
    t1.insert(15);
    t1.insert(79);
    t1.insert(90);
    t1.insert(10);
    t1.insert(55);
    t1.insert(12);
    t1.insert(20);
    t1.insert(50);
    /*root*/
    std::cout << t1.root->data << std::endl;

    /*Display Data*/
    t1.PreOrder(t1.root);
    std::cout << "----------" << std::endl;
    t1.inOrder(t1.root);
    std::cout << "----------" << std::endl;
    t1.postOrder(t1.root);
    std::cout << "----------" << std::endl;

    /*Search*/
    auto result =t1.search(t1.root, 99);
    if(result!=nullptr)
    {
        std::cout << "found the item" << std::endl;
    }
    else
    {
        std::cout << "not found the item" << std::endl;

    }

    /*find Max element in tree*/
   auto res= t1.findMax(t1.root);
    std::cout << res->data << std::endl;

    /*Data erase*/
    t1.erase(t1.root, 45);
    
     t1.PreOrder(t1.root);
    std::cout << "----------" << std::endl;














    int arr[7]={3,1,2,6,72,4,7};
    int n=7;
    std::sort(std::begin(arr),std::end(arr));
    if(binarySearch(arr, n, 1,0 , n-1)==-1)
    {
        std::cout << "not found" << std::endl;
    }
    else
    {
        std::cout << "found" << std::endl;
    }

    bool found =std::binary_search(std::begin(arr),std::end(arr),72);
    std::cout << std::boolalpha << found << std::endl;
    auto it=std::find(std::begin(arr),std::end(arr),72);

    if(it!=std::end(arr))
    {
        std::cout << "found" << std::endl;
        int index =std::distance(std::begin(arr), it);
        std::cout << index << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }



}