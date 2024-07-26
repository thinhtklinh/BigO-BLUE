#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Ex1: Fashion in Berland

// int main(int argc, char **argv) {
//     int N;
//     cin >> N;
//     int flag = 0;

//     for (int i = 0; i < N; i++) {
//         int button;
//         cin >> button;
//         if (button == 0)
//             flag++;
//     }

//     if (N == 1 && flag == 0) cout << "YES";
//     else if (N != 1 && flag == 1)
//         cout << "YES";
//     else
//         cout << "NO";

//     return 0;
// }

// Ex3: Bear and Game

// int main() {
//     int N;
//     cin >> N;

//     int preT = 0;
//     int nextT;
//     for (int i=0; i<N; i++) {
//         cin >> nextT;
//         if (nextT - preT > 15) {
//             cout << preT + 15;
//             break;
//         }
//         if (i == N-1) {
//             cout << ((nextT + 15 > 90) ? 90 : nextT + 15);
//             break;
//         }
//         preT = nextT;
//     }

//     return 0;
// }

// Ex4: Vitaly and Strings

// int main() {
//     string s1, s2;
//     getline(cin, s1);
//     getline(cin, s2);
//     int len = s1.length();

//     for (int j = len - 1; j > -1; j--) {
//         if (s1[j] != 'z') {
//             s1[j]++;
//             break;
//         }
//         else {
//             s1[j] = 'a';
//         }
//     }

//     if (s1 != s2) cout << s1;
//     else cout << "No such string";
// }

int main() {
    // LECTURE 1
    cout << "C++" << endl;

    vector<int> arr;

    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);

    vector<int>::iterator it;
    it = arr.begin() + 1;
    arr.insert(it, 2);

    cout << "Size: " << arr.size() << endl;

    cout << "3rd element: " << arr[2] << endl;

    arr[3] = 10;

    arr.pop_back();

    it = arr.begin() + 2;
    arr.erase(it);

    arr.clear();

    arr.resize(8);

    arr.resize(5);

    arr = {1, 2, 3, 4};

    cout << (arr.empty() ? "Empty" : "Not empty") << endl;

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    for (int i = arr.size() - 1; i > -1; i--) {
        cout << arr[i] << " ";
    }

    string str = "4Hello World";

    if (str[0] >= '0' && str[0] <= '9') {
        cout << "Digit" << endl;
    }

    cout << (isalpha(str[2]) ? "Is character" : "Not character") << endl;

    string num = "123";
    int nu = stoi(num);
    string num2 = to_string(nu);
    cout << num2 << endl;

    return 0;
}