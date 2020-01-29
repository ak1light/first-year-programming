#include <iostream>
void swap(int*, int*);
int msort(int*, int*, int*);
void info(const int*);
int* add(int*, const int*);

		int main() {
			int a = 5, b = 3, c = 1;
			info(&a);
			info(&b);
			info(&c);
			msort(&a, &b, &c);
			info(add(&a, add(&b, &c))); 
			
			return(0);
		}
		void swap(int* a, int* b) {
			*a = *a + *b;
			*b = *a - *b;
			*a = *a - *b;	
		}
		void info(const int* a) {
			std::cout << "Address:" << a << ";" << "Zna4enie:" << *a << ";"<< std::endl;
		}
		int msort(int* a , int* b , int* c) {
			if (*a > * b) swap(a, b);
			if (*b > * c) swap(b, c);
			if (*a > * b) swap(a, b);
			if (*b > * c) swap(b, c);
			
			return (*c);
		}
		int* add(int* a, const int* c) {
			*a += *c;
			return(a);
		}
