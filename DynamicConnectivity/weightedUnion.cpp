#include <iostream>

class weightedUnion
{
private:
    /* data */
    int *set;
    int *size;
    int _N;
    int root(int i);
public:
    weightedUnion(int N);
    ~weightedUnion();
    bool find(int p, int q); // O(N)
    void _union(int p, int q); // O(1) //worst case: O(N)
};

weightedUnion::weightedUnion(int N) : _N{N}
{
    set = new int[N];
    size = new int[N];
    for (size_t i = 0; i < N; i++)
    {
        set[i] = i; //self connceted means single nodes, no connectivity
        size[i] = 1; //starts with 1 element
    }
}

weightedUnion::~weightedUnion()
{
    delete[] set;
}

int weightedUnion::root(int i){
    while(i != set[i]){
        set[i] = set[set[i]]; //collapsible path
        i = set[i];
    }
    return i;
}

bool weightedUnion::find(int p, int q){
    return (root(p) == root(q)); 
}

void weightedUnion::_union(int p, int q){
    int i = root(p);
    int j = root(q);
    if(size[i] < size[j]){
        set[i] = j;
        size[j] += size[i];
    }
    else{
        set[j] = i;
        size[i] += size[j];
    }
}

int main(){
    weightedUnion sets(10);
    sets._union(3, 6);
    std::cout << sets.find(3, 6) << std::endl;
    return 0;
}