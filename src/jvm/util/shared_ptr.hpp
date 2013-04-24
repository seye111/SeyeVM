#ifndef JVM_SHARED_PTR_H
#define JVM_SHARED_PTR_H

#include <iostream>

namespace Jvm{

	template<typename T>
	class shared_ptr{
		T* ptr;
		int* ref_count;
	public:

		shared_ptr() : ptr(NULL), ref_count(new int(0)) {
			using std::cout;
			using std::endl;
			cout << "shared_ptr default constructor called [" << this << " : NULL], ref_count is " << *ref_count << endl;
		}

		shared_ptr(T* ptr) : ptr(ptr), ref_count(new int(0)) {
			using std::cout;
			using std::endl;
			if(ptr){
				++*ref_count;
			}
			cout << "shared_ptr pointer constructor called [" << this << " : " << ptr << "], ref_count is " << *ref_count << endl;
		}
		
		shared_ptr(const shared_ptr<T> & that) : ptr(that.ptr), ref_count(that.ref_count){
			using std::cout;
			using std::endl;
			if(ptr){
				++*ref_count;
			}
			cout << "shared_ptr copy constructor called [" << this << ", " << &that << " : " << that.ptr << "] "
				<< "ref_count is " << *ref_count << endl;
		}
		
		~shared_ptr(){
			using std::cout;
			using std::endl;
			if(!ptr){
				cout << "shared_ptr called destructor pointer not initialized " << *ref_count << " " << ptr << endl;
				return;
			}
			--*ref_count;
			cout << "shared_ptr destructor called [" << this << " : " << ptr << "], ref_count is " << *ref_count << endl;
			if(!*ref_count){ 
				cout << "shared_ptr deleting object" << endl;
				delete ptr;
				delete ref_count;
			}
		}

		shared_ptr<T> & operator=(const shared_ptr<T> & that){
			using std::cout;
			using std::endl;
			cout << "shared_ptr assignement= called [" << this << " : " << ptr << ", " << &that << " : " << that.ptr << "] ";
			if(that.ptr != ptr){
				if(ptr){
					--*ref_count;
					if(!*ref_count){
						delete ptr; 
						delete ref_count;
					}
				}
				ptr = that.ptr;
				ref_count = that.ref_count;
				++*ref_count;
			}
			cout << " ref_count is " << *ref_count << endl;
			return *this;
		}

		T & operator*() {return *ptr;} 

		T* operator->() {return ptr;} 

		T* get(){ return ptr;}
	
	};

}


#endif