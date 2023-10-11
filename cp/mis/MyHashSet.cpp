class MyHashMap 
{
private:
    int hash[1000001];
    int key[1000001];
    int value[1000001];
public:
    MyHashMap() 
    {
        for(int i=0;i<1000001;i++)
        {
            hash[i]=0;
            key[i]=0;
            value[i]=0;
        }
    }
    
    void put(int k, int v) 
    {
        if(hash[k]==0)
        {
            hash[k]=1;
            key[k]=k;
            value[k]=v;
        }
        else
        {
            int i=k;
            while(hash[i]!=0)
            {
                if(key[i]==k)
                {
                    value[i]=v;
                    return;
                }
                i++;
                if(i==1000001)
                    i=0;
            }
            hash[i]=1;
            key[i]=k;
            value[i]=v;
        }
    }
    
    int get(int k) 
    {
        if(hash[k]==0)
            return -1;
        else
        {
            int i=k;
            while(hash[i]!=0)
            {
                if(key[i]==k)
                    return value[i];
                i++;
                if(i==1000001)
                    i=0;
            }
            return -1;
        }
    }
    
    void remove(int k) 
    {
        if(hash[k]==0)
            return;
        else
        {
            int i=k;
            while(hash[i]!=0)
            {
                if(key[i]==k)
                {
                    hash[i]=0;
                    key[i]=0;
                    value[i]=0;
                    return;
                }
                i++;
                if(i==1000001)
                    i=0;
            }
        }
    }

};
int main()
{
    MyHashMap* obj = new MyHashMap(); 
    int key=1;
    int value=1;
    obj->put(key,value);
    int param_2 = obj->get(key);
    obj->remove(key);
    return 0;
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */