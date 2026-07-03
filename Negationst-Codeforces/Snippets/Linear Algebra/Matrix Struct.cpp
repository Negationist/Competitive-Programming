template<class T> struct Matrix{
    enum FieldType {
        DOUBLE = 0,
        MOD = 1
    };
    int n,m,type;
    static constexpr double eps = 1e-10;
    vector<vector<T>> data;
    Matrix(int n, int m) : n(n), m(m), data(n,vector<T>(m,T(0))){set_type();}
    Matrix(vector<vector<T>> &a): n((int)(a.size())), m((int)(a[0].size())), data(a){}
    Matrix() : n(0), m(0), data() { set_type(); }
    vector<T>& operator[](int i) {return data[i];}
    Matrix<T> operator*(Matrix<T>& other) const{
        assert(m == other.n);
        Matrix<T> res(n,other.m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<other.m;k++){
                    res[i][k] += data[i][j] * other[j][k];
                }
            }
        }
        return res;
    }
    void eye(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                data[i][j] = (i==j);
            }
        }
    }
    Matrix<T> operator^(ll p) {
		assert(p >= 0 && n==m);
		Matrix<T> res(n,n);
        res.eye();
        Matrix base = *this;
        while(p){
            if(p&1){
                res = res*base;
            }
            base = base*base;
            p>>=1;
        }
        return res;
	}
    void set_type(){
        if constexpr (std::is_floating_point<T>::value){
            type = DOUBLE;
        } else{
            type = MOD;
        }
    }
    T rref(){ //returns det(A) if it is square, 0 otherwise
        T det = T(n==m);
        int last_row = -1; //last row that had a pivot 
        for(int j=0;j<m;j++){ //pivot column
            int pivot_row = -1;
            if constexpr(std::is_floating_point_v<T>){
                T max_pivot = eps;
                for(int i=last_row+1;i<n;i++){
                    T num = abs(data[i][j]);
                    if(num>max_pivot){
                        pivot_row = i;
                        max_pivot = num;
                    }
                }
            } else{
                for(int i=last_row+1;i<n;i++){
                    T num = data[i][j];
                    if(num!=T(0)){
                        pivot_row = i;
                        break;
                    }
                }
            }
            if(pivot_row==-1){
                det = T(0);
                continue;
            }
            last_row++;
            if(last_row!=pivot_row){
                swap(data[last_row],data[pivot_row]);
                det*=(T(-1));
            }
            for(int i=0;i<n;i++){
                if(i!=last_row){
                    if(nonzero(data[i][j])){
                        T fact = (data[i][j]/data[last_row][j])*(T)(-1);
                        for(int k=j;k<m;k++){
                            data[i][k]+=(data[last_row][k]*fact);
                        }
                    }
                }
            }
            for(int k=j+1;k<m;k++){
                data[last_row][k]/=data[last_row][j];
            }
            det*=data[last_row][j];
            data[last_row][j] = T(1);
        }
        return det;
    }
    void transpose(){
        Matrix<T> res(m,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][i] = data[i][j];
            }
        }
        *this = res;
    }
    bool nonzero(T val){
        if(type==DOUBLE){
            return (abs(val)>eps);
        } else{
            return (val!=T(0));
        }
    }
    friend Matrix<T> rref(const Matrix<T> &A){
        Matrix<T> res = A;
        res.rref();
        return res;
    }
    friend Matrix<T> transpose(const Matrix<T> &A){
        Matrix<T> res = A;
        res.transpose();
        return res;
    }
    friend int rankof(const Matrix<T> &A){
        int res = 0;
        Matrix<T> temp = A;
        temp.rref();
        for(int i=0;i<temp.n;i++){
            bool found = 0;
            for(int j=0;j<temp.m;j++){
                if(temp.nonzero(temp[i][j])){
                    found = 1;
                }
            }
            res+=found;
        }
        return res;
    }
    friend int nullityof(const Matrix<T> &A){
        return A.m-rankof(A);
    }
    friend void debug(const Matrix<T> &A){
        cout << "\n";
        for(int i=0;i<A.n;i++){
            for(int j=0;j<A.m;j++){
                cout << A.data[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};