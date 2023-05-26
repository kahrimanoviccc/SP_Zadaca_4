#pragma once

#include<iostream>

template <typename T>
class Buffer{
  

  public:

  Buffer(size_t);
  Buffer();
  Buffer(const Buffer&);
  Buffer(Buffer&&);
  
  Buffer& operator=(const Buffer&);
  Buffer& operator=(Buffer&&);
  
  ~Buffer();
  
  template <typename N>
  Buffer& push(N&&);

  T pop();

  const T& front();
  const T& front() const;

  const T& back();
  const T& back() const;
 
  size_t size() const;
  size_t capacity() const;
  bool empty() const;


  private:
  
  void realloc();
  size_t capacity_;
  size_t size_;
  T* data_;
  int frst_ = 0;
  int lst_ = 0;
};

template <typename T>
  void Buffer<T>::realloc(){
    auto tmp = new T[capacity_*2];
    auto dif = size_ - frst_;
    capacity_*=2;
    std::copy(data_ + frst_, data_ + size_, tmp);
    std::copy(data_, data_+lst_, tmp + dif);
    frst_ = 0;
    lst_ = size_ - 1;
    delete [] data_;
    data_ = tmp;
  };

template <typename T>
  Buffer<T>::Buffer(size_t max_el)
    :  capacity_{max_el},size_{0}, data_{new T [capacity_]}
  {};

template <typename T>
  Buffer<T>::Buffer()
    : capacity_{10}, size_{0}, data_{new T[capacity_]} 
  {};

template <typename T>
  Buffer<T>::Buffer(const Buffer& o){
  capacity_ = o.capacity_;
  size_ = o.size_;
  data_ = new T[capacity_];
  std::copy(o.data_, o.data_+o.size_, data_);
  frst_ = o.frst_;
  lst_ = o.lst_;
  };

template <typename T>
  Buffer<T>::Buffer(Buffer&& o){
   capacity_ = o.capacity_;
  size_ = o.size_;
  data_ = o.data_;

  o.capacity_ = o.size_ = 0;
  o.data_ = nullptr;  
  frst_ = o.frst_;
  lst_ = o.lst_;
  };

template <typename T>
  Buffer<T>& Buffer<T>::operator=(const Buffer& o){
  
    delete [] data_;
  
  capacity_ = o.capacity_;
  size_ = o.size_;
  data_ = new T[capacity_];
  std::copy(o.data_, o.data_+o.size_, data_);
  frst_ = o.frst_;
  lst_ = o.lst_;

  return *this;
  
  };

template <typename T>
  Buffer<T>& Buffer<T>::operator=(Buffer&& o){
  
    delete [] data_;
  
  capacity_ = o.capacity_;
  size_ = o.size_;
  data_ = o.data_;
  frst_ = o.frst_;
  lst_ = o.lst_;

  o.capacity_ = o.size_ = 0;
  o.data_ = nullptr;  
  
  return *this;

  };

template <typename T>
  Buffer<T>::~Buffer(){
  
    delete [] data_;
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
};

template <typename T>
template  <typename N>
  Buffer<T>& Buffer<T>::push(N&& e){
if(size_ == 0){
data_[lst_] = std::forward<N>(e);
size_++;
}else if(size_ < capacity_){
  if(lst_ == capacity_){
    lst_ = 0;
    data_[lst_] = std::forward<N>(e);
    size_++;
  }else{  
    data_[++lst_] = std::forward<N>(e);
    size_++;
  };
}else{
  realloc();
  data_[++lst_] = std::forward<N>(e);
  size_++;
};
return *this;
};

template <typename T>
T Buffer<T>::pop(){
size_--;
return data_[frst_++];
};

template <typename T>
  const T& Buffer<T>::front(){
return data_[frst_];
};

template <typename T>
  const T& Buffer<T>::front() const{
return data_[frst_];
};

template <typename T>
  const T& Buffer<T>::back(){
return data_[lst_];
};

template <typename T>
  const T& Buffer<T>::back() const{
return data_[lst_];
};

template <typename T>
  size_t Buffer<T>::size() const{
  return size_;
  };

template <typename T>
  size_t Buffer<T>::capacity() const{
  return capacity_;
  };

template <typename T>
  bool Buffer<T>::empty() const{
  return size_ == 0;
  };



