#include <bits/stdc++.h>

using namespace std;

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    class Key{
    public:
        int cur,fine,dead,city_id;
    public:
        Key(){}
        Key(int cur,int fine,int dead,int city_id){
            this -> cur = cur;
            this -> fine = fine;
            this -> dead = dead;
            this -> city_id = city_id;
        }
        bool operator < (const Key &other) const {
            return (cur < other.cur) or
                   (cur == other.cur and fine > other.fine) or
                   (cur == other.cur and fine == other.fine and dead < other.dead) or
                   (cur == other.cur and fine == other.fine and dead == other.dead and city_id < other.city_id);
        }
        bool operator == (const Key &other) const {
            return cur == other.cur and fine == other.fine and dead == other.dead and city_id == other.city_id;
        }
        bool operator > (const Key &other) const  {
            return !(*this < other) and !(*this == other);
        }
    };

    class Node{
    public:
        Key key;
        int height,balance;
        int size_subtree;
        pair <int,int> max_fine;
        pair <int,int> max_dead;
        Node *left,*right;
    public:
        Node(){}
        Node(Key key){
            this -> left = this -> right = nullptr;
            this -> key = key;
            this -> height = this -> balance = 0;
            this -> size_subtree = 1;
            this -> max_fine = make_pair(-key.fine,key.city_id);
            this -> max_dead = make_pair(-key.dead,key.city_id);
        }
        Node(Node *ll,Node *rr,Key key,int height,int balance,int size_subbtree){
            this -> left = ll;
            this -> right = rr;
            this -> key = key;
            this -> height = height;
            this -> balance = balance;
            this -> size_subtree = size_subtree;
        }
        void computeInfo(){
            this -> height = 1 + max(this -> left ? this -> left -> height : 0,this -> right ? this -> right -> height : 0);
            this -> balance = (this -> left ? this -> left -> height : 0) - (this -> right ? this -> right -> height : 0);
            this -> size_subtree = 1 + (this -> left ? this -> left -> size_subtree : 0)
                                     + (this -> right ? this -> right -> size_subtree : 0);
            pair <int,int> cur_fine = make_pair(-(this -> key).fine,(this -> key).city_id);
            pair <int,int> cur_dead = make_pair(-(this -> key).dead,(this -> key).city_id);
            if(this -> left){
                minimize(cur_fine,this -> left -> max_fine);
                minimize(cur_dead,this -> left -> max_dead);
            }
            if(this -> right){
                minimize(cur_fine,this -> right -> max_fine);
                minimize(cur_dead,this -> right -> max_dead);
            }
            this -> max_fine = cur_fine;
            this -> max_dead = cur_dead;
        }
    };
    Node *tree = nullptr;

    Node* rotateLeft(Node* cur_tree){
        Node *new_root = cur_tree -> right;
        Node *ll = new_root -> left;
        new_root -> left = cur_tree;
        cur_tree -> right = ll;
        cur_tree -> computeInfo();
        new_root -> computeInfo();
        return new_root;
    }

    Node* rotateRight(Node* cur_tree){
        Node* new_root = cur_tree -> left;
        Node* rr = new_root -> right;
        new_root -> right = cur_tree;
        cur_tree -> left = rr;
        cur_tree -> computeInfo();
        new_root -> computeInfo();
        return new_root;
    }

    Node* rotateNode(Node* cur_tree){
        if(cur_tree -> balance > 1 and cur_tree -> left -> balance >= 0){
            return rotateRight(cur_tree);
        }
        if(cur_tree -> balance > 1 and cur_tree -> left -> balance < 0){
            cur_tree -> left = rotateLeft(cur_tree -> left);
            return rotateRight(cur_tree);
        }
        if(cur_tree -> balance < -1 and cur_tree -> right -> balance <= 0){
            return rotateLeft(cur_tree);
        }
        if(cur_tree -> balance < -1 and cur_tree -> right -> balance > 0){
            cur_tree -> right = rotateRight(cur_tree -> right);
            return rotateLeft(cur_tree);
        }
        return cur_tree;
    }

    Node* insertKey(Node *cur_tree,Key key){
        if(cur_tree == nullptr){
            return new Node(key);
        }
        if(key < cur_tree -> key){
            cur_tree -> left = insertKey(cur_tree -> left,key);
        } else if(key > cur_tree -> key){
            cur_tree -> right = insertKey(cur_tree -> right,key);
        } else {
            return cur_tree;
        }
        cur_tree -> computeInfo();
        cur_tree = rotateNode(cur_tree);
        return cur_tree;
    }

    Node* findLeftMost(Node *cur_tree){
        Node* ret = cur_tree;
        while(ret -> left){
            ret = ret -> left;
        }
        return ret;
    }

    Node* deleteKey(Node *cur_tree,Key key){
        if(cur_tree == nullptr){
            return nullptr;
        }
        if(key < cur_tree -> key){
            cur_tree -> left = deleteKey(cur_tree -> left,key);
        } else if(key > cur_tree -> key){
            cur_tree -> right = deleteKey(cur_tree -> right,key);
        } else {
            if(cur_tree -> left and cur_tree -> right){
                Node* t = findLeftMost(cur_tree -> right);
                cur_tree -> key = t -> key;
                cur_tree -> right = deleteKey(cur_tree -> right,t -> key);
            } else if(cur_tree -> left){
                cur_tree = cur_tree -> left;
            } else if(cur_tree -> right){
                cur_tree = cur_tree -> right;
            } else {
                cur_tree = nullptr;
            }
        }
        if(cur_tree == nullptr){
            return nullptr;
        }
        cur_tree -> computeInfo();
        cur_tree = rotateNode(cur_tree);
        return cur_tree;
    }

    bool findKey(Node *cur_tree,Key key){
        if(!cur_tree){
            return false;
        }
        bool cl = false,cr = false;
        if(key < cur_tree -> key){
            cl =  findKey(cur_tree -> left,key);
        } else if(key > cur_tree -> key){
            cr = findKey(cur_tree -> right,key);
        } else {
            return true;
        }
        return (cl | cr);
    }

    Key findKth(Node* cur,int k){
        Node* cur_tree = cur;
        while(true){
            int cl = (cur_tree -> left ? cur_tree -> left -> size_subtree : 0);
            if(cl + 1 == k){
                return cur_tree -> key;
            } else if(cl + 1 < k){
                cur_tree = cur_tree -> right;
                k -= (cl + 1);
            } else {
                cur_tree = cur_tree -> left;
            }
        }
    }

    int n,q;
    vector <Key> tot;

    void print(int k,Key key){
        cout<<"Query ? 4 "<<k<<" :\n";
        cout<<"The answer is the city with the index "<<key.city_id<<" \n";
        cout<<"- Information of the city "<<key.city_id<<" -\n";
        cout<<"-> Number of current patients :"<<' '<<key.cur<<'\n';
        cout<<"-> Has recovered :"<<' '<<key.fine<<'\n';
        cout<<"-> Was dead :"<<' '<<key.dead<<'\n';
    }

    void solve(){
        cin>>n>>q;
        tot.resize(n + 2,Key());
        for(int i = 1;i <= n;++i){
            tot[i] = Key(0,0,0,i);
        }
        while(q--){
            char c;
            int type;
            cin>>c>>type;
            if(c == 'q'){
                int x,y;
                cin>>x>>y;
                if(type == 1){
                    if(findKey(tree,tot[x])) {
                        tree = deleteKey(tree, tot[x]);
                    }
                    tot[x].cur += y;
                    tree = insertKey(tree,tot[x]);
                } else if(type == 2){
                    if(findKey(tree,tot[x])) {
                        tree = deleteKey(tree, tot[x]);
                    }
                    tot[x].cur -= y;
                    tot[x].fine += y;
                    if(tot[x].cur > 0){
                        tree = insertKey(tree,tot[x]);
                    }
                } else {
                    if(findKey(tree,tot[x])) {
                        tree = deleteKey(tree, tot[x]);
                    }
                    tot[x].cur -= y;
                    tot[x].dead += y;
                    if(tot[x].cur > 0){
                        tree = insertKey(tree,tot[x]);
                    }
                }
            } else {
                if(type == 4){
                    int k;
                    cin>>k;
                    print(k,findKth(tree,k));
                } else if(type == 5){
                    cout<<"Query ? 5 :\n";
                    cout<<"The number of safe cities is "<<n - (tree ? tree -> size_subtree : 0)<<'\n';
                } else if(type == 6){
                    int mx = (tree ? -(tree -> max_fine).first : 0);
                    int id = (tree ? (tree -> max_fine).second : 0);
                    cout<<"Query ? 6 :\n";
                    if(mx == 0){
                        cout<<"Currently, no recovery cases have been recorded\n";
                    } else {
                        cout << "The city with the highest recovery is city with the index " << id << '\n';
                        cout << "Quantity: " << mx << " people\n";
                    }
                } else {
                    int mx = (tree ? -(tree -> max_dead).first : 0);
                    int id = (tree ? (tree -> max_dead).second : 0);
                    cout<<"Query ? 7 :\n";
                    if(mx == 0){
                        cout<<"Currently, no deaths have been recorded\n";
                    } else {
                        cout << "The city with the highest death is city with the index " << id << '\n';
                        cout << "Quantity: " << mx << " people\n";
                    }
                }
                cout<<'\n';
            }
        }
    }
}

int main(void){
/*
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
*/
    task::solve();
}

