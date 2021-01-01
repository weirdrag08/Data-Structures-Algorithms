#include <iostream>
#include <string>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    pi p(1, 16);
    char arr[17];
    for (int i = 1; i < 17; i++)
    {
        arr[i] = 'a' + i - 1;
    }

    for (int i = 0; i < tc; i++)
    {
        int N;
        cin >> N;
        string s;
        cin >> s;
        int bit_count = 0, number = 16;
        for (int j = 0; j < s.size(); j++)
        {

            number /= 2;
            if (s[j] == '0')
            {
                p.second -= number;
                cout << "Second " << p.second << '\n';
            }

            else if (s[j] == '1')
            {
                p.first += number;
                cout << "First " << p.first << '\n';
            }

            bit_count++;
            if (bit_count == 4)
            {
                cout << arr[p.first];
                bit_count = 0;
                p.first = 1;
                p.second = 16;
                number = 16;
            }
        }
    }

    cout << '\n';
}