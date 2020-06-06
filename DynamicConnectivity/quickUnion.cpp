#include <iostream>

class quickUnion
{
private:
    /* data */
    int *set;
    int _N;
    int root(int i);
public:
    quickUnion(int N);
    ~quickUnion();
    bool find(int p, int q); // O(N)
    void _union(int p, int q); // O(1) //worst case: O(N)
};

quickUnion::quickUnion(int N) : _N{N}
{
    set = new int[N];
    for (size_t i = 0; i < N; i++)
    {
        set[i] = i; //self connceted means single nodes, no connectivity
    }
}

quickUnion::~quickUnion()
{
    delete[] set;
}

int quickUnion::root(int i){
    while(i != set[i]){
        i = set[i];
    }
    return i;
}

bool quickUnion::find(int p, int q){
    return (root(p) == root(q)); 
}

void quickUnion::_union(int p, int q){
    int pRoot = root(p);
    int qRoot = root(q);

    set[pRoot] = qRoot;
}

int main(){
    quickUnion sets(10);
    sets._union(3, 6);
    std::cout << sets.find(3, 6) << std::endl;
    return 0;
}