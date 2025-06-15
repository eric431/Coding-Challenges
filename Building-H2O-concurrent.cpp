class H2O {
    public:
        int num_h {};
        int num_o {};
    
        condition_variable cv;
        mutex mtx;
    
        H2O() {
            num_h = 0;
            num_o = 0;    
        }
    
        void hydrogen(function<void()> releaseHydrogen) {
            unique_lock<mutex> lock(mtx);
    
            cv.wait(lock, [this]{ return ((num_h < 2) && (num_o <= 1)); });
            ++num_h;
    
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();
    
            if(num_h == 2 && num_o == 1){
                num_h = 0;
                num_o = 0;
            }
    
            cv.notify_all();
        }
    
        void oxygen(function<void()> releaseOxygen) {
            unique_lock<mutex> lock(mtx);
    
            cv.wait(lock, [this]{ return ((num_h <= 2) && (num_o < 1)); });
            ++num_o;
    
            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();
    
            if(num_h == 2 && num_o == 1){
                num_h = 0;
                num_o = 0;
            }
    
            cv.notify_all();
        }
    };