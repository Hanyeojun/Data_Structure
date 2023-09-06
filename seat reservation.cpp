#include <iostream>
using namespace std;

class arr2D {
public:
    void set(int x, int y, int z) {
        // int k = x*6+y;
        int k = x * dimy + y;
        if (storage[k] != 0) {
            cout << "ERROR!!";
            return;
        }
        storage[k] = z;
    }

    int get(int x, int y) {
        // int k = x*6+y;
        int k = x * dimy + y;
        return storage[k];
    }
    arr2D(int x, int y) {
        int k = x * y;
        dimy = y;
        // storage = (int *) malloc(k * sizeof(int));
        storage = new int[k];
        for (int i = 0; i < k; i++) storage[i] = 0; // 예약번호는 양의정수
    }
private:
    // int storage[30];
    int* storage;
    int dimy;
};

int main()
{
    arr2D r(3, 7);
    int x, y, z; // 행, 렬, 값
    for (int i = 0; i < 4; i++) {
        cin >> x >> y >> z; // 행 렬 값 
        r.set(x, y, z);
    }
    for (int i = 0; i < 3; i++) {
        cin >> x >> y; // 행 렬
        cout << r.get(x, y);
    }
}
