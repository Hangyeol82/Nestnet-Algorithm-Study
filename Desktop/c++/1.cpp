#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize){
    
}

int main()
{
    // remove() 함수를 int로 구체화하는 경우

    cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;
    int x[] = {1, 2, 3, 4};
    int y[] = {-3, 5, 10, 1, 2, 3};
    int retSize;
    auto p = remove(x, 4, y, 6, retSize);
    if (retSize == 0)
    {
        cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < retSize; i++)
            cout << p[i] << ' ';
        cout << endl;
        delete[] p; // 할당받은 배열 반환 }
        // 배열의 모든 원소 출력
        // remove() 함수를 double로 구체화하는 경우 
        // 이곳에 작성
    }
}