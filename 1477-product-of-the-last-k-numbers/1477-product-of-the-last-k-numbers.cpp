class ProductOfNumbers {
public:
    vector<int>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        // if num is 0 clear the vector
        if(num==0) {
            v.clear();
            return;
        }
        
        // otherwise push the prefix product
        if(v.empty()) {
            v.push_back(num);
        }
        else {
            v.push_back(v.back()*num);
        }
    }
    
    int getProduct(int k) {
        // if k is exceeding the size of the vector that means 0 must have appeared in the stream. 0 has appeared that's why vector got cleared and size became less than k.
        // so product must be 0
        if(k>v.size()) {
            return 0;
        }
        
        // otherwise find the product of the last k elements 
        if(k==v.size()) {
            return v[k-1];
        }
        return v.back()/(v[v.size()-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */