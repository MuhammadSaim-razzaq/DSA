#include<iostream>
#include<limits.h>
using namespace std;

class node{
    public:
    //string
    string key;
    //string
    string value;
    node* next;

    node(string key,string value):key(key),value(value){
        next = nullptr;
    }
};

class hashmap{
    //present elements 
    //total capacity
    int nofelements,capacity;

    node** arr;
public:
    hashmap(int cap =100):capacity(cap),nofelements(0){
        arr = new node*[capacity];

        for(int i=0; i<capacity;i++){
            arr[i] = NULL;
        }

    }

    int hashfunction(string key){
        int sum =0, factor = 31;

        for(char c: key){
            sum = ((sum % capacity) + ((int)c * factor) % capacity) % capacity;
            factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
        }
        return sum;
    }

    void insert(const string& key, const string& value){
        node* newnode = new node(key,value);
        int index = hashfunction(key);

        if(arr[index] == nullptr){
            arr[index] = newnode;
        }else{
            //insert at start
            newnode->next = arr[index];
            arr[index]= newnode;
        }
        nofelements++;
    }

    void deletekey(const string& key){
        int index = hashfunction(key);
        node* temp = arr[index];
        node* prev= nullptr;
        
        while(temp!= nullptr){
            if(temp->key == key){
                if(prev != nullptr){
                    prev->next = temp->next;
                }else{
                    arr[index] = temp->next;
                }
                delete temp;
                nofelements--;
                cout<<"elemnet deleted"<<endl;
                return;
            }else{
                prev = temp;
                temp= temp->next;
            }
        }
        cout<<"element not found"<<endl;
    }



    void search(const string& key){
        int index = hashfunction(key);
        node* temp = arr[index];
        while(temp != nullptr){
            if(temp->key == key){
                cout<<"found at"<<index<<endl;
                return;
            }else{
                temp = temp->next;
            }
        }
        cout<<"not found"<<endl;
    }
};



int main(){
    hashmap h(10);
    h.insert("2","saim");
    h.deletekey("2");
    h.insert("3","hi saim");
    h.search("3");
    h.search("2");
}