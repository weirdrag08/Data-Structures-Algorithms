// #include<iostream>
// #include<unordered_map>
// #include<list>
// #include<vector>
// #include<stack>
// #include<queue>
// #include<climits>
// #include<algorithm>
// #include<string>
// #include<utility>
// using namespace std;

// #define mp make_pair
// #define INFI 10e8
// #define INF 10e7

// typedef pair<int, int> pi;
// typedef vector<int> vi;
// typedef vector<bool> vb;
// typedef long long ll;

// int main(){
//     unordered_map<char, int> s1_chars, s2_chars;
//     string s1, s2, temp = "", result = "";
//     bool loop1 = true, loop2 = true;
//     cin >> s1 >> s2;
//     int match_count = 0, desired_match_count = s2.size();
//     for(int i = 0; i < s2.size(); i++){
//         s2_chars[s2[i]] += 1;
//     }
//     for(int k = 0, i = 0, j = -1;; k++){
//         loop1 = false;
//         loop2 = false;
//         while ((i < s1.size()) && match_count < desired_match_count)
//         {
//             temp += s1[i];
//             s1_chars[s1[i]] += 1;
//             if(s1_chars[s1[i]] <= s2_chars[s1[i]]){
//                 match_count++;
//             }
//             cout << temp << '\n';
//             i++;
//             loop1 = true;
//         }

//         while ((j < i) && match_count == desired_match_count)
//         {
//             temp = s1.substr(j + 1, i - j);
//             if(result == "" || result.size() < temp.size()){
//                 result = temp;
//             }
//             j++;
//             s1_chars[s1[j]]--;
//             if(s1_chars[s1[j]] == 0){
//                 s1_chars.erase(s1[j]);
//             }
//             if(s1_chars[s1[j]] < s2_chars[s1[j]]){
//                 match_count--;
//             }
//             loop2 = true;
//         }
//         if(loop1 == false && loop2 == false){
//             break;
//         }
//     }
//     cout << result << '\n';
// }

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main()
{
    unordered_map<char, int> s1_chars, s2_chars;
    string s1, s2, temp = "", result = "";
    bool loop1 = true, loop2 = true;
    cin >> s1 >> s2;
    int match_count = 0, desired_match_count = s2.size();
    for (int i = 0; i < s2.size(); i++)
    {
        s2_chars[s2[i]] += 1;
    }
    for (int k = 0, i = -1, j = -1; (loop1 == true && loop2 == true); k++)
    {
        loop1 = false;
        loop2 = false;
        cout << i << "     " << s1.size() << endl;
        // cout<<((match_count<desired_match_count) && (i< s1.size()))<<endl;
        cout << boolalpha << (i < s1.size()) << endl;

        while ((i < s1.size()) && (match_count < desired_match_count))
        {
            i++;
            temp += s1[i];
            s1_chars[s1[i]] += 1;
            if (s1_chars[s1[i]] <= s2_chars[s1[i]])
            {
                match_count++;
            }

            loop1 = true;
        }

        while (match_count == desired_match_count && j < i)
        {
            if (result == "" || result.size() < temp.size())
            {
                result = s1.substr(j + 1, i - j);
                temp = s1.substr(j + 1, i - j);
            }
            j++;
            s1_chars[s1[j]]--;
            if (s1_chars[s1[j]] == 0)
            {
                s1_chars.erase(s1[j]);
            }
            if (s1_chars[s1[j]] < s2_chars[s1[j]])
            {
                match_count--;
            }
            loop2 = true;
        }
    }
    cout << result << '\n';
}
