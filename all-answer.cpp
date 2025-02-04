#include<iostream>
#include<vector>
using namespace std;


//  merge sort started
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> arr2;
    int left = low;
    int right = mid+1;


    while(left <= mid && right <= high )
    {
            if(arr[left] <= arr[right])
            {
                arr2.push_back(arr[left]);
                left++;
            }
            else 
            {
                arr2.push_back(arr[right]);
                right++;
            }
    }

    while(left<=mid)
    {
        arr2.push_back(arr[left]);
        left++;
    }


    while(right<=high)
    {
        arr2.push_back(arr[right]);
        right++;
    }


for(int i=low; i<=high; i++){

    arr[i]  = arr2[i-low];
}


}

int merge_sort(vector<int> &arr, int low, int high)
{

    if(low >= high){
        return 0;
    }

    int mid = (low + high)/2; 

    merge_sort(arr, low, mid);  
    merge_sort(arr, mid+1, high);

    merge(arr, low, mid, high);


}




void mainmerge_sort(vector<int> &arr){

    int n = arr.size();

     merge_sort(arr, 0, n-1);

     for(int i=0; i<n; i++){
    cout<< arr[i] << " " ;
}
cout<<endl;
}


/// merge sort ended


///quick sort start

int part(vector<int>  &arr, int low, int high){

        int last=arr[high];
        int i=low-1;

        for(int j=low;j<high;j++){
            if(arr[j] < last){
                i++;
                swap(arr[i],arr[j]);
            }
        }

        swap(arr[i+1],arr[high]);
        return i+1;

}

int quick_sort(vector<int> &arr, int low, int high){
    if(low < high){
        int p = part(arr,low,high);

        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);    
   }
}




void mainquick_sort(vector<int> &arr){
     int n=arr.size();

    quick_sort(arr,0,n-1);


    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

///quick sort end


///link-list start

class node
{
        public:
        int data;
        node *add;
};

void mainlinkedlist(){
    node *obj = new node();
    node *obj2= new node();
    node *obj3= new node();

    obj->data=10;
    obj->add=NULL;

    obj2->data=20;
    obj2->add=NULL;
    obj->add=obj2;


    obj3->data=30;
    obj3->add=NULL;
    obj2->add=obj3;


    cout<<"data is a ---->"<<obj->data<<"    "<<"adress is a ----> "<<obj->add<<endl;
    cout<<"data is a ---->"<<obj2->data<<"    "<<"adress is a ----> "<<obj2->add<<endl;
    cout<<"data is a ---->"<<obj3->data<<"    "<<"adress is a ----> "<<obj3->add<<endl;

}
///link-list end




///binary search start

void print_arr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl; 
}

int binary_search(int arr[], int low,int high,int target)
{

    while(low < high)
    {
            int mid=(low+high)/2;
            if(arr[mid]== target){
                return mid;
            }
            else if(arr[mid]>target){
                    high=mid;
            }
            else
            {
                low=mid+1;
            }
            
    }
    return -1;
    
}

void mainsearch(){
     int arr[5]={5, 10, 20, 30, 40};
        int n=5;
        int t;
        cout<<"enter a found element: ";
        cin>>t;

         print_arr(arr, n);

         int l_index= binary_search(arr,0, n ,t);

        if(l_index == -1)
        {
            cout<<"element not found...!"<<endl;
        }
        else
        {
            cout<<"element found at:"<<l_index <<endl;
        }

}

///binary search end





int main(){

   vector<int> arr = {5, 2, 1, 3, 4, 7, 6}; 
 
   int choice;
               
         do{

         cout<<"press 1 for linked list"<<endl;
         cout<<"press 2 for merege sort:"<<endl;
         cout<<"press 3 for Quick sort:"<<endl;
         cout<<"press 4 for binary search:"<<endl;


          cout<<"choice:";
          cin>>choice;


            switch(choice){
                    case 1:
                         mainlinkedlist();
                         cout<<"================================================"<<endl;
                    break;

                     case 2:
                            mainmerge_sort(arr);
                               cout<<"================================================"<<endl;
                    break;

                     case 3:
                            mainquick_sort(arr);
                               cout<<"================================================"<<endl;
                    break;

                     case 4:
                            mainsearch();
                               cout<<"================================================"<<endl;
                    break;

                    default:
                        cout<<"number is not in available:"<<endl;
                    break;
            }


         }while(choice!=0);

   

    return 0;
}