#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <time.h>

using namespace std;

int M = 0;
string removeSpaces(string s)
{
  string result = "";
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] != ' ')
    {
      result += s[i];
    }
  }
  return result;
}

void makeQueueForBitString(string s, unordered_set<string> &bits)
{
  int L = s.length();
  queue<string> result;
  result.push(s);

  while (!result.empty())
  {
    string current = result.front();
    for (int i = 0; i < L; i++)
    {
      for (int j = i; j < L; j++)
      {
        string copy = current;
        copy[i] = (current[i] == '1') ? '0' : '1';

        if (i != j)
        {
          copy[j] = (current[j] == '1') ? '0' : '1';
        }

        unordered_set<string>::const_iterator found = bits.find(copy);
        if (found != bits.end())
        {
          result.push(copy);
          bits.erase(found);
          // cout << result.size() << " queue\n";
        }
      }
    }

    unordered_set<string>::const_iterator found = bits.find(current);
    if (found != bits.end())
    {
      bits.erase(found);
    }

          // cout << result.size() << " queue\n";
    result.pop();
  }
  // while (!result.empty())
  // {
  //     makeQueueForBitString(result.front(), bits);
  //     result.pop();
  // }
}

int main()
{
  clock_t tStart = clock();
  int N;
  cin >> N;
  int L;
  cin >> L;

  string bit;
  unordered_set<string> bits;

  std::getline(cin, bit);
  while (N--)
  {
    std::getline(cin, bit);
    bit = removeSpaces(bit);
    bits.insert(bit);
  }

  // cout << bits.size() << endl;

  string s;
  int clusterCount = 0;
  while (!bits.empty())
  {
    auto it = bits.begin();
    s = *it;
    makeQueueForBitString(s, bits);
    M = 0;
    clusterCount++;
    // bits.clear();
  }

  cout << "Clusters: " << clusterCount << endl;

  printf("Time taken: %.4fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
  return 0;
}