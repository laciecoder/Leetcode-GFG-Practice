class ProductOfNumbers {
public:
    vector<int> arr;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);    
    }
    
    int getProduct(int k) {
        int prod = 1;
        for(int i = 1; i <= k; i++)
            prod *= arr[arr.size() - i];
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */