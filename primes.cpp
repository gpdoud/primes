
#include <iostream>
#include <bitset>

using namespace std;

const long MAX_PRIME = 1000000;
bitset<MAX_PRIME> bits;

void set_bit_false(long n) {
    bits.set(n, 0);
}

void set_multiples_false(long n) {
    for(auto i = 2; n * i < MAX_PRIME; i++) {
        bits.set(n * i, false);
    }
}

void check_prime(long n) {
    for(auto i = 2; i < n; i++) {
        if(n % i == 0) {
            set_bit_false(n);
            return;
        }
    }
    set_multiples_false(n);
}

void display_primes() {
    cout << "Prime number up to " << MAX_PRIME << endl;
    for(auto idx = 0; idx < MAX_PRIME; idx++) {
        if(bits.test(idx)) {
            cout << idx << ", ";
        }
    }
    cout << endl;
}

int main() {
    bits.set();
    bits.reset(0);
    for(auto idx = 2; idx < MAX_PRIME; idx++) {
        if(bits.test(idx) == false)
            continue;
        check_prime(idx);
    }
    display_primes();
    return 0;
}