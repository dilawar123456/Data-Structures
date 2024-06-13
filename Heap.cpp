//This is a Min heap

#include <iostream>
using namespace std;
class Heap
{
    int *arr;
    int max_size;
    int n;

public:
    Heap(int *arr, int max_size, int size)
    {
        this->arr = arr;
        this->max_size = max_size;
        n = size;
    }
    Heap(int max_size)
    {
        this->max_size = max_size;
        arr = new int[max_size+1];
        n = 0;
    }
   void heapify(int i)
    {
        int smallest=i;
        int l=2*i;
        int r=(2*i)+1;


        if(l<=n && arr[l]<arr[smallest])
        {
            smallest=l;
        }
        else if(r<=n && arr[r]<arr[smallest])
        {
            smallest=r;
        }

        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);

            heapify(smallest);
        }
    }
    void Buildheap()
    {
        int smallest = n / 2;

        for (int i = smallest; i > 0; i--)
        {
            heapify(i);
        }
    }
    void Insert(int val)
    {
        if (n == max_size)
        {
            cout << "The Heap is full" << endl;
            return;
        }
        else
        {
            n++;
            int i;
            for (i = n; i > 1;i=i/2)
            {
                if (val > arr[i / 2])
                {
                    break;
                }
                else
                {
                    arr[i] = arr[i / 2];
                }
            }
            arr[i] = val;
        }
    }
    int Delete()
    {
        int root=arr[1];
        arr[1]=arr[n];
        n--;
        heapify(1);
        //for pop function
        return root;
    }
    void Print()
    {
        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
};
int main()
{
    int max_size;
    int x;
    int val;
    cout<<"Enter the Max size of heap";
    cin>>max_size;
    Heap h1(max_size);
    while (x!=4)
    {
        cout<<"Please select an option "<<endl;
        cout<<"1- Insert "<<endl;
        cout<<"2- Delete "<<endl;
        cout<<"3- Print "<<endl;
        cout<<"4- Exit "<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter the value to insert"<<endl;
            cin>>val;
            h1.Insert(val);
        }
        if(x==2)
        {
            h1.Delete();
           h1.Buildheap();
        }
        if(x==3)
        {
            h1.Print();
        }

    }

}