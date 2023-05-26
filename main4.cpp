#include "Buffer.hpp"

//Testing circular buffer

int main()
{

Buffer<int> baf;
std::cout<< baf.empty() << std::endl;
baf.push(2).push(4).push(6).push(8).push(10).push(12);
std::cout<< baf.pop() << "\t" << baf.pop() << "\t" << baf.pop() << std::endl;
std::cout<< "Prva: " << baf.capacity() << std::endl;
baf.push(14).push(16).push(18).push(20).push(22).push(24).push(33);
std::cout<< "Prije realloc() " << baf.size() << "\t" << baf.capacity() << std::endl;
std::cout<< baf.front() << "\t" << baf.back() << std::endl;
baf.push(75);
std::cout<< "Poslije realloc() " <<baf.size() << "\t" << baf.capacity() << std::endl;
std::cout<< baf.front() << "\t" << baf.back() << std::endl;
Buffer<int> baf2 = baf;
std::cout<< baf2.front() << "\t" << baf2.back() << std::endl;
baf2.pop();
std::cout<< baf.front() << "\t" << baf.back() << std::endl;
std::cout<< baf2.front() << "\t" << baf2.back() << std::endl;

}
