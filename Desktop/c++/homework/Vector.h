#ifndef VECTOR_H
#define VECTOR_H

template <class T> class Vector {
  T *_memory;   // 동적으로 생성한 T 타입의 배열을 가리킬 포인터
  unsigned _capacity; // 동적으로 할당된 메모리의 크기
  unsigned _size;     // 배열에 저장된 요소의 수

public:
  Vector(unsigned capacity = 5) {
    // _memory의 크기를 매개변수 capacity 크기로 동적으로 할당하고
    // 동적으로 할당된 배열의 요소는 없도록 초기화하는 생성자를 여기에 구현
    _memory = new T[capacity];      // capacity만큼의 메모리를 할당
    _capacity = capacity;           // capacity를 저장
    _size = 0;                      // size를 0으로 초기화
  }

  Vector(unsigned size, const T &element) {
    // 메모리의 크기와 요소의 개수를 size 만큼 설정
    // size의 두 배 크기의 메모리를 동적으로 생성
    // 동적 메모리의 각 요소의 값은 element로 초기화하는 코드를 여기에 구현
    _memory = new T[size*2];      // size*2만큼의 메모리를 할당
    _size = size;                 // size를 저장
    _capacity = size*2;            // capacity를 size*2로 저장
    for(int i = 0 ; i < size ; i++){
      _memory[i] = element;       // element로 초기화
    }
  }

  unsigned size() const {
    // 동적 배열에 저장된 요소의 갯수를 리턴
    return _size;                 // size를 리턴
  }

  unsigned capacity() const {
    // 동적 배열의 크기를 리턴
    return _capacity;             // capacity를 리턴
  }

  const T &at(unsigned index) const {
    // 동적 배열의 index 위치에 저장된 요소를 리턴
    // 배열의 크기를 넘는 인덱스틑 고려하지 않아도 됨
    return _memory[index];      // index 위치의 요소를 리턴
  }

  void set(unsigned index, const T &element) {
    // index가 유효할 경우만 동적 배열의 index 위치의 요소를 element로 변경
    // index 요소가 유효하다는 의미는 배열의 요소의 갯수를 넘지 않는 범위의 인덱스라는 의미
    if(index < _capacity){
      _memory[index] = element;   // index 위치의 요소를 element로 변경
    }
  }

  bool empty() const {
    // 배열에 저장된 요소가 없을 경우 true, 그렇지 않다면 false를 리턴
    if(_size == 0)            // size가 0이면 true, 아니면 false
      return true;
    else
      return false;
  }

  void push_back(const T &element) {
    // 배열의 끝에 element를 추가
    if (_size == _capacity){      // size가 capacity-1이면 배열이 꽉 찬 것
      T* _new = new T[_capacity * 2];     // capacity*2만큼의 메모리를 할당
      for(int i = 0 ; i < _capacity ; i++){
        _new[i] = _memory[i];             // _memory의 요소를 _new에 복사
      }
      _capacity *= 2;                      // capacity*2를 저장                  
      delete[] _memory;                   // _memory를 해제
      _memory = _new;                     // _new로 memory를 바꿈
      _memory[_size++] = element;         // element를 추가
    }
    else{
      _memory[_size++] = element;        // element를 추가
    }
  }

  void pop_back() {
    // 배열의 마지막 요소를 제거
    // 더이상 제거할 요소가 없다면 무시
    if(_size>0){                  // 요소가 있으면
      _memory[_size] = '\0';      // 마지막 요소를 제거
      _size--;                    // size를 줄임
    }
  }

  void erase(unsigned index) {
    // index가 유효한 경우, 배열의 index 위치의 요소를 삭제
    // 유효하지 않은 경우는 아무 일도 일어나지 않음
    if(index < _capacity){        // index가 유효하면
      for(int i = index ; i < _capacity ; i++){
        _memory[i] = _memory[i+1];      // index부터 끝까지 한칸씩 앞으로 당김
      }
      _size--;                          // size를 줄임
    }
  }

  void insert(unsigned index, const T &element) {
    // index 위치가 유효한 경우(배열의 요소의 수를 넘지 않는 위치)
    // index 위치에 element를 삽입
    if(index < _capacity){          // index가 유효하면
      for(int i = _capacity ; i > index ; i--){
        _memory[i] = _memory[i-1];      // index부터 끝까지 한칸씩 뒤로 밀음
      }
      _memory[index] = element;         // index에 element를 삽입
      _size++;                          // size를 늘림
    }
  }
  ~Vector(){
    //동적 메모리 해제
    delete[] _memory;                   // memory를 해제
  }
};

#endif