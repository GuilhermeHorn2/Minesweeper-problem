#include <stdio.h>
#include <iostream>
#include <vector>

void make_field(std::vector<std::vector<char>> &field, std::vector<std::vector<int>> &count);

void count_mine(int a, int b, std::vector<std::vector<int>> &count);

void make_field(std::vector<std::vector<char>> &field);

void print_count(std::vector<std::vector<int>> &count);

int main()
{

 std::vector<char> a0 = {'*', '.', '.', '.'};
 std::vector<char> a1 = {'.', '.', '.', '.'};
 std::vector<char> a2 = {'.', '*', '.', '.'};
 std::vector<char> a3 = {'.', '.', '.', '.'};
 std::vector<std::vector<char>> m = {a0, a1, a2, a3};

 make_field(m);

 return 0;
}

void count_mine(int a, int b, std::vector<std::vector<int>> &count)
{

 int m = count.size();
 int n = count[0].size();

 for (int i = a - 1; i <= a + 1; i++)
 {
  if (i < m && i >= 0)
  {
   for (int j = b - 1; j <= b + 1; j++)
   {

    if (j < n && j >= 0)
    {
     if (count[i][j] != -1)
     {
      count[i][j]++;
     }
    }
   }
  }
 }
}

void make_field(std::vector<std::vector<char>> &field, std::vector<std::vector<int>> &count)
{

 for (int i = 0; i < field.size(); i++)
 {
  for (int j = 0; j < field[i].size(); j++)
  {
   if (field[i][j] == '*')
   {
    count_mine(i, j, count);
   }
  }
 }
}

void print_count(std::vector<std::vector<int>> &count)
{

 for (int i = 0; i < count.size(); i++)
 {
  for (int j = 0; j < count[i].size(); j++)
  {
   if (count[i][j] == -1)
   {
    std::cout << '*';
   }
   else
   {
    std::cout << count[i][j];
   }
  }
  std::cout << '\n';
 }
}

void make_field(std::vector<std::vector<char>> &field)
{

 std::vector<std::vector<int>> count;
 for (int i = 0; i < field.size(); i++)
 {
  std::vector<int> tmp;
  count.push_back(tmp);
  for (int j = 0; j < field[i].size(); j++)
  {
   if (field[i][j] == '*')
   {
    count[i].push_back(-1);
   }
   else
   {
    count[i].push_back(0);
   }
  }
 }
 make_field(field, count);
 print_count(count);
}
