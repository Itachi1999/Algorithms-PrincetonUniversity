// Now, this algorithm is not efficient; The time complexity of the union method is of O(N)
// If we want to union N elements of the array then we will have a time complexity of O(N^2)
// We, consider that to be very inefficient

#include <iostream>

class quickFind
{
private:
    /* data */
    int *set;
    int _N;
public:
    quickFind(int N);
    ~quickFind();
    bool find(int p, int q); // O(1)
    void _union(int p, int q); // O(N)
};

quickFind::quickFind(int N) : _N{N}
{
    set = new int[N];
    for (size_t i = 0; i < N; i++)
    {
        set[i] = i; //self connceted means single nodes, no connectivity
    }
}

quickFind::~quickFind()
{
    delete[] set;
}

bool quickFind::find(int p, int q){
    return (set[p] == set[q]);
}

void quickFind::_union(int p, int q){
    int pid = set[p];
    int qid = set[q];

    for (size_t i = 0; i < _N; i++)
    {
        if(set[i] == pid)
            set[i] = qid;
    }
    
}

int main(){
    quickFind sets(10);
    sets._union(3, 6);
    std::cout << sets.find(3, 6) << std::endl;
    return 0;
}