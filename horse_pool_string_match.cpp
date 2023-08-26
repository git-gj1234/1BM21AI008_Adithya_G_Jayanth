#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class horsepool{
    private:
        string text, pattern;
        unordered_map<char, int> shift_table;
    public:
        void get_strings();
        void fill_shift_table();
        void match_string();
};

void horsepool::get_strings(){
    cout << "enter the text: ";
    cin >> text;
    cout << "enter the pattern to match: ";
    cin >> pattern;
}

void horsepool::fill_shift_table(){
    int m = pattern.length();
    for(int i = 0; i < m - 1; i++){
        shift_table[pattern[i]] = m - i - 1;
    }
}

void horsepool::match_string(){
    int n = text.length();
    int m = pattern.length();
    int i = m-1;
    int x;
    while(i <= n-1){
        int k = 0;
        while(k < m && text[i-k] == pattern[m-k-1]){
            k++;
        }
        if(k == m){
            cout << "pattern match found at string index: " << i - m + 1 << "\n";
            cout << "pattern match found at absolute position: " << i - m + 2 << "\n";
            return ;
        }
        else    
            x = shift_table[text[i]]; 
            if(x == 0)
                i+=m;
            else 
                i+=x;
    }
    cout << "pattern not found in input string:";

}

int main(void){
    horsepool solver;
    solver.get_strings();
    solver.fill_shift_table();
    solver.match_string();
    return 0;
}