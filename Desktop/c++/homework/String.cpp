// 여기에 정의되지 않은 String 클래스의 멤버 함수들을 구현
#include "String.h"
#include <cstring>
#include <iostream>

const unsigned String::npos = -1;

String::String(){
    memory = new char[10];      // 10개의 문자를 저장할 수 있는 메모리를 할당
    memory[0] = '\0';           // memory에 '\0'을 저장
    capacity = 10;              // capacity에 10을 저장
}

String::String(const char *str){
    capacity = strlen(str)+1;             // capacity에 str+1의 길이를 저장
    memory = new char[capacity];     // capacity 만큼의 메모리를 할당
    strcpy(memory, str);                // str을 memory에 복사
}

String::String(const String &str){
    memory = new char[str.capacity];    // str의 capacity만큼의 메모리를 할당
    strcpy(memory, str.memory);         // str의 memory를 memory에 복사
    capacity = str.capacity;            // capacity에 str의 capacity를 저장
}

String::~String(){
    delete[] memory;                    // memory를 해제
}

void String::set(const char *str){
    delete[] memory;                   // memory를 해제
    capacity = strlen(str)+1;            // capacity에 str의 길이를 저장
    memory = new char[capacity];      // capacity 만큼 메모리를 할당
    strcpy(memory, str);               // str을 memory에 복사
}

void String::set(const String &str){
    delete[] memory;                // memory를 해제
    capacity = str.capacity;        // capacity에 str의 capacity를 저장
    memory = new char[capacity];    // capacity 만큼 메모리를 할당
    strcpy(memory, str.memory);     // str의 memory를 memory에 복사
}

unsigned String::length() const{
    unsigned l = 0;                 // 반환할 값
    while(memory[l] != '\0'){       
        l++;                        // memory의 길이를 구함
    }
    return l;
}

unsigned String::size() const{
    unsigned l = 0;                 // 반환할 값
    while (memory[l] != '\0')
    {
        l++;                        // memory의 길이를 구함
    }
    return l;
}

String String::substr(unsigned position, unsigned length) const{
    String tmp;                     // 반환할 객체
    tmp.memory = new char[length+1];    // length+1만큼의 메모리를 할당 (마지막에 '\0'을 넣기 위해)
    for(int i = 0 ; i <=length ; i++){
        tmp.memory[i] = memory[position + i];  // memory의 position부터 length만큼을 tmp에 복사 
    }
    tmp.memory[length] = '\0';      // 마지막에 '\0'을 넣음
    tmp.capacity = length+1;        // capacity에 length+1을 저장
    return tmp;
}

void String::insert(unsigned position, const char *str){
    char *tmp = new char[capacity + strlen(str)];       // capacity + str의 길이만큼의 메모리를 할당
    for(int i = 0 ; i < position ; i++){
        tmp[i] = memory[i];                             // position 전까지는 memory를 그대로 복사
    }
    for(int i = 0 ; i < strlen(str) ; i++){
        tmp[position + i] = str[i];             // str을 position부터 복사
    }
    for(int i = position ; i < capacity ; i++){
        tmp[i + strlen(str)] = memory[i];               // position 이후의 memory를 str이 끝나는 위치부터 복사
    }
    capacity += strlen(str);                        // capacity를 str의 길이만큼 증가
    delete[] memory;                                // 기존의 memory를 해제
    memory = tmp;                                   // tmp를 memory에 복사
}

void String::insert(unsigned position, const String &str){
    char *tmp = new char[capacity + str.size()];  // capacity + str의 크기 만큼의 메모리를 할당
    for(int i = 0 ; i < position ; i++){
        tmp[i] = memory[i];                         // position 전까지는 memory를 그대로 복사
    }
    for(int i = 0 ; i < str.size() ; i++){
        tmp[position + i] = str.memory[i];          // str을 position부터 복사
    }
    for(int i = position ; i < capacity ; i++){
        tmp[i + str.size()] = memory[i];          // position 이후의 memory를 str이 끝나는 위치부터 복사
    }
    capacity += str.size();                       // capacity를 str.size만큼 증가
    delete[] memory;                             // 기존의 memory를 해제
    memory = tmp;                               // tmp를 memory에 복사
}

void String::erase(unsigned position, unsigned length){
    char *tmp = new char[capacity - length];    // capacity - length만큼의 메모리를 할당
    for(int i = 0 ; i < position ; i++){
        tmp[i] = memory[i];                     // position 전까지는 memory를 그대로 복사
    }
    for(int i = position + length ; i < capacity ; i++){
        tmp[i - length] = memory[i];            // position + length 이후의 memory를 length만큼 앞으로 복사
    }
    capacity -= length;                         // capacity를 length만큼 감소
    delete[] memory;                            // 기존의 memory를 해제
    memory = tmp;                               // tmp를 memory에 복사
}

void String::replace(unsigned position, unsigned length, const char *str){
    erase(position, length);                    // position부터 length만큼을 삭제
    insert(position, str);                      // position에 str을 삽입
}

void String::replace(unsigned position, unsigned length, const String &str){
    erase(position, length);                    // position부터 length만큼을 삭제
    insert(position, str);                      // position에 str을 삽입
}

unsigned String::find(const char *str, unsigned position) const{
    for(int i = position ; i < capacity ; i++){
        if(memory[i] == str[0]){                // memory의 i번째 문자가 str의 첫번째 문자와 같을 때 for문 진행
            for(int j = 0 ; j < strlen(str) ; j++){
                if(memory[i+j] != str[j]){
                    break;                      // 문자가 다르면 break
                }
                if(j == strlen(str)-1){
                    return i;                   // 문자가 같으면 i를 반환
                }
            }
        }
    }
    return npos;                                // 문자열을 찾지 못하면 npos를 반환
}  

unsigned String::find(const String &str, unsigned position) const{
    for(int i = position ; i < capacity ; i++){
        if(memory[i] == str.memory[0]){         // memory의 i번째 문자가 str의 첫번째 문자와 같을 때 for문 진행
            for(int j = 0 ; j < str.size() ; j++){
                if(memory[i+j] != str.memory[j]){
                    break;                      // 문자가 다르면 break
                }
                if(j == str.size()-1){
                    return i;                   // 문자가 같으면 i를 반환
                }
            }
        }
    }
    return npos;                                // 문자열을 찾지 못하면 npos를 반환
}   

